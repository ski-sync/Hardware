#ifndef POINT_H
#define POINT_H

#include <Arduino.h>

#include <Adafruit_GPS.h>
#include <Adafruit_BME280.h>
#include <Adafruit_MPU6050.h>


class point
{
private:
    // time
    unsigned char hour;
    unsigned char minute;
    unsigned char seconds;
    unsigned short milliseconds;
    unsigned char year;
    unsigned char month;
    unsigned char day;

    // GPS
    long latitude;
    long longitude;
    long altitude;
    long speed;
    long angle;
    bool fix;
    unsigned char fixquality;
    unsigned char fixquality_3d;
    unsigned char satellites;
    unsigned char antenna;

    // BME280
    long temperature;
    long pressure;
    long humidity;

    // MPU6050
    long ax;
    long ay;
    long az;
    long gx;
    long gy;
    long gz;

public:
    point();
    ~point();
};


#endif // POINT_H