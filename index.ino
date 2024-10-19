#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
const char* server = "api.thingspeak.com";
WiFiClient client;
unsigned long myChannelNumber = YOUR_CHANNEL_NUMBER;
const char * myWriteAPIKey = "YOUR_WRITE_API_KEY";
int waterFlowPin = A0;
int pressurePin = A1;
int qualityPin = A2;
void setup() {
Serial.begin(115200);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
ThingSpeak.begin(client);
}
void loop() {
int waterFlow = analogRead(waterFlowPin);
int pressure = analogRead(pressurePin);
int quality = analogRead(qualityPin);
ThingSpeak.setField(1, waterFlow);
ThingSpeak.setField(2, pressure);
ThingSpeak.setField(3, quality);
ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
delay(15000); // Send data every 15 seconds
}