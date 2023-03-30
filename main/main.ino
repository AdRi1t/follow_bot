#include <SendOnlySoftwareSerial.h>
#include <Servo.h>
#include "HX711.h"
#include "fonction.h"
#include "LiquidCrystal.h"

//const int freqOutputPin = 13;   // OC1A output pin for ATmega32u4 (Arduino Nano)
const int SEL = 10;
const int OEB_0 = 2;
const int OEB_1 = 3;
const int OEB_2 = 11;
const int OEB_3 = 12;
const int txPin = 13;

int OEB_n[4] = { OEB_0, OEB_1, OEB_2, OEB_3 };

const int RST = 8;
const int Kv = 12;

int consigne_vitesse[4] = { 0, 0, 0, 0 };
int vitesse[4] = { 0, 0, 0, 0 };
int anc_pos[4] = { 0, 0, 0, 0 };
int pos[4] = { 0, 0, 0, 0 };
int sortie[4] = { 0, 0, 0, 0 };

int sortie0;
int sortie1;
int sortie2;
int sortie3;

unsigned long t_0;
unsigned long t_1;

SendOnlySoftwareSerial Serial4(txPin);  // Tx pin

// Buzzer
const int irPin = A0;     // Initialise le broche du capteur infrarouge à A0
const int buzzerPin = 4;  // Initialise le broche du buzzer à 4

// LCD
LiquidCrystal LCD(13, 12, 11, 10, 9, 8);

// Balance
HX711 scale_A;
HX711 scale_B;
HX711 scale_C;

// Coffre
Servo myservo;
char Incoming_value = 0;
const int RELAY_4_PIN = 5;
const int servo_pin = 9;

void setup() {
  /* Initialisation port Série */
  digitalWrite(RST, 1);
  Serial.begin(9600);
  Serial4.begin(9600);

  sortie0 = 0;
  sortie1 = 0;
  sortie2 = 0;
  sortie3 = 0;

  consigne_vitesse[0] = 0;
  consigne_vitesse[1] = 0;
  consigne_vitesse[2] = 0;
  consigne_vitesse[3] = 0;

  delay(4000);

  Serial4.write(170);
  delay(1);

  output(sortie0, 0);
  delay(1);
  output(sortie2, 2);
  delay(1);
  output(sortie1, 1);
  delay(1);
  output(sortie3, 3);

  t_0 = millis();

  pinMode(PIN_TRIGGER_ULTRASONIC_SENSOR_1, OUTPUT);  // Broche Trigger en sortie //
  pinMode(PIN_ECHO_ULTRASONIC_SENSOR_1, INPUT);      // Broche Echo en entree //

  pinMode(PIN_TRIGGER_ULTRASONIC_SENSOR_2, OUTPUT);  // Broche Trigger en sortie //
  pinMode(PIN_ECHO_ULTRASONIC_SENSOR_2, INPUT);      // Broche Echo en entree //

  // LCD
  LCD.begin(16, 2);  // définit le type d'écran lcd 16 x 2

  /*  Initialisation de la partie balance   */
  scale_A.begin(3, 2);
  scale_B.begin(5, 4);
  scale_C.begin(9, 8);
  // Calibration
  scale_A.set_scale(114.f);
  scale_B.set_scale(114.f);
  scale_C.set_scale(114.f);
  scale_A.tare();
  scale_B.tare();
  scale_C.tare();

  // Coffre
  myservo.attach(servo_pin);  // Attache le servo sur au pin 9
  pinMode(RELAY_4_PIN, OUTPUT);
}


void loop() {
  long InDistanceUltrasonicSensor1;
  long InDistanceUltrasonicSensor2;
  long InPreviousDistanceUltrasonicSensor1;
  long InPreviousDistanceUltrasonicSensor2;

  Serial.println("capteur droit = ");
  Serial.println(read_Ultrasonic_Sensor_1());
  Serial.println("capteur gauche = ");
  Serial.println(read_Ultrasonic_Sensor_2());

  InPreviousDistanceUltrasonicSensor1 = InDistanceUltrasonicSensor1;
  InPreviousDistanceUltrasonicSensor2 = InDistanceUltrasonicSensor2;

  InDistanceUltrasonicSensor1 = read_Ultrasonic_Sensor_1();
  InDistanceUltrasonicSensor2 = read_Ultrasonic_Sensor_2();

  AvancerReculer(InDistanceUltrasonicSensor1, InDistanceUltrasonicSensor2, InPreviousDistanceUltrasonicSensor1, InPreviousDistanceUltrasonicSensor2);

  asservissement();

  read_weight_bagage();
  check_buzzer();

  delay(100);
}
