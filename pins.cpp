#include "pins.h"

void initPins() {
  //Wheels
  digitalWrite(WHEELS_I1, LOW);
  digitalWrite(WHEELS_I2, LOW);

  digitalWrite(WHEELS_I3, LOW);
  digitalWrite(WHEELS_I4, LOW);

  analogWrite(WHEELS_ENA, LOW);
  analogWrite(WHEELS_ENB, LOW);

  pinMode(WHEELS_I1, OUTPUT);
  pinMode(WHEELS_I2, OUTPUT);
  pinMode(WHEELS_I3, OUTPUT);
  pinMode(WHEELS_I4, OUTPUT);
  pinMode(WHEELS_ENA, OUTPUT);
  pinMode(WHEELS_ENB, OUTPUT);

  //line sensor
  pinMode(LINE_SENSOR_READ, INPUT_PULLUP);

  //Arm
  digitalWrite(ARM_I1, LOW);
  digitalWrite(ARM_I2, LOW);

  analogWrite(ARM_ENA, LOW);

  pinMode(ARM_ENA, OUTPUT);
  pinMode(ARM_I1, OUTPUT);
  pinMode(ARM_I2, OUTPUT);

  //start button
  pinMode(START_BUTTON, INPUT);
}