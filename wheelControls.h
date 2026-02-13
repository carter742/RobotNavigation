#ifndef H_MOTOR_CONTROLS
#define H_MOTOR_CONTROLS

#include "timer.h"
#include "Arduino.h"
#include "pins.h"

#include <stdint.h>

void driveForward(const uint8_t speed=255);
void driveBackward(const uint8_t speed=255);

void stopDriving();

void rightWheelForward(const uint8_t speed=255);
void leftWheelForward(const uint8_t speed=255);
void rightWheelBackward(const uint8_t speed=255);
void leftWheelBackward(const uint8_t speed=255);

void leftWheelOff();
void rightWheelOff();

#endif