/*******************************************************************************
* AmbaSat-1 LoRa
* 17th June 2020
* Version 1.0
* Filename: main.cpp
*
* Copyright (c) 2020 AmbaSat Ltd
* https://ambasat.com
*
* Licensed under Creative Commons Attribution-ShareAlike 3.0
*
* Use this application to test the LoRa RFM95 functionality of your AmbaSat-1 Satellite
* Once the code is uploaded and run, the console should display a message 
* similar to 'LoRa Radio Initialised and working' 
*
* This code makes use of the RadioHead Packet Libary by M.McMauley
* http://www.airspayce.com/mikem/arduino/RadioHead/
*
* Install the library to compile and run this example
*
* ******************************************************************************/

#include <Arduino.h>
#include <RH_RF95.h>

#define RFM95_CS  		10
#define RFM95_INT 		2

RH_RF95 radio(RFM95_CS, RFM95_INT);

// ==============================================================================
void setup() {
    Serial.begin(9600);      

    while (!radio.init())
    {
        Serial.println("LoRa Radio Initialisation failed");
        while (1);
    }

    RH_RF95::ModemConfig modem_config = {
      0x78, 
      0xc4, 
      0x0c  
    };

    radio.setModemRegisters(&modem_config);	

	Serial.println("LoRa Radio Initialised and working");	
}

// ==============================================================================
void loop() 
{	                    
} 
