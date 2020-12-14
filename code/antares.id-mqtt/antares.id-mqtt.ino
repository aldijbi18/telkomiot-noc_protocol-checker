// Create by antares.id
// edited by Fikri Nizar Gustiyana

/*
    This is an example sketch to publish MQTT data to your
    Antares IoT Platform project device via ESP8266.

    MQTT server & port:
    platform.antares.id, port 1338

    MQTT topic:
    /oneM2M/req/your-access-key/antares-cse/json

    This sketch will deploy data to your Antares device
    and publish to the MQTT topic simultaneously.

    For more information, please visit https://antares.id/id/docs.html
*/

#include <AntaresESP8266MQTT.h>

#define ACCESSKEY "070548070652eed2:a99733c6af38c165"
#define WIFISSID "Tribe IoT"
#define PASSWORD "telkom2020"

#define projectName "Test-NOC"
#define deviceName "ESP8266-MQTT"
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
