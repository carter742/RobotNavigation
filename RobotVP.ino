#include "commandManager.h"

void setup() {
  lockPins();

  forward(255, {TIME, 1000});
  turnLeft(255, {TIME, 500});
  backward(255, {TIME, 1000});
  turnRightHard(255, 255, {TIME, 500});
  forward(255, {TIME, 2000});
  
  detectColor(true);
  turnLeftSoft(255, 255, {TIME, 500});
  detectColor(false);
  
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