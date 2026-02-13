#ifndef H_TIMER
#define H_TIMER

#include "Arduino.h"

class Timer {
public:
  Timer();
  bool wait(unsigned long time);
  void pause();
  void unpause();

private:
  unsigned long time = 0;
  unsigned long endTime = 0;
  bool isPaused = false;
};

#endif