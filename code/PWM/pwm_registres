void setup() {

  // Set OC0A (PD6) and OC0B (PD5) as outputs
  DDRD |= (1 << DDD6);  // PD6 = OC0A
  DDRD |= (1 << DDD5);  // PD5 = OC0B

  // Optional: Set PC0–PC3 as outputs (for manual control)
  DDRC |= (1 << DDC0);
  DDRC |= (1 << DDC1);
  DDRC |= (1 << DDC2);
  DDRC |= (1 << DDC3);

  // Configure Timer0 for Fast PWM, non-inverting mode on both OC0A and OC0B
  TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
  TCCR0B = (1 << CS01) | (1 << CS00);  // Prescaler = 64

  // Rapport cyclique entre [0,255]
  OCR0A = 50;  // ~20% de rapport cyclique PD6 
  OCR0B = 50;  // ~20% duty on PD5

  // Optional: Set PC0 and PC2 HIGH, PC1 and PC3 LOW
  PORTC |= (1 << PC0);
  PORTC &= ~ (1 << PC2);
  PORTC &= ~(1 << PC1);
  PORTC |= (1 << PC3);

  delay(5000);  // Keep PWM running for 5 seconds

  // Turn off PWM outputs
  OCR0A = 0;
  OCR0B = 0;

  // Turn off all PORTC pins
  PORTC &= ~((1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3));
}

void loop() {
  // Nothing
}
