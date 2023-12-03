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
#include "ecran.h"
#include <string>

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

/*-----------Class Ecran Functions Definition----------*/
Ecran::Ecran(){
    /* Configurer le nombre de lignes et de colonnes du LCD*/
    lcd.begin(16, 2);
    
    /* Configure le couleur du fond d'écran */
    lcd.setRGB(COULEUR_ROUGE, COULEUR_VERTE, COULEUR_BLEU); /* Ici fond d'écran en blanc*/
    
    delay(1000);
}

void Ecran::Afficher_Message(const String message, int ligneLCD){
    lcd.setCursor(ligneLCD, LCD_COLONNE_1);
    lcd.print(message);
}

void Ecran::Defiler_Message(const String message, int ligneLCD){
    lcd.setCursor(ligneLCD, LCD_COLONNE_1);
    /* Défiler */
    for (int iter = 0; iter < stringPourAfficher.length(); iter++) {
        lcd.print(message.substr(iter, iter+16));
        delay(500);
    }
    
}