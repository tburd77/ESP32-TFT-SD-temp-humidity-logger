#include "TempHumidityClock_ESP32.h"

    void setupDigitalOutputs() {
        pinMode(heaterOn_Pin, OUTPUT);//2
        pinMode(fanOn_Pin, OUTPUT);//4
    }
    
    void OnOff_TempHumid() {
        if (thermoStatus == true) {
            digitalWrite(heaterOn_Pin, HIGH);
        }else {
            digitalWrite(heaterOn_Pin, LOW);
        }
        
        if (fanStatus == true) {
            digitalWrite(fanOn_Pin, HIGH);
        }else {
            digitalWrite(fanOn_Pin, LOW);
        }
    }

