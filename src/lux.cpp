#include "Arduino.h"
#include "lux.h"
#include "config.h"
#include "hp_BH1750.h"

namespace lux {
    //TODO implement all of this

    //void readLux(Adafruit_TSL2561_Unified tsl) {
    //  Serial.println("Measuring Light level...(not really though, this is just for testing)");
    //  tsl.getEvent(&light_event);
    //  if(light_event.light) {
    //    Serial.println("Light registered: ");Serial.print(light_event.light);Serial.println(" lux");
    //    doc["lux"] = 123;
    //  } else {
    //    Serial.println("Sensor overload");
    //  }
    //}
    uint16_t luxDelay = NORMAL_LUX_DELAY; 
    uint16_t luxChangeThreshhold = LUX_CHANGE_THRESHHOLD; //Testing rate will be temporarely increased after change higher than this value is observed
    hp_BH1750 sens;
    bool highSample = false;
    float lastValue;
    byte count = 0;
    float avg;
    void begin() {
        bool avail = sens.begin(BH1750_TO_GROUND);
        if(!avail) {
            Serial.println("No BH1750 Sensor found!");
            while (true) {};
        }
        sens.start();


    }

    float sample() {
        if (sens.hasValue() == true) {
            float val = sens.getLux();
            if (highSample) {
                if (count < 10) {
                    avg += val;
                    count++;
                } else {
                    val = avg / 10;
                    count = 0;
                    highSample = false; 
                    sens.start();
                    luxDelay = NORMAL_LUX_DELAY;
                    lastValue = val;
                    return val;
                }
            } else if (abs(lastValue - val) >= LUX_CHANGE_THRESHHOLD) {
                luxDelay = FAST_LUX_DELAY;
                avg = val;
                highSample = true;
            } else {
                lastValue = val;
                sens.start();
                return val;
            }
        }
        sens.start();
        return lastValue;
    }

    float getValue() {
        return lastValue;
    }
}
