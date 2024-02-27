#include "BLEServerManager.h"

BLEServerManager::BLEServerManager() {
    pCharacteristic = nullptr;
    pServer = nullptr;
}

BLEServerManager* BLEServerManager::getInstance() {
    if (!instance) {
        instance = new BLEServerManager();
    }
    return instance;
}

void BLEServerManager::setup() {
    BLEDevice::init(DEVICE_NAME);
    pServer = BLEDevice::createServer();
    pServer->setCallbacks(new ServerCallbacks());

    BLEService *pService = pServer->createService(SERVICE_UUID);
    pCharacteristic = pService->createCharacteristic(
                         CHARACTERISTIC_UUID,
                         BLECharacteristic::PROPERTY_READ |
                         BLECharacteristic::PROPERTY_WRITE |
                         BLECharacteristic::PROPERTY_NOTIFY
                     );
    pCharacteristic->setCallbacks(new CharacteristicCallbacks());
    pCharacteristic->setValue("Initial Value");
    pService->start();

    // Setup advertising
    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x06); // Set the minimum value for advertising
    BLEDevice::startAdvertising();
    Serial.println("BLE Server setup done");
}

void BLEServerManager::sendValue(int value) {
    pCharacteristic->setValue(value);
    pCharacteristic->notify();
}

void BLEServerManager::sendMessage(String message) {
    pCharacteristic->setValue(message.c_str());
    pCharacteristic->notify();
}