#ifndef TIMER_H
#define TIMER_H


#include <Arduino.h>


class Timer {
    unsigned long startTime = 0;

public:
    void start();
    unsigned long elapsed();
};


#endif // TIMER_H
