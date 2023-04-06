#include "LiquidCrystal.h"
#include "fonction.h"


void LCD_write_stats() {
  float tension ;
  float tension2 ;
  int valeurA0;
  int restant;
  valeurA0 = analogRead(A0);  //définie la broche mesurant la tension
  tension = (valeurA0 *5.0)/1023;   //calcule la tension réelle
  //float p_bat = map(tension,5.1,3.9,0,100); //calcul du pourcentage de batterie en utilisant une formule linéaire
  tension2 = (tension*(37000))/15000;
  
    if ( tension >= 4.995
  ) {
     restant = 100;
    }
  
    else if ( tension >= 4.89 ) {
      restant = 90;
   }
   
    else if ( tension >= 4.785 ) {
      restant = 80;
   }
  
    else if ( tension >= 4.68 ) {
      restant = 70;
    }
    
    else if ( tension >= 4.575 ) {
      restant = 60;
   }
   
    else if ( tension >= 4.47 ) {
      restant = 50;
   }
   
    else if ( tension >= 4.365 ) {
      restant = 40;
   }
    else if ( tension >= 4.26 ) {
      restant = 30;
   }
    
    else if ( tension >= 4,155 ) {
      restant = 20;
    }
     else if ( tension >= 4,05 ) {
      restant = 10;
    }
  
    LCD.setCursor(1,0);
    LCD.print("autonomie=");
    LCD.print(restant);
    LCD.print("%");
    LCD.setCursor(0,1);
    LCD.print("tension =");
    LCD.print(tension2);
    LCD.print("V");
}
