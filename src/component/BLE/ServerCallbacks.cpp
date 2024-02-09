#include "ServerCallbacks.h"

void ServerCallbacks::onConnect(BLEServer* pServer, esp_ble_gatts_cb_param_t *param) {
    Serial.println("Client Connected");
    BLEAddress clientAddress = BLEAddress(param->connect.remote_bda);
    Serial.print("Client Address: ");
    Serial.println(clientAddress.toString().c_str());
}

void ServerCallbacks::onDisconnect(BLEServer* pServer) {
    Serial.println("Client Disconnected");
}