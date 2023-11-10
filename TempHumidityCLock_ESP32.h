
#ifndef TempHumidityClock_ESP32
#define TempHumidityClock_ESP32


    #include <SPI.h>
    #include <ESP32Time.h>


//TFT
    #include <Adafruit_GFX.h>    // Core graphics library
    #include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
    #include <Fonts/FreeSerif9pt7b.h>

    //Pin for ESP32
  #define TFT_CS         5  //case select connect to pin 5
  #define TFT_RST        21// for dual spi //reset connect to pin 15
  #define TFT_DC         32 //AO connect to pin 32  (not sure that this is really used)  try pin 25

  Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
   // Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

//Clock
    #include <WiFi.h>
    #include "time.h"

    const char* ntpServer = "pool.ntp.org";
    const long  gmtOffset_sec = 0;
    const int   daylightOffset_sec = 3600;
    String currentTime = "";
    String prevTime = "";
    String currentDate = "";
    String prevDate = "";
    
    struct tm timeinfo;


//Wifi
    #include <WiFi.h> 

//DHT
    #include <DHT.h>
    
    #define DHT_SENSOR_PIN  22 // ESP32 pin GPIO21 connected to DHT11 sensor
    #define DHT_SENSOR_TYPE DHT22
   
    DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

    float currentHumidity = 0.0; 
    float currentTemp = 0.0;
    float prevHumidity = 0.0; 
    float prevTemp = 0.0;
    
    int16_t  defaultTemp = 50;
    bool validRead_Temp = false;
    bool validRead_Humid = false;
    bool thermoStatus = false;
    bool tempHumdFileCreated = false;
    
// Buttons

    #define upButton_Pin   33
    #define downButton_Pin   26
    #define enterButton_Pin   25
    
    volatile unsigned long DebounceTimer;
    volatile int ButtonPressed;
    volatile int buttonPressed;
    volatile unsigned int delayTime = 200;
    volatile unsigned int delayRepeatTime = 500;
    volatile byte state = LOW;
    unsigned long lastInterrupt;  


//SPI
    #include <SPI.h>
    SPIClass spiSD(HSPI);
    #define SD_CS 15
  
// SD
    
    #include "FS.h"
    #include "SD.h"
    
// Digital Outputs



// millis
  #include <elapsedMillis.h>

    elapsedMillis checkTemp_Timer;
    elapsedMillis refreshDisplay_Timer;
    elapsedMillis saveSD_Data_Timer;


#endif
