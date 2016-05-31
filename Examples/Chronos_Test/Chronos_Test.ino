#include <Arduino.h>
#include <Chronos.h>
#include <ESP8266WiFi.h>

Chronos c;

const char* ssid = "yourssid";  //  your network SSID (name)
const char* pass = "yourpassword";       // your network password

const int timezone = 1;    
int dst = 0;

void setup() {

  Serial.begin(115200);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  

}

void loop() {

  time_t timeNow = c.now();
  Serial.print("localTime:");
  Serial.println(c.string(timeNow));

  time_t timeUtc = c.utc(timeNow);
  Serial.print("utcTime:");
  Serial.println(c.string(timeUtc));

  Serial.print("weekDay:");
  Serial.println(c.weekDay());

  delay(1000);
  
  //Thu Jan 01 00:00:00 1970



}
