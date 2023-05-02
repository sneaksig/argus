#include "env.h"
#include "Arduino.h"
#include "Adafruit_Sensor.h"
#include "DHT_U.h"
#include "config.h"


namespace env {
    DHT_Unified dht(DHTPin, DHTType);
    sensors_event_t dhtTempEvent;
    sensors_event_t dhtHumEvent;
    uint16_t MQreading = 0;
    float tempBuffer [IAQ_BUFFER_SIZE];
    float humBuffer [IAQ_BUFFER_SIZE];
    float iaqBuffer [IAQ_BUFFER_SIZE];
    byte iaqBufferCounter = 0;

    void begin() {
        dht.begin();  
        pinMode(MQPinA, INPUT);
        pinMode(MQPinD, INPUT);

    }

    void read() {
        dht.temperature().getEvent(&dhtTempEvent);
        dht.humidity().getEvent(&dhtHumEvent);
        MQreading = analogRead(MQPinA);

        tempBuffer[iaqBufferCounter] = dhtTempEvent.temperature;
        humBuffer[iaqBufferCounter] = dhtHumEvent.relative_humidity;
        iaqBuffer[iaqBufferCounter] = MQreading;
        iaqBufferCounter = (iaqBufferCounter + 1) % IAQ_BUFFER_SIZE;
    }


    float getTemperature() {
        return dhtHumEvent.relative_humidity;
    }

    float getRelHumidity() {
        return dhtTempEvent.temperature;
    }

    float getMQReading() {
        return MQreading;
    }
}