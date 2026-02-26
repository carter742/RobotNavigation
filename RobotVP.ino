#include "commandManager.h"
#include "armControls.h"
#include "colorSensor.h"
#include "lineSensor.h"

void setup() {
  forward(255, {TIME, 1000});
  turnLeft(255, {TIME, 1100});
  forward(255, {TIME, 300});
  turnRight(150, 20, {TIME, 10000});
  
  Serial.begin(9600);

  initPins();
  initColorSensor();

  //delay is detected so that all pins can fully reset 
  //when reset button is pressed.
  delay(100);
}

void loop() {
  updateLineSensor();
  updateColorSensor();

  if (isDetectingColor() && isDetectingLegalFish()) {
    pauseCmdExecution(true);
    fireArm();
    pauseCmdExecution(false);
  }

  executeCmds();
}

