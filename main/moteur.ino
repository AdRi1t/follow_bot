#include <SendOnlySoftwareSerial.h>
#include "fonction.h"

// Initialise les moteurs
void init_moteurs(){
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

}

void asservissement() {
  int n = 0;
  for (int n = 0; n < 4; n++) {
    pos[n] = readHCTL_n(n);
    vitesse[n] = pos[n] - anc_pos[n];
    anc_pos[n] = pos[n];
    sortie[n] = (Kv * (consigne_vitesse[n] - vitesse[n])) / 10 + consigne_vitesse[n] / 2;
    output(sortie[n], n);
    // Serial.print(vitesse[n]);
    delay(5);
  }

  Serial.write('\n');
}


int readHCTL_n(int n) {
  unsigned char LSB;
  unsigned char MSB;
  int POS;
  /* selection du circuit HCTL */

  digitalWrite(SEL, 0);
  digitalWrite(OEB_n[n], 0);

  /* lire HCTL MSB */
  MSB = inputHCTL();
  /* lire HCTL LSB */
  digitalWrite(SEL, 1);
  //  SEL = 1;
  LSB = inputHCTL();
  digitalWrite(OEB_n[n], 1);

  POS = (MSB << 8) | LSB;
  return POS;
}

int inputHCTL() {
  return ((PINC & B00001111) | (PIND & B11110000));
}

void commande(byte address, int val, byte mode) {
  //fonction d'envoi des commande au pont en H
  //  byte address = 128;       //adresse du pont en H 001111 sur les selecteurs
  Serial4.write(address);
  Serial4.write(mode);
  Serial4.write(val);
  Serial4.write((address + mode + val) & 0b01111111);
  /*
    mySerial4.write(address);
    mySerial4.write(mode);
    mySerial4.write(val);
    mySerial4.write((address + mode + val) &  0b01111111);
  */
}


void output(int val, byte mot) {

  if (mot == 0) {
    if (val > 127)
      commande(128, 127, 0);
    else if (val > 0)
      commande(128, val, 0);
    else if (val > -127)
      commande(128, -val, 1);
    else
      commande(128, 127, 1);
  } else if (mot == 2) {
    /* moteur 0 et 1 ont un sens opposé */
    if (val > 127)
      commande(128, 127, 1 + 4);
    else if (val > 0)
      commande(128, val, 1 + 4);
    else if (val > -127)
      commande(128, -val, 4);
    else
      commande(128, 127, 4);
  } else if (mot == 1) {
    if (val > 127)
      commande(129, 127, 0);
    else if (val > 0)
      commande(129, val, 0);
    else if (val > -127)
      commande(129, -val, 1);
    else
      commande(129, 127, 1);
  } else {
    /* moteur 0 et 1 ont un sens opposé */
    if (val > 127)
      commande(129, 127, 1 + 4);
    else if (val > 0)
      commande(129, val, 1 + 4);
    else if (val > -127)
      commande(129, -val, 4);
    else
      commande(129, 127, 4);
  }
}
