/**
 * @file Driver_Haut_Parleur.h
 * @author Huong Cam TANG (hctang@insa-toulouse.fr)
 * @brief Header du Driver pour gérer le haut-parleur connecté en USART avec Raspberry par ESP
 * @version 0.1
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __DriverHautPaleur__
#define __DriverHautPaleur__

/*-----------Include-------------*/
#include <Arduino.h>


/*-----------Exported Class----------*/

class Haut_Parleur
{
private:
    /**
     * @brief Attendre le message de retour de haut_parleur
     * 
     * @param None
     */
    void Recevoir_ack_h_parleur(void);

public:

    /**
     * @brief Lire une question par le haut parleur
     * 
     * @param no_question 
     */
    void Lire_question(int no_question);

    /**
     * @brief Lancer la musique de jeu par le haut parleur
     * 
     * @param None 
     */   
    void Mettre_musique_jeu(void);
    void Eteindre_musique_jeu(void);

    /**
     * @brief Lancer la voix de felicitation par le haut parleur
     * 
     * @param None 
     */   
    void Mettre_felicitation(void);

    /**
     * @brief Lancer la voix de dommage par le haut parleur
     * 
     * @param None 
     */   
    void Mettre_dommage(void);

    /**
     * @brief Lancer la voix de merci par le haut parleur
     * 
     * @param None 
     */   
    void Mettre_merci(void);

    /**
     * @brief Lancer la musique à décompter par le haut parleur
     * 
     * @param None 
     */   
    void Lancer_horloge(void);


};

#endif