#ifndef CODBOTS_WIFI_H
#define CODBOTS_WIFI_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <CODBOTS_ROM.h>
#include <IPAddress.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"

class CODBOTS_WIFI
{
public:
    // Wi-Fi status constants
    const int WIFI_STA = 2;
    const int WIFI_AP = 1;

    bool mode_sta;
    bool mode_ap;

    // Wi-Fi status strings
    const String wifiStatusStrings[8] = {
        "IDLE_STATUS",
        "NO_SSID_AVAIL",
        "SCAN_COMPLETED",
        "CONNECTED",
        "CONNECT_FAILED",
        "CONNECTION_LOST",
        "DISCONNECTED",
        "TIMEOUT"};

    // Default constructor
    CODBOTS_WIFI();

    // Constructor that takes a reference to CODBOTS_ROM and AsyncWebServer
    CODBOTS_WIFI(CODBOTS_ROM &rom, AsyncWebServer &server);

    // Set memory addresses for Wi-Fi credentials in ROM
    void setMemory(CODBOTS_ROM &rom, int rom_ssid_, int rom_password_);

    // Set the mode pin for switching between AP and STA modes
    void setModePin(int modepin, bool pindir);

    // Get a string representing the signal level based on RSSI
    String getSignalLevelName(int RSSI);

    // Get the signal level index based on RSSI
    int getSignalLevel(int RSSI);

    // Get a JSON string with available Wi-Fi networks
    String getWifiNetworksJSON();

    // Get a string representing the encryption type
    String getEncryptionTypeString(int encryptionType);

    // Get the current Wi-Fi mode (AP or STA)
    int getWifiMode();

    // Read Wi-Fi settings from ROM
    void readWifiSettings();

    // Connect to Wi-Fi (automatically determine mode)
    void connect();

    // Connect to Wi-Fi with specified mode (AP or STA)
    void connect(int mode);

    // Get the connection status
    int getConnectStatus();

    // Get a string representation of the connection status
    String getConnectStatus(int status);

    // Get the connection status as a JSON string
    String getConnectStatusJSON();

    // Get the IP address of the ESP32
    String getIP();

    // Start the AsyncWebServer
    bool beginServer(AsyncWebServer &server);

private:
    // Pointer to CODBOTS_ROM instance
    CODBOTS_ROM *rom_;

    // Pointer to AsyncWebServer instance
    AsyncWebServer *server_;

    // ROM addresses for Wi-Fi credentials
    int rom_ssid_;
    int rom_password_;

    // Mode pin details
    int modepin_;
    bool pindir_;

    // Connection start time
    long connectstarttime;

    // Wi-Fi mode (AP or STA)
    int wifimode;

    // Flag indicating AP mode
    bool apmode;

    // Flag indicating whether the server has been started
    bool server_started;

    // Access Point (AP) settings
    const char *ap_ssid = "WATCHDOG0001"; // SSID of ESP32's access point
    const char *ap_password = "abc12345"; // Password for ESP32's access point

    // Station (STA) settings
    String sta_ssid;     // SSID for STA mode
    String sta_password; // Password for STA mode

    // List of available Wi-Fi networks
    String wifi_list;

    // Signal level names and corresponding RSSI ranges
    const String signalLevelNames[5] = {
        "No Signal",
        "Very Weak",
        "Weak",
        "Moderate",
        "Strong"};

    const int signalLevelRanges[5] = {
        -100, // No Signal
        -90,  // Very Weak
        -70,  // Weak
        -50,  // Moderate
        0     // Strong
    };
};

#endif
