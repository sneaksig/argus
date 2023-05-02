#include "debug.h"
#include "SimpleCLI.h"
#include "Arduino.h"
#include "config.h"
#include "env.h"
#include "lux.h"


namespace debug {
    SimpleCLI cli;
    Command cmdSensors;



    void sensorsCallback(cmd* cmdPtr) {
        Command cmd(cmdPtr);

        Serial.println("printing all sensors");
        Serial.print("{\"dht_temp\":" + String(env::getTemperature()));
        Serial.print(",");
        Serial.print("\"dht_hum\": " + String(env::getRelHumidity()));
        Serial.print(",");
        Serial.print("\"MQ_read\": " + String(env::getMQReading()));
        Serial.print(",");
        Serial.print("\"lux\": " + String(lux::getValue()));
        Serial.println("}");

        Serial.println();

    }
    void cliBuffersCallback(cmd* cmdPtr) {
        Serial.print("Temperature Buffer:       ");
        for (int i = 0; i < IAQ_BUFFER_SIZE; i++) {
            Serial.print(env::tempBuffer[i]);
            Serial.print(", ");
        }
        Serial.println();

        Serial.print("Relative Humidity Buffer: ");
        for (int i = 0; i < IAQ_BUFFER_SIZE; i++) {
            Serial.print(env::humBuffer[i]);
            Serial.print(", ");
        }
        Serial.println();
        Serial.print("IAQ Buffer:               ");
        for (int i = 0; i < IAQ_BUFFER_SIZE; i++) {
            Serial.print(env::iaqBuffer[i]);
            Serial.print(", ");
        }
        Serial.println();
    }


    void begin() {
        cli.addCommand("lssens", sensorsCallback);
        cli.addCommand("lsbuf", cliBuffersCallback);

    }

    void update() {
        if (Serial.available()) {
            String input = Serial.readStringUntil('\n');
            Serial.println("$ " + input);

            cli.parse(input);
        }

    }


}

