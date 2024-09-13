#include <Arduino.h>
#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(13);  // attaches the servo on GPIO 13 to the servo object
  Serial.begin(115200);
}

void loop() {
  if(Serial.available()){
    int val = Serial.parseInt();
    myservo.write(val);
  }

}
