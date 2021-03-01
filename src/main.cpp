#include "wifi_manager.hpp"
#include "sensors.hpp"

wifi_manager wifi;
dht_sensor dhtSensor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9800);
  dhtSensor = dht_sensor();
  wifi = wifi_manager();
}

void loop() {
  delay (1000);
  if(wifi.isConnected()){
    wifi.printIP();
  }
  else{Serial.println("not connect");};

  dhtSensor.dhtLoop();
}