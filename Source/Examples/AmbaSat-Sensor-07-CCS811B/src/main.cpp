/*******************************************************************************
* AmbaSat-1 Sensor 07 - CCS811B
* 4th October 2021
* Version 1.01
* Filename: main.cpp
*
* Copyright (c) 2022 AmbaSat Ltd
* https://ambasat.com
*
* Licensed under Creative Commons Attribution-ShareAlike 3.0
*
* Use this application to test the circuitry of your AmbaSat-1 Satellite and Sensor 06 - SI1132
* Once the code is uploaded to your AmbaSat-1 board, view the debug output to confirm readings
*
* ******************************************************************************/

#include <Wire.h>

#include "SparkFunCCS811.h"

#define LED_PIN 9

#define CCS811_ADDR 0x5B //Default I2C Address
//#define CCS811_ADDR 0x5A //Alternate I2C Address

CCS811 mySensor(CCS811_ADDR);

// ==============================================================================
void setup()
{
    Wire.begin();
    // Initialise Serial Communication, Baud rate = 9600
    Serial.begin(9600);

    while (!Serial)
      delay(10);  

    // Turn on the LED during setup
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN, HIGH);

    Serial.println("Checking I2C device...");


    //This begins the CCS811 sensor and prints error status of .beginWithStatus()
    CCS811Core::CCS811_Status_e returnCode = mySensor.beginWithStatus(Wire); //Pass Wire1 into the library
    Serial.print("CCS811 begin exited with: ");
    Serial.println(mySensor.statusString(returnCode));

    // Turn LED off
    digitalWrite(LED_PIN, LOW);  
}

// ==============================================================================
void loop()
{ 
  //Check to see if data is ready with .dataAvailable()
  if (mySensor.dataAvailable())
  {
    //If so, have the sensor read and calculate the results.
    //Get them later
    mySensor.readAlgorithmResults();

    Serial.print("CO2[");
    //Returns calculated CO2 reading
    Serial.print(mySensor.getCO2());
    Serial.print("] tVOC[");
    //Returns calculated TVOC reading
    Serial.print(mySensor.getTVOC());
    Serial.print("] millis[");
    //Simply the time since program start
    Serial.print(millis());
    Serial.print("]");
    Serial.println();
  }
  delay(1000);
}


