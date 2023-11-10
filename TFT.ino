#include "TempHumidityClock_ESP32.h"

void setupTFT() {
   // Use this initializer if using a 1.44" TFT screen:
    tft.initR(INITR_144GREENTAB);
    tft.setRotation(3);
    tft.fillScreen(ST77XX_BLACK);
    tft.setFont(&FreeSerif9pt7b);
    tft.setTextSize(3);
}

void drawThermoStatus() {

  //int16_t  x1, y1;
   // uint16_t w, h;

   // tft.getTextBounds("OFF", 92, 121, &x1, &y1, &w, &h);
  //  tft.fillRect(x1, y1, w, h, ST77XX_BLUE);
    tft.setTextSize(1);
      DrawTextCover("OFF", 92, 121);
      tft.setCursor(0, 122);
      tft.setTextColor(ST77XX_YELLOW);
      
      tft.print("Set Temp");
      tft.setTextColor(ST77XX_GREEN);
      tft.print(defaultTemp);
      tft.setCursor(92, 122);
      tft.setTextColor(ST77XX_RED);
      if (thermoStatus == true) {
        tft.print("ON");
      }else {
        tft.print("OFF");
      }

}


void DrawTextCover(String time, int16_t x, int16_t y) {
    int16_t  x1, y1;
    uint16_t w, h;

    tft.getTextBounds(time, x, y, &x1, &y1, &w, &h);
    tft.fillRect(x1, y1, w, h, ST77XX_BLACK);
}
