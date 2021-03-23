#ifndef WIFI_MANAGER_HPP
#define WIFI_MANAGER_HPP

#include <Wifi.h>

class wifi_manager {
    public:
    wifi_manager(){connect();};
    bool isConnected(){return (WiFi.status() == WL_CONNECTED);};
    void printIP(){Serial.println(WiFi.localIP());};

    private:
    const char* ssid     = "Fone";
    const char* password = "12345678";
    void connect(){WiFi.begin(ssid, password);}
};

#endif