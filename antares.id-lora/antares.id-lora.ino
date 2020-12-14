// Create by antares.id
// edited by Fikri Nizar Gustiyana
// For more information, please visit https://antares.id/id/docs.html

#include <loraid.h>
#define ACCESSKEY "antares.id_accesskey"
#define DEVICEID "antares.id_deviceid"

long interval = 60000;    // 10 s interval to send message
long previousMillis = 0;  // will store last time message sent
unsigned int counter = 0;     // message counter

void setup() {
  // Setup loraid access
  lora.init();

  // Set LoRaWAN Class
  lora.setDeviceClass(CLASS_A);

  // Set Data Rate
  lora.setDataRate(2);
  
  // Put Antares Key and DevAddress here
  lora.setAccessKey(ACCESSKEY);
  lora.setDeviceId(DEVICEID);
}

void loop() {
  // put your main code here, to run repeatedly:
  char myStr[50];
  char outStr[255];
  int recvStatus = 0;
  
  unsigned long currentMillis = millis();

  // Check interval overflow
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis; 

    sprintf(myStr, "Test LoRaWAN Telkom %d ", counter); 

    lora.sendToAntares((unsigned char *)myStr, strlen(myStr), 0);
    counter++;
  }

  recvStatus = lora.readData(outStr);
  if(recvStatus) {
    Serial.println(outStr);
  }
  
  // Check Lora RX
  lora.update();
}