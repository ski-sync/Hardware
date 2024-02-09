#ifndef GPS_H_
#define GPS_H_

#include <Arduino.h>
#include <Adafruit_GPS.h>

#define GPSECHO true

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