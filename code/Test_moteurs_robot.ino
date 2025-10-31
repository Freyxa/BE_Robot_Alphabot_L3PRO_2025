#define PWMA   6           //Pin Moteur gauche
#define AIN2   A0          //Moteur gauche avance
#define AIN1   A1          //Moteur gauche recul
#define PWMB   5           //Pin Moteur droite
#define BIN1   A2          //Moteur droite avance
#define BIN2   A3          //Moteur droite recul&
  
void setup() {
  pinMode(PWMB,OUTPUT);                     
  pinMode(BIN2,OUTPUT);      
  pinMode(BIN1,OUTPUT);
  pinMode(PWMA,OUTPUT);                     
  pinMode(AIN2,OUTPUT);      
  pinMode(AIN1,OUTPUT);
  analogWrite(PWMB,30);
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,HIGH);
  analogWrite(PWMA,30);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  delay(5000);        
  analogWrite(PWMB,0);
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,LOW);
  analogWrite(PWMA,0);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,LOW);
}

void loop() {

}
