#include "BluetoothSerial.h"

// Проверка поддержки Bluetooth на ESP32
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run make menuconfig to fix it.
#endif

BluetoothSerial SerialBT;

const int LED_PIN = 23;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  // Запускаем классический Bluetooth. 
  // Это имя («BHJ_WORK_ESP32») теперь будет видно в настройках Bluetooth на телефоне!
  SerialBT.begin("BHJ_WORK_ESP32"); 
  
  Serial.println("Bluetooth устройство запущено!");
  Serial.println("Теперь зайдите в настройки Bluetooth на телефоне, найдите 'BHJ_WORK_ESP32' и подключитесь.");
}

unsigned long lastSendTime = 0;

void loop() {
  // 1. Читаем то, что прилетает из приложения (по классическому Bluetooth)
  if (SerialBT.available()) {
    char incomingChar = SerialBT.read();
    
    // Игнорируем символы переноса строки
    if (incomingChar != '\r' && incomingChar != '\n') {
      Serial.print("Получено из приложения: ");
      Serial.println(incomingChar);

      if (incomingChar == '1') {
        digitalWrite(LED_PIN, HIGH);
        SerialBT.println("LED turned ON"); // Отправляем ответ обратно в приложение
      } 
      else if (incomingChar == '0') {
        digitalWrite(LED_PIN, LOW);
        SerialBT.println("LED turned OFF"); // Отправляем ответ обратно в приложение
      }
    }
  }

  // 2. Пример отправки данных (например, метеостанции) в приложение каждые 3 секунды
  if (millis() - lastSendTime > 3000) {
    lastSendTime = millis();
    
    // Отправляем строку на телефон (в MIT App Inventor это поймает блок TextReceived)
    String weatherData = "Temp: 24.5C";
    SerialBT.println(weatherData);
    
    Serial.println("Отправлено в приложение: " + weatherData);
  }
  
  delay(20);
}
