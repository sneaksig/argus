#pragma once

#include <Arduino.h>
#include <SimpleCLI.h>
#include <config.h>
#include <env.h>
#include <lux.h>


namespace debug {

    void begin();
    void update();
}