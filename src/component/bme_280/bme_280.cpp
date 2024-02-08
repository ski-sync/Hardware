#include "bme_280.h"

Bme_280::Bme_280() {
    _bme = Adafruit_BME280();
}

void Bme_280::setup() {
    while (!_bme.begin()) {
        Serial1.println("Could not find a valid BME280 sensor, check wiring!");
        delay(1000);
    }
}

void Bme_280::update() {
    Serial1.print("Temperature = ");
    Serial1.print(_bme.readTemperature());
    Serial1.println(" *C");

    Serial1.print("Pressure = ");
    Serial1.print(_bme.readPressure() / 100.0F);
    Serial1.println(" hPa");

    Serial1.print("Approx. Altitude = ");
    Serial1.print(_bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial1.println(" m");

    Serial1.print("Humidity = ");
    Serial1.print(_bme.readHumidity());
    Serial1.println(" %");

    Serial1.println();
}