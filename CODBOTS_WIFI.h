#ifndef CODBOTS_WIFI_H
#define CODBOTS_WIFI_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <CODBOTS_ROM.h>
#include <IPAddress.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"

class CODBOTS_WIFI {
public:

/*
    WL_IDLE_STATUS (0): This status indicates that the Wi-Fi library is in an idle state, meaning that no attempt to connect to a Wi-Fi network has been made.

    WL_NO_SSID_AVAIL (1): This status means that there are no available Wi-Fi networks to connect to, or the specified SSID (Wi-Fi network name) cannot be found.

    WL_SCAN_COMPLETED (2): This status is returned after a Wi-Fi scan has been completed. You can use it to check if a scan operation has finished.

    WL_CONNECTED (3): This status indicates that the ESP32 is successfully connected to a Wi-Fi network.

    WL_CONNECT_FAILED (4): This status is returned if the ESP32 failed to connect to the specified Wi-Fi network.

    WL_CONNECTION_LOST (5): This status is returned if the ESP32 was previously connected to a network but lost the connection.

    WL_DISCONNECTED (6): This status indicates that the ESP32 is disconnected from the Wi-Fi network. It might not be connected or is explicitly disconnected.
*/
    const int WIFI_STA = 2;
    const int WIFI_AP = 1;

    // List of Wi-Fi status strings
const String wifiStatusStrings[8] = {
  "IDLE_STATUS",
  "NO_SSID_AVAIL",
  "SCAN_COMPLETED",
  "CONNECTED",
  "CONNECT_FAILED",
  "CONNECTION_LOST",
  "DISCONNECTED",
  "TIMEOUT"
};
 
     // Default constructor
    CODBOTS_WIFI();

    // Constructor that takes a reference to CODBOTS_ROM
    CODBOTS_WIFI(CODBOTS_ROM &rom,AsyncWebServer &server);

    
    void setMemory(CODBOTS_ROM &rom,int rom_ssid_, int rom_password_);
    void setModePin(int modepin,bool pindir);
    String getSignalLevelName(int RSSI);
    int getSignalLevel(int RSSI);
    String getWifiNetworksJSON();
    String getEncryptionTypeString(int encryptionType);

    


    int getWifiMode();//1-AP,2-STA

    void readWifiSettings();
    void connect();//check and connect to AP or STA
    void connect(int mode);//direct AP or STA
    int getConnectStatus();//3-CONNECTED
    String getConnectStatus(int status);//return string status
    String getConnectStatusJSON();

    //host start
    bool beginServer(AsyncWebServer &server);

private:
    //rom details
     CODBOTS_ROM* rom_;
     AsyncWebServer* server_;

     int rom_ssid_;
     int rom_password_;

     // connect mode
     int modepin_;
     bool pindir_;
     long connectstarttime;
     int wifimode = 0;

     bool apmode;

     bool server_started;

     // AP Settings
     const char *ap_ssid = "WATCHDOG0001"; // SSID (name) of your ESP32's access point
     const char *ap_password = "abc12345";  // Password for your ESP32's access point
     // WIFI Settings
     String sta_ssid ; // SSID (name)
     String sta_password ;  // Password

     String wifi_list;

     // Define arrays for signal level names and their corresponding RSSI ranges
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