#include "CharacteristicCallbacks.h"

void CharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic) {
    std::string rxValue = pCharacteristic->getValue();
    if (rxValue.length() > 0) {
    Serial1.println("Received Value: ");
    for (int i = 0; i < rxValue.length(); i++)
        Serial1.print(rxValue[i]);

    Serial1.println();

    if(rxValue == "ping") {
        pCharacteristic->setValue("pong");
        pCharacteristic->notify();
    }
    }
}