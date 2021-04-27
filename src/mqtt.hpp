#ifndef PUBSUBCLIENT_H
#define PUBSUBCLIENT_H

#include "PubSubClient.h"
#include "wifi_manager.hpp"
#include "String.h"

class mqtt_client{
    public:
        mqtt_client(){
            setupMQTT();
        };

        void mqttloop(){
            loop();
        }

        void publishMQTT(const char* topic, const char* message){
            client.publish(topic, message);
        }

    private:
        const char* mqttServer = "broker.hivemq.com";
        const int mqttPort = 1883;

        String ClientId;

        PubSubClient client;

        void loop(){
            client.loop();
        }

        void setupMQTT() {
            client.setServer(mqttServer, mqttPort);
        }

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