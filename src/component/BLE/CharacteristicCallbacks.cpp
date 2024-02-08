#include "CharacteristicCallbacks.h"

void CharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic) {
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