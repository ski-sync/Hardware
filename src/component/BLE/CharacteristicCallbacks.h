#ifndef CHARACTERISTIC_CALLBACKS_H
#define CHARACTERISTIC_CALLBACKS_H

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

class CharacteristicCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic);
};

#endif // CHARACTERISTIC_CALLBACKS_H