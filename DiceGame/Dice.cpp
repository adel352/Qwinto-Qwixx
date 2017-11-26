//
//  Dice.cpp
//  DiceGame
//
//  Created by Alexandre Prud'Homme on 2017-11-25.
//  Copyright © 2017 Adel Araji. All rights reserved.
//

#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Dice.h"

Dice::Dice(Colour c, int f): col(c), face(f) {};

int Dice::roll(){
    RandomDice *random = new RandomDice();
    face = random->roll();
    std::cout << "face in roll " << face << std::endl;
    return face;
}

Colour Dice::getColour() {
    return col;
}

int Dice::getFace(){
    return face;
}

//https://stackoverflow.com/questions/35904143/friend-not-allowed-outside-of-a-class-definition
std::ostream &operator<<(std::ostream& os, const Dice &dc)
{
    os<< "Dice with colour: ";
    
    switch(dc.col)
    {
        case RED:
            os << "RED";
            break;
        case YELLOW:
            os << "YELLOW";
            break;
        case GREEN:
            os << "GREEN";
            break;
        case BLUE:
            os << "BLUE";
            break;
        case WHITE:
            os << "WHITE";
            break;
    }
    os << " and face: " <<  dc.face;
    return os;
}
