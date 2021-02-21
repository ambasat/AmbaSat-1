/*******************************************************************************
* AmbaSat-1 
* Filename: main.h
*
* Copyright (c) 2021 AmbaSat Ltd
* https://ambasat.com
*
* licensed under Creative Commons Attribution-ShareAlike 3.0
* ******************************************************************************
*
* Supporting code/libraries:
*
* LoRa code Copyright (c) 2015 Thomas Telkamp and Matthijs Kooijman
*
* Permission is hereby granted, free of charge, to anyone
* obtaining a copy of this document and accompanying files,
* to do whatever they want with them without any restriction,
* including, but not limited to, copying, modification and redistribution.
* NO WARRANTY OF ANY KIND IS PROVIDED.
**
*******************************************************************************/

#include <Arduino.h>
#include <LoraMessage.h>
#include <Debugging.h>
#include "LowPower.h"

#define SERIAL_BAUD         9600 
#define LED_PIN             9

// AmbaSat-1 range of I2C compatible sensors and their TTN port IDs / Dashboard - config.inc
#define SENSOR_01_SHT31     51 // Temperature & Humidity
#define SENSOR_02_STS21     52 // Temperature
#define SENSOR_03_BME680    53 // Gas, Pressure, TVOC 
#define SENSOR_04_OPT3001   54 // Ambient Light
#define SENSOR_05_ZMOD4410  55 // TVOC 
#define SENSOR_06_SI1132    56 // UV 7 Ambient
#define SENSOR_07_CCS811B   57 // TVO & CO2
#define SENSOR_08_TESEO     58 // GPS

// LSM9DS1 Addresses
#define LSM9DS1_M	0x1E  // Mag address
#define LSM9DS1_AG	0x6B  // AG address

uint16_t readVcc();

// -----------------------------------------------------------------------------
// TTN payloads - see: https://www.thethingsnetwork.org/docs/devices/bytes.html
// -----------------------------------------------------------------------------

// TTN decode for SHT31 is as below
//  
// 'temperature' uses a 16bit two's complement with two decimals, so the range is -327.68 to +327.67 degrees
// 'humidity' is rounded to whole percent. eg 55.5% becomes 55%
// 'voltage' - eg. 2840 millivolts becomes 28 and in the Dashboard is decoded to 2.8 volts
//
// AmbaSat 'SENSOR_01_SHT31' TTN Payload Decoder expects:
// decode(bytes, [temperature, uint8, uint8, int16, int16, int16, int16, int16, int16, int16, int16, int16], ['temperature', 'humidity', 'voltage', 'gx', 'gy', 'gz', 'ax', 'ay', 'az', 'mx', 'my', 'mz']);
