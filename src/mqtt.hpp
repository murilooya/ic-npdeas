#ifndef PUBSUBCLIENT_H
#define PUBSUBCLIENT_H

#include "PubSubClient.h"
#include "wifi_manager.hpp"

class mqtt{
    public:
        mqtt();
        void mqttConnect(){
            client.setServer(mqttServer, mqttPort);
        };
        
    private:
        const char* mqttServer = "broker.hivemq.com";
        const int mqttPort = 1883;
        PubSubClient client;
        void reconnect() {
        Serial.println("Conectando ao MQTT Broker...");
        while (!client.connected()) {
            Serial.println("Reconectando ao MQTT Broker..");
            String clientId = "ESP32Client-";
            clientId += String(random(0xffff), HEX);
            
            if (client.connect(clientId.c_str())) {
                Serial.println("Connected.");
            }     
        }
}
};


#endif