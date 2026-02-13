#include "lineSensor.h"

const uint16_t BLACK_TOLERANCE = 50;
const uint16_t WHITE_TOLERANCE = 50;

uint16_t blackDetected = 0;
uint16_t whiteDetected = 0;

uint16_t linesDetected = 0;

bool overLine = false;
bool shouldCheckForLines = false;

void updateLineSensor() {
  if (!shouldCheckForLines)
    return;

  if (digitalRead(SENSOR_PIN)) {
    blackDetected++;
  } else {
    whiteDetected++;
  }

  if (blackDetected >= BLACK_TOLERANCE && !overLine) {
    whiteDetected = 0;
    linesDetected++;
    overLine = true;
  } else if (whiteDetected >= WHITE_TOLERANCE && overLine) {
    blackDetected = 0;
    overLine = false;
  }
}

void addLine() {
  linesDetected++;
}

unsigned int getLineNum() {
  return linesDetected;
}

void clearLines() {
  linesDetected = 0;
}

void checkForLines(const bool v) {
  shouldCheckForLines = v;
}