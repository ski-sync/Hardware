#include <Arduino.h>
#include "class/sm.h"
#include "class/timer.h"
#include "component/BLE/BLEServerManager.h"
#include "component/mpu_6050/mpu_6050.h"
#include "component/bme_280/bme_280.h"

BLEServerManager bleServerManager;
Fsm fsm;
Timer timer;
Mpu_6050 mpu_6050(MPU6050_RANGE_8_G);
Bme_280 bme_280;

void setup() { 
    Serial.begin(115200);
     
    Serial.println("Starting program!");

    // Initialize and set up BLE
    bleServerManager.setupBLE();

    // Initialize and set up the mpu_6050
    mpu_6050.setup();

    // Initialize and set up the bme_280
    bme_280.setup();

    // Start the timer
    timer.start();

}

void loop() {
  if (timer.elapsed() >= 10000) {
    mpu_6050.update();
    bme_280.update();
    bleServerManager.sendValue((int) timer.elapsed());
    timer.start();
  }
}
