#include "wheelControls.h"

void driveForward(const uint8_t speed) {
  rightWheelForward(speed);
  leftWheelForward(speed);
}

void driveBackward(const uint8_t speed) {
  rightWheelBackward(speed);
  leftWheelBackward(speed);
}

void stopDriving() {
  leftWheelOff();
  rightWheelOff();
}

void rightWheelForward(const uint8_t speed) {
  digitalWrite(WHEELS_I1, HIGH);
  digitalWrite(WHEELS_I2, LOW);
  analogWrite(WHEELS_ENA, speed);
}

void leftWheelForward(const uint8_t speed) {
  digitalWrite(WHEELS_I3, HIGH);
  digitalWrite(WHEELS_I4, LOW);
  analogWrite(WHEELS_ENB, speed);
}

void rightWheelBackward(const uint8_t speed) {
  digitalWrite(WHEELS_I1, LOW);
  digitalWrite(WHEELS_I2, HIGH);
  analogWrite(WHEELS_ENA, speed);
}

void leftWheelBackward(const uint8_t speed) {
  digitalWrite(WHEELS_I3, LOW);
  digitalWrite(WHEELS_I4, HIGH);
  analogWrite(WHEELS_ENB, speed);
}

void leftWheelOff() {
  digitalWrite(WHEELS_I1, LOW);
  digitalWrite(WHEELS_I2, LOW);
}

void rightWheelOff() {
  digitalWrite(WHEELS_I3, LOW);
  digitalWrite(WHEELS_I4, LOW);
}
