#include "com.h"
#include "Arduino.h"
#include "config.h"
#include "WiFi.h"
#include "secrets.h"


namespace com {

    void begin() {
        Serial.begin(SERIAL_BAUD);
        Serial.println(R""""(
        _______                       
        (_______)                      
        _______  ____ ____ _   _  ___ 
        |  ___  |/ ___) _  | | | |/___)
        | |   | | |  ( (_| | |_| |___ |
        |_|   |_|_|   \___ |____/(___/ 
                    (_____|           
                                    
        )"""");
        Serial.print("Ver. "); Serial.println(VERSION);

        /*
        WiFi.persistent(WIFI_PERSITENT);
        WiFi.begin(YOUR_SSID, YOUR_PSK);
        */

        //Serial.println("Connecting.");
        //while(WiFi.status() != WL_CONNECTED){
        //    delay(500);
        //    Serial.println(".");
        //}
        Serial.println("Connected! IP: " + String(WiFi.localIP()));
    }
}