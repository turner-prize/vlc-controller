#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <ESP8266HTTPClient.h>
//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager

int button = 4;
int buttonState = 0;

void setup() {
    pinMode(button, INPUT); // declare push button as input
    WiFiManager wifiManager;
    wifiManager.autoConnect("AutoConnectAP");
   }

void loop(){
  int buttonState = digitalRead(button);
  if (buttonState == HIGH) {
    PostRequest();
    delay(1000);
  }
}

void PostRequest()
{
  HTTPClient http;
  http.begin("http://192.168.1.132:5000/");
  int httpCode = http.GET();
  http.end(); //Close connection
}
