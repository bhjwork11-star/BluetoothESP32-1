#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define SERVICE_UUID "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
#define RX_UUID      "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define TX_UUID      "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

class MyCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pChar) {
    String v = pChar->getValue();
    v.trim(); 
    if (v == "1") digitalWrite(23, HIGH);
    if (v == "0") digitalWrite(23, LOW);
  }
};

class MyServerCallbacks : public BLEServerCallbacks {
  void onDisconnect(BLEServer* pServer) {
    pServer->startAdvertising();
  }
};

void setup() {
  pinMode(23, OUTPUT);
  
  BLEDevice::init("BHJ_WORK_ESP32");
  BLEServer *s = BLEDevice::createServer();
  s->setCallbacks(new MyServerCallbacks());

  BLEService *srv = s->createService(SERVICE_UUID);
  BLECharacteristic *chrRx = srv->createCharacteristic(RX_UUID, BLECharacteristic::PROPERTY_WRITE);
  chrRx->setCallbacks(new MyCallbacks());
  BLECharacteristic *chrTx = srv->createCharacteristic(TX_UUID, BLECharacteristic::PROPERTY_NOTIFY);
  chrTx->addDescriptor(new BLE2902());

  srv->start();
  
  BLEAdvertising *pAdvertising = s->getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->start();
}

void loop() {}