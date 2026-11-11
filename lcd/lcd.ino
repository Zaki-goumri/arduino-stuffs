#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String name = "just friends";

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);

  for (int i = 0; i < name.length(); i++) {
    lcd.print(name[i]);
    delay(300);
  }

  delay(1500);
}
