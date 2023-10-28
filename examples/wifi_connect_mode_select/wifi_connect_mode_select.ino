#include <CODBOTS_ROM.h>
#include <CODBOTS_WIFI.h>

CODBOTS_ROM rom;
CODBOTS_WIFI wifi;

#define ROM_WIFI_SSID 0
#define ROM_WIFI_PASSWORD 1

void setup() {
  
  Serial.begin(115200);

  rom.begin(10,4096);

  wifi.setMemory(rom,ROM_WIFI_SSID,ROM_WIFI_PASSWORD);
  wifi.setModePin(13,HIGH);

  while(!wifi.connect()){
    Serial.println(wifi.getMode());
    delay(50); 
  }


}

void loop() {
  // put your main code here, to run repeatedly:

}
