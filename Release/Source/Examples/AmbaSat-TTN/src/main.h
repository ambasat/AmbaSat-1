/*******************************************************************************
* AmbaSat-1 TTN
* 20th May 2020
* Version 1.0
* Filename: main.h
*
* Copyright (c) 2020 AmbaSat Ltd
* https://ambasat.com
*
* licensed under Creative Commons Attribution-ShareAlike 3.0
* ******************************************************************************/

#include <avr/sleep.h>
#include <avr/wdt.h>
#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>
#include "LowPower.h"
#include "i2c.h"
#include <Arduino.h>
#include <LoraMessage.h>
#include <settings.h>

#define addr 0x4A
#define LedPin 9
#define ADR_MODE 1

int sleepcycles = 130;
bool joined = false;
bool sleeping = false;

// -----------------------------------------------------------------------------
// Gyro/Magno/Accel structure
// -----------------------------------------------------------------------------
struct threeDData 
{
  	uint8_t x;
	uint8_t y;
	uint8_t z;
};

// -----------------------------------------------------------------------------
// TTN payload data structure - see https://www.thethingsnetwork.org/docs/devices/bytes.html
// -----------------------------------------------------------------------------
struct
{
  uint8_t sensorType;
	uint8_t field1; 
  float field2; 
	uint16_t voltage;
} packetData;

// Set the sensor type 
static const uint8_t sensorType = SENSOR_01_DHT30; // for test purposes

// TTN *****************************  IMPORTANT 
// 
// Set the following three values to match your unique AmbaSat-1 satellite   
// 
// The Network Session Key
static const PROGMEM u1_t NWKSKEY[16] = {0x38,0xD8,0xE7,0x52,0xEB,0x4F,0x81,0x0F,0xD9,0x55,0xAD,0xA4,0x1C,0xC2,0x5E,0xD1}; //<< CHANGE

// LoRaWAN AppSKey, application session key
static const u1_t PROGMEM APPSKEY[16] = {0x6B,0x98,0xF3,0x21,0x46,0xBF,0x35,0x20,0x21,0x99,0xBE,0x13,0x45,0x34,0x4C,0x6B}; //<< CHANGE

// LoRaWAN end-device address (DevAddr)
static const u4_t DEVADDR = 0x26011D67 ;  //<< CHANGE

/***********************************  IMPORTANT */

// These callbacks are only used in over-the-air activation, so they are
// left empty here (cannot be left out completely unless
// DISABLE_JOIN is set in config.h, otherwise the linker will complain).
void os_getArtEui (u1_t* buf) { }
void os_getDevEui (u1_t* buf) { }
void os_getDevKey (u1_t* buf) { }

static osjob_t sendjob;
static osjob_t initjob;

// Pin mapping
const lmic_pinmap lmic_pins = {
  .nss = 10,
  .rxtx = LMIC_UNUSED_PIN,
  .rst = 7,
  .dio = {2, A2, LMIC_UNUSED_PIN},
};

