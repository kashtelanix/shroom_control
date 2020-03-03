# shroom_control
Cheap DIY automatic incubator for mushroom growing

What it does:
- has two modes of action: incubation and fruiting
- keeps constant temperature   (21C for incubation, 25C for fruiting)
- fans out CO2 every 6 hours  (it's very quiet and the new air is filtered)
- displays temperature and humidity
- works well even for quite a large box

So after laying out the substrate, only things you have to worry about are humidity and harvest :]

Using a box with area 4300 cm2 I grew 100g of psilocibe cubensis in a single yield ^^ \
https://www.youtube.com/watch?v=TaKD1Vdarnw

## Building

Tools:
- soldering iron
- driller
- knife

Parts:
- box (I recommend those big transparent boxes from IKEA)
- arduino nano (or other compatible board) with usb cable
- 1m of heating cable 25W/m
- breadboard 830 point
- dupont male-male cables
- SSR
- nokia 5110 screen (blue one, red has different pins)
- DHT22 (termometer + humidity detector)
- fan 40x40x10mm 5 to 12 V
- USB charger 1A or more
- aquarium tube ~50cm length ~3cm diameter
- air filter
- switch
- 2x NPN 0.5A transistors 
- 5x cable ties
- some cables
- 2x plastic bottles
- insulating tape
- (optional) floating usb humidifier

If you order from aliexpress you can get all parts for less than 20$ (not counting the box).

Links to buy most of the parts:
- [box](https://www.ikea.com/us/en/cat/storage-boxes-baskets-10550/)
- [box lid](https://www.ikea.com/us/en/p/samla-lid-for-box-15-34-gallon-clear-90110301/)
- [arduino nano](https://www.aliexpress.com/item/1pcs-lot-Nano-3-0-controller-compatible-for-arduino-nano-CH340-USB-driver-NO-CABLE/32824272738.html)
- [heating cable](https://www.aliexpress.com/item/Heating-Cable-230V-12MM-25W-M-65-C-With-Screen-Shield-Screening-And-Can-Use-In/32785315898.html)
- [breadboard](https://www.aliexpress.com/item/Free-Shipping-400-Tie-Point-Interlocking-Solderless-Breadboard-for-ATMEGA-PIC-400-Tie-Point-Solderless-Breadboard/32456722581.html)
- [SSR](https://www.aliexpress.com/item/Free-shipping-Smart-Electronics-4-Channel-5V-DC-Relay-Module-Solid-State-High-Level-OMRON-SSR/32727486514.html)
- [nokia screen](https://www.aliexpress.com/item/1pcs-High-Quality-84-48-84x48-LCD-Module-White-backlight-adapter-PCB-for-Nokia-5110-for/32804943637.html)
- [DHT22 (termometer + humidity detector)](https://www.aliexpress.com/item/1pcs-Free-shipping-DHT22-Digital-Temperature-and-Humidity-Sensor-AM2302-Module-PCB-with-Cable-For-arduino/32761265326.html)
- [fan](https://www.aliexpress.com/item/Cooler-Axial-Fan-12V-40x40x10mm-For-Arduino-Raspberry-Pi-Computer-3D-printer-CF/32659757506.html)
- [USB charger](https://www.aliexpress.com/item/USB-Charger-Quick-Charge-3-0-Mobile-Phone-Charger-for-iPhone-Fast-Charger-Adapter-for-Huawei/32851875192.html)
- [humidifier](https://www.aliexpress.com/item/Free-on-Mini-Portable-Donuts-USB-Air-Humidifier-Purifier-Aroma-Diffuser-Steam-For-Home/32866873486.html)

Good luck! :D

## TODO
Create schematics and building tutorial.
Add control for humidifier.
