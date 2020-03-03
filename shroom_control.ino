#define MODE    "fruiting"  // incubation | fruiting

#define INCUBATION_TEMP       28
#define FRUITING_TEMP         24.5

#define FAN_SCHEDULE   900   // how often to turn on the fan (in seconds)
#define FAN_LENGTH     60        // turn it on for this many seconds every time

#define Kp  -1.0
#define Ki  -0.0003
#define LONG_PWM  180    // length of PWM cycle for heat control (in seconds)

#include "dht.h"

#define HEATER      2
#define MOTOR       3
#define DHTPIN      10

dht DHT;
long runtime = 0;
long heat_time = 0;

double temp_error;
double sum_errors = 0.0;
double pid_result;


void setup(void) {
  LcdInitialise();
  pinMode(HEATER, OUTPUT);
  digitalWrite(HEATER, HIGH);      // HIGH means off here, because it's connected to SSR
  pinMode(MOTOR, OUTPUT);
  digitalWrite(MOTOR, HIGH);  // HIGH means off here, because it's connected to SSR
}


void loop(void) {
  //init
  LcdClear();
  DHT.read22(DHTPIN);
  runtime++;    //count runtime, heater and humidifier ontime
  if ( !digitalRead(HEATER) )     heat_time++;

  //drawing
  gotoXY(0, 0);
  printString( MODE );
  gotoXY(0, 1);
  printString( String(runtime / 86400) + "d " + String((runtime / 3600) % 24) + "h " + String((runtime / 60) % 60) + "m");
  gotoXY(0, 2);
  printString( "temp " + String(DHT.temperature, 1) + "C");
  gotoXY(0, 3);
  printString( "H2O  " + String(DHT.humidity, 1) + "%");
  gotoXY(0, 4);
  printString( "h total " + String(100 * heat_time / runtime) + "%");
  gotoXY(0, 5);
  printString( "h now " + String(100 * pid_result, 0) + "%");

  if (DHT.temperature < 0) digitalWrite(HEATER, HIGH); // error, turn off the heater

  if (MODE == "incubation") {
    temp_error = DHT.temperature - INCUBATION_TEMP;
  }

  if (MODE == "fruiting") {
    temp_error = DHT.temperature - FRUITING_TEMP;

    if ( (runtime % FAN_SCHEDULE) < FAN_LENGTH ) digitalWrite(MOTOR, LOW);
    else  digitalWrite(MOTOR, HIGH);
  }

  sum_errors += temp_error;
  pid_result = Kp * temp_error + Ki * sum_errors;
  pid_result = (pid_result + 1) / 2;    // rescale from (-1, 1) to (0, 1)
  if (pid_result > 1) pid_result = 1;   // clip
  if (pid_result < 0) pid_result = 0;


  if ((runtime % LONG_PWM) < (pid_result * LONG_PWM)) digitalWrite(HEATER, LOW);
  else digitalWrite(HEATER, HIGH);

  delay(1000);
}
