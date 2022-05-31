#include <Arduino.h>
#include <ArduinoJson.h>
#include <SPI.h>
#include "heltec.h"
extern "C" {
	#include "freertos/FreeRTOS.h"
	#include "freertos/timers.h"
}


//#define RXD2 16
//#define TXD2 17

#define BAND  915E6
int value = 0;
int counter = 0;
DynamicJsonDocument doc(128);
char buff[128];
String bufff;

void setup() {
  Serial.begin(115200);
  Serial.println("LoRa Sender");
  Heltec.begin(true, true, true, true, BAND);
}

void loop() { 
  Serial.print("Sending packet: ");
  Serial.println(counter);
  doc["value"] =  rand()%100;
  doc["counter"] =  counter;
  serializeJson(doc,buff);
  LoRa.beginPacket();
  LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
  LoRa.print(buff);
  LoRa.endPacket();
  counter++;
  Serial.println("Packet sent");
  
  digitalWrite(25, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(25, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}