#ifndef WIFI_MANAGER_HPP
#define WIFI_MANAGER_HPP

#include <Wifi.h>

class wifi_manager {
    public:
    wifi_manager(){connect();};
    bool isConnected(){return (WiFi.status() == WL_CONNECTED);};
    void printIP(){Serial.println(WiFi.localIP());};

    private:
    const char* ssid     = "Lan House";
    const char* password = "lan160lan";
    void connect(){WiFi.begin(ssid, password);}
};

#endif