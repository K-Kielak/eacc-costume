#include <LiquidCrystal.h>

#include "letters.h" 

// Text setup
const int RS = 2, EN = 3, D4 = 4, D5 = 5, D6 = 6, D7 = 7;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

const Letter* DONT[] = {new D(lcd), new O(lcd), new N(lcd), new T(lcd)};
const Letter* DIE[] = {new D(lcd), new I(lcd), new E(lcd)};

bool textIsDont = false;
unsigned long prevTextChange = 0;
const unsigned long TEXT_INTERVAL = 1000;

// LED
const byte RED_LED = 11;

byte ledBrightness = 100;
unsigned long prevLedChange = 0;
const unsigned long LED_INTERVAL = 10;

// Joystick
const byte VRX = A0;
const byte VRY = A1;

void setup()
{
  lcd.begin(16, 2); 
  setupLetterBuildingBlocks(lcd);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  controlText(currentMillis);
  controlLeds(currentMillis);
}


void controlText(unsigned long currentMillis) {
  if (currentMillis - prevTextChange < TEXT_INTERVAL) {
    return;
  }

  lcd.clear();
  if (textIsDont) {
    writeText(lcd, DIE, 3);
    textIsDont = false;
  } else {
      writeText(lcd, DONT, 4);
    textIsDont = true;
  }

  prevTextChange = currentMillis;
}


void controlLeds(unsigned long currentMillis) {
  if (currentMillis - prevLedChange < LED_INTERVAL) {
    return;
  }

  int js_x_pos = analogRead(VRX);
  if (js_x_pos < 100 && ledBrightness < 255) {
    ledBrightness++;
  } else if (js_x_pos > 1000 && ledBrightness > 0) {
    ledBrightness--;
  }
 
  analogWrite(RED_LED, ledBrightness);
  prevLedChange = currentMillis;
}
