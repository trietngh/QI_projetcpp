/**
 * @file ecran.h
 * @author Triet NGUYEN (tr_nguye@insa-toulouse.fr)
 * @brief Header du Driver pour gérer l'écran LCD de la machine QI
 * @version 0.1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __ECRAN__
#define __ECRAN__

/*-----------Include-------------*/
#include "rgb_lcd.h"
#include <string>

using namespace std;


/*-----------Exported Constants----------*/
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

/*-----------Exported Class----------*/
class Ecran{
    private:
        rgb_lcd lcd;
    public:
        /**
         * @brief Constructeur pour la class écran
         * @param None
         */
        Ecran();

        /**
         * @brief Afficher un message au écran
         * 
         * @param stringPourAfficher    Message pour afficher
         * @param ligneLCD              Ligne sur laquelle le message est affiché
         *                              Peut être un des valeur suivant :
         *                                  LCD_LIGNE_1
         *                                  LCD_LIGNE_2
         */
        void Afficher_Message(const String message, int ligneLCD);
        /**
         * @brief Défiler un message sur l'écran
         * 
         * @param stringPourAfficher    Message pour afficher
         * @param ligneLCD              Ligne sur laquelle le message est affiché
         *                              Peut être un des valeur suivant :
         *                                  LCD_LIGNE_1
         *                                  LCD_LIGNE_2
         */
        void Defiler_Message(const String message, int ligneLCD);
};

#endif
