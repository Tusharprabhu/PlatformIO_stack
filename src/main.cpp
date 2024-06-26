#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 m_p_u;

void setup(){
  Serial.begin(115200);
  while(!Serial);
  delay(20);
  if(!m_p_u.begin()){
    while (1)
    {delay(20);}
    }
    
}

void loop(){
  sensors_event_t a, g, temp;
  m_p_u.getEvent(&a, &g, &temp);
  Serial.print("Accel X: "); Serial.print(a.acceleration.x); Serial.print(" m/s^2 \n");
  delay(100);
  Serial.print("Accel Y: "); Serial.print(a.acceleration.y); Serial.print(" m/s^2 \n");
  delay(100);
  Serial.print("Accel Z: "); Serial.print(a.acceleration.z); Serial.print(" m/s^2 \n");
  delay(100);
}