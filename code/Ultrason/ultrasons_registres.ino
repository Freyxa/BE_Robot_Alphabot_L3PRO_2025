#define ECHO   PD2   // Broche D2 -> bit 2 du port D
#define TRIG   PD3   // Broche D3 -> bit 3 du port D

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
