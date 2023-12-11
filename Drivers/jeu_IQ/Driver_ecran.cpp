/**
 * @file ecran.cpp
 * @author Triet NGUYEN (tr_nguye@insa-toulouse.fr)
 * @brief Driver pour gérer l'écran LCD de la machine QI
 * @version 0.1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*-----------Include-------------*/
#include "Driver_ecran.h"
using namespace std;

/*-----------Private Constants----------*/
#define COULEUR_ROUGE   255
#define COULEUR_VERTE   255 
#define COULEUR_BLEU   255

#define LCD_LIGNE_1 0
#define LCD_LIGNE_2 1
#define LCD_COLONNE_1 0
#define LCD_COLONNE_2 1
#define LCD_COLONNE_3 2
#define LCD_COLONNE_4 3
#define LCD_COLONNE_5 4
#define LCD_COLONNE_6 5
#define LCD_COLONNE_7 6
#define LCD_COLONNE_8 7
#define LCD_COLONNE_9 8
#define LCD_COLONNE_10 9
#define LCD_COLONNE_11 10
#define LCD_COLONNE_12 11
#define LCD_COLONNE_13 12
#define LCD_COLONNE_14 13
#define LCD_COLONNE_15 14
#define LCD_COLONNE_16 15

#define LCD_NB_LIGNE 2
#define LCD_NB_COLONNE 16

/*-----------Class Ecran Functions Definition----------*/
Ecran::Ecran(){
    /* Configurer le nombre de lignes et de colonnes du LCD*/
    lcd.begin(LCD_NB_COLONNE, LCD_NB_LIGNE);
    
    /* Configure le couleur du fond d'écran */
    lcd.setRGB(COULEUR_ROUGE, COULEUR_VERTE, COULEUR_BLEU); /* Ici fond d'écran en blanc*/
    
    delay(1000);
}

void Ecran::Afficher_Message(const String message, int ligneLCD){
    
    int nb_deplacement = message.length() - LCD_NB_COLONNE;
    int avance = 0;

    if (nb_deplacement > 0)
    {
        for(int i = 0; i <= nb_deplacement; i++)
        {
            lcd.setCursor(LCD_COLONNE_1, ligneLCD);
            for (int iter = avance; iter < int(message.length() - nb_deplacement + avance); iter++) {
                lcd.print(message[iter]);
            }
            avance++;
            delay(1000);
        }
    }
    else
    {
        lcd.setCursor(LCD_COLONNE_1, ligneLCD);
        lcd.print(message);
    }

}


void Ecran::Effacer_Ecran(void){
    lcd.clear();
}