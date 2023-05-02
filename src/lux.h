#pragma once

#include <Arduino.h>
#include <config.h>
#include <hp_BH1750.h>


namespace lux {
    extern uint16_t luxDelay;

    void begin();
    
    float sample();

    float getValue();



}