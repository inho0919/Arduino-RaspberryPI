#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,9,10,11,12);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("inho0919");
}

void loop() {
  // put your main code here, to run repeatedly:

}
