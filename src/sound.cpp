#include "sound.h"
#include "Arduino.h"
#include "config.h"


namespace sound {


    void begin() {
        pinMode(ADCPin, INPUT);
    }

    void sample() {

    }

    float getSample() {
        return -1;
    }
}