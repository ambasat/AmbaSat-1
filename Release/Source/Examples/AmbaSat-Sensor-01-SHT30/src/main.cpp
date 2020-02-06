/*******************************************************************************
* AmbaSat-1 Sensor 01 - SHT30-D
* 2nd February 2020
* Version 1.0
* Filename: main.cpp
*
* Copyright (c) 2020 AmbaSat Ltd
* https://ambasat.com
*
* Licensed under Creative Commons Attribution-ShareAlike 3.0
*
* Use this application to test the circuitry of your AmbaSat-1 Satellite and Sensor 01 - SHT30
* Once the code is uploaded to your AmbaSat-1 board, view the debug output to confirm readings
*
* Based on code from ClosedCube
* ******************************************************************************/
#include <Arduino.h>
#include <Wire.h>
#include "ClosedCube_SHT31D.h"

ClosedCube_SHT31D sht3xd;

// ==============================================================================
void setup() 
{
    Wire.begin();
    Serial.begin(9600);
    Serial.println("SHT3x Test");

  	sht3xd.begin(0x44); // I2C address: 0x44 or 0x45

	  Serial.print("Serial #");
  	Serial.println(sht3xd.readSerialNumber());

	  if (sht3xd.periodicStart(SHT3XD_REPEATABILITY_HIGH, SHT3XD_FREQUENCY_10HZ) != SHT3XD_NO_ERROR)
    {
	    	Serial.println("[ERROR] Cannot start periodic mode");
    }
}

// ==============================================================================
void loop() 
{
    SHT31D res = sht3xd.periodicFetchData(); 

    if (res.error == SHT3XD_NO_ERROR) 
    {
        Serial.print("T=");
        Serial.print(res.t);
        Serial.print("C, RH=");
        Serial.print(res.rh);
        Serial.println("%");
    } else 
    {
        Serial.print(": [ERROR] Code #");
        Serial.println(res.error);
    }

    delay(250);
}