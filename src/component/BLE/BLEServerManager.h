// BLEServerManager.h
#ifndef BLE_SERVER_MANAGER_H
#define BLE_SERVER_MANAGER_H

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "CharacteristicCallbacks.h"
#include "ServerCallbacks.h"

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define DEVICE_NAME         "ESP32_BLE_ski_sync"

class BLEServerManager {
private:
    BLECharacteristic *pCharacteristic;
    BLEServer *pServer;

public:
    BLEServerManager();
    void setupBLE();
    void sendValue(int value);
    void sendMessage(String message);
};

#endif // BLE_SERVER_MANAGER_H
