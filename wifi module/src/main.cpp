#include <Arduino.h> 
#include <WiFi.h>

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("Configuring access point...");
  
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  pinMode(2, OUTPUT);
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print("Click <a href=\"/H\">here</a> turn the LED on pin 2 on<br>");
            client.print("Click <a href=\"/L\">here</a> turn the LED on pin 2 off<br>");
            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(2, HIGH);
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(2, LOW);
        }
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
