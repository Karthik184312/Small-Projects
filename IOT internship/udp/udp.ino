#include <WiFi.h>
#include "DHT.h"
DHT dht(4, DHT11); 

const char* ssid = "vivo";
const char* password = "01234567";
const int udpPort = 5219;  

WiFiUDP udp;

void setup() {
  Serial.begin(115200);
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("WiFi connected.");
  Serial.println("UDP server started");
  udp.begin(udpPort);
}

void loop() {
  char packetBuffer[255];  
  
  int packetSize = udp.parsePacket();
  if (packetSize) {
    int len = udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;
    }
    if (strcmp(packetBuffer, "GET_H") == 0) {
      
      float humidity = readHumidity();/
      
      udp.beginPacket(udp.remoteIP(), udp.remotePort());
      udp.printf("Humidity: %.2f%%", humidity);
      udp.endPacket();
    }
  }
  delay(1000); 
}
float readHumidity()
{
float humidity = dht.readHumidity();
return humidity;
}
