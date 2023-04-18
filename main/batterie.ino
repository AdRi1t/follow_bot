#include "LiquidCrystal.h"
#include "fonction.h"

/* Affichage de l'état de la batterie sur l'écran LCD */
void LCD_write_stats() {
  float tension;
  float tension2;
  int valeurA0;
  int restant;
  valeurA0 = analogRead(A0);          //définie la broche mesurant la tension
  tension = (valeurA0 * 5.0) / 1023;  //calcule la tension réelle
  tension2 = (tension * (37000)) / 15000;

  if (tension >= 4.995) {
    restant = 100;
  }
  else if (tension >= 4.89) {
    restant = 90;
  }
  else if (tension >= 4.785) {
    restant = 80;
  }
  else if (tension >= 4.68) {
    restant = 70;
  }
  else if (tension >= 4.575) {
    restant = 60;
  }
  else if (tension >= 4.47) {
    restant = 50;
  }
  else if (tension >= 4.365) {
    restant = 40;
  }
  else if (tension >= 4.26) {
    restant = 30;
  }
  else if (tension >= 4.155) {
    restant = 20;
  }
  else if (tension >= 4.05) {
    restant = 10;
  }

   // Affichage des carrés en fonction de l'autonomie restante
  lcd.setCursor(0, 0);
  lcd.print(restant);
  lcd.print("% ");
  for (int i = 1; i <= 10; i++) {
    if (restant / 10 >= i) {
      lcd.write(byte(0)); // Affichage du symbole personnalisé pour le carré
    }
    else {
      lcd.print(" ");
    }
  }

  lcd.setCursor(0, 1);
  lcd.print("Tension :");
  lcd.print(tension2);
  lcd.print("V");
}
