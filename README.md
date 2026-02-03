# BE  Minirobot L3 pro

## L3 pro 2025 Instrumentation embarquée (≥150h)

Encadrant **:**   Thierry PERISSE

Etudiants : Marcelo FREIXA, Mathis FORET

Adresse mail :  [thierry.perisse@univ-tlse3.fr](mailto:thierry.perisse@univ-tlse3.fr)

Site web : http://thierryperisse.free.fr/

Pré-requis : les bases du langage C, les bases de l’électronique numériques, des notions de commandes de moteurs.

## **Objectifs de ce BE Bureau d'étude : (~150h)**

### ***Objectif 1*** :

- Apprendre à programmer un microcontrôleur afin de piloter un système embarqué (minirobot).

### ***Objectifs 2*** :

- Comprendre comment fonctionne un microcontrôleur.
- Développer ses propres bibliothèques pour interagir avec des nouveaux périphériques.

### Matériels :

***Cible choisie*** : Carte de développement Arduino UNO (microcontrôleur ATMega228p).

La documentation complète du microcontrôleur ATM328 est disponible [**ICI**](http://thierryperisse.free.fr/wp-content/uploads/2020/12/ATmega328P_Datasheet.pdf) (plusieurs centaines de pages).

**Système embarqué choisi :** Minirobot (AlphaBot2-Ar)

### Logiciels :

**Arduino** : Site web acceuil https://www.arduino.cc/

**Fritzing :** logiciel libre et gratuit (?) pour schématiser les montages : https://fritzing.org/

**Proteus** : logiciel de simulation de microcontrôleur (payant)

Dans toutes les solutions proposées, vous devrez fournir un schéma de câblage précis, en justifiant le choix du numéro des broches. Les codes devront comporter le moins d’instructions possible.

### Prise en main de la carte Arduino UNO et de l’IDE d’Arduino à l’aide de projets simples :

- **Projet 0 : Débuter avec Arduino** (programme exemple Blink)(LED BUILTIN)
    - Recherche programme exemple Blink
        
        ![](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/caad56fc-2cf1-4787-9ca7-1fa2f08082ba/Blink.png)
        
    - Choix de la carte cible (ici Arduino UNO)
        
        ![](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c1317004-a470-4f8c-ab07-e72d5af0477d/Untitled.png)
        
    - Choix du port COM
        
        ![](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/170ab9fa-0175-4ffd-8e6e-ca978af119c1/Untitled.png)
        
    - Vérifiez, Télécharger et tester le programme sur la carte UNO.
        
        Montrer que la LED clignote et mesurer à l’aide du PicoScope la fréquence et les temps à l’état haut Th et à l’état bas Tb.
        
        ```arduino
        void setup() {
          // initialize digital pin LED_BUILTIN as an output.
          pinMode(LED_BUILTIN, OUTPUT);
        }
        
        // the loop function runs over and over again forever
        void loop() {
          digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
          delay(1000);                      // wait for a second
          digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
          delay(1000);                      // wait for a second
        }
        ```
        
        ![IMG_20251203_134729.jpg](attachment:0086d255-7fd4-4862-8e72-9f21cdbe11fc:IMG_20251203_134729.jpg)
        
    - Mesurer à l’aide du PicoScope (T, F, Th, Tb).
        
        ![IMG_20251203_151535.jpg](attachment:8c83218c-e15a-4140-975f-4c8f9dbd6a60:IMG_20251203_151535.jpg)
        
        ![imagen.png](attachment:79efa5d3-0af9-436c-96d6-c1af12e28931:imagen.png)
        
        Les mesures du Picoscope donnent :
        
        - T (période) = 2,003 s
        - F (fréquence) = 499,2 mHz
        - Th (largeur d'impulsion haute) = 1,002 s (1002 ms)
        - Tf (largeur d'impulsion basse) = 1,001 s (1001 ms)
        
        Ceci correspond bien aux temps des états haut et bas choisis dans le code Arduino à l'aide de la fonction `delay(1000);`
        
- **Projet 1 : Faire clignoter une LED rouge** (externe à la carte)
    - Donner le schéma de câblage, choix de R.
        
        ![imagen.png](attachment:e0a0190c-9bd6-4daf-930b-859d95b4448e:imagen.png)
        
        ![IMG20251203141951.jpg](attachment:c2b9ef14-845e-43c4-81a7-2806ba1897c4:IMG20251203141951.jpg)
        
        LED borne positive connectée au PIN numérique 12 et borne négative à la masse (GND)
        
        **Choix de la résistance R:**
        
        Une LED rouge a une tension directe typique de 1,6 V à 2,0 V et fonctionne idéalement avec un courant de 10 mA à 20 mA.
        Les broches numériques de l'Arduino Uno délivrent 5 V en sortie (état HIGH). Une résistance R est donc placée en série avec la LED pour limiter le courant et protéger le composant.
        La valeur de R se détermine par la loi d'Ohm, en tenant compte de la tension à dissiper et du courant souhaité. 
        
        Un calcul simple permet de trouver une valeur de R adaptée:
        
        $$
        R = \frac{V_{\text{alim}} - V_{\text{LED}}}{I_{\text{LED}}} = \frac{5{,}0\ \text{V} - 2{,}0\ \text{V}}{I_{\text{LED}}} = \frac{3{,}0\ \text{V}}{I_{\text{LED}}}
        \quad \text{avec} \quad 10\ \text{mA} \leq I_{\text{LED}} \leq 20\ \text{mA}
        \quad \Rightarrow \quad 150\ \Omega \leq R \leq 300\ \Omega
        $$
        
        Pour maintenir un courant et un éclairage convenables, on délivrera un courant d'environ 15 mA :
        
        $$
        R = \frac{V_{\text{alim}} - V_{\text{LED}}}{I_{\text{LED}}} = \frac{5{,}0\ \text{V} - 2{,}0\ \text{V}}{15\ \text{mA}} = \frac{3{,}0\ \text{V}}{0{,}015\ \text{A}} = 200\ \Omega
        $$
        
        N'ayant pas de résistance de 200 Ω disponible, on choisit la valeur la plus proche : **R = 220 Ω.**
        
    
    - Validation du programme sur la carte.
        
        ```arduino
        #define LED 12
        
        void setup()
        {
          pinMode(LED, OUTPUT);
        }
        
        void loop()
        {  
        	digitalWrite(LED, HIGH);  
        	delay(1000);  
        	digitalWrite(LED, LOW);  
        	delay(1000);
        }
        
        ```
        
    - Quelle est la fréquence maximale possible ?
        
        La fréquence maximale du signal généré avec la fonction `delay()` dépend de la durée minimale que cette fonction peut atteindre.
        
        Dans l’environnement Arduino, la fonction `delay(t)` prend un argument exprimé en millisecondes (ms). La plus petite valeur non nulle utilisable est donc :
        
        $$
        t_{\min} = 1\,\text{ms} = 1 \times 10^{-3}\,\text{s}
        $$
        
        Pour un signal carré symétrique (50 % de rapport cyclique), une période complète T comprend un état haut et un état bas, chacun nécessitant un délai. Ainsi, la période minimale réalisable avec `delay(1)` est :
        
        $$
        T_{\min} = 2 \times t_{\min} = 2 \times 10^{-3}\,\text{s}
        $$
        
        La fréquence maximale correspondante est alors :
        
        $$
        f_{\max} = \frac{1}{T_{\min}} = \frac{1}{2 \times 10^{-3}} = 500\,\text{Hz}
        $$
        
- **Projet 1bis : Faire clignoter la LED (LED BUILTIN)** (sans fts Arduino)
    - Donner un programme et le commenter
        
        ```arduino
        // Exemple BLINK SANS FONCTION ARDUINO (sauf les fonctions temps)
        // LED <- PB5 : LED allumée quand PB5=1
        // testé le 15/12/2020
        
        void setup() {
                        // configurer broche PB5 en sortie
        DDRB |= 0x20;   // DDRB.5 <- 1
                        // ou DDRB|=B100000;  // parce que B100000 vaut 0x20
                        // ou DDRB|=32;       // parce que 0x20 vaut 32
        PORTB &= 0xDF;  // PORTB.5 <- 0
                        // ou DDRB&= ~0x20; 
                        // 0xDF est le complément de 0x20
        }
        
        void loop() {
        PORTB |= 0x20;  // PORTB.5 <- 1
        delay(200);     // 200 ms
        PORTB &= 0xDF;; // PORTB.5 <- 0
        delay(1000);    // 1s
        }
        ```
        
    - Quelle est la fréquence maximale possible ? Que pouvez vous en conclure ?
        
        La fréquence maximale possible est toujours limitée par la fonction `delay()`, donc on aura la même valeur trouvée précédemment : 500 Hz.
        
        L’optimisation au niveau des registres ne permet pas d’augmenter la fréquence si l’on continue d’utiliser `delay()`. Cela montre l’importance de choisir la bonne méthode de temporisation selon l’application. Pour atteindre des fréquences plus élevées, il faut abandonner `delay()` au profit de techniques plus fines, telles que :
        
        - L’utilisation de `delayMicroseconds()` ou `_delay_us()` si on descend au niveau des bibliothèques AVR, mais on sort alors de l’environnement Arduino.
        - De manière plus robuste et efficace, on utilisera la programmation des timers matériels du microcontrôleur, qui permettent de générer des signaux précis, à haute fréquence, sans bloquer le processeur, et ainsi exploiter au maximum la fréquence d’horloge de 16 MHz du ATmega328.
- **Projet 2** : **Gestion d'un bouton poussoir et d'une LED** (avec fcts Arduino)
    - Cahier des charges : LED ON quand BP OFF, LED OFF quand BP ON.
        
        Logigramme:
        
        ![imagen.png](attachment:b0028ce8-f575-4338-a63b-07e80d91f3b1:imagen.png)
        
    - Schéma de câblage, programme commenté et test expérimental.
        
        
        ```arduino
        
        // LED connecté au PIN 4
        // Bouton poussoir (BP) connecté au PIN 8
        #define LED 4 
        #define BP 8 
        
        void setup() 
        {
        	pinMode(LED, OUTPUT); // Configuration du PIN 4 en sortie
        	pinMode(BP, INPUT); // Configuartion du PIN 8 en entrée
        }
        void loop()
        { 
        	if(digitalRead(BP)== 1)  //  Si PIN 8 (BP) est à l'état haut
        	{    
        			digitalWrite(LED, LOW); // Ecrire sur PIN 4 (LED) état bas donc LED éteinte
        	} else     
        	{       
        		digitalWrite(LED, HIGH); // Sinon écrire sur PIN 4 (LED) état haut donc LED allumer
        	}
          
        }
        ```
        
        Choix des résistances :
        
        R_LED = 220 Ω
        
        R_BP = 1 kΩ
        
        La résistance de 1 kΩ maintient un état logique stable sur l'entrée (pull-down) et évite les lectures aléatoires dues aux parasites.
        
        ![IMG_20251203_161956.jpg](attachment:6000422d-2985-4fc7-83f7-5654c3aafb37:IMG_20251203_161956.jpg)
        
        ![IMG_20251203_162048.jpg](attachment:6ec2fd2c-056d-414c-9162-70bca5133a14:IMG_20251203_162048.jpg)
        
- **Projet 2bis** : **Gestion d'un bouton poussoir et d'une LED** (sans fts Arduino)
    - Cahier des charges : LED ON quand BP OFF, LED OFF quand BP ON.
        
        ![imagen.png](attachment:616dcd69-c13d-4c08-91bd-0cdd5165808b:imagen.png)
        
    - Schéma de câblage, programme commenté et test expérimental.
        
        ```arduino
        void setup() 
        { 
        	// Configure la broche PD4 (pin 4) en sortie
        	DDRD |= (1 << PD4); // OU bit à bit avec décalage (1 << 4) qui positionne le bit 4 à 1
        	                    // Équivalent : DDRD |= B00010000; (binaire, bit 4 = 1)
        	                    // Équivalent : DDRD |= 0x10; (hexadécimal, 0x10 = 16 = 2⁴)
        	
        	// Configure la broche PB0 (pin 8) en entrée
        	DDRB &= ~(1 << PB0); // ET bit à bit avec le complément de (1 << 0),
        	                     // ce qui force le bit 0 du registre DDRB à 0 (entrée)
        	                     // Équivalent : DDRB &= B11111110; (binaire, bit 0 = 0)
        	                     // Équivalent : DDRB &= 0xFE; (hexadécimal, 0xFE = 254)
        	
        	// PORTB |= (1 << PB0); // Décommenter cette ligne pour activer la résistance pull-up interne
        	                        // (si aucune résistance n'est câblée dans le circuit physique)
        }
        
        void loop()
        { 
        	// Si le bouton poussoir est appuyé (état haut)
        	if(PINB & (1 << PB0))  // ET bit à bit pour vérifier si PB0 est à 1
        	{    
        		PORTD &= ~(1 << PD4); // Éteindre la LED (forcer PD4 à 0)
        	} 
        	else // Bouton relâché
        	{      
        		PORTD |= (1 << PD4); // Allumer la LED (forcer PD4 à 1)
        	}
        }
        ```
        
- **Projet 3** : **Exemple d’utilisation de fonctions simples**
    - Cahier des charges : Si BP ON alors Clignotement rapide (100ms) sinon Clignotement lent (1s).
        
        ![imagen.png](attachment:59cd8031-9c02-4ee1-b088-80884bd0a64e:imagen.png)
        
    - Donner un programme clignote.ino avec l’utilisation de deux fonctions “clignote_rapide” et “clignote_lent” avec les fcs Arduino.
        
        ```arduino
        #define LED 4
        #define BP 8
        
        void clignote_rapide(); // Prototypage des fonctions de type void
        void clignote_lent();
        
        void setup() 
        {
          pinMode(LED, OUTPUT); // Configuration de la LED en sortie
          pinMode(BP, INPUT); // Configuration du bouton poussoir en entrée
        }
        
        void loop()
        {
          clignote_rapide(); // Appel de la fonction clignote_rapide
          clignote_lent(); // Appel de la fonction clignote_lent
        }
        
        void clignote_rapide() 
        {
          while(digitalRead(BP) == 1)  // Clignotement rapide si le bouton poussoir vaut 1 (état haut)
          {   
            digitalWrite(LED, HIGH);   
            delay(100);   
            digitalWrite(LED, LOW);   
            delay(100);
          } 
        }
        
        void clignote_lent() 
        {
          while(digitalRead(BP) == 0) // Clignotement lent si le bouton poussoir vaut 0 (état bas)
          {
            digitalWrite(LED, HIGH);   
            delay(1000);   
            digitalWrite(LED, LOW);    
            delay(1000);
          }
        }
        ```
        
    - Donner un programme clignote.ino avec l’utilisation de deux fonctions “clignote_rapide” et “clignote_lent” sans les fcs Arduino.
        
        ```arduino
        void setup() {
          DDRB |= (1 << PD4);
          DDRD &= ~(1 << PB0);
        }
        
        void loop() {
          clignote_rapide();
          clignote_lent();
        }
        
        void clignote_rapide() {
          while(PINB & (1 << PB0)) {
            PORTD |= (1 << PD4);
            delay(100);
            PORTD &= ~(1 << PD4);
            delay(100);
          }
        }
        
        void clignote_lent() {
          while(!(PINB & (1 << PB0))) { // <=> ((~PINB) & (1 << PB0))
            PORTD |= (1 << PD4);
            delay(1000);
            PORTD &= ~(1 << PD4);
            delay(1000);
          }
        }
        ```
        
        Version sans la fonction `delay()` en utilisant la fonction `millis()`  :
        
        ```arduino
        
        unsigned long temps_precedent = 0;
        unsigned int etat_led = 0;        // 0 = éteinte, 1 = allumée
        unsigned int clignotement = 0;     // 0 = lent, 1 = rapide
        
        void setup() {
          DDRD |= (1 << PD4);    // PD4 en sortie (LED)
          DDRB &= ~(1 << PB0);   // PB0 en entrée (bouton)
          // Si pull-up interne nécessaire : PORTB |= (1 << PB0);
        }
        
        void loop() {
          // Lire l'état du bouton : 1 si appuyé (suppose montage avec pull-down)
          unsigned int bouton_appuye = (PINB & (1 << PB0)) != 0;
          clignotement = bouton_appuye;
        
          unsigned long intervalle = clignotement ? 100UL : 1000UL; // en ms
        
          unsigned long temps_actuel = millis();
          
          if (temps_actuel - temps_precedent >= intervalle) {
            temps_precedent = temps_actuel;
            etat_led = 1 - etat_led; // Inverse l'état (0 ↔ 1)
        
            if (etat_led == 1) {
              PORTD |= (1 << PD4);   // Allumer la LED
            } else {
              PORTD &= ~(1 << PD4);  // Éteindre la LED
            }
          }
        }
        ```
        
- **Projet 3bis** : **Exemple d’utilisation de fonctions simples avec les fichiers .cpp et .h**
    - Cahier des charges identique : Si BP ON alors Clignotement rapide (100ms) sinon Clignotement lent (1s).
        
        
    - Donner un programme clignote.ino et les fichiers associés clignote.cpp et clignote.h avec les fcs Arduino.
        
        ```arduino
        //clignote.ino
        #include "clignote.h"
        
        void setup() 
        {
          pinMode(LED, OUTPUT);
          pinMode(BP, INPUT);
        }
        
        void loop()
        {
          clignote_rapide();
          clignote_lent();
        }
        ```
        
        ```arduino
        // clignote.h
        #ifndef CLIGNOTE_H
        #define CLIGNOTE_H
        
        #define LED PD4
        #define BP PB0
        
        // Déclaration des fonctions
        void clignote_rapide();
        void clignote_lent();
        
        #endif // CLIGNOTE_H
        ```
        
        ```arduino
        // clignote.cpp
        #include "clignote.h"
        #include <Arduino.h>
        
        void clignote_rapide() 
        {
          while(digitalRead(BP) == 1)  
          {   
            digitalWrite(LED, HIGH);   
            delay(100);   
            digitalWrite(LED, LOW);   
            delay(100);
          } 
        }
        
        void clignote_lent() 
        {
          while(digitalRead(BP) == 0) 
          {
            digitalWrite(LED, HIGH);   
            delay(1000);   
            digitalWrite(LED, LOW);    
            delay(1000);
          }
        }
        ```
        
    - Donner un programme clignote.ino et les fichiers associés clignote.cpp et clignote.h sans les fcs Arduino.
        
        ```arduino
        //clignote.ino
        #include "clignote.h"
        
        void setup() 
        {
          DDRD |= (1 << LED); // LED = PD4 (clignote.h)
          DDRB &= ~(1 << BP); // BP = PB0 (clignote.h)
        }
        
        void loop()
        {
          clignote_rapide();
          clignote_lent();
        }
        ```
        
        ```arduino
        // clignote.h
        #ifndef CLIGNOTE_H
        #define CLIGNOTE_H
        
        #define LED PD4
        #define BP PB0
        
        // Déclaration des fonctions
        void clignote_rapide();
        void clignote_lent();
        
        #endif // CLIGNOTE_H
        ```
        
        ```arduino
        // clignote.cpp
        #include "clignote.h"
        #include <Arduino.h>
        
        void clignote_rapide() {
            while (PINB & (1 << BP)) {          // Tant que le bouton est appuyé (état haut) => Lecture du bit de rang BP == PB0
                PORTD |= (1 << LED);            // Allumer la LED => Mise à 1 bit de rang LED == PD4
                delay(100);                     // Attendre 100 ms
                PORTD &= ~(1 << LED);           // Éteindre la LED => Mise à 0 bit de rang LED == PD4
                delay(100);                     // Attendre 100 ms
            }
        }
        
        void clignote_lent() {
            while (!(PINB & (1 << BP))) {       // Tant que le bouton est relâché (état bas) => Lecture du bit de rang BP == PB0
                PORTD |= (1 << LED);            // Allumer la LED => Mise à 1 bit de rang LED == PD4
                delay(1000);                    // Attendre 1 s
                PORTD &= ~(1 << LED);           // Éteindre la LED => Mise à 0 bit de rang LED == PD4
                delay(1000);                    // Attendre 1 s
            }
        }
        ```
        
- **Projet 4** : **Exemple simple d'utilisation de la librairie sérial** (affichage infos sur COM)
    - Tester le programme exemple suivant et commenter les lignes Serial.xxx
        
        ```arduino
        // Blink_Sérial
        
        void setup() {                
          pinMode(13, OUTPUT);   
          Serial.begin(9600);        // Initialise la communication série à 9600 bauds (vitesse de transmission)
          Serial.println("INIT");    // Envoie le message "INIT" sur le port série, suivi d'un retour à la ligne
        }
        
        void loop() {
          digitalWrite(13, HIGH);   
          Serial.println("LED ON");  // Envoie le message "LED ON" sur le port série (lorsque la LED est allumée)
          delay(1000);              
          digitalWrite(13, LOW);    
          Serial.println("LED OFF"); // Envoie le message "LED OFF" sur le port série (lorsque la LED est éteinte)
          delay(1000);              
        }
        ```
        
        ![imagen.png](attachment:3f869655-f62e-4ebc-bede-bd0a02ae580f:imagen.png)
        

### Mise en œuvre du capteur émetteur / récepteur US HC-SR04

- **Projet 5 : Génération du signal envoyé sur l’émetteur (cf doc composant)**
    - Comment choisir le signal ?       T, Th, F, Vmax, Vmin ?
        
        
        ![imagen.png](attachment:b2fc5312-b268-4e07-a514-9b9548fd235b:78597de7-8db5-42f1-adfc-353edce2ecfa.png)
        
        D'après les documents :
        
        - T = 60 ms pour laisser le temps d'une bonne lecture entre chaque mesure (measurement cycle selon la doc)
        - Th = correspond au Trigger Input Signal de type TTL de 10 µs pour déclencher le signal echo
        - F = 1/T ≈ 17 Hz
        - Vmax = 5 V
        - Vmin = 0 V
        
        ![imagen.png](attachment:39848508-93b2-464b-9e45-3eb7eca26117:imagen.png)
        
    - Schéma de câblage / Programme commenté / Validation expérimentale (mesures au picoscope)
        
        
        **Schéma de cablage dans le robot (Proteus):**
        
        ![imagen.png](attachment:4e7e208c-7424-44a6-a0d7-06dccbfa4821:imagen.png)
        
        **Cablage final pour un HC-SR04 (Echo=pin 4 et Trig=pin 5):**
        
        ![IMG_20251205_192349.jpg](attachment:4c5f902d-7629-4e4c-9f4b-197f5b577b60:IMG_20251205_192349.jpg)
        
        **Programmes commentés:**
        
        ```arduino
        //HC-SR04 du robot donc choix des pins obligatoire
        #define ECHO 2
        #define TRIG 3
        
        int Distance = 0;
        
        // Mesurer la distance
        int Distance_test() {
          digitalWrite(TRIG, LOW);          // Met la broche trig à LOW pendant 2μs
          delayMicroseconds(2);
          digitalWrite(TRIG, HIGH);         // Met la broche trig à HIGH pendant 10μs
          delayMicroseconds(10);
          digitalWrite(TRIG, LOW);          // Met la broche trig à LOW
          
          float Fdistance = pulseIn(ECHO, HIGH);  // Lit le temps à l'état haut de la broche echo (µs)
          Fdistance = Fdistance / 58;       // Calcul de la distance avec la formule de la doc
          return (int)Fdistance;
        }
        
        void setup() {
          Serial.begin(115200);
          pinMode(ECHO, INPUT);             // Définit la broche echo ultrason en entrée
          pinMode(TRIG, OUTPUT);            // Définit la broche trigger ultrason en sortie
        }
        
        void loop() {
          Distance = Distance_test();       // Affiche la distance
          
          if ((2 < Distance) && (Distance < 400)) {  // Plage ultrason : 2cm à 400cm
            Serial.print("Distance = ");
            Serial.print(Distance);
            Serial.println("cm");
          } else {
            Serial.println("!!! Hors de portée");
          }
          
          delay(250);
        }
        ```
        
        **Programme avec registres:**
        
        ```arduino
        
        // Programme avec registres
        // Broche D2 -> bit 2 du port D
        // Broche D3 -> bit 3 du port D
        
        #define ECHO   PD2   
        #define TRIG   PD3  
        
        void setup() {
          Serial.begin(115200);
        
          // Configuration des directions :
          DDRD &= ~(1 << ECHO);   // PD2 en entrée (ECHO)
          DDRD |=  (1 << TRIG);   // PD3 en sortie (TRIG)
        }
        
        int Distance_test() {
          // Envoi de l’impulsion TRIG (10 µs HIGH)
          PORTD &= ~(1 << TRIG);      // TRIG = 0
          _delay_us(2);
          PORTD |=  (1 << TRIG);      // TRIG = 1
          _delay_us(10);
          PORTD &= ~(1 << TRIG);      // TRIG = 0
        
          // Mesure du temps pendant lequel ECHO reste à 1
          unsigned long duration = 0;
        
          // Attente du front montant
          while (!(PIND & (1 << ECHO))) {}
        
          // Mesure pendant l’état HIGH
          unsigned long start = micros();
          while (PIND & (1 << ECHO)) {}
          unsigned long end = micros();
        
          duration = end - start;
        
          // Conversion en cm (durée / 58)
          float distance = duration / 58.0;
          return (int)distance;
        }
        
        void loop() {
          int Distance = Distance_test();
        
          if ((2 < Distance) && (Distance < 400)) {
            Serial.print("Distance = ");
            Serial.print(Distance);
            Serial.println(" cm");
          } else {
            Serial.println("Hors de portée!");
          }
        
          delay(250);
        }
        ```
        
        **Programme en utilisant .h et .cpp:**
        
        ```arduino
        
        #include "ultrasons.h"
        
        void setup ()
        {
          Serial.begin(115200);
        }
        
        void loop ()
        {
          int D = distance();
          Serial.print("Distance = ");
          Serial.print(D);
          Serial.println(" cm");
          delay(250);
        
        }
        ```
        
        ```arduino
        // .h
        
        #ifndef Ultrasons
        #define Ultrasons
        #include <Arduino.h>
        
        int distance();
        
        #endif
        ```
        
        ```arduino
        // .cpp
        
        #include "ultrasons.h"
        
        int distance() {
          // Envoi de l’impulsion TRIG (10 µs HIGH)
          DDRD |= (1 << DDD3);   // PD3 (TRIG) = sortie
          DDRD &= ~(1 << DDD2);  // PD2 (ECHO) = entrée (optionnel, mais clair)
        
          PORTD &= ~(1 << PD3);      // TRIG = 0
          _delay_us(2);
          PORTD |=  (1 << PD3);      // TRIG = 1
          _delay_us(10);
          PORTD &= ~(1 << PD3);      // TRIG = 0
        
          // Mesure du temps pendant lequel ECHO reste à 1
          unsigned long duration = 0;
        
          // Attente du front montant
          while (!(PIND & (1 << PD2))) {}
        
          // Mesure pendant l’état HIGH
          unsigned long start = micros();
          while (PIND & (1 << PD2)) {}
          unsigned long end = micros();
        
          duration = end - start;
        
          // Conversion en cm (durée / 58)
          float distance = duration / 58.0;
          return (int)distance;
        }
        ```
        
        **Mesure sur picoscope:**
        
        ![imagen.png](attachment:1f45c47c-c9e4-44ba-b5e8-234e6f1e2bf0:imagen.png)
        
        **Remarque :**
        
        On observe une impulsion de **13 µs** sur la broche Trig au lieu des **10 µs** attendus. Cette différence provient du temps d’exécution des fonctions Arduino (`digitalWrite()`, `delayMicroseconds()`), qui ajoutent quelques microsecondes de latence sur une carte comme l’Arduino Uno (ATmega328P à 16 MHz). La durée réelle du niveau haut inclut donc le délai demandé **plus** le surcoût des appels système.
        
- **Projet 6 : Récupération du signal issu du récepteur**
    - Visualiser le signal issu du récepteur au picoscope pour plusieurs distances, conclure ?
        
        
        **Distance 1:**
        
        ![imagen.png](attachment:97faaf14-14b7-4135-86ef-883c15808101:imagen.png)
        
        ⇒ Durée de l'état haut de echo : 8,946 ms
        
        ![imagen.png](attachment:4b8bf945-94e8-4d59-b7a5-b4fe157dcd5f:imagen.png)
        
        **Calcule de vérification:**
        
        **Démo de la formule:**
        
        $$
        d = \frac{v \cdot \Delta t}{2}
        = \frac{340~\text{m/s} \cdot (\Delta t \cdot 10^{-6}~\text{s})}{2}
        = \frac{34\,000~\text{cm/s} \cdot \Delta t \cdot 10^{-6}~\text{s}}{2}
        = \frac{34\,000 \cdot 10^{-6}}{2} \cdot \Delta t
        = 0.017 \cdot \Delta t
        \quad \Rightarrow \quad
        d~[\text{cm}] = \frac{\Delta t~[\mu\text{s}]}{58.8}
        \approx \frac{\Delta t~[\mu\text{s}]}{58}
        $$
        
        $$
        d~[\text{cm}] = \frac{\Delta t~[\mu\text{s}]}{58}
        = \frac{8.946 \times 10^{3}}{58}
        = \frac{8946}{58} \approx 154.2~\text{cm}
        $$
        
        ⇒ Cela correspond bien à la valeur affichée sur le serial port
        
    
    **Distance 2:**
    
    ![imagen.png](attachment:bc52bd35-14d5-46d4-a756-a611b8cbcb37:imagen.png)
    
    **Vérification par le calcul :**
    
    $$
    d~[\text{cm}] = \frac{\Delta t~[\mu\text{s}]}{58}
    = \frac{902.0}{58}
     \approx 15.5~\text{cm}
    $$
    
    **Distance 3:**
    
    ![imagen.png](attachment:7496e7bb-95ed-4ab8-8570-611a097c5e8b:imagen.png)
    
    **Vérification par le calcul :**
    
    $$
    d~[\text{cm}] = \frac{\Delta t~[\mu\text{s}]}{58}
    = \frac{233.0}{58}
     \approx 4.0~\text{cm}
    $$
    
    **Conclusion :** 
    
    On ne retrouve pas les mêmes valeurs car on affiche les valeurs en int, ce qui entraîne un arrondi ou une troncature. Dans notre cas, cela ne nous intéresse pas d'avoir une précision au millimètre près, qui nécessiterait un type float.
    

### Gestion des moteurs

- Projet 7 :  Génération d'une PWM —> Afin de piloter un moteur, générer à l’aide d’un Timer du micro-contrôleur un signal PWM de période T0 = 20ms et de rapport cyclique 7,5 %. Vérifier les caractéristiques de ce signal à l’aide du PicoScope.
    
    **Programme PWM avec Timer1:**
    
    ```arduino
    #define PWMA OCR1A
    #define TOP ICR1
    
    void setup() {
      // OC1A = PB1 (pin 9 sur Arduino Uno)
      DDRB |= (1 << DDB1);  // PB1 = OC1A en sortie
      
      // Broches de sens de rotation (PC0 et PC2)
      DDRC |= (1 << DDC0) | (1 << DDC2);
      
      // Mode Fast PWM, TOP = ICR1 (mode 14) (voir datasheet)
      TCCR1A = (1 << COM1A1) | (1 << WGM11);          // PWM non-inversé sur OC1A
      TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Prescaler = 8
      
      // Période = 20 ms → 50 Hz
      TOP = 39999;  // Valeur calculer dans les calculs dessous
      
      // Rapport cyclique = 7,5% 
      PWMA = TOP * 0.075;
      
      // Sens de rotation : avancer
      PORTC |= (1 << PC0);   // IN1 = HIGH
      PORTC &= ~(1 << PC2);  // IN2 = LOW
      
    }
    
    void loop() {
    }
    ```
    
    On rencontre un problème avec la génération du PWM pour piloter les moteurs sur l'AlphaBot2-AR : les deux moteurs sont câblés aux pins 5 et 6, manipulées par le Timer0. Or, le Timer0 ne possède que 8 bits [0–255]. Même en faisant varier le prescaler entre 1, 8, 64, 256 ou 1024, la fréquence de 50 Hz nécessaire pour obtenir une période T₀ = 20 ms ne sera jamais atteinte. 
    
    **On démontre cela d'après la formule du datasheet (page 80) :**
    
    ![imagen.png](attachment:28fd1427-cdb2-4b54-9a05-0c2050e42941:imagen.png)
    
    $$
    \begin{aligned}
    f_{\mathrm{PWM}} &= \frac{f_{\mathrm{clk}}}{N \cdot 256} = \frac{16000000}{1024 \cdot256} = 61\,\mathrm{Hz} \\
    T_{\mathrm{PWM}} &= \frac{1}{61} = 1{,}6 \times 10^{-2}\,\mathrm{s} = 16\,\mathrm{ms} \\
    T_0 &= 20\,\mathrm{ms} \\
    \Rightarrow\quad T_{\mathrm{PWM}} < T_0
    \end{aligned}
    $$
    
    **Solution :** utiliser le Timer1 codé en 16 bits, donc avec un intervalle de fréquences plus large.
    
    **On démontre cela d'après la formule du datasheet (page 103) :**
    
    ![imagen.png](attachment:112fec30-f3a2-4e3b-8ca0-9d690adea9b5:imagen.png)
    
    **Description des modes de génération des signaux (page 109) :**
    
    ![imagen.png](attachment:afa13ddc-bdea-4dca-84de-a431a123432b:imagen.png)
    
    $$
    \begin{aligned}
    f_{\mathrm{PWM}} &= \frac{f_{\mathrm{clk}}}{N  (1+TOP)} = \frac{16000000}{8(1 + ICR1) } =\frac{16000000}{8(1 + 39999 ) }= 50\,\mathrm{Hz} \\
    T_{\mathrm{PWM}} &= \frac{1}{50} = 2{,}0 \times 10^{-2}\,\mathrm{s} = 20\,\mathrm{ms} \\
    T_0 &= 20\,\mathrm{ms} \\
    \Rightarrow\quad T_{\mathrm{PWM}} = T_0
    \end{aligned}
    $$
    
    **Mesures au Picoscope:**
    
    ![imagen.png](attachment:7c4c45a3-92cb-43e7-b481-029fd73a9e43:imagen.png)
    
    **On observe les valeurs attendues avec le programme du début :**
    
    - **T0** = 20 ms
    - **Rapport cyclique** = 7,5%
    - **F0** = 50 Hz
    - **Etat haut** = 1,5 ms
- Projet 8 : Variation du rapport cyclique —> Ecrire un programme qui permet de faire varier la durée de l’état haut de ce signal de ± 5 % par rapport la valeur donnée ci-dessus. Vérifier les caractéristiques de ce signal à l’aide du PicoScope
    
    ```arduino
    #define PWMA OCR1A
    #define TOP ICR1
    
    void setup() {
    
      // OC1A = PB1 (pin 9 sur Arduino Uno)
      DDRB |= (1 << DDB1);  // PB1 = OC1A en sortie
      
      // Broches de sens de rotation (PC0 et PC2)
      DDRC |= (1 << DDC0) | (1 << DDC2);
      
      // Mode Fast PWM, TOP = ICR1 (mode 14) (voir datasheet)
      TCCR1A = (1 << COM1A1) | (1 << WGM11);          // PWM non-inversé sur OC1A
      TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Prescaler = 8
      
      // Période = 20 ms → 50 Hz
      TOP = 39999;  // Valeur calculer dans les calculs dessous
      
      // Sens de rotation : avancer
      PORTC |= (1 << PC0);   // IN1 = HIGH
      PORTC &= ~(1 << PC2);  // IN2 = LOW
      
    }
    
    void loop() {
    int i;
    for(i = TOP * 0.025; i <= TOP * 0.125; i++ )
    {
    	PWMA = i;
    	delay(2);
    }
    }
    ```
    

**Mesure du rapport cyclique avec variation de -5 % et durée à l'état haut :**

![imagen.png](attachment:37aaa3f3-1417-41c1-9a26-7555ec127526:imagen.png)

**Mesure du rapport cyclique sans variation et durée à l'état haut :**

![imagen.png](attachment:bfbfbd9b-3b7b-4de1-9152-5f0a8d38a4be:imagen.png)

**Mesure du rapport cyclique avec variation +5 % et durée à l'état haut :**

![imagen.png](attachment:e06f7e4e-10f3-4c7c-85bc-0a487b49f746:imagen.png)

- Projet 9 : Générer de deux signaux PWM indépendants qui permettrons de commander les 2 moteurs du robot
    
    ```arduino
    #define PWMA   6           //Pin Moteur gauche
    #define AIN2   A0          //Moteur gauche avance
    #define AIN1   A1          //Moteur gauche recul
    #define PWMB   5           //Pin Moteur droite
    #define BIN1   A2          //Moteur droite avance
    #define BIN2   A3          //Moteur droite recul
      
    void setup() {
    
    // Configurations des pins
      pinMode(PWMB,OUTPUT);                     
      pinMode(BIN2,OUTPUT);      
      pinMode(BIN1,OUTPUT);
      pinMode(PWMA,OUTPUT);                     
      pinMode(AIN2,OUTPUT);      
      pinMode(AIN1,OUTPUT);
      
    
    // Configuration rapport cyclique et direction
      analogWrite(PWMB,30);
      digitalWrite(BIN1,LOW);
      digitalWrite(BIN2,HIGH);
      
      analogWrite(PWMA,30);
      digitalWrite(AIN1,LOW);
      digitalWrite(AIN2,HIGH);
      delay(5000);        
      
     // Arreter les moteurs
      analogWrite(PWMB,0);
      digitalWrite(BIN1,LOW);
      digitalWrite(BIN2,LOW);
      
      analogWrite(PWMA,0);
      digitalWrite(AIN1,LOW);
      digitalWrite(AIN2,LOW);
    }
    
    void loop() {
    
    }
    ```
    
    **Code en registre et timers:**
    
    ```arduino
    #define PWMA OCR1A   // Moteur gauche
    #define PWMB OCR1B   // Moteur droit
    #define TOP  ICR1
    
    void setup() {
    
      // ===== PWM outputs =====
      DDRB |= (1 << DDB1) | (1 << DDB2);   // PB1 (OC1A / pin 9), PB2 (OC1B / pin 10)
    
      // ===== Direction pins =====
      DDRC |= (1 << DDC0) | (1 << DDC1) | (1 << DDC2) | (1 << DDC3);
    
      // ===== Timer1 : Fast PWM, TOP = ICR1 (mode 14) =====
      TCCR1A =
          (1 << COM1A1) |    // PWM non-inversé OC1A
          (1 << COM1B1) |    // PWM non-inversé OC1B
          (1 << WGM11);
    
      TCCR1B =
          (1 << WGM13) |
          (1 << WGM12) |
          (1 << CS11);       // Prescaler = 8
    
      // ===== Fréquence PWM =====
      // 16 MHz / 8 / 40000 = 50 Hz
      TOP = 39999;
    
      // ===== Vitesse initiale =====
      PWMA = TOP * 0.20;     // 20% moteur gauche
      PWMB = TOP * 0.20;     // 20% moteur droit
    
      // ===== Sens de rotation : AVANCER =====
      PORTC |=  (1 << PC0);  // IN1 gauche
      PORTC &= ~(1 << PC1);
    
      PORTC |=  (1 << PC3);  // IN2 droit
      PORTC &= ~(1 << PC2);
    
      delay(5000);
    
      // ===== Stop moteurs =====
      PWMA = 0;
      PWMB = 0;
    
      PORTC &= ~((1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3));
    }
    
    void loop() {
    }
    ```
    
    **PWM_moteurs fichier de type .h :**
    
    ```arduino
    #ifndef MOTEUR
    #define MOTEUR
    #include <Arduino.h>
    
    void pwm_moteurs(uint8_t a, uint8_t b, uint8_t c);  
    
    #endif
    ```
    
    **PWM_moteurs fichier de type .cpp :**
    
    ```arduino
    #include "pwm_moteurs.h"
    
    void pwm_moteurs(uint8_t a, uint8_t b, uint8_t c)
    {
      // Définir les pins 6 et 5 comme sorties 
      DDRD |= (1 << DDD6);  // PD6 = OC0A
      DDRD |= (1 << DDD5);  // PD5 = OC0B
    
      // Mettre à 1 les pins A0, A1, A2, A3 pour les définir comme sorties pour piloter le sens de rotation des moteurs
      DDRC |= (1 << DDC0);
      DDRC |= (1 << DDC1);
      DDRC |= (1 << DDC2);
      DDRC |= (1 << DDC3);
    
      // Configurer Timer0 for Fast PWM, non-inverting mode pour OC0A et OC0B
      TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
      TCCR0B = (1 << CS01) | (1 << CS00);  // Prescaler = 64
    
      // Rapport cyclique entre [0,255]
      OCR0A = a;  // ~20% de rapport cyclique pour le PD6 (Moteur gauche)
      OCR0B = b;  // ~20% de rapport cyclique pour le PD5 (Moteur droite)
    
      
      if(c == 1)
      {
      PORTC |= (1 << PC0);
      PORTC &= ~ (1 << PC2);
      PORTC &= ~(1 << PC1);
      PORTC |= (1 << PC3);
      }
      else if( c == 0)
      {
      PORTC &= ~ (1 << PC0);
      PORTC |= (1 << PC2);
      PORTC |= (1 << PC1);
      PORTC &= ~(1 << PC3);
      }
    }
    ```
    

### Gestion du Minirobot (AlphaBot2-Ar)

- Projet 10 : Déplacement en ligne droite
    - Câbler l’ensemble E/R US et commande des 2 moteurs
    - Ecrire un programme qui permet de gérer le déplacement en ligne droite d’un robot (prévoir rails ou autres), attention il faudra arrêter le robot si un obstacle est présent à une distance de 10cm.
        
        **Programme simple avec fonctions arduino:**
        
        ```arduino
        // --- Définition des broches du robot ---
        #define PWMA   6           // PWM moteur gauche (ENA)
        #define AIN2   A0          // Moteur gauche - avant (IN2)
        #define AIN1   A1          // Moteur gauche - arrière (IN1)
        #define PWMB   5           // PWM moteur droit (ENB)
        #define BIN1   A2          // Moteur droit - avant (IN3)
        #define BIN2   A3          // Moteur droit - arrière (IN4)
        
        #define ECHO   2           // Capteur ultrason - Echo
        #define TRIG   3           // Capteur ultrason - Trigger
        
        // --- Variables globales ---
        int distanceObstacle = 0;
        int vitesseDroite = 70;
        int vitesseGauche = 70;
        
        // --- Prototypes des fonctions ---
        int mesurerDistance();
        void avancer();
        void reculer();
        void tournerDroite();
        void tournerGauche();
        void arreter();
        
        void setup()
        {
          Serial.begin(115200);
          Serial.println("Exemple : évitement d'obstacle par capteur ultrason");
        
          // Configuration du capteur ultrason
          pinMode(ECHO, INPUT);
          pinMode(TRIG, OUTPUT);
        
          // Configuration des moteurs
          pinMode(PWMA, OUTPUT);
          pinMode(AIN2, OUTPUT);
          pinMode(AIN1, OUTPUT);
          pinMode(PWMB, OUTPUT);
        
          analogWrite(PWMA, vitesseGauche);
          analogWrite(PWMB, vitesseDroite);
        
          arreter(); // Robot à l’arrêt au démarrage
        }
        
        void loop()
        {
          // Mesure de la distance
          distanceObstacle = mesurerDistance();
          
          Serial.print("Distance = ");
          Serial.print(distanceObstacle);
          Serial.println(" cm");
        
          // Si un obstacle est à moins de 10 cm → éviter
          if(distanceObstacle <= 10)
          {
            arreter();
            //delay(100);
        
            //tournerDroite();
            // tournerGauche();   // Alternative possible
            //delay(500);
          }
          else
          {
            avancer();
          }
        
          delay(70);
        }
        
        // --- Fonction de mesure de distance ultrason ---
        int mesurerDistance()
        {
          digitalWrite(TRIG, LOW);
          delayMicroseconds(2);
        
          digitalWrite(TRIG, HIGH);  // Impulsion de 10 us
          delayMicroseconds(10);
        
          digitalWrite(TRIG, LOW);
        
          float tempsEcho = pulseIn(ECHO, HIGH);
          float distance = tempsEcho / 58.0;  // Conversion en cm
        
          return (int)distance;
        }
        
        void arreter()
        {
          analogWrite(PWMA, 0);
          analogWrite(PWMB, 0);
        
          digitalWrite(AIN1, LOW);
          digitalWrite(AIN2, LOW);
          digitalWrite(BIN1, LOW);
          digitalWrite(BIN2, LOW);
        }
        ```
        
        **Programme sans fonctions Arduino en utilisant nos bibliothèques :**
        
        ```arduino
        #include <Arduino.h>
        #include "pwm_moteurs.h"
        #include "ultrasons.h"
        
        void setup()
        {  
        }
        
        void loop()
        {  
        	int d = distance();   
        	if (d <= 10)  
         { 
        	  pwm_moteurs(0,0,1); 
            delay(100);  
         }  
          else 
         {    
        	  pwm_moteurs(50,50,1); 
         }   
            delay(70);
            
        }
        
        ```
        
        **Test de déplacement en ligne droite et arrêt à 10 cm :**
        
        [VID20260129184201.mp4](attachment:bd137448-37d8-474c-90f8-b1e42ed91ace:VID20260129184201.mp4)
        

- Projet 11 : Suiveur de ligne
    - Expliquer le fonctionnement des cinq capteurs présents sur le minirobot constitués chacun d’une LED (émetteur) et et d’un photo-transistor (récepteur).
        
        **Fonctionnement capteurs infrarouges:**
        
        ![image.png](attachment:88b45ba7-c2f7-493c-ad6a-1b940f3e4026:image.png)
        
        ## **Selon la doc du ITR20001/T:**
        
        L'ITR20001/T est composé d'une diode électroluminescente infrarouge (IR) et d'un phototransistor NPN en silicium, placés côte à côte dans un boîtier thermoplastique noir avec des axes optiques convergents. En fonctionnement normal, le phototransistor reçoit uniquement le rayonnement provenant directement de la diode infrarouge. Lorsqu'un objet réfléchissant s'approche du capteur, le phototransistor détecte également le rayonnement infrarouge réfléchi par cet objet.
        
        ### **Caractéristiques techniques essentielles (doc dans la section liens utiles)**
        
        ### **1. Composition**
        
        - **Émetteur** : Diode IR en GaAlAs (Arséniure d’Aluminium-Gallium), λₚ = 940 nm, lentille transparente.
        - **Récepteur** : Phototransistor NPN en silicium, encapsulé sous lentille noire (filtre visible).
        - **Disposition** : Les deux composants sont côte à côte, axes optiques convergents, dans un boîtier thermoplastique noir (bloque la lumière parasite).
        
        ### **2. Fonctionnement**
        
        - **En l’absence d’objet** : le phototransistor ne reçoit aucune lumière réfléchie → courant de collecteur très faible (*IC(OFF) ≤ 2 µA* à VCE = 5 V, IF = 20 mA).
        - **En présence d’un objet réfléchissant à proximité** : le rayonnement IR est renvoyé vers le phototransistor, générant un courant de collecteur typique de ≥ 200 µA (*IC(ON)* dans les mêmes conditions).
        - **Temps de réponse** : tr = tf = 25 µs (montée et descente), ce qui permet une détection rapide pour des applications dynamiques (robot roulant à vitesse modérée).
        
        ### **3. Caractéristiques électriques et physiques**
        
        | Paramètre | Valeur typique / max |
        | --- | --- |
        | Tension directe IR (VF) | 1,2 V (à IF = 20 mA) |
        | Longueur d’onde crête (λₚ) | 940 nm |
        | Courant direct max (IF) | 50 mA |
        | Courant de collecteur max (IC) | 20 mA |
        | VCE(sat) | ≤ 0,4 V (à IC = 2 mA, éclairement = 1 mW/cm²) |
        | Courant d’obscurité (ICEO) | ≤ 100 nA (à VCE = 5 V, pas d’éclairement) |
        
        ### **4. Température de fonctionnement**
        
        - **Topr** : –40 °C à +85 °C → adapté aux environnements intérieurs variés.
        
        ### **5. Applications recommandées par le fabricant**
        
        - Souris optiques
        - Scanners / copieurs
        - Pilotes de disquettes
        - Commutation sans contact (*Non-contact switching*) → très pertinent pour la détection de ligne ou d’obstacles sur un robot mobile.
        
        ### Pertinence pour **Alphabot2-AR**
        
        Le capteur ITR20001/T est idéal pour :
        
        - **Le suivi de ligne** : contraste élevé entre surface noire (absorption IR → faible IC) et surface claire (réflexion IR → IC élevé).
        - **Détection d’obstacles proches** (quelques mm à 2–3 cm, selon réflectivité).
        - **Intégration embarquée** : faible encombrement, faible consommation, interface simple (résistance de pull-up suffisante pour sortie numérique).
        - **Robustesse** : le boîtier noir + λ = 940 nm (hors spectre visible) réduit fortement les interférences lumineuses ambiante.
    - Donner un algorithme et un programme pour la gestion des moteurs en utilisant 2 capteurs.
        
        **Choix des capteurs:**
        
        Puisque nous utilisons seulement 2 capteurs sur les 5 disponibles, nous choisissons judicieusement le capteur le plus à gauche et le plus à droite du robot. De cette manière, nous pourrons déterminer la couleur du terrain de chaque bord du robot pour piloter correctement sa trajectoire en suivant un chemin avec une couleur spécifique.
        
        En respectant la notation du constructeur, on a comme capteur à gauche le IR1 et à droite le IR5.
        
        **Algorithme :**
        
        ```
        // Algorithme
        
        Début
            Initialiser les broches des capteurs (gauche, droite) en entrée
            Initialiser les broches de commande des moteurs
            
            Tant que vrai :
                Lire état_capteur_gauche
                Lire état_capteur_droite
                
                Si (capteur_gauche == BLANC) ET (capteur_droite == BLANC) :
                    // Sur la ligne → avancer tout droit
                    Moteur_gauche : AVANT
                    Moteur_droite : AVANT
                    
                Sinon si (capteur_gauche == NOIR) ET (capteur_droite == BLANC) :
                    // Ligne à gauche → tourner à droite
                    Moteur_gauche : AVANT
                    Moteur_droite : ARRET 
                    
                Sinon si (capteur_gauche == BLANC) ET (capteur_droite == NOIR) :
                    // Ligne à droite → tourner à gauche
                    Moteur_gauche : ARRET 
                    Moteur_droite : AVANT
                    
                Sinon si (capteur_gauche == NOIR) ET (capteur_droite == NOIR) :
                    // Intersection ou arrêt → s'arrêter
                    Moteur_gauche : ARRET
                    Moteur_droite : ARRET
                    
                FinSi
            FinTantQue
        Fin
        
        ```
        
        **Logigramme:**
        
        ```mermaid
        flowchart TD
            subgraph Init
                A([Debut]) --> B[Initialiser capteurs Gauche et Droit en entree]
                B --> C[Initialiser commandes moteurs]
            end
        
            subgraph Lecture
                C --> D[Lire capteur gauche]
                D --> E[Lire capteur droit]
            end
        
            subgraph Decisions
                E --> F{G=BLANC et D=BLANC ?}
                F -- Oui --> G[AVANCER TOUT DROIT]
                F -- Non --> H{G=NOIR et D=BLANC ?}
                H -- Oui --> I[TOURNER A DROITE]
                H -- Non --> J{G=BLANC et D=NOIR ?}
                J -- Oui --> K[TOURNER A GAUCHE]
                J -- Non --> L{G=NOIR et D=NOIR ?}
                L -- Oui --> M[ARRET COMPLET]
                L -- Non --> N[Boucle]
            end
        
            G --> N
            I --> N
            K --> N
            M --> N
            N --> D
        
        ```
        
        **TLC1543 CAN 10 bit :**
        
        ![image.png](attachment:f2b33940-df49-46de-914f-a2195606f0c0:image.png)
        
    
    ```arduino
    #include "TRSensors.h"
    
    #define PWMA   6
    #define AIN2   A0
    #define AIN1   A1
    #define PWMB   5
    #define BIN1   A2
    #define BIN2   A3
    
    #define NUM_SENSORS 5
    #define VITESSE 50
    #define SEUIL 600   // à ajuster après test
    
    TRSensors trs;
    unsigned int sensorValues[NUM_SENSORS];
    
    void avancer() {
      digitalWrite(AIN1, LOW);  digitalWrite(AIN2, HIGH);
      digitalWrite(BIN1, LOW);  digitalWrite(BIN2, HIGH);
      analogWrite(PWMA, VITESSE);
      analogWrite(PWMB, VITESSE);
    }
    
    void tournerGauche() {
      digitalWrite(AIN1, LOW);  digitalWrite(AIN2, LOW);
      digitalWrite(BIN1, LOW);  digitalWrite(BIN2, HIGH);
      analogWrite(PWMA, 0);
      analogWrite(PWMB, VITESSE);
    }
    
    void tournerDroite() {
      digitalWrite(AIN1, LOW);  digitalWrite(AIN2, HIGH);
      digitalWrite(BIN1, LOW);  digitalWrite(BIN2, LOW);
      analogWrite(PWMA, VITESSE);
      analogWrite(PWMB, 0);
    }
    
    void arret() {
      analogWrite(PWMA, 0);
      analogWrite(PWMB, 0);
    }
    
    void setup() {
      pinMode(PWMA, OUTPUT);
      pinMode(AIN1, OUTPUT);
      pinMode(AIN2, OUTPUT);
      pinMode(PWMB, OUTPUT);
      pinMode(BIN1, OUTPUT);
      pinMode(BIN2, OUTPUT);
    
      Serial.begin(9600);
    
      
    
      // Calibration
      for (int i = 0; i < 100; i++) {
        trs.calibrate();
        delay(20);
      }
    }
    
    void loop() {
      trs.readLine(sensorValues);
    
      int g = sensorValues[0]; // IR1
      int d = sensorValues[4]; // IR5
    
      bool noirG = g > SEUIL;
      bool noirD = d > SEUIL;
    
      Serial.print(g);
      Serial.print(" | ");
      Serial.println(d);
    
      if (!noirG && !noirD) {
        avancer();
      }
      else if (noirG && !noirD) {
        tournerGauche();
      }
      else if (!noirG && noirD) {
        tournerDroite();
      }
      else {
        arret();
      }
    
      delay(10);
    
    ```
    
    **Premiers tests de suivi de ligne avec deux capteurs et des fonctions pour ajuster la direction :**
    
    [VID20251226170744.mp4](attachment:27d09c8f-d176-4436-9c54-294c967f6d7b:VID20251226170744.mp4)
    
    - Suivre une ligne avec 3 capteurs : algorithme / programme commenté / tests
        
        ```arduino
        #include "TRSensors.h"
        
        #define PWMA   6
        #define AIN2   A0
        #define AIN1   A1
        #define PWMB   5
        #define BIN1   A2
        #define BIN2   A3
        
        #define NUM_SENSORS 5
        #define VITESSE_BASE 60
        #define KP 0.04
        
        TRSensors trs;
        unsigned int sensorValues[NUM_SENSORS];
        
        void setup() {
          pinMode(PWMA, OUTPUT);
          pinMode(AIN1, OUTPUT);
          pinMode(AIN2, OUTPUT);
          pinMode(PWMB, OUTPUT);
          pinMode(BIN1, OUTPUT);
          pinMode(BIN2, OUTPUT);
        
          delay(2000); // temps pour placer le robot
        
          // Calibration (BOUGER le robot à la main)
          for (int i = 0; i < 100; i++) {
            trs.calibrate();
            delay(20);
          }
        }
        
        void loop() {
          trs.readLine(sensorValues);
        
          int g = sensorValues[0];
          int m = sensorValues[2];
          int d = sensorValues[4];
        
          int somme = g + m + d;
        
          int erreur = 0;
          if (somme > 0) {
            erreur = (-1000 * g + 0 * m + 1000 * d) / somme;
          }
        
          int correction = KP * erreur;
        
          // limiter les réactions trop violentes
          correction = constrain(correction, -40, 40);
        
          int vitesseG = VITESSE_BASE + correction;
          int vitesseD = VITESSE_BASE - correction;
        
          vitesseG = constrain(vitesseG, 20, 255);
          vitesseD = constrain(vitesseD, 20, 255);
        
          // moteurs en avant
          digitalWrite(AIN1, LOW);
          digitalWrite(AIN2, HIGH);
          digitalWrite(BIN1, LOW);
          digitalWrite(BIN2, HIGH);
        
          analogWrite(PWMA, vitesseG);
          analogWrite(PWMB, vitesseD);
        
          delay(5);
        }
        
        ```
        
        **Explication du code:**
        
        Le robot utilise trois capteurs infrarouges pour suivre une ligne noire. L'erreur est calculée par une moyenne pondérée des capteurs : 
        
          $erreur = (−1000 × capteur\ gauche + 0 × capteur\ milieu + 1000 × capteur\ droite) / somme\ des\ valeurs$
        
        Cette erreur est multipliée par un gain proportionnel KP pour obtenir la correction appliquée aux moteurs. La correction est limitée entre −40 et 40: `correction = constrain(correction, -40, 40);` afin d'éviter des réactions trop brutales et des oscillations. Sans les termes intégral (I) et dérivé (D) du PID, le robot ne peut pas compenser les biais persistants ni anticiper les changements rapides , la commande reste purement proportionnelle. La vitesse de chaque moteur est ajustée par cette correction autour d'une vitesse de base, puis contrainte aux limites des moteurs. Cette approche permet au robot de tourner progressivement vers la ligne et de la suivre de manière stable. On va chercher un correcteur plus robuste en utilisant les trois termes du PID.
        
        **Estimation de la position de la ligne par la fonction `readLine()`:**
        
        Le robot est équipé de cinq capteurs infrarouges disposés linéairement à l'avant. Chaque capteur mesure la réflectance du sol : une surface noire (la ligne) absorbe la lumière infrarouge et produit une valeur faible, tandis qu'une surface blanche renvoie davantage de lumière et produit une valeur élevée. Après calibration, chaque capteur fournit une valeur analogique comprise entre 0 (noir) et 1000 (blanc).
        
        La fonction `readLine()` estime la position latérale continue de la ligne par rapport à l'axe du robot. Chaque capteur possède une position géométrique fixe $Pi = i × 1000$, définissant une échelle normalisée de 0 à 4000 pour les cinq capteurs. Pour privilégier les capteurs qui détectent la ligne, les valeurs mesurées sont transformées en poids inverses $Wi = Smax − Si$, donnant plus d'importance aux capteurs situés au-dessus de la ligne noire.
        
        La position de la ligne est calculée par une moyenne pondérée :
        
        $$
        \text{position} = \frac{\sum_{i=0}^{4} W_i \cdot P_i}{\sum_{i=0}^{4} W_i}
        
        $$
        
        Cette méthode fournit une estimation continue et interpolée de la position de la ligne, même lorsqu'elle se situe entre deux capteurs. La valeur retournée par `readLine()` sert à calculer l'erreur de position par rapport au centre du robot. Elle constitue l'entrée du correcteur PID, garantissant un suivi de ligne fluide et stable.
        
        **Role du PID:**
        
        La position mesurée par `readLine()` est ensuite comparée à la position idéale au centre du robot (2000) pour calculer l’erreur : 
        
           $erreur = position - position\ ideale$. 
        
        Le correcteur PID transforme cette erreur en correction appliquée aux moteurs. La correction est la somme de trois termes :
        
         $P = Kp × erreur$ 
        
        $I = intégrale\ cumulée\ des \ erreurs$
        
         $D = Kd × (erreur - erreur\ précédente)$. 
        
        Le terme P corrige directement l’écart actuel, le terme I compense les erreurs persistantes dues aux imperfections du robot ou des moteurs, et le terme D anticipe la variation de l’erreur pour stabiliser la trajectoire et limiter les oscillations.
        
        Enfin, la correction est utilisée pour ajuster la vitesse relative des moteurs : si la correction est positive, le moteur gauche tourne à vitesse maximale et le moteur droit est réduit de la valeur de la correction ; si la correction est négative, le moteur droit reste à vitesse maximale et le moteur gauche est réduit de la valeur absolue de la correction. Cette approche permet au robot de tourner progressivement vers la ligne et d’assurer un suivi fluide et précis.
        
        **Commande des moteurs:**
        
        Le PID transforme l'erreur de position de la ligne en **commande moteur proportionnelle**, ajustant la vitesse relative des deux roues pour corriger la trajectoire. La sortie du PID, appelée **correction**, correspond à la différence de vitesse appliquée entre les moteurs gauche et droit. Plus l'erreur est grande, plus la correction est importante, ce qui augmente la différence de PWM et provoque un virage plus prononcé vers la ligne.
        
        - Le **terme proportionnel (P)** agit directement sur l'écart instantané. Si la ligne est à gauche, le PWM du moteur gauche diminue et celui du moteur droit augmente, entraînant une rotation vers la ligne.
        - Le **terme intégral (I)** compense les biais persistants dus à des moteurs légèrement différents ou à un robot asymétrique. Il ajuste progressivement les PWM pour atteindre la ligne idéale.
        - Le **terme dérivé (D)** anticipe les variations rapides de l'erreur et réduit les oscillations. Il ajuste les PWM plus rapidement lors d'un virage serré.
        
        Ainsi, le PID ne modifie pas directement la position du robot, mais **contrôle les PWM des moteurs** pour que le robot converge vers la ligne de manière stable, fluide et proportionnelle à l'écart détecté par les capteurs.
        
        **Tests de fonctionnement avec 3 capteurs et un correcteur PID :**
        
        [VID20251226174230.mp4](attachment:bfdec515-cbbe-442a-b90e-4c922a422085:VID20251226174230.mp4)
        
    
    **Programme suiveur de ligne avec fonctions arduino et 5 capteurs:**
    
    ```arduino
    #include "TRSensors.h"
    
    #define PWMA   6           
    #define AIN2   A0          
    #define AIN1   A1          
    #define PWMB   5           
    #define BIN1   A2          
    #define BIN2   A3          
    #define NUM_SENSORS 5
    
    TRSensors trs = TRSensors();
    unsigned int sensorValues[NUM_SENSORS];
    unsigned int last_proportional = 0;
    unsigned int position;
    long integral = 0;
    
    void setup() {
      Serial.begin(115200);
      
    
      pinMode(PWMA, OUTPUT);                     
      pinMode(AIN2, OUTPUT);      
      pinMode(AIN1, OUTPUT);
      pinMode(PWMB, OUTPUT);       
      pinMode(BIN1, OUTPUT);     
      pinMode(BIN2, OUTPUT);  
      
     
      digitalWrite(AIN2, HIGH);
      digitalWrite(AIN1, LOW);
      digitalWrite(BIN1, HIGH); 
      digitalWrite(BIN2, LOW);
      
     
      analogWrite(PWMA, 0);
      analogWrite(PWMB, 0);
      
      Serial.println("Calibrating sensors...");
      delay(500);
      
      
      analogWrite(PWMA, 40);
      analogWrite(PWMB, 40);
      
      for (int i = 0; i < 100; i++) {
        
        if (i < 25 || i >= 75) {
          digitalWrite(AIN1, HIGH);
          digitalWrite(AIN2, LOW);
          digitalWrite(BIN1, LOW); 
          digitalWrite(BIN2, HIGH);  
        }
        
        else {
          digitalWrite(AIN1, LOW);
          digitalWrite(AIN2, HIGH);
          digitalWrite(BIN1, HIGH); 
          digitalWrite(BIN2, LOW);  
        }
        trs.calibrate();
        delay(20);
      }
      
      
      analogWrite(PWMA, 0);
      analogWrite(PWMB, 0);
      
      Serial.println("Calibration complete!");
      delay(1000);
      
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, HIGH);
      digitalWrite(BIN1, LOW); 
      digitalWrite(BIN2, HIGH);
    }
    
    void loop() {
      
      position = trs.readLine(sensorValues);
      
      
      for (unsigned char i = 0; i < NUM_SENSORS; i++) {
        Serial.print(sensorValues[i]);
        Serial.print('\t');
      }
      Serial.println(position);
      
      
      int proportional = (int)position - 2000;
      
      
      int derivative = proportional - last_proportional;
      integral += proportional;
      last_proportional = proportional;
      
      
      int power_difference = proportional/20 + integral/10000 + derivative*10;
      
    
      const int maximum = 100;
      if (power_difference > maximum)
        power_difference = maximum;
      if (power_difference < -maximum)
        power_difference = -maximum;
      
      
      if (power_difference < 0) {
        
        analogWrite(PWMA, maximum + power_difference);
        analogWrite(PWMB, maximum);
      }
      else {
        
        analogWrite(PWMA, maximum);
        analogWrite(PWMB, maximum - power_difference);
      }
      
      
      if (sensorValues[1] > 900 && sensorValues[2] > 900 && sensorValues[3] > 900) {
        analogWrite(PWMA, 0);
        analogWrite(PWMB, 0);
        Serial.println("Line lost - stopping!");
      }
    }
    ```
    
    **Programme suiveur de ligne avec gestion des moteurs en registres:**
    
    ```arduino
    #include "TRSensors.h"
    #include "pwm_moteurs.h"
    
    #define NUM_SENSORS 5
    
    TRSensors trs = TRSensors();
    unsigned int sensorValues[NUM_SENSORS];
    unsigned int last_proportional = 0;
    unsigned int position;
    long integral = 0;
    
    void setup() {
      Serial.begin(115200);
      
      // Initialisation du PWM et des directions (sera faite dans pwm_moteurs)
      // On arrête les moteurs au départ
      pwm_moteurs(0, 0, 1); // a=0, b=0, avancer (mais vitesse nulle)
    
      Serial.println("Calibrating sensors...");
      delay(500);
    
      // Calibration : on fait tourner les moteurs lentement en alternant sens
      for (int i = 0; i < 100; i++) {
        if (i < 25 || i >= 75) {
          
          pwm_moteurs(40, 40, 0); 
        } else {
          pwm_moteurs(40, 40, 1); 
        }
        trs.calibrate();
        delay(20);
      }
    
      pwm_moteurs(0, 0, 1); // arrêt
      Serial.println("Calibration complete!");
      delay(1000);
    }
    
    void loop() {
      position = trs.readLine(sensorValues);
    
      // Affichage debug
      for (unsigned char i = 0; i < NUM_SENSORS; i++) {
        Serial.print(sensorValues[i]);
        Serial.print('\t');
      }
      Serial.println(position);
    
      // Détection perte de ligne
      if (sensorValues[1] > 900 && sensorValues[2] > 900 && sensorValues[3] > 900) {
        pwm_moteurs(0, 0, 1); // arrêt
        Serial.println("Line lost - stopping!");
        return;
      }
    
      // Calcul PID
      int proportional = (int)position - 2000;
      int derivative = proportional - last_proportional;
      integral += proportional;
      last_proportional = proportional;
    
      int power_difference = proportional / 20 + integral / 10000 + derivative * 10;
    
      const int MAX_PWM = 100; // Valeur max pour OCR0A/OCR0B (0–255, mais 100 = ~40%)
      if (power_difference > MAX_PWM) power_difference = MAX_PWM;
      if (power_difference < -MAX_PWM) power_difference = -MAX_PWM;
    
      uint8_t left_pwm, right_pwm;
    
      if (power_difference < 0) {
        // Tourner à gauche : réduire vitesse gauche
        left_pwm  = MAX_PWM + power_difference;  // power_difference est négatif
        right_pwm = MAX_PWM;
      } else {
        // Tourner à droite : réduire vitesse droite
        left_pwm  = MAX_PWM;
        right_pwm = MAX_PWM - power_difference;
      }
    
      // Appliquer les vitesses (toujours en AVANT)
      pwm_moteurs(left_pwm, right_pwm, 1);
    }
    ```
    
    **Test de fonctionnement suiveur de ligne avec PID amelioré:**
    
    On remarque un fonctionnement correct, mais lors des virages prononcés, le robot a tendance à osciller pour rétablir sa position souhaitée. Il faudra corriger la fonction `pwm_moteurs` et retravailler le PID.
    
    **Amélioration de la bibliothèque pwm_moteurs et PID :**
    
    ```arduino
    #ifndef MOTEUR
    #define MOTEUR
    #include <Arduino.h>
    
    void pwm_init();
    void pwm_moteurs(uint8_t a, uint8_t b, uint8_t c);  
    
    #endif
    ```
    
    ```arduino
    #include "pwm_moteurs.h"
    
    void pwm_init() {
        // PWM pins
        DDRD |= (1 << DDD6) | (1 << DDD5);  // PD6 = OC0A, PD5 = OC0B
    
        // Direction pins
        DDRC |= (1 << DDC0) | (1 << DDC1) | (1 << DDC2) | (1 << DDC3);
    
        // Timer0 Fast PWM, non-inverting
        TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
        TCCR0B = (1 << CS01); // prescaler = 8 → ~7.8 kHz
    
        // Stop moteurs au départ
        OCR0A = 0;
        OCR0B = 0;
    }
    
    void pwm_moteurs(uint8_t a, uint8_t b, uint8_t c) {
        OCR0A = a;  // gauche
        OCR0B = b;  // droite
    
        if (c) { // AVANT
            PORTC |= (1 << PC0) | (1 << PC3);
            PORTC &= ~((1 << PC1) | (1 << PC2));
        } else { // ARRIÈRE
            PORTC |= (1 << PC1) | (1 << PC2);
            PORTC &= ~((1 << PC0) | (1 << PC3));
        }
    }
    ```
    
    ```arduino
    #include "TRSensors.h"
    #include "pwm_moteurs.h"
    
    #define NUM_SENSORS 5
    
    TRSensors trs = TRSensors();
    unsigned int sensorValues[NUM_SENSORS];
    unsigned int last_proportional = 0;
    unsigned int position;
    long integral = 0;
    
    void setup() {
      Serial.begin(115200);
      
      // Initialisation PWM et directions → Timer0 configuré une seule fois
      pwm_init();   
      pwm_moteurs(0, 0, 1); // arrêter les moteurs au départ
    
      Serial.println("Calibrating sensors...");
      delay(500);
    
      // Calibration : on fait tourner les moteurs lentement en alternant sens
      for (int i = 0; i < 100; i++) {
        if (i < 25 || i >= 75) {
          // Reculer légèrement
          pwm_moteurs(40, 40, 0);
        } else {
          // Avancer légèrement
          pwm_moteurs(40, 40, 1);
        }
        trs.calibrate();
        delay(20);
      }
    
      pwm_moteurs(0, 0, 1); // arrêt après calibration
      Serial.println("Calibration complete!");
      delay(1000);
    }
    
    void loop() {
      // Lecture des capteurs
      position = trs.readLine(sensorValues);
    
      // Debug
      for (unsigned char i = 0; i < NUM_SENSORS; i++) {
        Serial.print(sensorValues[i]);
        Serial.print('\t');
      }
      Serial.println(position);
    
      // Détection perte de ligne
    
      // Détection perte de ligne (inchangée)
      if (sensorValues[1] > 900 && sensorValues[2] > 900 && sensorValues[3] > 900) {
        pwm_moteurs(0, 0, 1);
        Serial.println("Line lost - stopping!");
        return;
      }
    
      // Calcul PID amélioré
      int proportional = (int)position - 2000;
      int derivative = proportional - last_proportional;
      
      integral += proportional;
      if (integral > 10000) integral = 10000;
      if (integral < -10000) integral = -10000;
      
      last_proportional = proportional;
    
      //  Paramètres PID adoucis :
      int power_difference = proportional / 15 + integral / 10000 + derivative * 2;
    
      //  Gestion de vitesse adaptative en virage :
      const int MAX_PWM_STRAIGHT = 100;
      const int MAX_PWM_TURN = 70;
      int max_pwm = (abs(proportional) > 500) ? MAX_PWM_TURN : MAX_PWM_STRAIGHT;
    
      if (power_difference > max_pwm) power_difference = max_pwm;
      if (power_difference < -max_pwm) power_difference = -max_pwm;
    
      uint8_t left_pwm, right_pwm;
      if (power_difference < 0) {
        left_pwm  = max_pwm + power_difference; // power_difference négatif
        right_pwm = max_pwm;
      } else {
        left_pwm  = max_pwm;
        right_pwm = max_pwm - power_difference;
      }
    
      pwm_moteurs(left_pwm, right_pwm, 1);
    }
    ```
    
    **Test du suiveur de ligne avec bibliothèques PWM améliorées, PID adouci et commande spécifique pour virages :**
    
- Projet 12 : Suivre une ligne et éviter les obstacles
    - CDC : le robot détecte un obstacle en suivant sa ligne, il doit s’arrêter, le contourner et retrouver la ligne.
        
        Programme avec notre bibliothèque:  
        
        RGB LEDS:
        
        ```arduino
        #include <Adafruit_NeoPixel.h>
        
        #define PIN 7
        
        Adafruit_NeoPixel RGB = Adafruit_NeoPixel(4, PIN, NEO_GRB + NEO_KHZ800);
        
        void setup() {
          // put your setup code here, to run once:
          RGB.begin();
          RGB.setPixelColor(0, RGB.Color(0, 0, 50));
          RGB.setPixelColor(1, RGB.Color(0, 0, 50));
          RGB.setPixelColor(2, RGB.Color(0, 0, 50));
          RGB.setPixelColor(3, RGB.Color(0, 0, 50));
          RGB.show();
        }
        
        void loop() {
          // put your main code here, to run repeatedly:
        
        }
        ```
        

### Matériels utiles (lien lextronic et doc composants)

- Doc Carte Arduino
    
    [Carte Arduino® Uno DIP Rev 3 A000066](https://www.lextronic.fr/carte-arduino-uno-dip-rev3-A000066-2474.html)
    
- Doc Capteur US HC-SR04
    
    [Capteur ultrasons HC-SR04 pour Arduino](https://www.lextronic.fr/capteur-ultrasons-hc-sr04-51716.html)
    
- Doc Base Shield pour Arduino
    
    [Platine Grove Base Shield pour Arduino® UNO et Leonardo 103030000](https://www.lextronic.fr/platine-grove-base-shield-v2-103030000-14174.html)
    

### Liens utiles : cours / docs

- [Datasheet ATMega328p](http://thierryperisse.free.fr/wp-content/uploads/2020/12/ATmega328P_Datasheet.pdf)
- [AlphaBot2-Ar](https://www.waveshare.com/wiki/AlphaBot2-Ar)
- [Site LOCODUINO](https://www.locoduino.org/)
- [Datasheet ITR20001-T](https://cdn-shop.adafruit.com/product-files/3930/ITR20001-T.pdf)
