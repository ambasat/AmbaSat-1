/*******************************************************************************
* AmbaSat-1 Sensor 02 - STS21
* 27th January 2020
* Version 1.0
* Filename: main.cpp
*
* Copyright (c) 2022 AmbaSat Ltd
* https://ambasat.com
*
* Licensed under Creative Commons Attribution-ShareAlike 3.0
*
* Use this application to test the circuitry of your AmbaSat-1 Satellite and Sensor 02 - STS21
* Once the code is uploaded, view the debug output to confirm temperature readings
*
* ******************************************************************************/

#include <Arduino.h>
#include <Wire.h>

#define addr 0x4A // STS21 I2C address is 0x4A(74)

// ==============================================================================
void setup() {
    Wire.begin();
    Serial.begin(9600);
}

// ==============================================================================
void loop() {
    unsigned int data[2];

    // Start I2C Transmission
    Wire.beginTransmission(addr);

    // Select no hold master
    Wire.write(0xF3);

    // End I2C Transmission
    Wire.endTransmission();
    delay(300);

    // Request 2 bytes of data
    Wire.requestFrom(addr, 2);

    // Read 2 bytes of data
    if (Wire.available() == 2)
    {
      data[0] = Wire.read();
      data[1] = Wire.read();
    }

    // Convert the data
    int rawtmp = data[0] * 256 + data[1];
    int value = rawtmp & 0xFFFC;
    double cTemp = -46.85 + (175.72 * (value / 65536.0));
    double fTemp = cTemp * 1.8 + 32;

    // Output data to serial monitor
    Serial.print("Temperature in Celsius:  ");
    Serial.print(cTemp);
    Serial.println(" C");
    Serial.print("Temperature in Fahrenheit:  ");
    Serial.print(fTemp);
    Serial.println(" F");
    delay(1000);
}