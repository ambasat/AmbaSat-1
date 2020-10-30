/*******************************************************************************
* AmbaSat-1 Sensor 06 - SI1132
* 30th October 2020
* Version 1.01
* Filename: main.cpp
*
* Copyright (c) 2020 AmbaSat Ltd
* https://ambasat.com
*
* Licensed under Creative Commons Attribution-ShareAlike 3.0
*
* Use this application to test the circuitry of your AmbaSat-1 Satellite and Sensor 06 - SI1132
* Once the code is uploaded to your AmbaSat-1 board, view the debug output to confirm readings
*
* Based on original code from FaBoPlatform - FaBoUV-Si1132-Library
* ******************************************************************************/


#include <FaBoUV_Si1132.h>

FaBoUV faboUV;

// ==============================================================================
void setup()
{
    Wire.begin();
    // Initialise Serial Communication, Baud rate = 9600
    Serial.begin(9600);
   
  Serial.println("Checking I2C device...");

  while(!faboUV.begin()){
    Serial.println("Si1132 Not Found");
    delay(5000);
  }
  
  Serial.println("Found Si1132");
  Serial.println("");
}

// ==============================================================================
void loop()
{ 
  int uv_rawdata = faboUV.readUV();
  int uv_index = uv_rawdata / 100;
  int ir = faboUV.readIR();
  int visible = faboUV.readVisible();

  Serial.print("RAW:");
  Serial.println(uv_rawdata);

  Serial.print("UV_INDEX:");
  Serial.println(uv_index);

  Serial.print("IR:");
  Serial.print(ir);
  Serial.println(" lux");

  Serial.print("Visible:");
  Serial.print(visible);
  Serial.println(" lux");

  Serial.println("");
  
  delay(1000);
}


