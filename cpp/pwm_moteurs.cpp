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
