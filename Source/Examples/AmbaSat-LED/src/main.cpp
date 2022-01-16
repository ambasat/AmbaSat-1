/*******************************************************************************
* AmbaSat-1 LED Flash
* 11th May 2020
* Version 1.0
* Filename: main.cpp
*
* Copyright (c) 2022 AmbaSat Ltd
* https://ambasat.com
*
* Licensed under Creative Commons Attribution-ShareAlike 3.0
*
* Use this application to test the circuitry of your AmbaSat-1 Satellite
* Once the code is uploaded, the onboard LED should flash on and off every second 
*
* ******************************************************************************/

#include <Arduino.h>

#define LED_PIN 9

// ==============================================================================
void setup() {
    Serial.begin(9600);        // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_PIN, OUTPUT);
}

// ==============================================================================
void loop() 
{
	
  	digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  	Serial.println ("On");  
  	delay(500);                       
  	digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
  	Serial.println ("Off");
  	delay(500);                       
} 
