#include "pins.h"

void lockPins() {
  //Wheels
  pinMode(I1, INPUT_PULLUP);
  pinMode(I2, INPUT_PULLUP);
  pinMode(I3, INPUT_PULLUP);
  pinMode(I4, INPUT_PULLUP);
  pinMode(ENA, INPUT_PULLUP);
  pinMode(ENB, INPUT_PULLUP);

  digitalWrite(I1, INPUT_PULLUP);
  digitalWrite(I2, INPUT_PULLUP);

  digitalWrite(I3, INPUT_PULLUP);
  digitalWrite(I4, INPUT_PULLUP);

  //line sensor
  pinMode(SENSOR_PIN, INPUT_PULLUP);
}

void initPins() {
  //Wheels
  digitalWrite(I1, LOW);
  digitalWrite(I2, LOW);

  digitalWrite(I3, LOW);
  digitalWrite(I4, LOW);

  analogWrite(ENA, LOW);
  analogWrite(ENB, LOW);

  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  //line sensor
  pinMode(SENSOR_PIN, INPUT_PULLUP);
}