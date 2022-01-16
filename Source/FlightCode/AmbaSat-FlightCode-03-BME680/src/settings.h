/*******************************************************************************
* AmbaSat-1 Prototype
* LoRaWAN encrypted data submission to TTN
* 16th January 2021
* Version 1.02
* Filename: settings.h
* See main.cpp for Copyright and licensing
* ******************************************************************************/

// Define serial baudrate
#define SERIAL_BAUD         9600 // 19200 //9600
#define LED_PIN             9
#define BATTERY_PIN         A7
//#define USE_MOSFET          0
#define BATTERY_ENABLE_PIN  A3
//#define DEBUG
//#define FLASH_SS            8
#define SLEEP_COUNT         2
#define BATTERY_RATIO       4.7373

// these sensor defines will be deprecated
#define SENSOR_01_SHT30     1 // Temperature & Humidity
#define SENSOR_02_STS21     2 // Temperature
#define SENSOR_03_BME680    3 // Gas 
#define SENSOR_04_OPT3001   4 // Ambient Light
#define SENSOR_05_ZMOD4410  5
#define SENSOR_06_SI1132    6
#define SENSOR_07_CCS811B   7
#define SENSOR_08_TESEO     8
