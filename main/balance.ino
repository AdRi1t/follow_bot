#include "HX711.h"
#include "fonction.h"

/*  Retourne le poids en gramme */
int read_weight_bagage() {
  int read_value = 0;
  read_value += scale_A.get_units(5);
  read_value += scale_B.get_units(5);
  read_value += scale_C.get_units(5);

  /*
  Serial.print("Weight : ");
  Serial.println(read_value);
  */
  return read_value;
}