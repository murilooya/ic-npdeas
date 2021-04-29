#ifndef PUBSUBCLIENT_H
#define PUBSUBCLIENT_H

#include "PubSubClient.h"
#include "wifi_manager.hpp"
#include "String.h"

class mqtt_client{
    public:
        mqtt_client(wifi_manager wifi){
            setupMQTT(wifi);
        };

        void mqttLoop(){
            loop();
        }

        void publishMQTT(const char* topic, const char* message){
            client.publish(topic, message);
            Serial.print("Topic: ");
            Serial.println(topic);
            Serial.print("Message: ");
            Serial.println(message);
        }

        bool isMQTTConnect(){
            return client.connected();
        }

        void tryReconnect(){
            reconnect();
        }

    private:
        const char* mqttServer = "broker.hivemq.com";
        uint16_t mqttPort = 1883;

        String ClientId;

        PubSubClient client;

        void loop(){
            client.loop();
        }

        void setupMQTT(wifi_manager _wifi) {
            PubSubClient client (_wifi.getWifiClient());
            client.setServer(mqttServer, mqttPort);
        }
        void reconnect() {
            Serial.println("Conectando ao MQTT Broker...");
            while (!isMQTTConnect()) {
                Serial.println("Reconectando ao MQTT Broker..");
                String clientId = "ESP32Client-";
                clientId += String(random(0xffff), HEX);

                Serial.println(clientId);

                if (client.connect(clientId.c_str())) {
                        Serial.println("Connected.");
                }
                Serial.println ("Here i go");     
            }
        }
};


#endif