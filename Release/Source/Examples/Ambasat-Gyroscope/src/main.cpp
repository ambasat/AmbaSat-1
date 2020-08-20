/*******************************************************************************
* AmbaSat-1 LSM9DS1 9DOF sensor. Accelerometer, Gyroscope and Magnetometer

* 20th August 2020
* Version 1.0
* Filename: main.cpp
*
* Copyright (c) 2020 AmbaSat Ltd
* https://ambasat.com
*
* Licensed under Creative Commons Attribution-ShareAlike 3.0
*
* Use this application to test the circuitry of your AmbaSat-1 Satellite and LSM9DS1 Gyro/Magneto/Acccel)
* Once the code is uploaded to your AmbaSat-1 board, view the debug output to confirm readings
*
* =================================================================================
* Requires the SparkFun LSM9DS1 IMU library 
*
* Based upon original code from:
*
*  Sparkfun: LSM9DS1_Basic_I2C.ino
*  SFE_LSM9DS1 Library Simple Example Code - I2C Interface
*  by Jim Lindblom @ SparkFun Electronics
*  Original Creation Date: April 30, 2015
*  https://github.com/sparkfun/LSM9DS1_Breakout
*
* For more information, see:
* https://learn.sparkfun.com/tutorials/lsm9ds1-breakout-hookup-guide/all
*
* ******************************************************************************/
// The SFE_LSM9DS1 library requires both Wire and SPI be included BEFORE including the 9DS1 library.
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <SparkFunLSM9DS1.h>

//////////////////////////
// LSM9DS1 Library Init //
//////////////////////////
LSM9DS1 imu;

///////////////////////
// Example I2C Setup //
///////////////////////
// SDO_XM and SDO_G are both pulled high, so our addresses are:
 #define LSM9DS1_M	0x1E // Would be 0x1C if SDO_M is LOW
 #define LSM9DS1_AG	0x6B // Would be 0x6A if SDO_AG is LOW

////////////////////////////
// Sketch Output Settings //
////////////////////////////
#define PRINT_CALCULATED
//#define PRINT_RAW
#define PRINT_SPEED 250 // 250 ms between prints

static unsigned long lastPrint = 0; // Keep track of print time

// Earth's magnetic field varies by location. Add or subtract a declination to get a more accurate heading. 
// Calculate yours here: http://www.geomag.bgs.ac.uk/data_service/models_compass/wmm_calc.html

#define DECLINATION -0.62 // Declination (degrees), northallerton, North Yorks 

//Function definitions
void printGyro();
void printAccel();
void printMag();
void printAttitude(float ax, float ay, float az, float mx, float my, float mz);


// ==============================================================================
void setup() 
{
    Serial.begin(9600);
    while (!Serial);

    Wire.begin();

    if (imu.begin() == false) // with no arguments, this uses default addresses (AG:0x6B, M:0x1E) and i2c port (Wire).
    {
        Serial.println("Failed to communicate with LSM9DS1");
        Serial.println("Please check your wiring");
        while (1);
    }
}

// ==============================================================================
void loop()
{
  // Update the sensor values whenever new data is available
  if ( imu.gyroAvailable() )
  {
    // To read from the gyroscope,  first call the
    // readGyro() function. When it exits, it'll update the
    // gx, gy, and gz variables with the most current data.
    imu.readGyro();
  }
  if ( imu.accelAvailable() )
  {
    // To read from the accelerometer, first call the
    // readAccel() function. When it exits, it'll update the
    // ax, ay, and az variables with the most current data.
    imu.readAccel();
  }
  if ( imu.magAvailable() )
  {
    // To read from the magnetometer, first call the
    // readMag() function. When it exits, it'll update the
    // mx, my, and mz variables with the most current data.
    imu.readMag();
  }

  if ((lastPrint + PRINT_SPEED) < millis())
  {
    printGyro();  // Print "G: gx, gy, gz"
    printAccel(); // Print "A: ax, ay, az"
    printMag();   // Print "M: mx, my, mz"

    // Print the heading and orientation
    // Call print attitude. The LSM9DS1's mag x and y axes are opposite to the accelerometer, so my, mx are
    // substituted for each other.
    printAttitude(imu.ax, imu.ay, imu.az, -imu.my, -imu.mx, imu.mz);
    Serial.println();

    lastPrint = millis(); // Update lastPrint time
  }
}

