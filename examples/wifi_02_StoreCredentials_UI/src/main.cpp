#include <Arduino.h>
#include <ii_WIFI.h>
#include <ii_ROM.h>

ii_ROM rom;
#define ROM_WIFI_SSID 0     // Define constant for WiFi SSID in ROM
#define ROM_WIFI_PASSWORD 1 // Define constant for WiFi password in ROM

ii_WIFI wifi;

void setup()
{
  Serial.begin(115200); // Start serial communication at 115200 baud rate

  rom.begin(10, 4096); // Initialize ROM with 10 blocks, each of 4096 bytes

  // Configure WiFi settings
  wifi.setModePin(15, HIGH);                             // Set the mode pin (15) and its state (HIGH)
  wifi.setMemory(rom, ROM_WIFI_SSID, ROM_WIFI_PASSWORD); // Set ROM memory for storing WiFi credentials

  wifi.connect(true); // Connect to WiFi. If true, wait for connection

  // Configure server paths for LED control
  // Path for turning LED on
  wifi.addPath("/ledon", HTTP_GET, [](AsyncWebServerRequest *request)
               {
                 digitalWrite(PIN_DEBUG, HIGH);              // Turn LED on
                 request->send(200, "text/plain", "LED ON"); // Send response
               });

  // Path for turning LED off
  wifi.addPath("/ledoff", HTTP_GET, [](AsyncWebServerRequest *request)
               {
                 digitalWrite(PIN_DEBUG, LOW);                // Turn LED off
                 request->send(200, "text/plain", "LED OFF"); // Send response
               });
}

void loop()
{
  // Main code to run repeatedly goes here
}
