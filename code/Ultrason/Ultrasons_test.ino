#define ECHO   2 // ECHO -> PIN NUMERIQUE 2    
#define TRIG   3 // TRIG -> PIN NUMERIQUE 3  

int Distance = 0;           // Distance actuelle (en cm)
int DistanceFiltree = 0;    // Distance lissée (filtrée)
const float alpha = 0.3;    // Coefficient de filtrage (0.1 = très stable / 1 = brut)


int Distance_test()         // Fonction pour mesurer la distance
{
  digitalWrite(TRIG, LOW);   // Mettre le pin trig en état bas pendant 2us
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);  //  Mettre le pin trig en état haut pendant 10us
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);    // Mettre le pin trig en état bas
  float Fdistance = pulseIn(ECHO, HIGH);  // Lecture du temps à l'état haut du pin echo 
  Fdistance= Fdistance/58;       // Formule datasheet du HCSR04        
  return (int)Fdistance;   // Retour de la valeur en cm
}  

void setup()
{
  Serial.begin(115200);  
  pinMode(ECHO, INPUT);    // Definir pin echo ultrasonique comme entrée
  pinMode(TRIG, OUTPUT);   // Definir pin trig ultrasonique comme sortie
}

void loop()
{
  int mesure = Distance_test();

  // Filtrage de la mesure
  if (mesure > 0 && mesure <= 400) {
    DistanceFiltree = (int)(alpha * mesure + (1 - alpha) * DistanceFiltree);
  }

  // Mise à jour de la distance
  Distance = DistanceFiltree;

  // Affichage dans le moniteur série
  Serial.print("Distance filtrée = ");
  Serial.print(Distance);
  Serial.println(" cm");
}
