/*******************************************************************************
* AmbaSat-1 Release
* Filename: main.cpp
* LoRaWAN encrypted data submission to TTN
* 16th January 2022
* Version 1.04
* Filename: main.cpp
* Authors: Martin Platt 
*
* Copyright (c) 2022 AmbaSat Ltd
* https://ambasat.com
*
* licensed under Creative Commons Attribution-ShareAlike 3.0
* ******************************************************************************
*
* This example will post AmbaSat Sensor 03 data (BME680)  to the AmbaSat Dashboard
* using frequency and encryption settings matching those of the The Things Network.
*
* This example uses ABP (Activation-by-personalisation), where a DevAddr and
* Session keys are preconfigured (unlike OTAA, where a DevEUI and
* application key is configured, while the DevAddr and session keys are
* assigned/generated in the over-the-air-activation procedure).
**
* Note: LoRaWAN per sub-band duty-cycle limitation is enforced (1% in
* g1, 0.1% in g2), but not the TTN fair usage policy.

* To use this code, first register your application and device with
* the things network, to set or generate an AppEUI, DevEUI and AppKey.
* Multiple devices can use the same AppEUI, but each device has its own
* DevEUI and AppKey.
*
* Please define the radio type correctly in config.h.
*
* Supporting code/libraries:
*
* Based on code originally created by
* Copyright (c) 2015 Thomas Telkamp and Matthijs Kooijman
*
* Permission is hereby granted, free of charge, to anyone
* obtaining a copy of this document and accompanying files,
* to do whatever they want with them without any restriction,
* including, but not limited to, copying, modification and redistribution.
* NO WARRANTY OF ANY KIND IS PROVIDED.
*
* LowPower Library
* Author: Lim Phang Moh
* Company: Rocket Scream Electronics
* Website: www.rocketscream.com
* This is a lightweight low power library for Arduino.
* The LowPower Library is licensed under Creative Commons Attribution-ShareAlike 3.0
*
* Welcome to AmbaSat Low Earth Orbit 
*
*******************************************************************************/
#include "main.h"

#include "Adafruit_BME680.h"

#define SEALEVELPRESSURE_HPA (1013.25)
#define BME680_DEFAULT_ADDRESS_AMBASAT  (0x76)     ///< AmbaSat BME680 address

Adafruit_BME680 bme; // I2C


// initial job
static void initfunc (osjob_t* j)
{
    // reset MAC state
    LMIC_reset();

    // start joining
    LMIC_startJoining();
    // init done - onEvent() callback will be invoked...
}

// -----------------------------------------------------------------------------
// readVcc
// -----------------------------------------------------------------------------
long readVcc()
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

// -----------------------------------------------------------------------------
// readSensorBME680
// -----------------------------------------------------------------------------
void readSensorBME680()
{
    // Tell BME680 to begin measurement.
    unsigned long endTime = bme.beginReading();
    
    if (endTime == 0) 
    {
        #ifdef DEBUG
        Serial.println(F("Failed to begin reading :("));
        #endif
        return;
    }

    #ifdef DEBUG
    Serial.print(F("Reading started at "));
    Serial.print(millis());
    Serial.print(F(" and will finish at "));
    Serial.println(endTime);

    Serial.println(F("You can do other work during BME680 measurement."));
    #endif

    delay(50); // This represents parallel work.

    // There's no need to delay() until millis() >= endTime: bme.endReading()
    // takes care of that. It's okay for parallel work to take longer than
    // BME680's measurement time.

    // Obtain measurement results from BME680. Note that this operation isn't
    // instantaneous even if milli() >= endTime due to I2C/SPI latency.
    if (!bme.endReading()) 
    {
     //   Serial.println(F("Failed to complete reading :("));
        return;
    }

    #ifdef DEBUG
    Serial.print(F("Reading completed at "));
    Serial.println(millis());

    Serial.print(F("Temperature = "));
    Serial.print(bme.temperature);
    Serial.println(F(" *C"));

    Serial.print(F("Pressure = "));
    Serial.print(bme.pressure / 100.0);
    Serial.println(F(" hPa"));

    Serial.print(F("Humidity = "));
    Serial.print(bme.humidity);
    Serial.println(F(" %"));

    Serial.print(F("Gas = "));
    Serial.print(bme.gas_resistance / 1000.0);
    Serial.println(F(" KOhms"));

    Serial.print(F("Approx. Altitude = "));
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(F(" m"));

    Serial.println();
    #endif

    packetData.temperature = bme.temperature;
    packetData.humidity = bme.humidity;
    packetData.altitude = bme.readAltitude(SEALEVELPRESSURE_HPA); // 5 meters
    packetData.gas = bme.gas_resistance / 1000.0; // 182 kOhms
    packetData.pressure = bme.pressure / 100.0; // 1013 hPa
}

