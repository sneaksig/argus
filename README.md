# arGUS - A multisensoral presence detector

*strongly* inspired by DOI: 10.1109/ISC246665.2019.9071717

## Sensors and Hardware

- Espressif ESP32 as the brains
- Sound: Ky-038
- Luminosity: GL5528, BH1750(better, since no calibration?), TSL2591 to use unified sensor library
- CO2: SNS-MQ135
- Temperature and relative Humidity: ~~DHT11~~ DHT22, this one is better since it has better acccuracy and can handle negative temperatures
- LoRa(maybe?): RN2483
- Addionally:
	- BME688 ?

## TODOS 

## General
- [ ] unify all sensor events into one sensor_event_t 
- [ ] finish all sensor reading routines and serialize them into json
- [x] use formatted strings instead of arduinoJson(less bloat, less code defects)

### Env
- [x] move env to separate file
- [x] provide access to Members with getters instead of raw event access
- [ ] remove global scope of events

### LIGHT 
- [x] init sensors
- [ ] setup sensor
	- [ ] integrationTime
	- [ ] Gain
- [ ] add buffer for light sensor 
- [x] check if current value is higher than previous value
- [x] temporarely increase sampel rate after threshhold is passed
- [x] arithmetic mean
- [ ] add config option for how many quick samples will be taken after change detected

### Sound
- [ ] init sensors
- [ ] calibrate digital read
- [ ] add external interrupt on calibrated digital read

### Button
- [ ] add button module
- [ ] implement two buttons
	- [ ] one for incrementing number of people present
	- [ ] one for decrementing
- [ ] add button count to POST json

### Movement sensor
- [ ] add movement sensor module
- [ ] init movement sensor

### WiFi 
### AsyncWebserver?
no
