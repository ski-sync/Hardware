#include "bme_280.h"

Bme_280::Bme_280() {
    _bme = Adafruit_BME280();
}

void Bme_280::setup() {
    while (!_bme.begin()) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        delay(1000);
    }
}

void Bme_280::update() {
    Serial.print("Temperature = ");
    Serial.print(_bme.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");
    Serial.print(_bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(_bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(_bme.readHumidity());
    Serial.println(" %");

    Serial.println();
}