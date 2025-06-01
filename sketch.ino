#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD 16x2 via I2C
#define col 16
#define lin 2
#define ende 0x27
LiquidCrystal_I2C lcd(ende, col, lin);

// Pinos
int ledRedPin = 13;
int ledGreenPin = 11;
int ledYellowPin = 12;
int potPin = A0;
int PIN_TRIG = 3;
int PIN_ECHO = 2;
int boozerPin = 8;

bool boozerActive = false;

void setup() {
  Serial.begin(115200);

  pinMode(ledRedPin, OUTPUT);
  pinMode(ledYellowPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(boozerPin, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Monitorando");
  lcd.setCursor(0, 1);
  lcd.print("Bueiro...");
  delay(2000);
  lcd.clear();
}

void loop() {

  int chuva = analogRead(potPin); 
  Serial.print("Chuva: ");
  Serial.println(chuva);
  int intervalo;
  if (chuva > 700) {
    intervalo = 1000;
  } else if (chuva > 300) {
    intervalo = 3000;
  } else {
    intervalo = 5000;
  }

  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  long duracao = pulseIn(PIN_ECHO, HIGH);
  float distancia = duracao * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  digitalWrite(ledRedPin, LOW);
  digitalWrite(ledYellowPin, LOW);
  digitalWrite(ledGreenPin, LOW);

  if (distancia <= 40) {
    digitalWrite(ledRedPin, HIGH);
    if (!boozerActive) {
      tone(boozerPin, 440);
      boozerActive = true;
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nivel de agua");
    lcd.setCursor(0, 1);
    lcd.print("alto "); lcd.print(distancia); lcd.print("cm");
    delay(300);
  }
  else if (distancia <= 100) {
    digitalWrite(ledYellowPin, HIGH);
    noTone(boozerPin);
    boozerActive = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nivel de agua");
    lcd.setCursor(0, 1);
    lcd.print("medio "); lcd.print(distancia); lcd.print("cm");
    delay(300);
  }
  else {
    digitalWrite(ledGreenPin, HIGH);
    noTone(boozerPin);
    boozerActive = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nivel de agua");
    lcd.setCursor(0, 1);
    lcd.print("bom "); lcd.print(distancia); lcd.print("cm");
    delay(300);
  }

  delay(intervalo); 
}
