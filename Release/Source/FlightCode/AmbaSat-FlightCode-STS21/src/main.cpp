/*******************************************************************************
* AmbaSat-1 
* Filename: main.cpp
* AmbaSat-1 Flight Code for Sensor 02 - STS21: Temperature
* 22nd February 2021
* Authors: Martin Platt, James Vonteb 
* with contributions by Michael F. Kamprath, https://github.com/michaelkamprath
*
* Copyright (c) 2021 AmbaSat Ltd
* https://ambasat.com
*
* AmbaSat opensource code available on gitHub at:
* https://github.com/ambasat
*
* To use this code, set NWKSKEY, APPSKEY & DEVADDR values as per your Dashboard
* See the HowTo: https://ambasat.com/howto/kit-2/#/../unique-ids
*
* For ISM band configuration: See lmic/config.h eg. #define CFG_us915 1
* licensed under Creative Commons Attribution-ShareAlike 3.0
* ******************************************************************************/

#include "main.h"
#include "AmbaSatSTS21.h"
#include "AmbaSatLMIC.h"
#include "AmbaSatLSM9DS1.h"

// TTN *****************************  
// The Network Session Key / DO NOT SHARE
static const PROGMEM u1_t NWKSKEY[16] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

// LoRaWAN AppSKey, application session key / DO NOT SHARE
static const u1_t PROGMEM APPSKEY[16] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

// LoRaWAN end-device address (DevAddr) / DO NOT SHARE
static const u4_t DEVADDR = 0x00000000 ;
/********************************/

int sleepcycles = 130; // 130 X 8 seconds = ~17 mins sleep

// AmbaSat Library objects (see: https://platformio.org/lib/search?query=ambasat)
AmbaSatSTS21 *ambasatSTS21;
AmbaSatLMIC *ambasatLMIC;
AmbaSatLSM9DS1 *ambasatLSM9DS1;

// ============================================================================

void setup()
{
    Serial.begin(9600);

    while (!Serial)
        delay(10);    

    // Turn the LED ON 
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(LED_PIN, HIGH);

    // Create the LMIC object
    ambasatLMIC = new AmbaSatLMIC();

    // Set static session parameters. Instead of dynamically establishing a session
    // by joining the network, precomputed session parameters are provided.
    uint8_t appskey[sizeof(APPSKEY)];
    uint8_t nwkskey[sizeof(NWKSKEY)];
    memcpy_P(appskey, APPSKEY, sizeof(APPSKEY));
    memcpy_P(nwkskey, NWKSKEY, sizeof(NWKSKEY));
    
    // Setup LMIC
    ambasatLMIC->setup(0x13, DEVADDR, appskey, nwkskey);

    // Turn the LED OFF
    digitalWrite(LED_PIN, LOW);

    // Create the sensor object
    ambasatSTS21 = new AmbaSatSTS21();

    // Create the IMU object
    ambasatLSM9DS1 = new AmbaSatLSM9DS1();

    // Initialise IMU
    if (ambasatLSM9DS1->begin(LSM9DS1_AG, LSM9DS1_M) == false) 
    {
        PRINTLN_DEBUG(F("Failed to communicate with the AmbaSat-1 LSM9DS1 IMU"));
        while (1);
    }

    PRINTLN_DEBUG("Setup complete");    
}

// ============================================================================

void loop()
{
    float temperature;
    uint16_t voltage;
    LoraMessage message;

    voltage = readVcc();

    // read SHT31
    if (ambasatSTS21->getSensorReading(&temperature)  == false) 
    {
        PRINTLN_DEBUG(F("Failed to read sensor data"));
    }  
      
    PRINT_DEBUG(F("TEMP: "));
    PRINT_DEBUG(temperature);   
    PRINT_DEBUG(F(", VOLT: "));
    PRINTLN_DEBUG(voltage);   

    uint8_t voltsEncoded = (uint8_t) (voltage / 100);   // eg. 2840 millivolts becomes 28 and in the Dashboard decoded to 2.8 volts

    // read LSM9DS1
    ambasatLSM9DS1->readGyro();
    ambasatLSM9DS1->readAccel();
    ambasatLSM9DS1->readMag();

    PRINT_DEBUG(F("GYRO: "));
    PRINT_DEBUG(ambasatLSM9DS1->gx);
    PRINT_DEBUG(F(", "));
    PRINT_DEBUG(ambasatLSM9DS1->gy);
    PRINT_DEBUG(F(", "));
    PRINTLN_DEBUG(ambasatLSM9DS1->gz);    

    PRINT_DEBUG(F("ACCEL: "));
    PRINT_DEBUG(ambasatLSM9DS1->ax);
    PRINT_DEBUG(F(", "));
    PRINT_DEBUG(ambasatLSM9DS1->ay);
    PRINT_DEBUG(F(", "));
    PRINTLN_DEBUG(ambasatLSM9DS1->az);      

    PRINT_DEBUG(F("MAG: "));
    PRINT_DEBUG(ambasatLSM9DS1->mx);
    PRINT_DEBUG(F(", "));
    PRINT_DEBUG(ambasatLSM9DS1->my);
    PRINT_DEBUG(F(", "));
    PRINTLN_DEBUG(ambasatLSM9DS1->mz);  
 

   // ***********************************************
   // Prepare message payload. NOTE: The order of the
   // payload data is important for the TTN decoder. 
   // Do not change the order
   // **********************************************

    // Temperature uses a 16bit two's complement with two decimals, so the range is -327.68 to +327.67 degrees
    message.addTemperature(temperature); 
    
    message.addUint8(voltsEncoded);

    message.addUint16(ambasatLSM9DS1->gx); 
    message.addUint16(ambasatLSM9DS1->gy); 
    message.addUint16(ambasatLSM9DS1->gz); 
        
    message.addUint16(ambasatLSM9DS1->ax); 
    message.addUint16(ambasatLSM9DS1->ay); 
    message.addUint16(ambasatLSM9DS1->az); 

    message.addUint16(ambasatLSM9DS1->mx); 
    message.addUint16(ambasatLSM9DS1->my); 
    message.addUint16(ambasatLSM9DS1->mz); 

    // send payload 
    ambasatLMIC->sendSensorPayload(SENSOR_01_SHT31, message);  

    // sleep 8 seconds * sleepcycles
    for (int i=0; i < sleepcycles; i++)
    {
        LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);    
    }     
}

// ============================================================================

uint16_t readVcc()
{
    // Read 1.1V reference against AVcc
    // set the reference to Vcc and the measurement to the internal 1.1V reference
    #if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
        ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
    #elif defined (__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
        ADMUX = _BV(MUX5) | _BV(MUX0);
    #elif defined (__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
        ADMUX = _BV(MUX3) | _BV(MUX2);
    #else
        ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
    #endif

    delay(2); // Wait for Vref to settle
    ADCSRA |= _BV(ADSC); // Start conversion
    while (bit_is_set(ADCSRA,ADSC)); // measuring

    uint8_t low  = ADCL; // must read ADCL first - it then locks ADCH
    uint8_t high = ADCH; // unlocks both

    long result = (high<<8) | low;

    result = 1125300L / result;
    return result; // Vcc in millivolts
}