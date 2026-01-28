#define TRIG_PIN 9
#define ECHO_PIN 10
#define RED_LED 2
#define GREEN_LED 3

long duration;
int distance;
int threshold = 70; // cm

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
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
    Serial.println("ALERT"); 
     digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    delay(100);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    delay(100); 
  } else {
    Serial.println("CLEAR");  
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
     // Object far
  }

  delay(200);
}
