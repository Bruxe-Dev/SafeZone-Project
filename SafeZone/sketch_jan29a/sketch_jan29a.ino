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
#define WHITE_LED A1  // for safe area
// buzzer handled in Python

#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);

int fireTempThreshold = 40;
int dangerDistance = 50; // person detection distance
int typeDelay = 50;  // faster typing

// Non-blocking blink variables
unsigned long previousMillis = 0;
const long blinkInterval = 600;
bool yellowState = false;
bool redState = false;

void typeMessage(String text, int row) {
  lcd.setCursor(0, row);
  for (int i = 0; i < text.length(); i++) {
    lcd.print(text[i]);
    delay(typeDelay);
  }
}

// Ultrasonic distance measurement
long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return 999; // nothing detected
  return duration * 0.034 / 2;
}

void allOff() {
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(WHITE_LED, LOW);
}

void setup() {
  pinMode(FLAME_PIN, INPUT_PULLUP);  // flame sensor
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);

  dht.begin();
  Serial.begin(9600);

  lcd.begin(16, 2);
  typeMessage("SafeZone System", 0);
  typeMessage("Initializing", 1);
  delay(2000);
  lcd.clear();
}

void loop() {
  int flame = digitalRead(FLAME_PIN); // LOW when fire detected
  float temp = dht.readTemperature();
  if (isnan(temp)) temp = 0;
  long distance = getDistance(); // person detection

  lcd.clear();
  unsigned long currentMillis = millis();

  // ================= CASE 1: Fire + NO person =================
  if ((flame == LOW || temp >= fireTempThreshold) && distance > dangerDistance) {
    allOff();
    // blink yellow
    if (currentMillis - previousMillis >= blinkInterval) {
      previousMillis = currentMillis;
      yellowState = !yellowState;
      digitalWrite(YELLOW_LED, yellowState ? HIGH : LOW);
    }
    typeMessage("FIRE ALERT!", 0);
    typeMessage("NO PERSON", 1);

    Serial.println("ALERT1"); // send to Python
  }

  // ================= CASE 2: Fire + PERSON nearby =================
  else if ((flame == LOW || temp >= fireTempThreshold) && distance <= dangerDistance) {
    allOff();
    // alternate red and yellow
    if (currentMillis - previousMillis >= blinkInterval) {
      previousMillis = currentMillis;
      redState = !redState;
      digitalWrite(RED_LED, redState ? HIGH : LOW);
      digitalWrite(YELLOW_LED, !redState ? HIGH : LOW);
    }
    typeMessage("FIRE ALERT!", 0);
    typeMessage("PERSON DETECTED", 1);

    Serial.println("ALERT2"); // send to Python
  }

  // ================= CASE 3: No fire + PERSON nearby =================
  else if ((flame == HIGH && temp < fireTempThreshold) && distance <= dangerDistance) {
    allOff();
    digitalWrite(WHITE_LED, HIGH);
    typeMessage("PERSON DETECTED", 0);
    typeMessage("AREA SAFE", 1);
    // no buzzer
  }

  // ================= CASE 4: No fire + NO person =================
  else {
    allOff();
    digitalWrite(GREEN_LED, HIGH);
    typeMessage("AREA SAFE", 0);
    typeMessage("NO PERSON", 1);
    // no buzzer
  }

  delay(200);
}
