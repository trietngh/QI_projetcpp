/**
 * @file Driver_Liste_Questions.h
 * @author TANG Huong Cam (hctang@insa-toulouse.fr)
 * @brief Header du Driver pour gérer la liste des questions de jeu IQ
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef Driver_Liste_Questions_h
#define Driver_Liste_Questions_h

/*-----------Include-------------*/
#include <iostream>
#include <map>
using namespace std;

/*-----------Exported Class----------*/

class Liste_questions
{
private:

/*-----------Private Class Liste_questions Attribut Declaration----------*/
    std::map <int,char> liste_des_question;
public:

    /*-----------Public Class Liste_questions Functions Definition----------*/

    /**
     * @brief Construct a new Liste_questions object
     * 
     * @param None
     */
    Liste_questions();

    /**
     * @brief Prendre une question dans la liste par hasard
     * 
     * @param nb_questions_posees 
     * @return int : numero de question
     */
    int random_question (int nb_questions_posees);

    /**
     * @brief Prendre la réponse de la question
     * 
     * @param no_question 
     * @return char : réponse de question
     */
    char recevoir_reponse (int no_question);
};


#endif