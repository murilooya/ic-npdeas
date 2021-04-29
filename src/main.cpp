#include "wifi_manager.hpp"
#include "sensors.hpp"
#include "PubSubClient.h"
#include "mqtt.hpp"

dht_sensor dhtSensor;
wifi_manager wifi;
mqtt_client mqtt;

int last_time = 0;

void setup() {

  Serial.begin (9800);
  dhtSensor = dht_sensor();
  wifi = wifi_manager();
  mqtt = mqtt_client(wifi);

}

void loop() {
  delay(1000);
  if(!wifi.isConnected())
    Serial.println("not connect");

  if (!mqtt.isMQTTConnect())
    mqtt.tryReconnect();
  
  //dhtSensor.dhtLoop();
  mqtt.mqttLoop();

  long now = millis();
  
  if (now - last_time > 00){
    mqtt.publishMQTT("/swa/temperature", "ola");
    last_time = now;
  }
}