#define TRIG_PIN 9
#define ECHO_PIN 10

long duration;
int distance;
int threshold = 70; // cm

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo
  duration = pulseIn(ECHO_PIN, HIGH, 30000);
  distance = duration * 0.034 / 2;

  if (distance > 0 && distance <= threshold) {
    Serial.println("ALERT");   // Object close
  } else {
    Serial.println("CLEAR");   // Object far
  }

  delay(200);
}
