#pragma once

#include "Arduino.h"

class Timer {
public:
  Timer();
  bool wait(unsigned long time);
  void pause();
  void unpause();
  bool isPaused();


private:
  unsigned long time = 0;
  unsigned long endTime = 0;
  bool paused = false;
};
