/*******************************************************************************
* AmbaSat-1 TTN
* 17th January 2021
* Version 1.0
* Filename: main.cpp
*
* Copyright (c) 2020 AmbaSat Ltd
* https://ambasat.com
*
* This application will submit test data to The Things Network (TTN)
* Data is routed by TTN to the AmbaSat Dashboard
* You MUST set your unique AmbaSat-1 KEYS & DEVICE ID in main.h
*
* Licensed under Creative Commons Attribution-ShareAlike 3.0
*
* This example will send Temperature, humidity & battery information
* using frequency and encryption settings matching those of
* the The Things Network.
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
* AmbaSat-1 Low Earth Orbit Space Satellite
* Copyright (c) 2020 AmbaSat Ltd
* https://ambasat.com
*
* NOTE. You MUST set your unique AmbaSat-1 KEYS & DEVICE ID in main.h
*
*******************************************************************************/
#include "main.h"


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

// =========================================================================================================================================
// onEvent
// =========================================================================================================================================
void onEvent (ev_t ev)
{
    int i, j;

    switch (ev)
    {
        case EV_SCAN_TIMEOUT:
            Serial.println(F("EV_SCAN_TIMEOUT"));
        break;
        case EV_BEACON_FOUND:
            Serial.println(F("EV_BEACON_FOUND"));
        break;
        case EV_BEACON_MISSED:
            Serial.println(F("EV_BEACON_MISSED"));
        break;
        case EV_BEACON_TRACKED:
            Serial.println(F("EV_BEACON_TRACKED"));
        break;
        case EV_JOINING:
            Serial.println(F("EV_JOINING"));
        break;
        case EV_JOINED:
            Serial.println(F("EV_JOINED"));
            // Disable link check validation (automatically enabled
            // during join, but not supported by TTN at this time).
            LMIC_setLinkCheckMode(0);
            digitalWrite(LedPin, LOW);
            // after Joining a job with the values will be sent.
            joined = true;
        break;
        case EV_RFU1:
            Serial.println(F("EV_RFU1"));
        break;
        case EV_JOIN_FAILED:
            Serial.println(F("EV_JOIN_FAILED"));
        break;
        case EV_REJOIN_FAILED:
            Serial.println(F("EV_REJOIN_FAILED"));
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
            }

            Serial.println(F("EV_TXCOMPLETE (includes waiting for RX windows)"));
            delay(50);  // delay to complete Serial Output before Sleeping

            // Schedule next transmission
            // next transmission will take place after next wake-up cycle in main loop
        break;
        case EV_LOST_TSYNC:
            Serial.println(F("EV_LOST_TSYNC"));
        break;
        case EV_RESET:
            Serial.println(F("EV_RESET"));
        break;
        case EV_RXCOMPLETE:
            // data received in ping slot
            Serial.println(F("EV_RXCOMPLETE"));
        break;
        case EV_LINK_DEAD:
            Serial.println(F("EV_LINK_DEAD"));
        break;
        case EV_LINK_ALIVE:
            Serial.println(F("EV_LINK_ALIVE"));
        break;
        default:
            Serial.println(F("Unknown event"));
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
        Serial.println("Field2:" + String(packetData.field2));
        Serial.println("Field1:" + String(packetData.field1));
        Serial.println("Voltage:" + String(packetData.voltage));
        Serial.println("Sensor Type:" + String(packetData.sensorType));
    #endif

    message.addTemperature(packetData.field2);
    message.addHumidity(packetData.field1);
    message.addUint16(packetData.voltage);
    message.addUint8(packetData.sensorType);

    // Check that there is not a current TX/RX job running
    if (LMIC.opmode & OP_TXRXPEND)
    {
        Serial.println(F("Current OP_TXRXPEND is running so not sending"));
    }
    else
    {
        // Prepare upstream data transmission at the next possible time.
        LMIC_setTxData2(1, message.getBytes(), message.getLength(), 0);
        Serial.println(F("Sending payload "));
    }
}

// =========================================================================================================================================
// setup
// =========================================================================================================================================
void setup()
{
    Serial.begin(SERIAL_BAUD);
    delay(250);

    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    digitalWrite(LED_PIN, HIGH);
    delay(25);
    digitalWrite(LED_PIN, LOW);

    delay(25);

    pinMode(LedPin, OUTPUT);

    packetData.sensorType = sensorType;

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
    LMIC_setDrTxpow(DR_SF7, 14);
}

// =========================================================================================================================================
//  loop
// =========================================================================================================================================
void loop()
{
    packetData.field2 = 21; // Assign dummy temperature value to field1
    packetData.field1 = 55; // Assign dummy humidity value to field1

    packetData.voltage = readVcc(); 

    do_send(&sendjob);    // send the sensor payload to TTN

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
