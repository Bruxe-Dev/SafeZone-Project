int flameAnalog = A0; // AO pin

void setup() {
  Serial.begin(9600);
}

void loop() {
  int flameValue = analogRead(flameAnalog);
  Serial.print("Flame intensity: ");
  Serial.println(flameValue);
  delay(500);
}
