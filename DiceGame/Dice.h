/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#ifndef Dice_h
#define Dice_h
#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Colour.h"
#include "RandomDice.h"

struct Dice{
    
private:
    const Colour col;
    int face;

public:
    //Default Constructor
    Dice() = default;
    
    //Constructor with 2 parameters
    Dice(Colour c, int f);
    
    //Roll function implementation
    int roll();
    
    Colour getColour();
    
    int getFace();
    
    //Overloading insertion function
    friend std::ostream &operator<<(std::ostream& os, const Dice &dc);
    
    std::string getStringColour();
};

#endif /* Dice_h */
