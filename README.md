# BE_Robot_Alphabot_L3PRO_2025

## Description
Projet : Aide au stationnement en marche arrière à l’aide de capteurs ultrasons (Arduino UNO). 

Ce projet vise à développer un système d’assistance au stationnement en marche arrière, basé sur un microcontrôleur Arduino UNO. Il combine trois éléments essentiels :   

- La génération de signaux PWM pour contrôler la vitesse des moteurs du Alphabot2-Ar (robot simulant un véhicule en recul).
- La mesure de distance en temps réel à l’aide d’un capteur ultrason HC-SR04. 
- Le clignotement d’une LED dont la fréquence varie en fonction de la distance détectée (plus la distance diminue, plus le clignotement s’accélère, avertissant ainsi le conducteur d’un obstacle proche).
     
L’ensemble du système illustre une intégration pratique de la modulation de largeur d’impulsion (PWM), de la détection de proximité et d’une interface visuelle simple pour une assistance intuitive en situation de recul. 

## Contenu du dépôt
- `code/` : Code source du projet  
- `include/` : Fichiers header
- `cpp/`: Fichiers cpp 
- `docs/` : Documentation et datasheets 
- `mesures/` : Observation et mesures au picoscope
- `simulation/` : Simulations sur proteus

## Installation
Exemple pour un projet Arduino :
1. Installer l’IDE Arduino  
2. Ouvrir le fichier `code/[...].ino` (inclure fichier .h et .cpp dans certains cas)
3. Compiler et téléverser sur la carte  

