#include <Arduino.h>
#include <HardwareSerial.h>
#include <SPI.h>
#include "heltec.h"

#include "SoftwareSerial.h"
SoftwareSerial MySerial(32,33);

#define BAND  915E6
int value = 0;
char buff;
String buffstr;

void setup() {
  Serial.begin(115200);
  MySerial.begin(9600);
  Serial.println("LoRa Sender");
  Heltec.begin(true, true, true, true, BAND);
}

void loop() { 
  if (MySerial.available() > 0) {
    // read the incoming byte:
    buffstr = MySerial.readStringUntil('#');
    Serial.print(buffstr);
    LoRa.beginPacket();
    LoRa.print(buffstr);
    LoRa.endPacket();

    }
  }