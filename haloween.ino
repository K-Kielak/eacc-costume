#include <LiquidCrystal.h>

#include "letters.h" 

const int LED_PIN = 2;

const int RS = 12, EN = 11, D4 = 6, D5 = 5, D6 = 4, D7 = 3;
const LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

const Letter* DONT[] = {new D(lcd), new O(lcd), new N(lcd), new T(lcd)};
const Letter* DIE[] = {new D(lcd), new I(lcd), new E(lcd)};

const bool textIsDont = true;
const unsigned long prevTextChange = 0;
const unsigned long TEXT_INTERVAL = 3000;

//////////////////////

void setup()
{
  // sets the LCD's rows and colums:
  lcd.begin(0, 2);
  setupLetterBuildingBlocks(lcd);
}

//////////////


// void setup() {
//   lcd.begin(16, 2);
//   lcd.write("æ");

//   pinMode(LED_PIN, OUTPUT);
// }

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - prevTextChange > TEXT_INTERVAL) {
    if (textIsDont) {
      writeText(lcd, DIE, 3);
      textIsDont = false;
    } else {
      writeText(lcd, DONT, 4);
      textIsDont = true;
    }
  }
}
