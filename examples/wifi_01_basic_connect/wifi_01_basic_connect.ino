#include <ii_WIFI.h>

ii_WIFI wifi;

void setup() {
  Serial.begin(115200);

  wifi.setAP("ii-WIFI-AccessPoint","12345678");
  //wifi.setSTA("RT","rtx24710");

  wifi.connect(true);

  wifi.addPath("/ledon", HTTP_GET, [](AsyncWebServerRequest *request) {
    digitalWrite(PIN_DEBUG, HIGH);
    request->send(200, "text/plain", "LED ON");
  });

  wifi.addPath("/ledoff", HTTP_GET, [](AsyncWebServerRequest *request) {
    digitalWrite(PIN_DEBUG, LOW);
    request->send(200, "text/plain", "LED OFF");
  });

  wifi.printPaths();
}

void loop() {
  // put your main code here, to run repeatedly:
}
