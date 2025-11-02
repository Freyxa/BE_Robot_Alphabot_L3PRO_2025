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
