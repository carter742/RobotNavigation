#pragma once

#include "Arduino.h"
#include "pins.h"

#include <stdint.h>

void updateLineSensor();

uint16_t getLineNum();
void clearLines();
void addLine();
void checkForLines(const bool v);