#include <IRremote.h>
#include <IRremoteInt.h>


/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#define RECEIVERS 3

IRrecv *irrecvs[RECEIVERS];
decode_results results;

int RECV_PIN = 10;
int led = 2;

int RECV_PIN_2 = 11;
int led2 = 3;

int RECV_PIN_3 = 12;
int led3 = 4;

void setup()
{
  Serial.begin(9600);
  
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  irrecvs[0] = new IRrecv(RECV_PIN); // Receiver #0
  irrecvs[1] = new IRrecv(RECV_PIN_2); // Receiver #1
  irrecvs[2] = new IRrecv(RECV_PIN_3); // Receiver #2

  for (int i = 0; i < RECEIVERS; i++) {
    irrecvs[i]->enableIRIn();
  }
  
  Serial.println(F("Ready to receive IR signals"));
}

void loop() {

  for (int i = 0; i < RECEIVERS; i++) {
    if (irrecvs[i]->decode(&results)) {
      Serial.print("Receiver #");
      Serial.print(i);
      Serial.print(":");
      Serial.println(results.value, HEX);

      digitalWrite(i+2, HIGH);
      delay(100);
      digitalWrite(i+2, LOW);
      
      irrecvs[i]->resume();
    }

    delay(100);
  }
}


