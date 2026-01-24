#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup(){
  lcd.begin(16, 2);
  lcd.print("H");
  delay(200);
  lcd.print("E");
  delay(200);
  lcd.print("L");
  delay(200);
  lcd.print("L");
  delay(200);
  lcd.print("O, ");
  delay(200);
  lcd.print("H");
  delay(200);
  lcd.print("O");
  delay(200);
  lcd.print("W ");
  delay(200);
  lcd.print("I");
  delay(200);
  lcd.print("S ");
  delay(200);

  lcd.setCursor(0, 1);
  lcd.print("E");
  delay(200);
  lcd.print("V");
  delay(200);
  lcd.print("E");
  delay(200);
  lcd.print("R");
  delay(200);
  lcd.print("Y");
  delay(200);
  lcd.print("O");
  delay(200);
  lcd.print("N");
  delay(200);
  lcd.print("E");
}
void loop(){
}