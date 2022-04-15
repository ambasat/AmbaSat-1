/*******************************************************************************
* AmbaSat-1 Sensor 06 - SI1132
* 15th April 2022
* Version 1.1
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
#include <AmbaSatSI1132.h>

#define LED_PIN 9
AmbaSatSI1132 *ambasatSI1132;

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
  digitalWrite(LED_PIN, HIGH);

  Serial.println("Checking I2C device...");

  ambasatSI1132 = new AmbaSatSI1132();

  ambasatSI1132->setup();
  
  // Turn LED off
  digitalWrite(LED_PIN, LOW);  
}

// ==============================================================================
void loop()
{   
  ambasatSI1132->readSensor();

  Serial.print("UV: ");
  Serial.println(ambasatSI1132->uv/100.0);    

  Serial.print("VIS: ");
  Serial.println(ambasatSI1132->vis);    

  Serial.print("IR: ");

  Serial.println(ambasatSI1132->ir);    
  
  Serial.println(" ");
  delay(1000);
}


