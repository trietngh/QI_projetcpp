# QI_projetcpp
Projet pour la matière C++ 4AESE INSA Toulouse: Machine de jeu à quiz qui récompense ou punit l'utilisateur selon la correction de sa réponse au quiz.

## Comment lancer la machine de jeu QI ?
- Compiler et télécharger le code du fichier jeu_IQ/jeu_IQ.ino pour ESP8266 avec Arduino IDE
- Télécharger le dossier Raspberry sur le Raspberry
- Assurer que le Raspberry est connecté à un haut parleur Bluetooth et la sortie du son est changé à celui ci
- Dans le dossier Raspberry, exécuter la ligne de code ci-dessous dans un terminal:
    `code`python application_rasp.py`code`


## Comment interagir avec la machine de jeu QI ?

- A l'écran d'acceuil
    + appuyer A pour lancer le jeu
    + appuyer B pour régler la position de servo

- Pendant le jeu 
    + un joueur joue 6 questions au maximum
    + tout d'abord, la machine lit la question
    + appuyer A ou B ou C correspond à la réponse pour la question pendant 3 secondes
    + si la réponse est faux : prendre une punition envoyé par le disque de punition
    + si la réponse est vrai : prendre une cadeau envoyé par le disque de cadeau
    + appuyer A pour continuer ou B pour quitter
    + si le joueur quitte : prendre une punition envoyé par le disque de punition

- Pendant le réglage de servo
    + appuyer A : tourner au sens d'horloge
    + appuyer B : tourner au sens d'anti-horloge
    + appuyer C : terminer le réglage
