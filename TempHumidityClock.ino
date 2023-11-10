#include "TempHumidityClock_ESP32.h"

void setup(void) {

    Serial.begin(115200);

    setupSD();
    setupTFT();
    setupWifi();
    setupClock();
    setupDHT();  
    setupButtons();
    setupDigitalOutputs();
    
    drawThermoStatus();
}

void loop() {


      currentTime = "";
      
      GetTime();
      GetDate();

     if(buttonPressed) {
      checkButtons();
      buttonPressed = 0;
     }
      

   
      if (currentTime != prevTime) {
        DrawTime();
        prevTime = currentTime;
      }
    
      if(currentDate != prevDate) {
        DrawDay();
        //GetDate();
        prevDate = currentDate;
      }

      if (checkTemp_Timer > 15000) 
      { 
        checkTempHumidity();
        checkTemp_Timer = 0;
        
        if (thermoStatus == true) {//true = on
           if (currentTemp >= defaultTemp + 3) {
              thermoStatus = false;
           }
        }else {
          if (currentTemp < defaultTemp) {
              thermoStatus = true;
           }
        }
        
        if (fanStatus == true) {//true = on
           if (currentHumidity >= defaultHumidity + 3) {
              fanStatus = false;
           }
        }else {
          if (currentHumidity < defaultHumidity) {
              fanStatus = true;
           }
        }
        saveTempHumid();
        OnOff_TempHumid();
      }

      if (refreshDisplay_Timer > 10000) {
        refreshDisplay_Timer = 0;
        drawThermoStatus();
      }

    
    delay(1000);
}

/*
FreeMono12pt7b.h    FreeSansBoldOblique12pt7b.h
FreeMono18pt7b.h    FreeSansBoldOblique18pt7b.h
FreeMono24pt7b.h    FreeSansBoldOblique24pt7b.h
FreeMono9pt7b.h     FreeSansBoldOblique9pt7b.h
FreeMonoBold12pt7b.h    FreeSansOblique12pt7b.h
FreeMonoBold18pt7b.h    FreeSansOblique18pt7b.h
FreeMonoBold24pt7b.h    FreeSansOblique24pt7b.h
FreeMonoBold9pt7b.h   FreeSansOblique9pt7b.h
FreeMonoBoldOblique12pt7b.h FreeSerif12pt7b.h
FreeMonoBoldOblique18pt7b.h FreeSerif18pt7b.h
FreeMonoBoldOblique24pt7b.h FreeSerif24pt7b.h
FreeMonoBoldOblique9pt7b.h  FreeSerif9pt7b.h
FreeMonoOblique12pt7b.h   FreeSerifBold12pt7b.h
FreeMonoOblique18pt7b.h   FreeSerifBold18pt7b.h
FreeMonoOblique24pt7b.h   FreeSerifBold24pt7b.h
FreeMonoOblique9pt7b.h    FreeSerifBold9pt7b.h
FreeSans12pt7b.h    FreeSerifBoldItalic12pt7b.h
FreeSans18pt7b.h    FreeSerifBoldItalic18pt7b.h
FreeSans24pt7b.h    FreeSerifBoldItalic24pt7b.h
FreeSans9pt7b.h     FreeSerifBoldItalic9pt7b.h
FreeSansBold12pt7b.h    FreeSerifItalic12pt7b.h
FreeSansBold18pt7b.h    FreeSerifItalic18pt7b.h
FreeSansBold24pt7b.h    FreeSerifItalic24pt7b.h
FreeSansBold9pt7b.h   FreeSerifItalic9pt7b.h
*/
