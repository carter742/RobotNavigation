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
  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  analogWrite(ENA, speed);
}

void leftWheelForward(const uint8_t speed) {
  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);
  analogWrite(ENB, speed);
}

void rightWheelBackward(const uint8_t speed) {
  digitalWrite(I1, LOW);
  digitalWrite(I2, HIGH);
  analogWrite(ENA, speed);
}

void leftWheelBackward(const uint8_t speed) {
  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);
  analogWrite(ENB, speed);
}

void leftWheelOff() {
  digitalWrite(I1, LOW);
  digitalWrite(I2, LOW);
}

void rightWheelOff() {
  digitalWrite(I3, LOW);
  digitalWrite(I4, LOW);
}
