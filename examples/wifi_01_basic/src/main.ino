
#include <Arduino.h>
#include <ii_WIFI.h>
#include <ii_ROM.h>

ii_ROM rom;
ii_WIFI wifi;
AsyncWebServer server(80);

#define ROM_WIFI_SSID 0
#define ROM_WIFI_PASSWORD 1

#define PIN_DEBUG 2
#define PIN_WIFI 15
void initServer();

void setup()
{
    Serial.begin(115200);

    rom.begin(10, 4096);

    pinMode(PIN_DEBUG, OUTPUT);

    wifi.setModePin(PIN_WIFI, HIGH);
    wifi.setMemory(rom, ROM_WIFI_SSID, ROM_WIFI_PASSWORD);

    wifi.beginServer(server);
    initServer();
    wifi.connect();

    while (wifi.isConnecting())
    {
        delay(100);
        Serial.print(".");
        digitalWrite(2, !digitalRead(2));
    }
    Serial.println(".");
    Serial.println(wifi.getConnectDetails());

    if (wifi.getWifiMode() == WIFI_AP)
    {
        digitalWrite(2, HIGH);
    }
}

void initServer()
{

    server.on("/ledon", HTTP_GET, [](AsyncWebServerRequest *request)
              { 
      digitalWrite(PIN_DEBUG, HIGH);
      request->send(200, "text/plain", "LED ON"); });

    server.on("/ledoff", HTTP_GET, [](AsyncWebServerRequest *request)
              {
      digitalWrite(PIN_DEBUG, LOW);
      request->send(200, "text/plain", "LED OFF"); });
}

void loop()
{
}