// =========================================================================================================================================
// onEvent
// =========================================================================================================================================
void onEvent (ev_t ev)
{
//    int i, j;

    switch (ev)
    {        
        case EV_SCAN_TIMEOUT:
           #ifdef DEBUG
           Serial.println(F("EV_SCAN_TIMEOUT")); 
           #endif
        break;
        case EV_BEACON_FOUND:
            #ifdef DEBUG    
            Serial.println(F("EV_BEACON_FOUND")); 
            #endif
        break;
        case EV_BEACON_MISSED:
            #ifdef DEBUG    
            Serial.println(F("EV_BEACON_MISSED")); 
            #endif
        break;
        case EV_BEACON_TRACKED:
            #ifdef DEBUG    
            Serial.println(F("EV_BEACON_TRACKED")); 
            #endif
        break;
        case EV_JOINING:
            #ifdef DEBUG    
            Serial.println(F("EV_JOINING")); 
            #endif
        break;
     
        case EV_JOINED:
            #ifdef DEBUG    
            Serial.println(F("EV_JOINED")); 
            #endif
            // Disable link check validation (automatically enabled
            // during join, but not supported by TTN at this time).
            LMIC_setLinkCheckMode(0);
            
            // digitalWrite(LedPin, LOW);
            
            // after Joining a job with the values will be sent.
            joined = true;
        break;
        case EV_RFU1:
        #ifdef DEBUG    
        Serial.println(F("EV_RFU1")); 
        #endif
        break;
        case EV_JOIN_FAILED:
        #ifdef DEBUG    
        Serial.println(F("EV_JOIN_FAILED")); 
        #endif
        break;
        case EV_REJOIN_FAILED:
        #ifdef DEBUG    
        Serial.println(F("EV_REJOIN_FAILED")); 
        #endif
            // Re-init
            os_setCallback(&initjob, initfunc);
        break;
        case EV_TXCOMPLETE:
            sleeping = true;

            if (LMIC.dataLen)
            {
                // data received in rx slot after tx
                // if any data received, a LED will blink
                // this number of times, with a maximum of 10
                #ifdef DEBUG
                Serial.print(F("Data Received: "));
                Serial.println(LMIC.frame[LMIC.dataBeg], HEX);
          
          
                i=(LMIC.frame[LMIC.dataBeg]);
                // i (0..255) can be used as data for any other application
                // like controlling a relay, showing a display message etc.
                if (i>10)
                {
                    i=10;     // maximum number of BLINKs
                }

                for(j = 0; j < i ; j++)
                {
                    digitalWrite(LedPin, HIGH);
                    delay(200);
                    digitalWrite(LedPin, LOW);
                    delay(400);
                }
                #endif
            }

            #ifdef DEBUG    
            Serial.println(F("EV_TXCOMPLETE (includes waiting for RX windows)"));
            #endif

            delay(50);  // delay to complete Serial Output before Sleeping

            // Schedule next transmission
            // next transmission will take place after next wake-up cycle in main loop
        break;
        case EV_LOST_TSYNC:
          #ifdef DEBUG  
          Serial.println(F("EV_LOST_TSYNC")); 
          #endif
        break;
        case EV_RESET:
          #ifdef DEBUG  
          Serial.println(F("EV_RESET")); 
          #endif
        break;
        case EV_RXCOMPLETE:
            // data received in ping slot
          #ifdef DEBUG  
          Serial.println(F("EV_RXCOMPLETE")); 
          #endif
        break;
        case EV_LINK_DEAD:
          #ifdef DEBUG  
          Serial.println(F("EV_LINK_DEAD")); 
          #endif
        break;
        case EV_LINK_ALIVE:
          #ifdef DEBUG  
          Serial.println(F("EV_LINK_ALIVE")); 
          #endif
        break;
        default:
          #ifdef DEBUG  
          Serial.println(F("Unknown event")); 
          #endif
        break;
    }
}

// =========================================================================================================================================
// do_send
// =========================================================================================================================================
void do_send(osjob_t* j)
{
    LoraMessage message;

    #ifdef DEBUG
        Serial.println("temperature:" + String(packetData.temperature));
        Serial.println("humidity:" + String(packetData.humidity));
        Serial.println("Voltage:" + String(packetData.voltage));
        Serial.println("Sensor Type:" + String(packetData.sensorType));
    #endif

    // !!! IMPORTANT - do not change the order of these as the AmbaSat TTN payload decoder expects this order !!!
    message.addTemperature(packetData.temperature); // Temperature uses a 16bit two's complement with two decimals, so the range is -327.68 to +327.67 degrees
    message.addHumidity(packetData.humidity);
    message.addUint16(packetData.voltage);
    message.addUint8(packetData.sensorType);
    message.addUint16(packetData.pressure);
    message.addUint16(packetData.gas);
    message.addUint32(packetData.altitude);

    // Check that there is not a current TX/RX job running
    if (LMIC.opmode & OP_TXRXPEND)
    {
        #ifdef DEBUG
        Serial.println(F("Current OP_TXRXPEND is running so not sending"));
        #endif
    }
    else
    {
        // Prepare upstream data transmission at the next possible time.

        // The first parameter in the below function call is the port number
        // AmbaSat uses the port number to specify the type of sensor

        LMIC_setTxData2(SENSOR_03_BME680, message.getBytes(), message.getLength(), 0);
      //  Serial.println(F("P/L sent"));
    }
}

