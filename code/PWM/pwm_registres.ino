void setup() {

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
  OCR0A = 50;  // ~20% de rapport cyclique pour le PD6 (Moteur gauche)
  OCR0B = 50;  // ~20% de rapport cyclique pour le PD5 (Moteur droite)

  // Mettre PC0 et PC2 à l'état haut pour avancer et donc PC1 et PC3 à l'état bas 
  PORTC |= (1 << PC0);
  PORTC &= ~ (1 << PC2);
  PORTC &= ~(1 << PC1);
  PORTC |= (1 << PC3);

  delay(5000);  // Avancer pendant 5s 

  // Eteindre sorties PWM donc moteurs aussi
  OCR0A = 0;
  OCR0B = 0;

  // Remettre comme à l' état intial les pins A0, A1, A2, A3
  PORTC &= ~((1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3));
}

void loop() {
}
