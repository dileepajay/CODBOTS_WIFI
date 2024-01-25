 

# ii_WIFI Library API Reference

## Overview

The `ii_WIFI` library is designed for managing Wi-Fi and server functionalities on ESP32 devices. Below is the API documentation for key functions used in the library.

## Functions

### `void connect(bool waitForConnection)`

Initiates a connection to a Wi-Fi network.

- **Parameters**
  - `waitForConnection`: A boolean value. If `true`, the function waits until the connection is established.
- **Returns**
  - None.

### `void setModePin(uint8_t pin, uint8_t state)`

Sets a mode pin for the ESP32 device.

- **Parameters**
  - `pin`: The GPIO pin number used for setting the mode.
  - `state`: The state to set for the mode pin (e.g., `HIGH` or `LOW`).
- **Returns**
  - None.

### `void setMemory(ii_ROM &rom, int ssidAddress, int passwordAddress)`

Configures the memory settings for storing Wi-Fi credentials.

- **Parameters**
  - `rom`: Reference to an `ii_ROM` object for ROM operations.
  - `ssidAddress`: The address in ROM for storing the Wi-Fi SSID.
  - `passwordAddress`: The address in ROM for storing the Wi-Fi password.
- **Returns**
  - None.

### `void addPath(const char* path, HttpMethod method, RequestHandlerFunction handler)`

Adds a server path with a specified handler function.

- **Parameters**
  - `path`: The URL path to be added.
  - `method`: The HTTP method (e.g., `HTTP_GET`, `HTTP_POST`).
  - `handler`: The function to handle requests to this path.
- **Returns**
  - None.

### Example Usage

```cpp
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
```

 