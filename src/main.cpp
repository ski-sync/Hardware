#include <Arduino.h>
#include "class/sm.h"
#include "class/timer.h"
#include "component/BLE/BLEServerManager.h"
#include "component/mpu_6050/mpu_6050.h"
#include "component/bme_280/bme_280.h"
#include "component/GPS/GPS.h"

Fsm fsm;
Timer timer;
Mpu_6050 mpu_6050(MPU6050_RANGE_8_G);
Bme_280 bme_280;
GPS gps;

void setup() { 

    Serial.begin(115200);
    Serial.println("Starting program!");

    // Initialize and set up the BLE server
    BLEServerManager::getInstance()->setupBLE();


    // Initialize and set up the mpu_6050
    mpu_6050.setup();

    // Initialize and set up the bme_280
    bme_280.setup();

    // Initialize and set up the GPS
    gps.setup();

    // Start the timer
    timer.start();
}

void loop() {
  gps.update();
  // bleServerManager.sendValue((int) timer.elapsed());
  // generate a random number between 0 and 100
  if (timer.elapsed() >= 1000) {
    BLEServerManager::getInstance()->sendValue(100);
    mpu_6050.update();
    bme_280.update();
    timer.start();
  }
}
