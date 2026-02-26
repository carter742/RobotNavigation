#include "commandManager.h"
#include "armControls.h"
#include "colorSensor.h"
#include "lineSensor.h"
#include "timer.h"

const size_t BUTTON_HOLD_TIME = 500;

bool running = false;

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
  if (!running) {
    handleStartUp();
    return;
  }

  updateLineSensor();
  updateColorSensor();

  if (isDetectingColor() && isDetectingLegalFish()) {
    pauseCmdExecution(true);
    fireArm();
    pauseCmdExecution(false);
  }

  running = !executeCmds();
}

void handleStartUp() {
  static Timer timer;
  static bool toggle = false;

  bool callibrate = (toggle && timer.wait(BUTTON_HOLD_TIME));

  if (digitalRead(START_BUTTON) && !toggle) {
    toggle = true;
  } else if (!digitalRead(START_BUTTON) && toggle) {
    toggle = false;

    if (callibrate) {
      resetColorSensorCallibration();
      callibrateColorSensor(100);
    } else {
      running = true;
    }
  }
}