# CODBOTS_WIFI: WiFi Management Library

This library provides a flexible and easy-to-use interface for managing WiFi connections on ESP32 devices. It includes features for both Access Point (AP) and Station (STA) modes, allowing your ESP32 to function as a standalone access point or connect to an existing WiFi network.

## Features

- **Automatic Mode Switching:** The library intelligently switches between AP and STA modes based on the configuration and user preferences.
- **Web Server Integration:** Easily set up a web server to configure WiFi settings, view available networks, and monitor connection status.
- **JSON-based Communication:** The library uses JSON for communication, making it compatible with various web-based applications and frameworks.
- **Flexible Configuration:** Set WiFi credentials in non-volatile memory (ROM) and easily switch between different configurations.
- **SPIFFS Support:** Serve static files and web pages from the SPIFFS file system for a customizable web interface.
- **Signal Strength Indication:** Provides signal strength information in descriptive terms (e.g., "Weak," "Strong") and numerical values.

## Usage

1. **Include the Library:**
   Include the library in your ESP32 project.

   ```cpp
   #include <CODBOTS_ROM.h>
   #include <CODBOTS_WIFI.h>

   CODBOTS_ROM rom;
   CODBOTS_WIFI wifi;
   AsyncWebServer server(80);
   ```

2. **Initialization:**
   Initialize the library and set up the web server for WiFi configuration.

   ```cpp
   void setup() {
     // Initialize ROM and WiFi
     rom.begin(10, 4096);
     wifi.setMemory(rom, ROM_WIFI_SSID, ROM_WIFI_PASSWORD);
     wifi.setModePin(WIFI_MODE_PIN, HIGH);
     wifi.beginServer(server);
     wifi.connect();
   }
   ```

3. **Main Loop:**
   Add the necessary logic to your main loop.

   ```cpp
   void loop() {
     // Main loop code
   }
   ```

4. **Documentation:**
   For detailed information on library functions and usage, refer to the inline comments and documentation within the source code.

## Contributing

Feel free to contribute, report issues, or suggest improvements!

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```

Feel free to customize the content further based on your specific preferences and additional information you want to provide.