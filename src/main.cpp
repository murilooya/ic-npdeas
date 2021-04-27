#include "wifi_manager.hpp"
#include "sensors.hpp"
#include "PubSubClient.h"
#include "mqtt.hpp"

dht_sensor dhtSensor;
wifi_manager wifi;
mqtt_client mqtt;

void setup() {

  Serial.begin (9800);
  dhtSensor = dht_sensor();
  wifi = wifi_manager();
  mqtt = mqtt_client();
  PubSubClient client (wifi.getWifiClient());
}

void loop() {
  delay (1000);
  if(wifi.isConnected()){
    wifi.printIP();
  }
  else{Serial.println("not connect");};

  dhtSensor.dhtLoop();
}