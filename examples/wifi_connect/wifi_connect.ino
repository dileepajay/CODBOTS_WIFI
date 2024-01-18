
#include <ii_WIFI.h>
#include "ii_ROM.h"
#include <ESPAsyncWebServer.h>

ii_ROM rom;
ii_WIFI wifi; 
AsyncWebServer server(80);

#define ROM_WIFI_SSID 0
#define ROM_WIFI_PASSWORD 1

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200);

  rom.begin(10, 4096);

  wifi.setMemory(rom, ROM_WIFI_SSID, ROM_WIFI_PASSWORD);

  //rom.clearSlot(ROM_WIFI_SSID);
  //rom.clearSlot(ROM_WIFI_PASSWORD);
  //rom.writeSlot("DJAY",ROM_WIFI_SSID);
  //rom.writeSlot("andhrgsn#h123",ROM_WIFI_PASSWORD);
  //Serial.println(wifi.getWifiNetworksJSON());
  wifi.setModePin(13, HIGH);
  pinMode(2, OUTPUT);
  wifi.beginServer(server);
  wifi.connect();
  while (!wifi.getConnectStatus()==WL_CONNECTED) {
    delay(100);
   // Serial.println("Connecting...");
    digitalWrite(2, !digitalRead(2));
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
