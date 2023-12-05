#include "Driver_Palette_Commande.h"
#include "Arduino.h"

Palette_Commande palette;


void test(){
  Serial.println(palette.Recevoir_Reponse(5000));
  palette.Attendre_Demarrage();
  Serial.println("Demarre");
  palette.Attendre_Remplissage_Cadeau();
  Serial.println("Rempli");
}


void setup() {
  Serial.begin(9600);
  test();

} 



void loop() {


   
}
