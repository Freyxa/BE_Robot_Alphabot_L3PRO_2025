#include "pwm_moteurs.h"

void setup()
{
  pwm_moteurs(50,50,1); // pwm_moteurs(a,b,c)
                        // a = [0,255] => PWM gauche
                        // b = [0,255] => PWM droite
                        // c = 1 pour avancer ou 0 pour recul
}
void loop()
{

}
