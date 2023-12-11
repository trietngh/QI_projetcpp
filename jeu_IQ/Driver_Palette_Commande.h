/**
 * @file Driver_Palette_Commande.h
 * @author TANG Huong Cam (hctang@insa-toulouse.fr)
 * @brief Header du Driver pour gérer la palette de commande de jeu IQ
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MYPALETTE_H
#define MYPALETTE_H

/*-----------Include-------------*/
#include <Arduino.h>


/*-----------Exported Class----------*/

class Palette_Commande{
    private: 

    /*-----------Private Class Palette_Commande Attribut Declaration----------*/

    const int buttonPinA = D5;   // the number of the pushbutton pin, D4
    const int buttonPinB = D6;   // the number of the pushbutton pin, D7
    const int buttonPinC = D7;   // the number of the pushbutton pin, D4

    public:

    /*-----------Class Palette_Commande Functions Definition----------*/

    /**
     * @brief Construct a new Palette_Commande object
     * 
     */
    Palette_Commande(void);

    /**
     * @brief Attendre jusqu'au joueur appuie le bouton indiqué
     * 
     * @param bouton 
     */
    void Attendre_Bouton(char bouton);

    /**
     * @brief Attendre une réponse pendant un temps terminé
     * 
     * @param waiting_time 
     * @return char : revoyer 'F' quand il n'y a aucune réponse
     *
     */
    char Recevoir_Reponse(int waiting_time);

    /**
     * @brief Attendre une réponse de joueur
     * 
     * @return char 
     */
    char Recevoir_Reponse(void);


};


#endif