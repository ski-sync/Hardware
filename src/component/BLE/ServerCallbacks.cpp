#include "ServerCallbacks.h"

void ServerCallbacks::onConnect(BLEServer* pServer, esp_ble_gatts_cb_param_t *param) {
    Serial1.println("Client Connected");
    BLEAddress clientAddress = BLEAddress(param->connect.remote_bda);
    Serial1.print("Client Address: ");
    Serial1.println(clientAddress.toString().c_str());
}

void ServerCallbacks::onDisconnect(BLEServer* pServer) {
    Serial1.println("Client Disconnected");
}