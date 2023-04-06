#include <Servo.h>
#include "fonction.h"

void open_box() {
  digitalWrite(magnet_pin, LOW);
  for (int pos = 0; pos <= 90; pos += 1) {  // Va de 0 degrés à 90 degrés par pas de 1 degré
    myservo.write(pos);                    
    delay(50);                             
  }
}

void close_box() {
  for (int pos = 90; pos >= 0; pos -= 1) {  // Va de 90 degrés à 0 degrés par pas de 1 degré
    myservo.write(pos);                    
    delay(50);                              
  }
  digitalWrite(magnet_pin, HIGH);
}

/*
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    Incoming_value = Serial.read();
    Serial.print(Incoming_Value);
    Serial.print("\n");
    if (Incoming_value == '1')
      digitalWrite(13, HIGH);
    else if (Incoming_value == '0')
      digitalWrite(13, LOW)
  }
}
*/
