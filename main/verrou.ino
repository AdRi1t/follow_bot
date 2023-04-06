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
