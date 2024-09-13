#include <Arduino.h>

#include <WiFi.h>
#define Wifi_ssdi "Galaxy S20 FE 5G"
#define Wifi_password "ineedhelp"

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  WiFi.begin(Wifi_ssdi, Wifi_password);

  Serial.println("Starting");
}
bool isConnected = false;
void loop()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Connected to wifi");
    digitalWrite(LED_BUILTIN, HIGH);
    isConnected = true;
  }

  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println(".");
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(1000);
    isConnected=false;
  }
}
