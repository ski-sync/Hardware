#include <Arduino.h>
#include "class/sm.h"
#include "class/timer.h"
#include "class/BLE/BLEServerManager.h"

BLEServerManager bleServerManager;
Fsm fsm;
Timer timer;

void setup() { 
    Serial.begin(115200);
     
    Serial.println("Starting program!");

    // Initialize and set up BLE
    bleServerManager.setupBLE();

    // Start the timer
    timer.start();
}

void loop() {
  delay(1000);
}
