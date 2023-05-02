#pragma once

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT_U.h>
#include <config.h>

namespace env
{
    extern float tempBuffer[IAQ_BUFFER_SIZE];
    extern float humBuffer[IAQ_BUFFER_SIZE];
    extern float iaqBuffer[IAQ_BUFFER_SIZE];
    

    void begin();
    void read();

    float getTemperature();
    float getRelHumidity();
    float getMQReading();
} // namespace env

