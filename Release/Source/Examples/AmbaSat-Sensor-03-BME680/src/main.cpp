/*******************************************************************************
* AmbaSat-1 Sensor 03 - BME680
* 1st February 2020
* Version 1.0
* Filename: main.cpp
*
* Copyright (c) 2020 AmbaSat Ltd
* https://ambasat.com
*
* Licensed under Creative Commons Attribution-ShareAlike 3.0
*
* Use this application to test the circuitry of your AmbaSat-1 Satellite and Sensor 03 - BME680
* Once the code is uploaded to your AmbaSat-1 board, view the debug output to confirm readings
*
* =================================================================================
* This is a library for the BME680 gas, humidity, temperature & pressure sensor
*
* Designed specifically to work with the Adafruit BME680 Breakout
* ----> http://www.adafruit.com/products/3660
*
* These sensors use I2C or SPI to communicate, 2 or 4 pins are required
* to interface.
*
* Adafruit invests time and resources providing this open source code,
* please support Adafruit and open-source hardware by purchasing products
* from Adafruit!
*
* Original written by Limor Fried & Kevin Townsend for Adafruit Industries.
* =================================================================================
*
* ******************************************************************************/
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"

#define SEALEVELPRESSURE_HPA (1013.25)
#define BME680_DEFAULT_ADDRESS_AMBASAT  (0x76)     ///< AmbaSat BME680 address

Adafruit_BME680 bme; // I2C

// ==============================================================================
void setup() 
{
    Serial.begin(9600);
    while (!Serial);
    Serial.println(F("BME680 async test"));

    if (!bme.begin(BME680_DEFAULT_ADDRESS_AMBASAT)) 
    {
        Serial.println(F("Could not find a valid BME680 sensor, check wiring"));
        while (1);
    }

    // Set up oversampling and filter initialization
    bme.setTemperatureOversampling(BME680_OS_8X);
    bme.setHumidityOversampling(BME680_OS_2X);
    bme.setPressureOversampling(BME680_OS_4X);
    bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
    bme.setGasHeater(320, 150); // 320*C for 150 ms
}

// ==============================================================================
void loop() 
{
    // Tell BME680 to begin measurement.
    unsigned long endTime = bme.beginReading();
    if (endTime == 0) {
        Serial.println(F("Failed to begin reading :("));
        return;
    }

    Serial.print(F("Reading started at "));
    Serial.print(millis());
    Serial.print(F(" and will finish at "));
    Serial.println(endTime);

    Serial.println(F("You can do other work during BME680 measurement."));
    delay(50); // This represents parallel work.

    // There's no need to delay() until millis() >= endTime: bme.endReading()
    // takes care of that. It's okay for parallel work to take longer than
    // BME680's measurement time.

    // Obtain measurement results from BME680. Note that this operation isn't
    // instantaneous even if milli() >= endTime due to I2C/SPI latency.
    if (!bme.endReading()) 
    {
        Serial.println(F("Failed to complete reading :("));
        return;
    }

    Serial.print(F("Reading completed at "));
    Serial.println(millis());

    Serial.print(F("Temperature = "));
    Serial.print(bme.temperature);
    Serial.println(F(" *C"));

    Serial.print(F("Pressure = "));
    Serial.print(bme.pressure / 100.0);
    Serial.println(F(" hPa"));

    Serial.print(F("Humidity = "));
    Serial.print(bme.humidity);
    Serial.println(F(" %"));

    Serial.print(F("Gas = "));
    Serial.print(bme.gas_resistance / 1000.0);
    Serial.println(F(" KOhms"));

    Serial.print(F("Approx. Altitude = "));
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(F(" m"));

    Serial.println();
    delay(2000);
}