#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run make menuconfig to fix it.
#endif

BluetoothSerial SerialBT;

const int LED_PIN = 23;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  SerialBT.begin("LED_TEST");  
  
  Serial.println("Bluetooth устройство запущено!");
  Serial.println("Теперь зайдите в настройки Bluetooth на телефоне, найдите 'BHJ_WORK_ESP32' и подключитесь.");
}

void loop() {
  if (SerialBT.available()) {
    char incomingChar = SerialBT.read();

    if (incomingChar != '\r' && incomingChar != '\n') {
      Serial.print("Получено из приложения: ");
      Serial.println(incomingChar);

      if (incomingChar == '1') {
        digitalWrite(LED_PIN, HIGH);
        SerialBT.println("LED turned ON");
      } 
      else if (incomingChar == '0') {
        digitalWrite(LED_PIN, LOW);
        SerialBT.println("LED turned OFF");
      }
    }
  }
  
  delay(20);
}
