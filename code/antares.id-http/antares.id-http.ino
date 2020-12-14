// Create by antares.id
// edited by Fikri Nizar Gustiyana

#include <AntaresESP8266HTTP.h>

#define ACCESSKEY "070548070652eed2:a99733c6af38c165"
#define WIFISSID "Tribe IoT"
#define PASSWORD "telkom2020"

#define projectName "Test-NOC"
#define deviceName "ESP826-HTTP"
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