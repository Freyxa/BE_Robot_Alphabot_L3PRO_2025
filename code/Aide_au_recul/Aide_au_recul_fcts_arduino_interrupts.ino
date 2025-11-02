
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

#define LED_PIN 13  // LED intégrée sur Arduino UNO

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
  
  // ==== LED ====
  pinMode(LED_PIN, OUTPUT);
  
  // ==== Série ====
  Serial.begin(9600);
}

void loop() {
  trigger_ultrasonic();
  delay(100);

  if (new_measure) {
    noInterrupts();
    float distance_cm = (float)echo_time / 58.0;
    new_measure = false;
    interrupts();

    Distance = distance_cm;

    // ==== Contrôle de la LED ====
    updateLED(Distance);

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
    if (Distance > 10) {
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, HIGH);
      digitalWrite(BIN1, LOW);
      digitalWrite(BIN2, HIGH);
    } else {
      digitalWrite(AIN1, LOW);
      digitalWrite(AIN2, LOW);
      digitalWrite(BIN1, LOW);
      digitalWrite(BIN2, LOW);
    }

    Serial.print("Distance: ");
    Serial.print(Distance);
    Serial.println(" cm");
  }
}

void updateLED(float distance) {
  static unsigned long previousMillis = 0;
  static bool ledState = false;
  unsigned long interval = 0;

  // Éteindre par défaut
  digitalWrite(LED_PIN, LOW);

  if (distance < 2 || distance > 400) {
    // Hors plage : éteinte
    return;
  }

  if (distance < 20) {
    // Moins de 20 cm : LED allumée en continu
    digitalWrite(LED_PIN, HIGH);
    return;
  }

  // Définir l'intervalle de clignotement selon la distance
  if (distance >= 100) {
    // ≥ 1 m : éteinte (ou très lent, ici éteinte)
    return;
  }
  else if (distance >= 50) {
    // 50–100 cm : lent → toutes les 800 ms
    interval = 500;
  }
  else if (distance >= 30) {
    // 30–50 cm : modéré → toutes les 400 ms
    interval = 150;
  }
  else if (distance >= 20) {
    // 20–30 cm : rapide → toutes les 150 ms
    interval = 50;
  }

  // Clignotement non bloquant
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }
}

// ---- Déclenchement ultrason ----
void trigger_ultrasonic() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
}

// ---- Interruption ECHO ----
void echo_change() {
  if (digitalRead(ECHO) == HIGH) {
    start_time = micros();
  } else {
    echo_time = micros() - start_time;
    new_measure = true;
  }
}
