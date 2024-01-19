#include <Arduino.h>
#include "class/sm.h"
#include "class/timer.h"
#include "class/BLE/BLEServerManager.h"
#include "class/capteur/mpu_6050.h"

BLEServerManager bleServerManager;
Fsm fsm;
Timer timer;
Mpu_6050 mpu_6050(MPU6050_RANGE_8_G);

void setup() { 
    Serial.begin(115200);
     
    Serial.println("Starting program!");

    // Initialize and set up BLE
    bleServerManager.setupBLE();

    // Initialize and set up the mpu_6050
    mpu_6050.setup();

    // Start the timer
    timer.start();

}

void loop() {
  if (timer.elapsed() >= 100) {
    mpu_6050.update();
    bleServerManager.sendValue((int) timer.elapsed());
    timer.start();
  }
}
