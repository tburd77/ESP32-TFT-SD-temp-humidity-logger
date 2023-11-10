#include "TempHumidityClock_ESP32.h"

void setupButtons() {

    pinMode(enterButton_Pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(enterButton_Pin), [] {
    if (ButtonPressed += (millis() - DebounceTimer) >= (delayTime ) && buttonPressed == 0) {
      DebounceTimer = millis();
      if (millis() - lastInterrupt > delayRepeatTime)
      {
       // state = HIGH;
        lastInterrupt = millis();
        buttonPressed = 3;
      }
    }
  }, RISING);

  
    pinMode(downButton_Pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(downButton_Pin), [] {
    if (ButtonPressed += (millis() - DebounceTimer) >= (delayTime ) && buttonPressed == 0) {
      DebounceTimer = millis();
      if (millis() - lastInterrupt > delayRepeatTime)
      {
        state = LOW;
        lastInterrupt = millis();
        buttonPressed = 2;
      }
    }
  }, RISING);
  

    pinMode(upButton_Pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(upButton_Pin), [] {
    if (ButtonPressed += (millis() - DebounceTimer) >= (delayTime ) && buttonPressed == 0) {
      DebounceTimer = millis();
      if (millis() - lastInterrupt > delayRepeatTime)
      {
        state = HIGH;
        lastInterrupt = millis();
        buttonPressed = 1;
      }
    }
  }, RISING);
}

   
void checkButtons(){

  switch (buttonPressed) {
      case 1:Serial.println("up button Pressed");
          break;
      case 2:Serial.println("down button Pressed");
          break;
      case 3:Serial.println("enter button Pressed");
          break;     
    }
}
