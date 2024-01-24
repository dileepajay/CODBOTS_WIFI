#include <Arduino.h>

#include <ii_WIFI.h>
#include <ii_ROM.h>

ii_ROM rom;
#define ROM_WIFI_SSID 0
#define ROM_WIFI_PASSWORD 1

ii_WIFI wifi;

void setup()
{
  Serial.begin(115200);

  rom.begin(10, 4096);

  wifi.setModePin(15, HIGH);
  wifi.setMemory(rom, ROM_WIFI_SSID, ROM_WIFI_PASSWORD);

  wifi.connect(true);

  // Simple server example: Adding two paths to the server to control LEDs (ON and OFF).
  wifi.addPath("/ledon", HTTP_GET, [](AsyncWebServerRequest *request)
               {
    digitalWrite(PIN_DEBUG, HIGH); // Turn LED ON
    request->send(200, "text/plain", "LED ON"); });

  wifi.addPath("/ledoff", HTTP_GET, [](AsyncWebServerRequest *request)
               {
    digitalWrite(PIN_DEBUG, LOW); // Turn LED OFF
    request->send(200, "text/plain", "LED OFF"); });
}

void loop()
{
  // put your main code here, to run repeatedly:
}
