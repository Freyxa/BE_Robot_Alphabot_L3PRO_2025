#define ECHO   2  // Broche ECHO
#define TRIG   3  // Broche TRIG

int Distance = 0;
int DistanceFiltree = 0;
const float alpha = 0.5;  // ↑ Plus réactif (0.4 à 0.6 = bon compromis)

int Distance_test() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Timeout de 25 ms → distance max ~430 cm (au-delà, pulseIn renvoie 0)
  unsigned long duration = pulseIn(ECHO, HIGH, 25000);

  if (duration == 0) return -1;  // Aucun écho reçu

  float distance = duration / 58.0;  // Conversion en cm

  // Valider la plage utile du HC-SR04 (2 cm à 400 cm)
  if (distance < 2 || distance > 400) {
    return -1;
  }

  return (int)distance;
}

void setup() {
  Serial.begin(115200);
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
}

void loop() {
  int mesure = Distance_test();

  if (mesure > 0) {
    // Filtrage exponentiel réactif
    DistanceFiltree = (int)(alpha * mesure + (1 - alpha) * DistanceFiltree);
    Distance = DistanceFiltree;

    Serial.print("Distance filtrée = ");
    Serial.print(Distance);
    Serial.println(" cm");
  } else {
    // Optionnel : garder l'ancienne valeur ou marquer "hors portée"
    Serial.println("Hors de portée !");
    // Distance = 0; // ou laisser inchangée
  }

  delay(250);  // Respecter le temps de repos du HC-SR04
}
