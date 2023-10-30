#include <Arduino.h>
#include <LiquidCrystal.h>

#include "letters.h" 

byte LT[8] = {B00111, B01111, B11111, B11111, B11111, B11111, B11111, B11111};
byte UB[8] = {B11111, B11111, B11111, B00000, B00000, B00000, B00000, B00000};
byte RT[8] = {B11100, B11110, B11111, B11111, B11111, B11111, B11111, B11111};
byte LL[8] = {B11111, B11111, B11111, B11111, B11111, B11111, B01111, B00111};
byte LB[8] = {B00000, B00000, B00000, B00000, B00000, B11111, B11111, B11111};
byte LR[8] = {B11111, B11111, B11111, B11111, B11111, B11111, B11110, B11100};
byte UMB[8] = {B11111, B11111, B11111, B00000, B00000, B00000, B11111, B11111};
byte LMB[8] = {B11111, B00000, B00000, B00000, B00000, B11111, B11111, B11111};

Letter::Letter(LiquidCrystal &lcdRef) : lcd(lcdRef) {}

D::D(LiquidCrystal &lcdRef): Letter(lcdRef) {}
byte D::write(int startingX) {
  lcd.setCursor(startingX, 0); 
  lcd.write(255);  
  lcd.write(1); 
  lcd.write(2);
  lcd.setCursor(startingX, 1); 
  lcd.write(255);  
  lcd.write(4);  
  lcd.write(5);
  return startingX+3;
}

O::O(LiquidCrystal &lcdRef): Letter(lcdRef) {}
byte O::write(int startingX) {
  lcd.setCursor(startingX,0);
  lcd.write(8);
  lcd.write(2);
  lcd.setCursor(startingX,1);
  lcd.write(3);
  lcd.write(5);
  return startingX+2;
}

N::N(LiquidCrystal &lcdRef): Letter(lcdRef) {}
byte N::write(int startingX) {
  lcd.setCursor(startingX,0);
  lcd.write(8);
  lcd.write(2);
  lcd.write(255);
  lcd.setCursor(startingX,1);
  lcd.write(255);
  lcd.write(3);
  lcd.write(5);
  return startingX+3;
}

T::T(LiquidCrystal &lcdRef): Letter(lcdRef) {}
byte T::write(int startingX) {
  lcd.setCursor(startingX,0);
  lcd.write(1);
  lcd.write(255);
  lcd.write(1);
  lcd.setCursor(startingX,1);
  lcd.write(254);
  lcd.write(255);
  return startingX+3;
}

I::I(LiquidCrystal &lcdRef): Letter(lcdRef) {}
byte I::write(int startingX) {
  lcd.setCursor(startingX,0);
  lcd.write(1);
  lcd.write(255);
  lcd.write(1);
  lcd.setCursor(startingX,1);
  lcd.write(4);
  lcd.write(255);
  lcd.write(4);
  return startingX+3;
}

E::E(LiquidCrystal &lcdRef): Letter(lcdRef) {}
byte E::write(int startingX) {
  lcd.setCursor(startingX,0);
  lcd.write(255);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(startingX, 1);
  lcd.write(255);
  lcd.write(7);
  lcd.write(7); 
  return startingX+3;
}

R::R(LiquidCrystal &lcdRef): Letter(lcdRef) {}
byte R::write(int startingX) {
  lcd.setCursor(startingX,0);
  lcd.write(255);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(startingX,1);
  lcd.write(255);
  lcd.write(254);
  lcd.write(2); 
  return startingX+3;
}

K::K(LiquidCrystal &lcdRef): Letter(lcdRef) {}
byte K::write(int startingX) {
  lcd.setCursor(startingX,0);
  lcd.write(255);
  lcd.write(4);
  lcd.write(5);
  lcd.setCursor(startingX,1);
  lcd.write(255);
  lcd.write(254);
  lcd.write(2); 
  return startingX+3;
}

B::B(LiquidCrystal &lcdRef): Letter(lcdRef) {}
byte B::write(int startingX) {
  lcd.setCursor(startingX,0);
  lcd.write(255);
  lcd.write(6);
  lcd.write(5);
  lcd.setCursor(startingX, 1);
  lcd.write(255);
  lcd.write(7);
  lcd.write(2);
  return startingX+3;
}

void setupLetterBuildingBlocks(LiquidCrystal lcd) {
  lcd.createChar(8,LT);
  lcd.createChar(1,UB);
  lcd.createChar(2,RT);
  lcd.createChar(3,LL);
  lcd.createChar(4,LB);
  lcd.createChar(5,LR);
  lcd.createChar(6,UMB);
  lcd.createChar(7,LMB);
}

void writeText(LiquidCrystal lcd, Letter** text, int textLength) {
  int xPos = 0;
  for (int i = 0; i < textLength; i++) {
    xPos = text[i]->write(xPos);

    // Add space between letters
    lcd.setCursor(xPos, 0);
    lcd.write(254);
    lcd.setCursor(xPos, 1);
    lcd.write(254);
    xPos++;
    
  }
}