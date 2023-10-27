#ifndef LETTERS_H
#define LETTERS_H

#include <Arduino.h>
#include <LiquidCrystal.h>

class Letter {
protected:
    LiquidCrystal &lcd;

public:
    Letter(LiquidCrystal &lcdRef);
    virtual byte write(int startingX) = 0;
};

class D : public Letter {
public:
    D(LiquidCrystal &lcdRef);
    byte write(int startingX) override;
};

class O : public Letter {
public:
    O(LiquidCrystal &lcdRef);
    byte write(int startingX) override;
};

class N : public Letter {
public:
    N(LiquidCrystal &lcdRef);
    byte write(int startingX) override;
};

class T : public Letter {
public:
    T(LiquidCrystal &lcdRef);
    byte write(int startingX) override;
};

class I : public Letter {
public:
    I(LiquidCrystal &lcdRef);
    byte write(int startingX) override;
};

class E : public Letter {
public:
    E(LiquidCrystal &lcdRef);
    byte write(int startingX) override;
};

void writeText(LiquidCrystal lcd, Letter** text, int textLength);
void setupLetterBuildingBlocks(LiquidCrystal lcd);

#endif // LETTERS_H
