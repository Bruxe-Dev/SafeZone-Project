#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void typeText(const char *text, int row) {
  lcd.setCursor(0, row);

  for (int i = 0; text[i] != '\0'; i++) {
    lcd.print(text[i]);
    delay(150);
  }
}
byte spin0[8] = {
  0b00100,
  0b01100,
  0b11100,
  0b01100,
  0b00100,
  0b00000,
  0b00000,
  0b00000
};

byte spin1[8] = {
  0b00100,
  0b00110,
  0b00111,
  0b00110,
  0b00100,
  0b00000,
  0b00000,
  0b00000
};

byte spin2[8] = {
  0b00000,
  0b00000,
  0b00100,
  0b01110,
  0b11111,
  0b00000,
  0b00000,
  0b00000
};

byte spin3[8] = {
  0b00000,
  0b00000,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000,
  0b00000
};


void setup() {
  lcd.begin(16, 2);
  lcd.clear();

  typeText("SYSTEM CHECK ", 0);
  delay(2000);

  // Load custom characters
  lcd.createChar(0, spin0);
  lcd.createChar(1, spin1);
  lcd.createChar(2, spin2);
  lcd.createChar(3, spin3);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PLEASE WAIT");

  // Spinner position
  lcd.setCursor(13, 0);

  // Animate loading icon
  for (int i = 0; i < 20; i++) {
    lcd.write(byte(i % 4));
    delay(200);
  }

  lcd.clear();
  lcd.print("DONE!");
};

void loop() {
}