// ==============================================================================
void printGyro()
{
    // Now we can use the gx, gy, and gz variables as we please.
    // Either print them as raw ADC values, or calculated in DPS.
    Serial.print("G: ");

    #ifdef PRINT_CALCULATED
        // If you want to print calculated values, you can use the
        // calcGyro helper function to convert a raw ADC value to
        // DPS. Give the function the value that you want to convert.
        Serial.print(imu.calcGyro(imu.gx), 2);
        Serial.print(", ");
        Serial.print(imu.calcGyro(imu.gy), 2);
        Serial.print(", ");
        Serial.print(imu.calcGyro(imu.gz), 2);
        Serial.println(" deg/s");
    #elif defined PRINT_RAW
        Serial.print(imu.gx);
        Serial.print(", ");
        Serial.print(imu.gy);
        Serial.print(", ");
        Serial.println(imu.gz);
    #endif
}

// ==============================================================================
void printAccel()
{
    // Now we can use the ax, ay, and az variables as we please.
    // Either print them as raw ADC values, or calculated in g's.
    Serial.print("A: ");

    #ifdef PRINT_CALCULATED
        // If you want to print calculated values, you can use the
        // calcAccel helper function to convert a raw ADC value to
        // g's. Give the function the value that you want to convert.
        Serial.print(imu.calcAccel(imu.ax), 2);
        Serial.print(", ");
        Serial.print(imu.calcAccel(imu.ay), 2);
        Serial.print(", ");
        Serial.print(imu.calcAccel(imu.az), 2);
        Serial.println(" g");
    #elif defined PRINT_RAW
        Serial.print(imu.ax);
        Serial.print(", ");
        Serial.print(imu.ay);
        Serial.print(", ");
        Serial.println(imu.az);
    #endif
}

// ==============================================================================
void printMag()
{
    // Now we can use the mx, my, and mz variables as we please.
    // Either print them as raw ADC values, or calculated in Gauss.
    Serial.print("M: ");

    #ifdef PRINT_CALCULATED
        // If you want to print calculated values, you can use the
        // calcMag helper function to convert a raw ADC value to
        // Gauss. Give the function the value that you want to convert.
        Serial.print(imu.calcMag(imu.mx), 2);
        Serial.print(", ");
        Serial.print(imu.calcMag(imu.my), 2);
        Serial.print(", ");
        Serial.print(imu.calcMag(imu.mz), 2);
        Serial.println(" gauss");
    #elif defined PRINT_RAW
        Serial.print(imu.mx);
        Serial.print(", ");
        Serial.print(imu.my);
        Serial.print(", ");
        Serial.println(imu.mz);
    #endif
}

// Calculate pitch, roll, and heading.
// Pitch/roll calculations taken from this app note:
// http://cache.freescale.com/files/sensors/doc/app_note/AN3461.pdf?fpsp=1

// Heading calculations taken from this app note:
// http://www51.honeywell.com/aero/common/documents/myaerospacecatalog-documents/Defense_Brochures-documents/Magnetic__Literature_Application_notes-documents/AN203_Compass_Heading_Using_Magnetometers.pdf

// ==============================================================================
void printAttitude(float ax, float ay, float az, float mx, float my, float mz)
{
    float roll = atan2(ay, az);
    float pitch = atan2(-ax, sqrt(ay * ay + az * az));

    float heading;

    if (my == 0)
        heading = (mx < 0) ? PI : 0;
    else
        heading = atan2(mx, my);

    heading -= DECLINATION * PI / 180;

    if (heading > PI) heading -= (2 * PI);
    else if (heading < -PI) heading += (2 * PI);

    // Convert everything from radians to degrees:
    heading *= 180.0 / PI;
    pitch *= 180.0 / PI;
    roll  *= 180.0 / PI;

    Serial.print("Pitch, Roll: ");
    Serial.print(pitch, 2);
    Serial.print(", ");
    Serial.println(roll, 2);
    Serial.print("Heading: "); Serial.println(heading, 2);
}

