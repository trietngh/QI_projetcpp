/**
 * @file Driver_Haut_Parleur.h
 * @author TANG Huong Cam (hctang@insa-toulouse.fr)
 * @brief Header du Driver pour gérer le haut-parleur connecté en USART avec ESP par Raspberry
 * @version 0.1
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __DriverHautPaleur__
#define __DriverHautPaleur__

#include <Arduino.h>

class Haut_Parleur
{
private:
    void Recevoir_ack_h_parleur(void);

public:
    void Lire_question(int no_question);
    void Mettre_musique_jeu(void);
    void Eteindre_musique_jeu(void);
    void Mettre_felication(void);
    void Mettre_dommage(void);
    void Mettre_merci(void);
    void Verifier_connexion(void);
    void Lancer_horloge(void);


};

#endif