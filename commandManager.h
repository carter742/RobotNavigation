#ifndef H_COMMAND_MANAGER
#define H_COMMAND_MANAGER

#include "wheelControls.h"
#include "lineSensor.h"
#include "timer.h"
#include "Arduino.h"

#include <stdint.h>

//Movement Methods
enum ExitConditionType : uint8_t {
  NONE, // <- this will do nothing
  TIME,
  LINES,
};

struct ExitCondition {
  ExitConditionType exitType;
  uint16_t condition;
};

bool executeCmds();
bool isDetectingColor();

// Movement Commands
void detectColor(const bool check);

void forward(const uint8_t speed, const ExitCondition exitCondition);
void backward(const uint8_t speed, const ExitCondition exitCondition);

void turnRight(const uint8_t speed, const ExitCondition exitCondition);
void turnLeft(const uint8_t speed, const ExitCondition exitCondition);

void turnRightHard(const uint8_t speed, const uint8_t tightness, const ExitCondition exitCondition);
void turnLeftHard(const uint8_t speed, const uint8_t tightness, const ExitCondition exitCondition);

void turnRightSoft(const uint8_t speed, const uint8_t tightness, const ExitCondition exitCondition);
void turnLeftSoft(const uint8_t speed, const uint8_t tightness, const ExitCondition exitCondition);

#endif