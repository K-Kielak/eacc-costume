#include <LiquidCrystal.h>

#include "letters.h" 

// Text
const int RS = 2, EN = 3, D4 = 4, D5 = 5, D6 = 6, D7 = 7;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

const Letter* DONT[] = {new D(lcd), new O(lcd), new N(lcd), new T(lcd)};
const Letter* DIE[] = {new D(lcd), new I(lcd), new E(lcd)};

const Letter* NEED[] = {new N(lcd), new E(lcd), new E(lcd), new D(lcd)};
const Letter* BEER[] = {new B(lcd), new E(lcd), new E(lcd), new R(lcd)};

byte textMode = 0;
bool firstPart = false;
unsigned long prevTextChange = 0;
const unsigned long TEXT_INTERVAL = 1000;

// LED
const byte BUILTIN_LED = 13;
const byte RED_LED = 11;
const byte LCD_BACKLIGHT = 10;
const byte GREEN_LED = 9;

byte ledBrightness = 100;
unsigned long prevLedChange = 0;
const unsigned long LED_INTERVAL = 10;

// Joystick
const int JOYSTICK_HIGH = 1000;
const int JOYSTICK_LOW = 100;

const byte VRX = A0;
const byte VRY = A1;

void setup()
{
  lcd.begin(16, 2); 
  setupLetterBuildingBlocks(lcd);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(LCD_BACKLIGHT, OUTPUT);
  pinMode(BUILTIN_LED, OUTPUT);
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

  int js_y_pos = analogRead(VRY);
  if (js_y_pos > JOYSTICK_HIGH) {
    textMode = 1;
  } else if (js_y_pos < JOYSTICK_LOW) {
    textMode = 0;
  }

  lcd.clear();
  if (textMode == 0) {
    // Don't die
    if (firstPart) {
      writeText(lcd, DIE, 3);
    } else {
      writeText(lcd, DONT, 4);
    }
  } else if (textMode = 1) {
    // Need drink

    if (firstPart) {
      writeText(lcd, NEED, 4);
    } else {
      writeText(lcd, BEER, 4);
    }
  }
  
  firstPart = !firstPart;
  prevTextChange = currentMillis;
}


void controlLeds(unsigned long currentMillis) {
  if (currentMillis - prevLedChange < LED_INTERVAL) {
    return;
  }

  int js_x_pos = analogRead(VRX);
  if (js_x_pos < JOYSTICK_LOW && ledBrightness < 255) {
    ledBrightness++;
  } else if (js_x_pos > JOYSTICK_HIGH && ledBrightness > 0) {
    ledBrightness--;
  }
 
  analogWrite(RED_LED, ledBrightness);
  analogWrite(GREEN_LED, ledBrightness);
  analogWrite(LCD_BACKLIGHT, ledBrightness);
  analogWrite(BUILTIN_LED, ledBrightness);
  prevLedChange = currentMillis;
}
