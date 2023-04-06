#include "fonction.h"
/*
void setup() {
  pinMode(buzzerPin, OUTPUT); // Initialise la broche du buzzer comme une sortie
  Serial.begin(9600); // Initialise la communication série à 9600 bauds
}

void loop() {
  int irValue = analogRead(irPin); // Lit la valeur analogique du capteur infrarouge
  distance = 26.983 * pow(irValue, -1.169); // Convertit la valeur analogique en distance en cm
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0.06) { // Si un obstacle est détecté à moins de 30 cm
    digitalWrite(buzzerPin, HIGH); // Active le buzzer
  } else {
    digitalWrite(buzzerPin, LOW); // Désactive le buzzer
  }

  delay(10); // Attend 500 ms avant la prochaine mesure
}
*/

void check_buzzer() {
  float distance;                            // Variable pour stocker la distance mesurée
  int irValue = analogRead(irPin);           // Lit la valeur analogique du capteur infrarouge
  distance = 26.983 * pow(irValue, -1.169);  // Convertit la valeur analogique en distance en cm
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0.06) {            // Si un obstacle est détecté à moins de 30 cm
    digitalWrite(buzzerPin, HIGH);  // Active le buzzer
  } else {
    digitalWrite(buzzerPin, LOW);  // Désactive le buzzer
  }
}