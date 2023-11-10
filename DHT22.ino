#include "TempHumidityClock_ESP32.h"

void setupDHT() {
 
  dht_sensor.begin(); // initialize the DHT sensor
  checkTempHumidity();
  DrawTemp();
  DrawHumid();
}

void checkTempHumidity() {

  currentHumidity  = dht_sensor.readHumidity();
  currentTemp = dht_sensor.readTemperature(true);

  if (isnan(currentHumidity)) {
    validRead_Humid = false;
      Serial.println("Failed to read Humidity from DHT sensor!");
  }else {
      validRead_Humid = true;
    //  if(prevHumidity != currentHumidity) {  
          DrawHumid();
     // }
  }

  if (isnan(currentTemp)) {
    validRead_Temp = false;
    Serial.println("Failed to read Temperature from DHT sensor!");
  } else {
      validRead_Temp = true;  
     // if(prevTemp != currentTemp) {  
          DrawTemp();
    //  }
  }

  if( validRead_Humid == false && validRead_Temp == false) {

    dht_sensor.begin();
   // setupDHT();
    Serial.println("retry init dht22");
  }
  
}

void DrawTemp() {
      tft.setTextSize(1);
    //  DrawTextCover(String(prevTemp), 72, 82);
      DrawTextCover(String(currentTemp), 72, 82);
      tft.setCursor(0, 82);
      tft.setTextColor(ST77XX_GREEN);
      tft.print("Temp. ");
      tft.setCursor(72, 82);
      tft.print(currentTemp);
   //   Serial.print("temp = ");Serial.println(currentTemp);
}

void DrawHumid() {
      tft.setTextSize(1);
      DrawTextCover(String(currentHumidity), 72, 102);
      //DrawTextCover(String(prevHumidity), 72, 102);
      tft.setCursor(0, 102);
      tft.setTextColor(ST77XX_GREEN);
      tft.print("Humidity ");
      tft.setCursor(72, 102);
      tft.print(currentHumidity);
     // tft.print(currentTemp);
     // Serial.print("humid = ");Serial.println(currentHumidity);
}
