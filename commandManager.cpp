#include "commandManager.h"

const uint8_t MAX_CMD_NUMBER = 50;
const uint8_t LINE_BASED_CMD_START = 100;

enum CmdType : uint8_t {
  DRIVE_FORWARD,
  DRIVE_BACKWARD,
  TURN_LEFT,
  TURN_RIGHT,
  TURN_LEFT_HARD,
  TURN_RIGHT_HARD,
  DETECTING_COLOR,
  STOP_DETECTING_COLOR,
};

struct Command {
  CmdType cmdType;
  ExitCondition exitCondition;
  uint8_t speedL;
  uint8_t speedR;
};

Command cmds[MAX_CMD_NUMBER];

Timer timer;

uint8_t numberOfCmds = 0;
uint8_t i = 0;

bool colorDetectingEnabled = false;

void handleExitCondition(const ExitCondition exitCondition);
void addCmd(Command command);

bool isDetectingColor() {
  return colorDetectingEnabled;
}

bool executeCmds() {
  if (i == numberOfCmds) {
    stopDriving();
    return false;
  }

  const Command cmd = cmds[i];
  Serial.println(cmd.cmdType);

  switch (cmd.cmdType) {
    case DRIVE_FORWARD:
      driveForward(cmd.speedL);
      break;
    case DRIVE_BACKWARD:
      driveBackward(cmd.speedL);
      break;
    case TURN_LEFT:
    case TURN_RIGHT:
      rightWheelForward(cmd.speedR);
      leftWheelForward(cmd.speedL);
      break;
    case TURN_LEFT_HARD:
      rightWheelForward(cmd.speedR);
      leftWheelBackward(cmd.speedL);
      break;
    case TURN_RIGHT_HARD:
      rightWheelBackward(cmd.speedR);
      leftWheelForward(cmd.speedL);
      break;
    case DETECTING_COLOR:
      colorDetectingEnabled = true;
      break;
    case STOP_DETECTING_COLOR:
      colorDetectingEnabled = false;
      break;
  }

  handleExitCondition(cmd.exitCondition);
  return true;
}

void handleExitCondition(const ExitCondition exitCondition) {
  const uint16_t condition = exitCondition.condition;
  bool shouldStop = false;

  switch (exitCondition.exitType) {
    case TIME:
      shouldStop = timer.wait(condition);
      break;
    
    case LINES:
      shouldStop = (condition == getLineNum());
      if (shouldStop) clearLines();
      checkForLines(true);
      break;
    
    default:
      shouldStop = true;
      break;
  }

  if (shouldStop) {
    checkForLines(false);
    stopDriving();
    i++;
  }
}

void addCmd(Command command) {
  cmds[numberOfCmds] = command;
  numberOfCmds++;
}

void detectColor(const bool check) {
  Command command;
  command.cmdType = (check) ? DETECTING_COLOR : STOP_DETECTING_COLOR;
  command.exitCondition = {NONE, 0};
  addCmd(command);
}

void forward(const uint8_t speed, const ExitCondition exitCondition) {
  Command command;
  command.exitCondition = exitCondition;
  command.cmdType = DRIVE_FORWARD;
  command.speedL = speed;
  command.speedR = speed;
  addCmd(command);
}

void backward(const uint8_t speed, const ExitCondition exitCondition) {
  Command command;
  command.exitCondition = exitCondition;
  command.cmdType = DRIVE_BACKWARD;
  command.speedL = speed;
  command.speedR = speed;
  addCmd(command);
}

void turnRight(const uint8_t speed, const ExitCondition exitCondition) {
  Command command;
  command.exitCondition = exitCondition;
  command.cmdType = TURN_RIGHT;
  command.speedR = 0;
  command.speedL = speed;
  addCmd(command);
}

void turnLeft(const uint8_t speed, const ExitCondition exitCondition) {
  Command command;
  command.exitCondition = exitCondition;
  command.cmdType = TURN_LEFT;
  command.speedR = speed;
  command.speedL = 0;
  addCmd(command);
}

void turnRight(const uint8_t speedL, const int16_t speedR, const ExitCondition exitCondition) {
  Command command;
  command.exitCondition = exitCondition;

  if (speedR < 0) {
    command.cmdType = TURN_RIGHT_HARD;
    command.speedR = -speedR;
  } else {
    command.cmdType = TURN_RIGHT;
    command.speedR = speedR;
  }

  command.speedL = speedL;
  addCmd(command);
}

void turnLeft(const uint8_t speedR, const int16_t speedL, const ExitCondition exitCondition) {
  Command command;
  command.exitCondition = exitCondition;
  command.speedR = speedR;

  if (speedL < 0) {
    command.cmdType = TURN_LEFT_HARD;
    command.speedL = -speedL;
  } else {
    command.cmdType = TURN_LEFT;
    command.speedL = speedL;
  }

  addCmd(command);
}