// =========================================================================================================================================
// setup
// =========================================================================================================================================
void setup()
{
    #ifdef DEBUG
    Serial.begin(SERIAL_BAUD);
    delay(250);

    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    digitalWrite(LED_PIN, HIGH);
    delay(25);
    digitalWrite(LED_PIN, LOW);
    #endif

    packetData.sensorType = sensorType;

    if (!bme.begin(BME680_DEFAULT_ADDRESS_AMBASAT)) 
    {
        #ifdef DEBUG
        Serial.println(F("BME680 not found"));
        #endif

        while (1);
    }

    // Set up oversampling and filter initialization
    bme.setTemperatureOversampling(BME680_OS_8X);
    bme.setHumidityOversampling(BME680_OS_2X);
    bme.setPressureOversampling(BME680_OS_4X);
    bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
    bme.setGasHeater(320, 150); // 320*C for 150 ms    

    // LMIC init
    os_init();
    // Reset the MAC state. Session and pending data transfers will be discarded.
    LMIC_reset();

    // Set static session parameters. Instead of dynamically establishing a session
    // by joining the network, precomputed session parameters are be provided.
    uint8_t appskey[sizeof(APPSKEY)];
    uint8_t nwkskey[sizeof(NWKSKEY)];
    memcpy_P(appskey, APPSKEY, sizeof(APPSKEY));
    memcpy_P(nwkskey, NWKSKEY, sizeof(NWKSKEY));
    LMIC_setSession (0x1, DEVADDR, nwkskey, appskey);

    #if defined(CFG_eu868)
        // Set up the channels used by the Things Network, which corresponds
        // to the defaults of most gateways. Without this, only three base
        // channels from the LoRaWAN specification are used, which certainly
        // works, so it is good for debugging, but can overload those
        // frequencies, so be sure to configure the full frequency range of
        // your network here (unless your network autoconfigures them).
        // Setting up channels should happen after LMIC_setSession, as that
        // configures the minimal channel set.
        // NA-US channels 0-71 are configured automatically
        LMIC_setupChannel(0, 868100000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
        LMIC_setupChannel(1, 868300000, DR_RANGE_MAP(DR_SF12, DR_SF7B), BAND_CENTI);      // g-band
        LMIC_setupChannel(2, 868500000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
        LMIC_setupChannel(3, 867100000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
        LMIC_setupChannel(4, 867300000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
        LMIC_setupChannel(5, 867500000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
        LMIC_setupChannel(6, 867700000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
        LMIC_setupChannel(7, 867900000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
        LMIC_setupChannel(8, 868800000, DR_RANGE_MAP(DR_FSK,  DR_FSK),  BAND_MILLI);      // g2-band
        // TTN defines an additional channel at 869.525Mhz using SF9 for class B
        // devices' ping slots. LMIC does not have an easy way to define set this
        // frequency and support for class B is spotty and untested, so this
        // frequency is not configured here.
    #elif defined(CFG_us915)
        // NA-US channels 0-71 are configured automatically
        // but only one group of 8 should (a subband) should be active
        // TTN recommends the second sub band, 1 in a zero based count.
        // https://github.com/TheThingsNetwork/gateway-conf/blob/master/US-global_conf.json

        LMIC_setupChannel(0, 923200000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
        LMIC_setupChannel(1, 923400000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
        LMIC_setupChannel(2, 923600000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
        LMIC_setupChannel(3, 923800000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
        LMIC_setupChannel(4, 924000000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
        LMIC_setupChannel(5, 924200000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
        LMIC_setupChannel(6, 924400000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
        LMIC_setupChannel(7, 924600000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
        LMIC_setupChannel(8, 924800000, DR_RANGE_MAP(DR_FSK,  DR_FSK),  BAND_MILLI);      // g2-band

        LMIC_selectSubBand(1);

    #endif

    // Disable link check validation
    LMIC_setLinkCheckMode(0);

    // TTN uses SF9 for its RX2 window.
    LMIC.dn2Dr = DR_SF9;

    // Set data rate and transmit power for uplink (note: txpow seems to be ignored by the library)
    // LMIC_setDrTxpow(DR_SF12, 14);
    LMIC_setDrTxpow(DR_SF7, 14);
}

// =========================================================================================================================================
//  loop
// =========================================================================================================================================
void loop()
{
    readSensorBME680();

    packetData.voltage = readVcc();

    do_send(&sendjob);    // send sensor payload

    while(sleeping == false)
    {
        os_runloop_once();
    }

    sleeping = false;

    for (int i=0; i < sleepcycles; i++)
    {
      LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);    //sleep 8 seconds * sleepcycles
    }
}
