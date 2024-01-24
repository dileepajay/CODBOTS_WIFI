#include <ii_WIFI.h>

ii_WIFI wifi;

void setup() {
  Serial.begin(115200);

  // Set Access Point (AP) credentials if available. 
  // If not set, the library will generate an auto SSID with the default password '12345678'.
  // Uncomment the line below to set custom AP credentials.
  // wifi.setAP("ii-WIFI-AccessPoint","12345678");

  // Set credentials to connect to a WiFi network (Station mode - STA).
  // If set, the library prioritizes these credentials over stored ROM data.
  // Uncomment the line below to set custom WiFi credentials for STA mode.
  // wifi.setSTA("WIFI_SSID","WIFI_PW");

  // Start the server and connect to WiFi either as a Station (STA) or as an Access Point (AP).
  // If the parameter is true, the function waits for a connection to establish.
  // Finally, it displays the connection details.
  wifi.connect(true);

  // Simple server example: Adding two paths to the server to control LEDs (ON and OFF).
  wifi.addPath("/ledon", HTTP_GET, [](AsyncWebServerRequest *request) {
    digitalWrite(PIN_DEBUG, HIGH); // Turn LED ON
    request->send(200, "text/plain", "LED ON");
  });

  wifi.addPath("/ledoff", HTTP_GET, [](AsyncWebServerRequest *request) {
    digitalWrite(PIN_DEBUG, LOW); // Turn LED OFF
    request->send(200, "text/plain", "LED OFF");
  });

  // Print the paths added to the server for debugging and verification.
  wifi.printPaths();
}

void loop() {
  // Main code to be executed repeatedly goes here.
}
