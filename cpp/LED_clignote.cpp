#include "clignote.h"


void clignote_init() {
    DDRB |= (1 << DDB5);  
}

void clignote_lent() {
  PORTB |= (1 << PORTB5);
  delay(1000);
  PORTB &= ~(1 << PORTB5);
  delay(1000);     

}

void clignote_rapide() {
  
  PORTB|= (1 << PORTB5);
  delay(100);
  PORTB &= ~(1 << PORTB5);
  delay(100);
}
