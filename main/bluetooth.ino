#include <string.h>
#include "fonction.h"

boolean sendCommand(String message) {
  if (bluetoothSerial.available()) {
    bluetoothSerial.println(message);
    return true;
  } else {
    return false;
  }
}

/*
 * Fonction utilisée pour extraire la fonction et la valeur
 * reçut en commande lors de la communication bluetooth
 * de la forme "feature:value;".
 */
void getCommand(String& S_feature, String& S_value) {
  while (bluetoothSerial.available()) {
    char c = (char)bluetoothSerial.read();
    int phase = 0;
    if (c == ':') {
      phase = 1;
    } else if (c == ';' || c == '\0' || c == '\n') {
      return 0;
    } else {
      if (phase == 0) {
        S_feature += c;
      } else {
        S_value += c;
      }
    }
  }
}
