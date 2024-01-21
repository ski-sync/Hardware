#ifndef BME_280_H_
#define BME_280_H_


#include <Arduino.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

class Bme_280 {
    Adafruit_BME280 _bme;
public:
    Bme_280();
    void setup();
    void update();
};


#endif // BME_280_H_