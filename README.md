rgbcp
=====

The home made ARM Cortex-M3 hardware project with RGB leds that displays name of my girl. 

General description:
This device will display the word "АНЯ" with RGB-leds (10 RGB-leds for one symbol -> 30 RGB-leds -> 90 sub-leds)
The device will be powered from usb or 4xAA batteries.
I want to create automatic selection of power source Battery -> USB.
I want to create monitoring of power source (which power source used - Battery/USB and Battery Level) and change the LEDs maximum brightness level according to Battery Level.
I want to create reverse battery protection.
I want to create Battery Level via 4 leds (0% -> 25% -> 50% -> 75% -> 100%).
I want to use 4 DIP-switches (1 for Firmware Download mode and 3 for debug purposes).
I want to use 6 Push-Buttons (2 for Select Animaton Mode <NEXT>/<PREV>, 2 for select Animation Speed <FAST>/<SLOW>, and 2 for select Brightness of leds).

The RGB Cortex Project consists of the next steps:
1. Hardware schematic (The KiCAD EDA will be used).
2. Hardware PCB (KiCAD).
3. Building home-made device from step1&step2.
4. Programming Firmware for ARM Cortex M3 with USB-HID interface.
5. Programming Software (C++ & Qt) for creating animation themes and writes it to device via HID API.
6. Test and Posts results here.
