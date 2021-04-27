#ifndef WIFI_MANAGER_HPP
#define WIFI_MANAGER_HPP

#include <WiFi.h>

class wifi_manager {
    public:
    wifi_manager(){
        connect();
    };
    bool isConnected(){
        return (WiFi.status() == WL_CONNECTED);
    };
    void printIP(){
        Serial.println(WiFi.localIP());
    };
    WiFiClient& getWifiClient(){
        return wifi_client;
    };

    private:
    const char* ssid     = "vai colocar credito";
    const char* password = "caldicana";
    void connect(){WiFi.begin(ssid, password);}
    WiFiClient wifi_client;
};

#endif