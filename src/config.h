#pragma once

#define VERSION "0.0.3"


/* === Communication Settings ===*/
#define SERIAL_PORT Serial
#define SERIAL_BAUD 9600
#define WIFI_PERSITENT false


#define JSONSIZE 1024
/* === Sensor conenctions config ===*/
#define MQPinA 34 // Analogue pin of the MQ135
#define MQPinD 35 // Digital Pin of MQ135
#define ADCPin 33 //Sound pin sound digital pin for interrupt: 18b 
#define DHTPin 13
#define DHTType DHT22


/* === Buffer Size config === */
#define IAQ_BUFFER_SIZE 10


/* === Sampling rate config === */
#define NORMAL_LUX_DELAY 10000 // Normal delay between two lux-samples in milliseconds. Note that the actual sample rate is adaptive
#define FAST_LUX_DELAY 1000 //Delay between two lux samples, when it gets increased 
#define IAQ_ALARM_DELAY 60000000
#define LUX_CHANGE_THRESHHOLD 100


/* === Post Settings (how often data will be send to the server) ===*/
#define POST_INTERVAL 10000
