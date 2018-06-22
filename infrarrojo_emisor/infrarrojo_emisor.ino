#include <IRremote.h>

IRsend irsend;
  
void setup()
{
  Serial.begin(9600);
}
void loop() {
  irsend.sendSony(0xa8bca, 16);
  Serial.println("Enviado");
  delay(1000);
}
