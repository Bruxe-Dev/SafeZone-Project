#include <DHT.h>

#define DHTPIN 2       // DATA pin connected to D2
#define DHTTYPE DHT11  // Change to DHT22 if needed

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature(); // Celsius

  if (isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");

  delay(2000);
}
