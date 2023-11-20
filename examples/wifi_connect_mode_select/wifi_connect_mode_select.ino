/*
  Author: Dileepa Jayawardena
  Date: 2023/10/05

  The provided Arduino code configures an ESP32 to connect to Wi-Fi using stored credentials in ROM.
  It utilizes the CODBOTS_ROM and CODBOTS_WIFI libraries, sets up a web server, and toggles a debug
  LED during the connection process. The device can switch between client and access point modes
  using a button on pin 34. Access the configuration page at the local IP address to manage
  Wi-Fi settings.
*/

#include <CODBOTS_ROM.h>
#include <CODBOTS_WIFI.h>

// Define pin constants
#define PIN_DEBUG 2
#define WIFI_MODE_PIN 34

// Create instances of necessary classes
CODBOTS_ROM rom;
CODBOTS_WIFI wifi;
AsyncWebServer server(80);

// Define ROM addresses for WiFi credentials
#define ROM_WIFI_SSID 0
#define ROM_WIFI_PASSWORD 1

/*
  To access this page, upload the sketch /data folder
  http://(IP)/wifi_connect.html
*/

void setup()
{
  // Initialize serial communication
  Serial.begin(115200);

  // Set up DEBUG LED
  pinMode(PIN_DEBUG, OUTPUT);

  Serial.println("Initializing ROM");
  // Initialize ROM with size 10 and block size 4096
  rom.begin(10, 4096);

  Serial.println("Setting memory addresses from ROM");
  // Set memory addresses for WiFi credentials in ROM
  wifi.setMemory(rom, ROM_WIFI_SSID, ROM_WIFI_PASSWORD);

  Serial.println("Set access point mode button");
  // Set the mode pin for switching between client and access point modes
  wifi.setModePin(WIFI_MODE_PIN, HIGH);

  // Begin the web server
  wifi.beginServer(server);

  // Connect to WiFi
  wifi.connect();

  // Wait for a successful connection
  while (wifi.getConnectStatus() != WL_CONNECTED)
  {
    digitalWrite(PIN_DEBUG, !digitalRead(2));
    delay(100);
    Serial.print('.');
  }
  Serial.println(' ');
  Serial.println(wifi.getIP() + "/wifi_connect.html");
}

void loop()
{
  // Main loop code (empty in this example)
}
