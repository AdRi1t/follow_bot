#include <../HX711_Arduino_Library/src/HX711.h>
#include "fonction.h"

/* Initialise les pins de balance */
void init_balance(){

  // Initialisation de la partie balance
  scale_A.begin(pin_scale_A[0],pin_scale_A[1]);
  scale_B.begin(pin_scale_B[0],pin_scale_B[1]);
  scale_C.begin(pin_scale_C[0],pin_scale_C[1]);

  // Calibration
  scale_A.set_scale(114.f);
  scale_B.set_scale(114.f);
  scale_C.set_scale(114.f);
  scale_A.tare();
  scale_B.tare();
  scale_C.tare();
}

/*  Retourne le poids en gramme */
int read_weight_bagage() {
  int read_value = 0;
  read_value += scale_A.get_units(5);
  read_value += scale_B.get_units(5);
  read_value += scale_C.get_units(5);

  return read_value;
}
