/*******************************************************************************
* AmbaSat-1 Sensor 04 - OPT3001
* 5th February 2020
* Version 1.0
* Filename: main.cpp
*
* Copyright (c) 2020 AmbaSat Ltd
* https://ambasat.com
*
* Licensed under Creative Commons Attribution-ShareAlike 3.0
*
* Use this application to test the circuitry of your AmbaSat-1 Satellite and Sensor 04 - OPT3001
* Once the code is uploaded to your AmbaSat-1 board, view the debug output to confirm readings
*
* Based on code from ClosedCube
* ******************************************************************************/

#include <Arduino.h>
#include <Wire.h>
#include <ClosedCube_OPT3001.h>

ClosedCube_OPT3001 opt3001;

#define OPT3001_ADDRESS 0x44  // OPT3001 I2C address is 0x45(69)

void printError(String text, OPT3001_ErrorCode error);
void printResult(String text, OPT3001 result); 
void configureSensor(); 

// ==============================================================================
void setup() {
    Wire.begin();
    Serial.begin(9600);

    Serial.println("OPT3001 Arduino Test");

    opt3001.begin(OPT3001_ADDRESS);
    Serial.print("OPT3001 Manufacturer ID");
    Serial.println(opt3001.readManufacturerID());
    Serial.print("OPT3001 Device ID");
    Serial.println(opt3001.readDeviceID());

    configureSensor();
    printResult("High-Limit", opt3001.readHighLimit());
    printResult("Low-Limit", opt3001.readLowLimit());
    Serial.println("----");        
}

// ==============================================================================
void loop()
{
	OPT3001 result = opt3001.readResult();
	printResult("OPT3001", result);
	delay(500);
}

// ==============================================================================
void configureSensor() 
{
    OPT3001_Config newConfig;
    
    newConfig.RangeNumber = B1100;	
    newConfig.ConvertionTime = B0;
    newConfig.Latch = B1;
    newConfig.ModeOfConversionOperation = B11;

    OPT3001_ErrorCode errorConfig = opt3001.writeConfig(newConfig);
   
    if (errorConfig != NO_ERROR)
    {
        printError("OPT3001 configuration", errorConfig);
    }
    else 
    {
        OPT3001_Config sensorConfig = opt3001.readConfig();
        Serial.println("OPT3001 Current Config:");
        Serial.println("------------------------------");
        
        Serial.print("Conversion ready (R):");
        Serial.println(sensorConfig.ConversionReady,HEX);

        Serial.print("Conversion time (R/W):");
        Serial.println(sensorConfig.ConvertionTime, HEX);

        Serial.print("Fault count field (R/W):");
        Serial.println(sensorConfig.FaultCount, HEX);

        Serial.print("Flag high field (R-only):");
        Serial.println(sensorConfig.FlagHigh, HEX);

        Serial.print("Flag low field (R-only):");
        Serial.println(sensorConfig.FlagLow, HEX);

        Serial.print("Latch field (R/W):");
        Serial.println(sensorConfig.Latch, HEX);

        Serial.print("Mask exponent field (R/W):");
        Serial.println(sensorConfig.MaskExponent, HEX);

        Serial.print("Mode of conversion operation (R/W):");
        Serial.println(sensorConfig.ModeOfConversionOperation, HEX);

        Serial.print("Polarity field (R/W):");
        Serial.println(sensorConfig.Polarity, HEX);

        Serial.print("Overflow flag (R-only):");
        Serial.println(sensorConfig.OverflowFlag, HEX);

        Serial.print("Range number (R/W):");
        Serial.println(sensorConfig.RangeNumber, HEX);

        Serial.println("------------------------------");
    }    
}

// ==============================================================================
void printResult(String text, OPT3001 result) 
{
	if (result.error == NO_ERROR) 
  {
      Serial.print(text);
      Serial.print(": ");
      Serial.print(result.lux);
      Serial.println(" lux");
	}
	else 
  {
	  	printError(text,result.error);
	}
}

// ==============================================================================
void printError(String text, OPT3001_ErrorCode error) 
{
    Serial.print(text);
    Serial.print(": [ERROR] Code #");
    Serial.println(error);
}