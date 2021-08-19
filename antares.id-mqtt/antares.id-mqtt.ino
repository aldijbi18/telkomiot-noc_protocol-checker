// Create by antares.id
// edited by Aldi Wijaya
// For more information, please visit https://antares.id/id/docs.html

#include <AntaresESP8266MQTT.h>

#define ACCESSKEY "antares.id_accesskey"
#define WIFISSID "WiFi_SSID"
#define PASSWORD "WiFi_Password"

#define projectName "antares.id_applicationname"
#define deviceName "antares.id_devicename"
int counter = 0;
AntaresESP8266MQTT antares(ACCESSKEY);

void setup() {
  Serial.begin(115200);
  antares.setDebug(true);
  antares.wifiConnection(WIFISSID, PASSWORD);
  antares.setMqttServer();
}

void loop() {
  String p = ("MQTT TEST ke " + String(counter));
  antares.checkMqttConnection();

  // Add variable to data storage buffer
  antares.add("data", p);

  // Publish and print data
  antares.publish(projectName, deviceName);
  delay(60000);
  counter++;
}
