#include <Arduino.h>
#include "Adafruit_Sensor.h"
#include "DHT.h"
#include "wifi_manager.hpp"

#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht (DHTPIN, DHTTYPE);

wifi_manager wifi;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9800);
  dht.begin();
  wifi = wifi_manager();
}

void loop() {
  delay (1000);
  if(wifi.isConnected()){
    wifi.printIP();
  }
  else{Serial.println("not connect");}

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));

}