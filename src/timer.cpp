#include <Arduino.h>
#include "timer.h"

void Timer::start() {
    startTime = millis();
}

unsigned long Timer::elapsed() {
    return millis() - startTime;
}