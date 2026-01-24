#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup(){
  lcd.begin(16, 2);
  lcd.clear();

  char text[]="LCD TEST MODE...";
  for(int i=0;text[i] !='\0'; i++){
    lcd.print(text[i]);
    delay(200);
  }
}
void loop(){
}