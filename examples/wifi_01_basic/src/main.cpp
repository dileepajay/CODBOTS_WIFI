
#include <Arduino.h>
#include <ii_WIFI.h>
#include <ii_ROM.h>

ii_ROM rom;
ii_WIFI wifi;
AsyncWebServer server(80);

#define ROM_WIFI_SSID 0
#define ROM_WIFI_PASSWORD 1

void setup()
{

    pinMode(2, OUTPUT);
    Serial.begin(115200);

    rom.begin(10, 4096);

    wifi.setMemory(rom, ROM_WIFI_SSID, ROM_WIFI_PASSWORD);

    wifi.setModePin(13, HIGH);
    pinMode(2, OUTPUT);
    wifi.beginServer(server);
    wifi.connect();
    while (!wifi.getConnectStatus() == WL_CONNECTED)
    {
        delay(100);
        Serial.println("Connecting...");
        digitalWrite(2, !digitalRead(2));
    }
    Serial.println(wifi.getConnectDetails());
}

void loop()
{
}
