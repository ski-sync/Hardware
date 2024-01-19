#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "callback.h"

void MyCharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic) {
    std::string rxValue = pCharacteristic->getValue();
    if (rxValue.length() > 0) {
    Serial.println("Received Value: ");
    for (int i = 0; i < rxValue.length(); i++)
        Serial.print(rxValue[i]);

    Serial.println();

    if(rxValue == "ping") {
        pCharacteristic->setValue("pong");
        pCharacteristic->notify();
    }
    }
}

void MyServerCallbacks::onConnect(BLEServer* pServer, esp_ble_gatts_cb_param_t *param) {
    Serial.println("Client Connected");
    BLEAddress clientAddress = BLEAddress(param->connect.remote_bda);
    Serial.print("Client Address: ");
    Serial.println(clientAddress.toString().c_str());
}

void MyServerCallbacks::onDisconnect(BLEServer* pServer) {
    Serial.println("Client Disconnected");
}