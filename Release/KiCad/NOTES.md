# AmbaSat-1 KiCad Notes

## Getting Started

**Important!** Always have an antenna connected before using the AmbaSat-1

Here's one that works:
[Amazon 433Mhz Antenna and U.FL to SMA cable](https://www.amazon.com/dp/B07DDF5YCJ?psc=1&ref=ppx_yo2_dt_b_product_details)

A 3.3V USB to Serial adapter is required for programming.  This is a known good/recommended one:
[SparkFun FTDI Basic Breakout 3.3V DEV-09873](https://www.sparkfun.com/products/9873)

## Programming Notes for Open Research Institute (ORI) provided AmbaSat-1 KiCad boards

For those already familiar with Arduino programming, these instructions should be plenty.
For those who have never programmed using the Arduino environment before, these will get you close, but will probably gloss over some details.
For those somewhere in the middle, consider it a learning exercise.

The AmbaSat-1 is a "generic" ATmega328 processor.  It can be programmed using Arduino sketches and libraries.

If you received an AmbaSat-1 KiCad from ORI, it has been programmed with the MiniCore version of the OptiBoot Bootloader.

*If you are starting with a blank ATmega328, you will likely need to program a bootloader (this is outside the current instruction scope... basically you need an ISP programmer, hook up the correct pins, and program the bootloader).*

These are the options the bootloader was programmed with:
```
Board: "ATmega328"
Clock: "External 4MHz"
BOD: "BOD 1.8V"
EEPROM: "EEPROM retained"
Compiler LTO: "LTO disabled"
Variant: "328P / 328PA"
Bootloader: "Yes (UART0)"
```

These commands are for reference for advanced users - they will not run as-is, but do show the parameters used...
```
avrdude -C"avrdude.conf" -v -patmega328p -catmelice_isp -Pusb -Ulfuse:w:0xec:m -Uhfuse:w:0xda:m -Uefuse:w:0xfe:m
avrdude -C"avrdude.conf" -v -patmega328p -catmelice_isp -Pusb -Uflash:w:"optiboot_flash_atmega328p_UART0_9600_4000000L_B5.hex":i -Ulock:w:0xcF:m
```

The AmbaSat project uses PlatformIO as their development tool of choice.  https://platformio.org/
The AmbaSat-1.json included in the AmbaSat-1/Release/Source/Examples/.../boards assumed a 1MHz internal oscillator was being used.  If you utilize the examples and PlatformIO, you should verify which settings are being used, and you may need to change them, or reprogram with a different bootloader.

You can also use the standard Arduino IDE, but you will need to load the MiniCore board support.

[Arduino IDE](https://www.arduino.cc/en/software)

[MiniCore Board Support Package](https://github.com/MCUdude/MiniCore)

[See the MiniCore installation instructions here](https://github.com/MCUdude/MiniCore#how-to-install)

Using the Arduino IDE with the MiniCore board support package, you want to select Tools->Board->MiniCore->ATmega328, and then use the same configuration options that were shown above for the bootloader.

## Quick Check for ORI supplied AmbaSat-1 KiCad boards

ORI AmbaSat-1 KiCad boards have been pre-loaded with the standard Blink sketch which will blink the LED on/off at about 1Hz.

To test:

**!!!Make sure you have an antenna connected!!!**

Connect the USB to Serial adapter to the AmbaSat such that the signals match (DTR to DTR, RXI to TX, TXO to RX, 3V3 to VIN, CTS to SS, GND to GND). 

![AmbaSat-1 Programming](media/Programming_1.jpg?raw=true "AmbaSat-1 Programming")

![AmbaSat-1 Programmer](media/Programming_2.jpg?raw=true "AmbaSat-1 Programmer")

Plug the USB to Serial adapter into your computer using the appropriate cable.  The LED should blink on/off at about 1Hz.

## Programming with the Arduino IDE

### Pinout details

The ORI AmbaSat-1 KiCad using MiniCore has the following pin functions:
```
ATmega328P  MiniCore/Arduino  RFM96 Connection
PB4         D12 (MISO)        MISO
PB3         D11 (MOSI)        MOSI
PB5         D13 (SCK)         SCK
PB2         D10 (SS)          SS
PD2         D2                DIO0
PC2         D16 / A2          DIO1
PC1         D15 / A1          DIO2
PB1         D9                (none - LED)
```

*PC1/D15/A1/DIO2 is added as a rework wire through a 1K ohm resistor.  The DIO2 pin on the RFM96 is bidirectional in some modes, and allows direct modulation of the RF signal.*

### Programming Blink 

1. Start the Arduino IDE
2. Select Tools->Board->MiniCore->ATmega328, and then use the same configuration options that were shown above for the bootloader.
3. Select Files->Examples->Basics->Blink
4. Add the line #define LED_BUILTIN 9 just after the main comment block and before the setup() function
5. Change the two 'delay(1000);' lines in the loop() routine to be 'delay(100);'  ...  the board already has the 1s delays programmed in, you need something different...
6. Tools->Port-> (select the appropriate serial port for the USB<->Serial adapter)
7. Press the Upload button (the right pointing arrow just under the menu bar)
8. Hopefully you eventually get a 'Done uploading' message and the LED is blinking fast :-)

### Radio programming with the Arduino IDE

To test radio operation between two boards, I found it easiest to install the RadioHead Arduino Library (follow instructions here http://www.airspayce.com/mikem/arduino/RadioHead/)

Program one board using Examples->RadioHead->rf95->rf95_client and the other using rf95_server

Use you favorite terminal program (like Tera Term) and open up both devices at 9600 N81

You should see something like this:

![RF Client and Server](media/rf_client_server.png?raw=true "RF Client and Server")

## Arduino and Adafruit RFM96 Breakout

Here are some details to wire up an Arduino with the [Adafruit RFM96 module](https://www.adafruit.com/product/3073).  If you use an ATmega328P based Arduino, you pretty much have a breadboard AmbaSat-1, except by default it will be running at 16MHz instead of 4MHz.

```
Arduino Pin  RFM96 Module
A1 (D15)     G2
A2 (D16)     G1
5V           VIN
GND          GND
D13          SCK
D12          MISO
D11          MOSI
D10          CS
D2           G0
