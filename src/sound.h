#pragma once

#include <Arduino.h>
#include <config.h>

namespace sound {

    void begin();
    void sample();
    float getSample();


}