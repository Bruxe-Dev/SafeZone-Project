#include <LiquidCrystal.h>
#include <DHT.h>

// ================= LCD =================
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

// ================= PINS =================
#define FLAME_PIN 2
#define DHT_PIN 3
#define TRIG_PIN 4
#define ECHO_PIN 5

#define RED_LED 6
#define GREEN_LED 7
#define YELLOW_LED A0

#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);

int fireTempThreshold = 40;
int dangerDistance = 50;
int typeDelay = 120;

void typeMessage(String text, int row) {
  lcd.setCursor(0, row);
  for (int i = 0; i < text.length(); i++) {
    lcd.print(text[i]);
    delay(typeDelay);
  }
}

long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return 999;
  return duration * 0.034 / 2;
}

void blinkYellow() {
  digitalWrite(YELLOW_LED, HIGH);
  delay(300);
  digitalWrite(YELLOW_LED, LOW);
  delay(300);
}

void allOff() {
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
}

void setup() {
  pinMode(FLAME_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);

  dht.begin();
  Serial.begin(9600);

  lcd.begin(16, 2);
  typeMessage("SafeZone System", 0);
  typeMessage("Initializing", 1);
  delay(2000);
  lcd.clear();
}

void loop() {
  int flame = digitalRead(FLAME_PIN);
  float temp = dht.readTemperature();
  long distance = getDistance();

  lcd.clear();

  if (flame == LOW || temp >= fireTempThreshold) {
    allOff();
    typeMessage("FIRE ALERT!", 0);
    typeMessage("KEEP AWAY", 1);
    blinkYellow();
  }
  else if (distance <= dangerDistance) {
    allOff();
    digitalWrite(RED_LED, HIGH);
    typeMessage("DO NOT ENTER", 0);
    typeMessage("DANGER ZONE", 1);
    Serial.println("BUZZ");
    delay(500);
  }
  else {
    allOff();
    digitalWrite(GREEN_LED, HIGH);
    typeMessage("AREA SAFE", 0);
    typeMessage("WELCOME", 1);
    delay(500);
  }
}