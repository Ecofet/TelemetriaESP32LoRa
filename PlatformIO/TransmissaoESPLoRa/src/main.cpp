#include <Arduino.h>


#define RXD2 16
#define TXD2 17

void setup() {
  // Observe que o formato para definir uma porta serial é o seguinte: Serial2.begin(taxa de transmissão, protocolo, pino RX, pino TX);
  Serial.begin(115200);
  //Serial1.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

  Serial.println("Serial Txd está no pino: "+String(TX));
  Serial.println("Serial Rxd está no pino: "+String(RX));
}

void loop() { //Escolha Serial1 ou Serial2 conforme necessário
  while (Serial2.available()) {
    Serial.print(char(Serial2.read()));
  }
}

//
// https://circuits4you-com.translate.goog/2018/12/31/esp32-hardware-serial2-example/?_x_tr_sl=en&_x_tr_tl=pt&_x_tr_hl=pt-BR&_x_tr_pto=sc
//
//
//
//
//
//
//
