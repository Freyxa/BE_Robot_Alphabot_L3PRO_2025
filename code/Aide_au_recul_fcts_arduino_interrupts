
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 9

#define ECHO   2
#define TRIG   3
#define PWMA   6           
#define AIN2   A0          
#define AIN1   A1        
#define PWMB   5           
#define BIN1   A2         
#define BIN2   A3   

volatile unsigned long start_time = 0;
volatile unsigned long echo_time = 0;
volatile bool new_measure = false;

float Distance = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() { 
  // ==== Moteurs ====
  pinMode(PWMB, OUTPUT);                     
  pinMode(BIN2, OUTPUT);      
  pinMode(BIN1, OUTPUT);
  pinMode(PWMA, OUTPUT);                     
  pinMode(AIN2, OUTPUT);      
  pinMode(AIN1, OUTPUT);
  analogWrite(PWMB, 30);
  analogWrite(PWMA, 30);

  // ==== Capteur ultrason ====
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(ECHO), echo_change, CHANGE);

  // ==== OLED ====
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  
  // ==== Série ====
  Serial.begin(9600);
}

void loop() {
  // Déclenche une mesure ultrason toutes les 100 ms
  trigger_ultrasonic();
  delay(100);

  // Si une nouvelle mesure est prête
  if (new_measure) {
    noInterrupts();
    float distance_cm = (float)echo_time / 58.0;
    new_measure = false;
    interrupts();

    Distance = distance_cm;

    // ==== Affichage OLED ====
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    if (Distance > 2 && Distance < 400) {
      display.setCursor(30, 20);
      display.print(Distance, 0);
      display.println("cm");
    } else {
      display.setCursor(10, 20);
      display.println("Hors de");
      display.setCursor(10, 40);
      display.println("portee!");
    }
    display.display();

    // ==== Contrôle moteurs ====
    if (Distance > 15) {
      // Avancer
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, HIGH);
      digitalWrite(BIN1, LOW);
      digitalWrite(BIN2, HIGH);
    } else {
      // Stop
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, LOW);
      digitalWrite(BIN1, LOW);
      digitalWrite(BIN2, LOW);
    }

    // ==== Debug série ====
    Serial.print("Distance: ");
    Serial.print(Distance);
    Serial.println(" cm");
  }
}

// ---- Fonction déclenchement ultrason ----
void trigger_ultrasonic() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
}

// ---- Interruption sur front CHANGE de ECHO ----
void echo_change() {
  if (digitalRead(ECHO) == HIGH) {
    start_time = micros();
  } else {
    echo_time = micros() - start_time;
    new_measure = true;
  }
}
