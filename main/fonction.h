#ifndef FONCTION_H
#define FONCTION_H

#define TAILLE 100
#define DELAY_BETWEEN_MEASURES 50

#define MAX_DISTANCE_ULTRASONIC_SENSOR 500;  // Distance maxi a mesurer en cm//
#define MIN_DISTANCE_ULTRASONIC_SENSOR 3;    // Distance mini a mesurer en cm//

#define PIN_ECHO_ULTRASONIC_SENSOR_1 41     // Broche Echo du HC-SR04 sur D7 //
#define PIN_TRIGGER_ULTRASONIC_SENSOR_1 43  // Broche Trigger du HC-SR04 sur D8 //

#define PIN_ECHO_ULTRASONIC_SENSOR_2 35     // Broche Echo du HC-SR04 sur D7 //
#define PIN_TRIGGER_ULTRASONIC_SENSOR_2 33  // Broche Trigger du HC-SR04 sur D8 //


// Bluetooth
void getCommand(String& S_feature, String& S_value);
boolean sendCommand(String message);

// Fonction des capteurs ultrason
int AvancerReculer(int, int, int, int);
int read_Ultrasonic_Sensor_1();
int read_Ultrasonic_Sensor_2();

// Fonction pour les moteurs
void init_motor();
void asservissement();
int readHCTL_n(int);
int inputHCTL();
void commande(byte, int , byte );
void output(int, byte);

//Buzzer
void check_buzzer();

// Fonction pour le poids
int read_weight_bagage();

// Fonction pour le niveau de batterie
void LCD_write_stats();

// Fonction du coffre
void open_box();
void close_box();

#endif