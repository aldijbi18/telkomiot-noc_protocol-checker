// Create by antares.id
// edited by Fikri Nizar Gustiyana

#include <loraid.h>

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
  lora.setAccessKey("070548070652eed2:a99733c6af38c165");
  lora.setDeviceId("e5dc08e0");
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
