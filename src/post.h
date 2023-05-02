#pragma once
#include <secrets.h>
#include <ArduinoHttpClient.h>
#include <config.h>
#include <com.h>

/* This module handles posting the data to to webserver*/

namespace post {

    void begin();

    void setPost();
    void update();
    void postNow(String postData);
}