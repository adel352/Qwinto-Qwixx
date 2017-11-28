//
//  Dice.h
//  DiceGame
//
//  Created by Alexandre Prud'Homme on 2017-11-25.
//  Copyright © 2017 Adel Araji. All rights reserved.
//

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
};

#endif /* Dice_h */
