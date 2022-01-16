/*******************************************************************************
* AmbaSat-1 Release
* Filename: main.h
* LoRaWAN encrypted data submission to TTN
* 25th June 2021
* Version 1.01
* Filename: main.h
* Authors: James K. 
*
* Copyright (c) 2022 AmbaSat Ltd
* https://ambasat.com
*
* licensed under Creative Commons Attribution-ShareAlike 3.0
* ******************************************************************************
*
* This example will send data to the AmbaSat Dashboard 
* using frequency and encryption settings matching those of
* the The Things Network.
*
* This example uses ABP (Activation-by-personalisation), where a DevAddr and
* Session keys are preconfigured (unlike OTAA, where a DevEUI and
* application key is configured, while the DevAddr and session keys are
* assigned/generated in the over-the-air-activation procedure).
**
* Note: LoRaWAN per sub-band duty-cycle limitation is enforced (1% in
* g1, 0.1% in g2), but not the TTN fair usage policy.

* To use this code, first register your application and device with
* the things network, to set or generate an AppEUI, DevEUI and AppKey.
* Multiple devices can use the same AppEUI, but each device has its own
* DevEUI and AppKey.
*
* Please define the radio type correctly in config.h.
*
* Supporting code/libraries:
*
* Based on code originally created by
* Copyright (c) 2015 Thomas Telkamp and Matthijs Kooijman
*
* Permission is hereby granted, free of charge, to anyone
* obtaining a copy of this document and accompanying files,
* to do whatever they want with them without any restriction,
* including, but not limited to, copying, modification and redistribution.
* NO WARRANTY OF ANY KIND IS PROVIDED.
**
*******************************************************************************/

#include <avr/sleep.h>
#include <avr/wdt.h>
#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>
#include "LowPower.h"
#include <Arduino.h>
#include <LoraMessage.h>
#include <settings.h>

// #define addr 0x4A
#define LedPin 9
#define ADR_MODE 1

int sleepcycles = 130;
bool joined = false;
bool sleeping = false;

// -----------------------------------------------------------------------------
// Gyro/Magno/Accel structure
// -----------------------------------------------------------------------------
/*
struct threeDData 
{
  	uint8_t x;
	uint8_t y;
	uint8_t z;
};
*/

// -----------------------------------------------------------------------------
// TTN payload data structure - see https://www.thethingsnetwork.org/docs/devices/bytes.html
// -----------------------------------------------------------------------------
struct
{
  	uint8_t sensorType;
	uint8_t humidity; 		// humidity percent
    float temperature;   	// temperature in degrees C
	uint16_t voltage;  		// in millivolts
	uint16_t pressure; 		// hPa 
	uint16_t gas;      		// kOhms
 	float altitude;    		// meters
} packetData;

// Set the sensor type 
static const uint8_t sensorType = SENSOR_03_BME680;

// TTN *****************************  
// The Network Session Key / DO NOT SHARE
static const PROGMEM u1_t NWKSKEY[16] = {0x88,0x02,0x56,0xEA,0xD0,0x8F,0x7D,0x87,0x90,0x7B,0xB5,0xD3,0x04,0xA3,0x34,0x07};

// LoRaWAN AppSKey, application session key / DO NOT SHARE
static const u1_t PROGMEM APPSKEY[16] = {0x6B,0x87,0x3D,0xAC,0x5E,0X7D,0x32,0xF5,0xF1,0x98,0xBB,0x0E,0x2E,0x62,0xD8,0x54};

// LoRaWAN end-device address (DevAddr) / DO NOT SHARE
static const u4_t DEVADDR = 0x26013BB9 ;
/********************************/


// These callbacks are only used in over-the-air activation, so they are
// left empty here (cannot be left out completely unless
// DISABLE_JOIN is set in config.h, otherwise the linker will complain).
void os_getArtEui (u1_t* buf) { }
void os_getDevEui (u1_t* buf) { }
void os_getDevKey (u1_t* buf) { }

static osjob_t sendjob;
static osjob_t initjob;

// AmbaSat lmic pin mapping
const lmic_pinmap lmic_pins = {
  .nss = 10,
  .rxtx = LMIC_UNUSED_PIN,
  .rst = 7,
  .dio = {2, A2, LMIC_UNUSED_PIN},
};

