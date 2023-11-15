/*******************************************************************************
* AmbaSat-1 
* Filename: main.h
*
* Copyright (c) 2023 AmbaSat Ltd
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
#define SENSOR_09_TEST      59 // Test sensor


// LSM9DS1 Addresses
#define LSM9DS1_M	0x1E  // Mag address
#define LSM9DS1_AG	0x6B  // AG address

// -----------------------------------------------------------------------------
// Settings
// -----------------------------------------------------------------------------

// This Sensor ID, should be unique in the same network
#define SENSOR_ID       57     

// Gateway ID that will receive the messages from this node
#define GATEWAY_ID      1

// Network ID, only nodes from the same network see each other
#define NETWORKID       100

// Must match RX's freq!
#define RF95_FREQ       868.1

// The version number of the comms packet
#define PACKET_VERSION  1

// pins connected to Arduino (for reference, not required for Whisper Node)
#define RFM95_CS        10
#define RFM95_RST       9
#define RFM95_INT       2

#define LED_PIN         9

uint16_t readVcc();


// -----------------------------------------------------------------------------
// Transfer packet data structure
// -----------------------------------------------------------------------------
struct
{
      uint32_t deviceId;
	  uint16_t co2;
	  uint16_t tvoc;
	  uint16_t voltage;
	  uint8_t checksum;
} packetData;

// -----------------------------------------------------------------------------
// Checksum calc
// -----------------------------------------------------------------------------
uint8_t checksum (unsigned char *ptr, size_t sz)
{
    uint8_t chk = 0;

    while (sz-- != 0)
    {
        chk -= *ptr++;
    }

    return chk;
}

// -----------------------------------------------------------------------------
// PrintHex8 - prints 8-bit data in hex with leading zeroes
// -----------------------------------------------------------------------------
void PrintHex8(uint8_t *data, uint8_t length)
{
    Serial.print("0x");

    for (int i=0; i<length; i++)
    {
        if (data[i]<0x10)
        {
           Serial.print("0");
        }

        Serial.print(data[i], HEX);
        Serial.print(" ");
    }

    Serial.print("\n");
}

// -----------------------------------------------------------------------------
// OLD: TTN payloads - see: https://www.thethingsnetwork.org/docs/devices/bytes.html
// -----------------------------------------------------------------------------

// TTN decode for CCS811B is as below
//  
// AmbaSat 'SENSOR_07_CCS811B' TTN Payload Decoder expects:
// decode(bytes, [int16, int16, uint8, int16, int16, int16, int16, int16, int16, int16, int16, int16], ['co2', 'tvoc', 'voltage', 'gx', 'gy', 'gz', 'ax', 'ay', 'az', 'mx', 'my', 'mz']);