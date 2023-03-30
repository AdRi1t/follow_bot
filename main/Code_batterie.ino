#include "LiquidCrystal.h"

void LCD_write_stats() {
  float tension;
  int valeurA0;
  int restant;
  valeurA0 = analogRead(A0);          //définie la broche mesurant la tension
  tension = (valeurA0 * 5.0) / 1023;  //calcule la tension réelle

  if (tension >= 4.8) {
    restant = 100;
  } else if (tension >= 4.7) {
    restant = 50;
  } else if (tension >= 4, 55) {
    restant = 10;
  }

  LCD.setCursor(1, 0);
  LCD.print("autonomie =");
  LCD.print(restant);
  LCD.print("%");
}

/*
void setup() {
   LCD.begin(16, 2); // définit le type d'écran lcd 16 x 2

}

void loop() {

  float tension ;
  int valeurA0;
  int restant;
  valeurA0 = analogRead(A0);  //définie la broche mesurant la tension
  tension = (valeurA0 *5.0)/1023;   //calcule la tension réelle

  if ( tension >= 4.8) {
    restant = 100;
  }

  else if ( tension >= 4.7 ) {
    restant = 50;
  }

  else if ( tension >= 4,55 ) {
    restant = 10;
  }
 
  delay(1000);

  LCD.setCursor(1, 0);
  LCD.print("autonomie =");
  LCD.print(restant);
  LCD.print("%");
}
*/
