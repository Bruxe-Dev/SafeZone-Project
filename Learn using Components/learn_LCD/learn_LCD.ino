#include <LiquidCrystal.h>

// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String message = "Hello World! Welcome!";
int delayTime = 200; // milliseconds between each letter

void setup() {
  lcd.begin(16, 2);  // 16x2 LCD
}

void loop() {
  typeMessage(message, 0); // Display on row 0 (top row)
  delay(1000);             // Wait 1 second
  lcd.clear();             // Clear the screen
  delay(500);
}

// Function to type message letter by letter
void typeMessage(String text, int row) {
  lcd.setCursor(0, row);       // Start at first column of the row
  for (int i = 0; i < text.length(); i++) {
    lcd.print(text[i]);        // Print one letter
    delay(delayTime);          // Wait before next letter
  }
}