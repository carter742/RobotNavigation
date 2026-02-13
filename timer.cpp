#include "timer.h"

Timer::Timer() {}

bool Timer::wait(unsigned long time) {  
  if (endTime == 0) {
    this->time = time;
    endTime = this->time + millis();
  }

  if (endTime > millis() && !isPaused)
    return false;

  endTime = 0;
  return true;
}

void Timer::pause() {
  isPaused = true;
}

void Timer::unpause() {
  if (isPaused) endTime = time + millis();
  isPaused = false;
}