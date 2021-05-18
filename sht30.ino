#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_SHT31.h"


Adafruit_SHT31 sht31 = Adafruit_SHT31();



void setup() {

  Serial.begin(115200);

  Serial.println("SHT31 test");

  if (! sht31.begin(0x44)) {   // Set to 0x45 for alternate i2c addr

    Serial.println("Couldn't find SHT31");

    while (1) delay(1);

  }

}





void loop() {

  Serial.print("Temp *C = "); Serial.println(sht31.readTemperature());//.readtemperature()함수를 이용해, 온도값을 읽습니다.

  Serial.print("Hum. % = "); Serial.println(sht31.readHumidity());//.readHumidity()를 이용해, 습도값을 읽습니다.



  Serial.println();

  delay(1000);

}
