#include "commandManager.h"

void setup() {
  lockPins();

  forward(255, {TIME, 1000});
  turnLeft(255, {TIME, 1100});
  forward(255, {TIME, 300});
  turnRight(150, 20, {TIME, 10000});
  
  Serial.begin(9600);

  //delay is detected so that all pins can fully reset 
  //when reset button is pressed.
  delay(100);

  initPins();
}

void loop() {
  updateLineSensor();

  if (isDetectingColor()) {
    Serial.println("CHECKING FOR COLOR");
  }

  executeCmds();
}