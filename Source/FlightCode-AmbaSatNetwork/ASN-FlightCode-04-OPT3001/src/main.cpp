/*******************************************************************************
* AmbaSat-1 
* Filename: main.cpp
* AmbaSat Network (ASN) Flight Code for Sensor 01 - SHT31: Temperature & Humidity
* 6th December 2023
*
* Copyright (c) 2023 AmbaSat Ltd
* https://ambasat.com
*
* licensed under Creative Commons Attribution-ShareAlike 3.0
* ******************************************************************************/

#include "main.h"
#include <Wire.h>
#include <ClosedCube_OPT3001.h>
#include "AmbaSatLSM9DS1.h"
#include <RH_RF95.h>

// The AmbaSat Network (ASN) *****************************  
// Network Session Key / DO NOT SHARE
static const PROGMEM uint8_t NWKSKEY[16] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

// LoRaWAN AppSKey, application session key / DO NOT SHARE
static const uint8_t PROGMEM APPSKEY[16] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

// AmbaSat Network end-device address (DevAddr) / DO NOT SHARE
static const uint32_t DEVADDR = 0x00000000 ;
/********************************/

int sleepcycles = 8; // eg. 8 x 8 secs = 64 secs sleep. 130 X 8 secs = ~17 mins sleep

// ============================================================================
void(* resetFunc) (void) = 0;  //declare reset function at address 0
void configureSensor() ;
void printError(String text, OPT3001_ErrorCode error);
void printResult(String text, OPT3001 result); 

ClosedCube_OPT3001 opt3001;
#define OPT3001_ADDRESS 0x44  // OPT3001 I2C address is 0x45(69)

// AmbaSat Library objects (see: https://platformio.org/lib/search?query=ambasat)
AmbaSatLSM9DS1 *ambasatLSM9DS1;

// RadioHead Library object
RH_RF95 radio(RFM95_CS, RFM95_INT);


// -----------------------------------------------------------------------------
// RFM95 setup
// -----------------------------------------------------------------------------
void radioSetup()
{
    pinMode(RFM95_RST, OUTPUT);
    digitalWrite(RFM95_RST, HIGH);

    // manual reset
    digitalWrite(RFM95_RST, LOW);
    delay(10);
    digitalWrite(RFM95_RST, HIGH);
    delay(10);

    while (!radio.init())
    {
        Serial.println("LoRa radio init failed");
        while (1);
    }

    RH_RF95::ModemConfig modem_config = {
      0x78, // Reg 0x1D: BW=125kHz, Coding=4/8, Header=explicit
      0xc4, // Reg 0x1E: Spread=4096chips/symbol, CRC=enable
      0x0c  // Reg 0x26: LowDataRate=On, Agc=On
    };
    
    radio.setModemRegisters(&modem_config);

    Serial.println("LoRa radio init OK");

    if (!radio.setFrequency(RF95_FREQ)) 
    {
        Serial.println("setFrequency failed");
    }

    radio.setTxPower(23, false);
    radio.sleep();
}

// ============================================================================

void setup()
{
    Serial.begin(9600);

    while (!Serial)
        delay(10);    

    // Turn the LED ON 
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);

    // Create the sensor object

    opt3001.begin(OPT3001_ADDRESS);

    configureSensor();

    printResult("High-Limit", opt3001.readHighLimit());
    printResult("Low-Limit", opt3001.readLowLimit());
    Serial.println("----");          

    // Create the IMU object
    ambasatLSM9DS1 = new AmbaSatLSM9DS1();

    // Initialise IMU
    if (ambasatLSM9DS1->begin(LSM9DS1_AG, LSM9DS1_M) == false) 
    {
        PRINTLN_DEBUG(F("Failed to communicate with the AmbaSat-1 LSM9DS1 IMU"));
        while (1);
    }

    radioSetup();    

    PRINTLN_DEBUG("Setup complete");    
    // Turn the LED OFF
    digitalWrite(LED_PIN, LOW);    
}

// ============================================================================

void loop()
{
    uint16_t voltage;

    voltage = readVcc();

    OPT3001 result = opt3001.readResult();

    uint8_t voltsEncoded = (uint8_t) (voltage / 100);   // eg. 2840 millivolts becomes 28 and in the Dashboard decoded to 2.8 volts
 
    PRINT_DEBUG(F("LUX: "));
    PRINT_DEBUG(result.lux);   
    PRINT_DEBUG(F(", VOLT: "));
    PRINTLN_DEBUG(voltsEncoded);   

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
 

   /*
   // ***********************************************
   // GYRO DATA TO BE PROCESSED
    message.addUint16(ambasatLSM9DS1->gx); 
    message.addUint16(ambasatLSM9DS1->gy); 
    message.addUint16(ambasatLSM9DS1->gz); 
        
    message.addUint16(ambasatLSM9DS1->ax); 
    message.addUint16(ambasatLSM9DS1->ay); 
    message.addUint16(ambasatLSM9DS1->az); 

    message.addUint16(ambasatLSM9DS1->mx); 
    message.addUint16(ambasatLSM9DS1->my); 
    message.addUint16(ambasatLSM9DS1->mz); 
   // **********************************************
   */

    packetData.deviceId = DEVADDR;
    packetData.lux = result.lux;
    packetData.voltage = voltsEncoded;

    int radioBufLen = sizeof(packetData);

    uint8_t y = checksum( (unsigned char*)(&packetData), radioBufLen - 1);
    packetData.checksum = y;

    Serial.println("Checksum:" + String(packetData.checksum));
    Serial.print("Sending packet: ");
    PrintHex8( (uint8_t*)&packetData, radioBufLen);

    // Send it
    radio.setHeaderTo(GATEWAY_ID);
    radio.setHeaderFrom(SENSOR_ID);

    radio.send((const uint8_t*)(&packetData), radioBufLen);
        
    Serial.println("Packet sent, sleeping");
    radio.waitPacketSent(5000);

    radio.sleep();


    // sleep 8 seconds * sleepcycles
    for (int i=0; i < sleepcycles; i++)
    {
        LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);    
    }     

    resetFunc(); 
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