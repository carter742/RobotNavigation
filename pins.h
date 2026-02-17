#ifndef H_PINS
#define H_PINS

#include <Arduino.h>

// Wheels
#define ENB 3 // PWM or analog
#define ENA 5 // PWM or analog
#define I1 8
#define I2 9
#define I3 10
#define I4 11

//Line Sensor
#define SENSOR_PIN 12

//pin setup
void lockPins();
void initPins();

#endif