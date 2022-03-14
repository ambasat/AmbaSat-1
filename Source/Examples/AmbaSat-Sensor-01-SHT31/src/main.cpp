/*******************************************************************************
* AmbaSat-1 Sensor 01 - SHT30-D
* 2nd February 2020
* Version 1.0
* Filename: main.cpp
*
* Copyright (c) 2022 AmbaSat Ltd
* https://ambasat.com
*
* Licensed under Creative Commons Attribution-ShareAlike 3.0
*
* Use this application to test the circuitry of your AmbaSat-1 Satellite and Sensor 01 - SHT30
* Once the code is uploaded to your AmbaSat-1 board, view the debug output to confirm readings
*
* Based on code from Adafruit
* ******************************************************************************/
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include "Adafruit_SHT31.h"

#define LED_PIN 9

bool enableHeater = false;
uint8_t loopCnt = 0;

Adafruit_SHT31 sht31 = Adafruit_SHT31();

// ==============================================================================

void setup() {
  Serial.begin(9600);

  while (!Serial)
    delay(10);     

    // Turn on the LED during setup
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN, HIGH);

  Serial.println("SHT31 test");

  if (! sht31.begin(0x44)) 
  {  
      Serial.println("Couldn't find SHT31");
      while (1) delay(1);
  }

  Serial.print("Heater Enabled State: ");

  if (sht31.isHeaterEnabled())
    Serial.println("ENABLED");
  else
    Serial.println("DISABLED");

    // Turn LED off
    digitalWrite(LED_PIN, LOW);    
}

// ==============================================================================

void loop() {
  float t = sht31.readTemperature();
  float h = sht31.readHumidity();

  if (! isnan(t)) 
  {  
    Serial.print("Temp *C = "); Serial.print(t); Serial.print("\t\t");
  } else { 
    Serial.println("Failed to read temperature");
  }
  
  if (! isnan(h)) 
  {  
    Serial.print("Hum. % = "); Serial.println(h);
  } else { 
    Serial.println("Failed to read humidity");
  }

  delay(1000);

  // Toggle heater enabled state every 30 seconds
  // An ~3.0 degC temperature increase can be noted when heater is enabled
  if (++loopCnt == 30) 
  {
    enableHeater = !enableHeater;
    sht31.heater(enableHeater);
    Serial.print("Heater Enabled State: ");
  
    if (sht31.isHeaterEnabled())
      Serial.println("ENABLED");
    else
      Serial.println("DISABLED");

    loopCnt = 0;
  }
}