#include <ESP8266WebFileManager.h>
#include <ESP8266WiFi.h>
#include <FS.h>

#define FS_SSID "FSManagerSSID"
#define FS_PWD "password"

void setupWiFi() {
  WiFi.disconnect();
  WiFi.softAP(FS_SSID, FS_PWD);
  Serial.print("SSID: "); Serial.println(FS_SSID);
  Serial.print("Password: "); Serial.println(FS_PWD);
  Serial.print("IP: "); Serial.println(WiFi.softAPIP());
}

void setup() {
  delay(300);
  Serial.begin(115200);
  Serial.println();

  setupWiFi();
  SPIFFS.begin();
  ESP8266WebFileManager::begin(80);
}

void loop() {
  ESP8266WebFileManager::handleClient();
}

