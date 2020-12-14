// Create by antares.id
// edited by Fikri Nizar Gustiyana
// For more information, please visit https://antares.id/id/docs.html

#include <AntaresESP8266HTTP.h>

#define ACCESSKEY "antares.id_accesskey"
#define WIFISSID "WiFi_SSID"
#define PASSWORD "WiFi_Password"

#define projectName "antares.id_projectname"
#define deviceName "ESP8266-HTTP"
int counter = 0;
AntaresESP8266HTTP antares(ACCESSKEY);

void setup() {
  Serial.begin(115200);
  antares.setDebug(true);
  antares.wifiConnection(WIFISSID, PASSWORD);
  /* Use wifiConnectionNonSecure instead if you don't want to use HTTPS
     and avoid SNTP matching */
  //antares.wifiConnectionNonSecure(WIFISSID,PASSWORD);
}

void loop() {
  String p = ("HTTP TEST ke " + String(counter));
  antares.add("data", p);
  antares.send(projectName, deviceName);
  delay(60000);
  counter++;
}