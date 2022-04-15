/*******************************************************************************
* AmbaSat-1 Sensor 03 - BME680
* 15th April 2022
* Version 1.1
* Filename: main.cpp
*
* Copyright (c) 2022 AmbaSat Ltd
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
* ******************************************************************************/

#include <AmbasatBME680.h>

AmbasatBME680 *ambasatBME680;

// ============================================================================

void setup()
{
	Serial.begin(9600);

	ambasatBME680 = new AmbasatBME680();
	while(!ambasatBME680->begin())
	{
		Serial.print(F("-  Unable to find BME680. Trying again in 5 seconds.\n"));
		delay(5000);
	}
	while(!ambasatBME680->set_sensor(BME680_OS_2X,BME680_OS_4X,BME680_OS_8X,BME680_FILTER_SIZE_3,300,100))
	{
		Serial.print(F("-  Unable to configure BME680. Trying again in 5 seconds.\n")); 
		delay(5000);
	}
	delay(2000);
	Serial.println("Setup complete");    
}

// ============================================================================


void loop()
{
	if (E_SUCCESS ==  ambasatBME680->read_data())
	{
		Serial.print("Temperature = ");
		Serial.print(ambasatBME680->field_data.temperature /100.0);
		Serial.println(" *C");

		Serial.print("Pressure = ");
		Serial.print(ambasatBME680->field_data.pressure / 100.0);
		Serial.println(" hPa");

		Serial.print("Humidity = ");
		Serial.print(ambasatBME680->field_data.humidity /1000.0);
		Serial.println(" %");

		Serial.print("Gas = ");
		Serial.print(ambasatBME680->field_data.gas_resistance / 1000.0);
		Serial.println(" KOhms");

		Serial.println();	
		delay(3000);  
	}
}
