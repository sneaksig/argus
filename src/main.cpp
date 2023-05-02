#include <config.h>
#include <lux.h>
#include <env.h>
#include <debug.h>
#include <com.h>
#include <sound.h>
#include <post.h>

#include <Arduino.h>
#include <WiFi.h>



hw_timer_t* iaqTimer;
uint64_t iaqTimerDelay= IAQ_ALARM_DELAY; //currently at 60 seconds

unsigned long lastLuxTimestamp = 0;
unsigned long lastPostTimestamp = 0;
bool performReadIAQ = true;




void IRAM_ATTR onIAQtimer() {
  performReadIAQ = true;
}


void setup() {
  //Attach sensors and serial
  com::begin();
  env::begin();
  lux::begin();
  //sound::begin();
  //post::begin();

  //Setup SimpleCLI
  debug::begin();
  

  //Start timers for interrupts
  iaqTimer = timerBegin(0, 80, true);
  timerAttachInterrupt(iaqTimer, &onIAQtimer, true);
  timerAlarmWrite(iaqTimer,iaqTimerDelay, true);
  timerAlarmEnable(iaqTimer);
}





void loop() {
  if (performReadIAQ) {
    env::read();
    performReadIAQ = false;
  }
  if (millis() - lastLuxTimestamp >= lux::luxDelay)  {
    lux::sample();
    lastLuxTimestamp = millis();
  }
  if (millis() - lastPostTimestamp >= POST_INTERVAL) {
    String data = "{\"dht_temp\":" + String(env::getTemperature());
    data = data + ",";
    data = data + "\"dht_hum\":" + String(env::getRelHumidity());
    data = data + ",";
    data = data + "\"MQ_read\":" + String(env::getMQReading());
    data = data + ",";
    data = data + "\"lux\":" + String(lux::getValue()) ;
    data = data + "}";
    //post::postNow(data);
    lastPostTimestamp = millis();
  }
  debug::update();
}

