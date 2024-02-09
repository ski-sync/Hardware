#ifndef GPS_H_
#define GPS_H_

#include <Arduino.h>
#include <Adafruit_GPS.h>

#define GPSECHO false

class GPS
{
    Adafruit_GPS GPSModule;

public:
    GPS();
    void setup();
    void update();
    void printData();
};

#endif // GPS_H_