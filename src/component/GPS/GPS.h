#ifndef GPS_H_
#define GPS_H_

#include <Arduino.h>
#include <Adafruit_GPS.h>

#define GPSECHO false

class GPS
{
private:
    Adafruit_GPS GPSModule;
    static GPS *instance;
    GPS();

public:
    static GPS *getInstance();
    void setup();
    void update();
    void printData();
};

#endif // GPS_H_