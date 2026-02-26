#pragma once

#include <Arduino.h>

//Wheels
#define WHEELS_ENB 3 // analog
#define WHEELS_ENA 2 // analog
#define WHEELS_I1 8
#define WHEELS_I2 9
#define WHEELS_I3 10
#define WHEELS_I4 11

//Line Sensor
#define LINE_SENSOR_READ 12

//Color Sensor
#define COLOR_SENSOR_SCL 5 // analog (library handles set up)
#define COLOR_SENSOR_SDA 4 // analog (library handles set up)

//Arm
#define ARM_ENA 1 // analog
#define ARM_I1 7
#define ARM_I2 6

//Start Button
#define START_BUTTON 5

//pin setup
void initPins();
