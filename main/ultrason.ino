#include <SendOnlySoftwareSerial.h>
#include "fonction.h"

void init_capteurs(){
 
  pinMode(PIN_TRIGGER_ULTRASONIC_SENSOR_1, OUTPUT);  // Broche Trigger en sortie //
  pinMode(PIN_ECHO_ULTRASONIC_SENSOR_1, INPUT);      // Broche Echo en entree //

  pinMode(PIN_TRIGGER_ULTRASONIC_SENSOR_2, OUTPUT);  // Broche Trigger en sortie //
  pinMode(PIN_ECHO_ULTRASONIC_SENSOR_2, INPUT);  
}

int AvancerReculer(int InDistanceUltrasonicSensor1, int InDistanceUltrasonicSensor2, int InPreviousDistanceUltrasonicSensor1, int InPreviousDistanceUltrasonicSensor2) {
  if (InDistanceUltrasonicSensor1 > 40 && InDistanceUltrasonicSensor2 > 40)  //Avancer
  {
    consigne_vitesse[0] = 40;
    consigne_vitesse[1] = -40;
    consigne_vitesse[2] = -40;
    consigne_vitesse[3] = 40;

    if (InDistanceUltrasonicSensor2 > (InDistanceUltrasonicSensor1 + 10))  //Pivot Avant Droit
    {
      consigne_vitesse[0] = 40;
      consigne_vitesse[1] = 40;
      consigne_vitesse[2] = 40;
      consigne_vitesse[3] = 40;
    }

    if (InDistanceUltrasonicSensor1 > (InDistanceUltrasonicSensor2 + 10))  //Pivot Avant Gauche
    {
      consigne_vitesse[0] = -40;
      consigne_vitesse[1] = -40;
      consigne_vitesse[2] = -40;
      consigne_vitesse[3] = -40;
    }
  }

  else if (InDistanceUltrasonicSensor1 < 30 && InDistanceUltrasonicSensor2 < 30)  //Reculer
  {
    consigne_vitesse[0] = -40;
    consigne_vitesse[1] = 40;
    consigne_vitesse[2] = 40;
    consigne_vitesse[3] = -40;
  }

  else if (InDistanceUltrasonicSensor1 < 30 && InDistanceUltrasonicSensor1 < (InDistanceUltrasonicSensor2 + 10))  //Pivot Arrière Gauche
  {
    consigne_vitesse[0] = 40;
    consigne_vitesse[1] = 40;
    consigne_vitesse[2] = 40;
    consigne_vitesse[3] = 40;
  }

  else if (InDistanceUltrasonicSensor2 < 30 && InDistanceUltrasonicSensor2 < (InDistanceUltrasonicSensor1 + 10))  //Pivot Arrière Droit
  {
    consigne_vitesse[0] = -40;
    consigne_vitesse[1] = -40;
    consigne_vitesse[2] = -40;
    consigne_vitesse[3] = -40;
  }

  else if (sortie[0] == 0 && sortie[1] == 0 && sortie[2] == 0 && sortie[3] == 0 && InPreviousDistanceUltrasonicSensor1 == InDistanceUltrasonicSensor1 && InPreviousDistanceUltrasonicSensor2 == InDistanceUltrasonicSensor2)  //Stop
  {
    consigne_vitesse[0] = 0;
    consigne_vitesse[1] = 0;
    consigne_vitesse[2] = 0;
    consigne_vitesse[3] = 0;
  }

  else {
    consigne_vitesse[0] = 0;
    consigne_vitesse[1] = 0;
    consigne_vitesse[2] = 0;
    consigne_vitesse[3] = 0;
  }
}


int read_Ultrasonic_Sensor_1() {
  long InSignalTimeSensorUltrasonic1;
  long InDistanceSensorUltrasonic1;

  digitalWrite(PIN_TRIGGER_ULTRASONIC_SENSOR_1, LOW);  // On efface l'etat logique de TRIG //
  delayMicroseconds(2);
  digitalWrite(PIN_TRIGGER_ULTRASONIC_SENSOR_1, HIGH);  // On met la broche TRIG a "1" pendant 10μS //
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER_ULTRASONIC_SENSOR_1, LOW);  // On remet la broche TRIG a "0" //
  // Debut de la mesure avec un signal de 10 μS applique sur TRIG //

  // On mesure combien de temps le niveau logique haut est actif sur ECHO //
  InSignalTimeSensorUltrasonic1 = pulseIn(PIN_ECHO_ULTRASONIC_SENSOR_1, HIGH);
  // Calcul de la distance grace au temps mesure //
  InDistanceSensorUltrasonic1 = InSignalTimeSensorUltrasonic1 * 0.034 / 2;  
  // Verification si valeur mesuree dans la plage //

  return (InDistanceSensorUltrasonic1);
}

int read_Ultrasonic_Sensor_2() {
  long InAcquisitionTimeUltrasonicSensor2;
  long InDistanceUltrasonicSensor2;

  digitalWrite(PIN_TRIGGER_ULTRASONIC_SENSOR_2, LOW);  // On efface l'etat logique de TRIG //
  delayMicroseconds(2);
  digitalWrite(PIN_TRIGGER_ULTRASONIC_SENSOR_2, HIGH);  // On met la broche TRIG a "1" pendant 10μS //
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER_ULTRASONIC_SENSOR_2, LOW);  // On remet la broche TRIG a "0" //

  // On mesure combien de temps le niveau logique haut est actif sur ECHO //
  InAcquisitionTimeUltrasonicSensor2 = pulseIn(PIN_ECHO_ULTRASONIC_SENSOR_2, HIGH);
  // Calcul de la distance grace au temps mesure //
  InDistanceUltrasonicSensor2 = InAcquisitionTimeUltrasonicSensor2 * 0.034 / 2;
  // Verification si valeur mesuree dans la plage //

  return (InDistanceUltrasonicSensor2);
}
