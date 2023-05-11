#include <Arduino.h>

int inputs[8]={19,21,22,23,18,5,17,16};
int outputs[7]={27,26,13,15,33,25,14}; 
int val_cont=0;

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  
  for (int i=0; i<8; i++){
    pinMode(inputs[i], INPUT_PULLUP);
  }

  for (int i=0; i<7; i++){
    pinMode(outputs[i], OUTPUT);
  } 
}

void loop() {

  digitalWrite(LED_BUILTIN,HIGH);

  for (int i=0; i<8; i++){
    bool x = digitalRead(inputs[i]);
    if (x == LOW) {
      val_cont++;
    }
  }

  if (val_cont > 0){
    for (int i=0; i<7; i++){
      digitalWrite(outputs[i],HIGH);
      delay(250);
      digitalWrite(outputs[i],LOW);
      delay(250);

    }
  }
    delay(1000);
    val_cont =0;
    digitalWrite(LED_BUILTIN,LOW);
    delay(1000);
  
}