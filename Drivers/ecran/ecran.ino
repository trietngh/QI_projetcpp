#include "ecran.h"
Ecran ecranLCD;
void setup() 
{
}


void loop() 
{
  //string msg1 = "Bienvenue";
  ecranLCD.Afficher_Message(String((5000-millis())/1000), LCD_LIGNE_1);
  //string msg2 = "Appuyer sur A pour démarrer.";
  
  ecranLCD.Lancer_horloge(3000);
}