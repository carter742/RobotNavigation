#include "timer.h"

Timer::Timer() {}

bool Timer::wait(unsigned long time) {  
  if (endTime == 0) {
    this->time = time;
    endTime = this->time + millis();
  }

  if (endTime > millis() && !paused)
    return false;

  endTime = 0;
  return true;
}

void Timer::pause() {
  paused = true;
}

void Timer::unpause() {
  if (paused) endTime = time + millis();
  paused = false;
}

bool Timer::isPaused() {
  return paused;
}