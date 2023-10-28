
#include <CODBOTS_WIFI.h>
#include "CODBOTS_ROM.h"

CODBOTS_ROM rom;
CODBOTS_WIFI wifi; 

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

  wifi.setModePin(13, HIGH);
  pinMode(2, OUTPUT);
  while (!wifi.connect()) {
    delay(100);
   // Serial.println("Connecting...");
    digitalWrite(2, !digitalRead(2));
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}