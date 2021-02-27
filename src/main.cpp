#include <Arduino.h>
#include "Adafruit_Sensor.h"
#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht (DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9800);
  dht.begin();
}

void loop() {
  delay(2000);
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