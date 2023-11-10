#include "TempHumidityClock_ESP32.h"

void setupClock() {
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    
    GetTime();
    prevTime = currentTime;
    DrawTime();
    
    GetDate();
    prevDate = currentDate;
    DrawDay();
}

void GetTime(){

    if(!getLocalTime(&timeinfo)){
        Serial.println("Failed to obtain time");
        return;
    }
    setTimezone("PST8PDT,M3.2.0,M11.1.0");
    char hourMinutesBuff[12];
    strftime(hourMinutesBuff, sizeof(hourMinutesBuff), "%H:%M", &timeinfo);
    currentTime = String(hourMinutesBuff);
}

void GetDate() {
    char monthDayYearBuff[20];
    strftime(monthDayYearBuff, sizeof(monthDayYearBuff), "%B %d, %Y", &timeinfo);
    currentDate = String(monthDayYearBuff);

    int16_t  c = currentDate.indexOf(' ');// get first space   
    currentDate.remove(3, c - 2);
    int16_t  b = currentDate.length();
    String a = currentDate.substring(3, b);
    String d = currentDate.substring(0, 3);
    currentDate = d + " " + a;
}

void setTimezone(String timezone){
  setenv("TZ",timezone.c_str(),1);
  tzset();
}

void DrawTime() {
      tft.setTextSize(3);
      DrawTextCover(prevTime, 0, 42);
      tft.setCursor(0, 42);
      tft.setTextColor(ST77XX_YELLOW);
      tft.print(currentTime);
}

void DrawDay() {
      tft.setTextSize(1);
      DrawTextCover(prevDate, 16, 64);
      tft.setCursor(16, 64);
      tft.setTextColor(ST77XX_YELLOW);
      tft.print(currentDate);

     
}

/*
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
Serial.print("Day of week: ");
Serial.println(&timeinfo, "%A");
Serial.print("Month: ");
Serial.println(&timeinfo, "%B");
Serial.print("Day of Month: ");
Serial.println(&timeinfo, "%d");
Serial.print("Year: ");
Serial.println(&timeinfo, "%Y");
Serial.print("Hour: ");
Serial.println(&timeinfo, "%H");
Serial.print("Hour (12 hour format): ");
Serial.println(&timeinfo, "%I");
Serial.print("Minute: ");
Serial.println(&timeinfo, "%M");
Serial.print("Second: ");
Serial.println(&timeinfo, "%S");

 */
