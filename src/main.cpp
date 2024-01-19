#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "callback.h"
#include "sm.h"

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

BLECharacteristic *pCharacteristic; // Make global

void setup() {  
  Serial.begin(115200);
  Serial.println("Starting BLE work!");

  BLEDevice::init("Long name works now");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
                       CHARACTERISTIC_UUID,
                       BLECharacteristic::PROPERTY_READ |
                       BLECharacteristic::PROPERTY_WRITE |
                       BLECharacteristic::PROPERTY_NOTIFY // Enable notifications
                     );

  pCharacteristic->setValue("Hello World says Neil");
  pCharacteristic->setCallbacks(new MyCharacteristicCallbacks()); // Set the callback
  pServer->setCallbacks(new MyServerCallbacks()); // Set the server callbacks


  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
}

void loop() {
  // Example: Update value every second
  static unsigned long lastUpdate = 0;
  if (millis() - lastUpdate > 1000) {
    lastUpdate = millis();
    // Update the value
    String newValue = "Time since start: " + String(millis()/1000) + " seconds";
    pCharacteristic->setValue(newValue.c_str());
    
    // Notify the client
    pCharacteristic->notify();
  }
}
