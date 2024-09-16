#include <WebServer.h>
#include <WiFi.h>

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";
const int ledPin = 2;

void handleRoot();
void handleOn();
void handleOff();

WebServer server(80);

void setup() {
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  Serial.println("Hotspot IP:");
  Serial.println(WiFi.softAPIP());

  server.on("/", HTTP_GET, handleRoot);
  server.on("/on", HTTP_GET, handleOn);
  server.on("/off", HTTP_GET, handleOff);

  pinMode(ledPin, OUTPUT);
  server.begin();
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String html = "<!DOCTYPE html><html><head><title>ESP32 Web Server</title></head><body><h1>ESP32 Web Server</h1><p><a href=\"/on\"><button>ON</button></a></p><p><a href=\"/off\"><button>OFF</button></a></p></body></html>";
  server.send(200, "text/html", html.c_str());
}

void handleOn() {
  digitalWrite(ledPin, HIGH);
  server.send(200, "text/plain", "LED turned on");
}

void handleOff() {
  digitalWrite(ledPin, LOW);
  server.send(200, "text/plain", "LED turned off");
}