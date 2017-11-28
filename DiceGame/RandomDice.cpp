//
//  RandomDice.cpp
//  DiceGame
//
//  Created by Alexandre Prud'Homme on 2017-11-25.
//  Copyright © 2017 Adel Araji. All rights reserved.
//

#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "RandomDice.h"

int RandomDice::roll() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(1,6);
    int x  = dis(gen);
    //std::cout << "x in random dice" << x << std::endl;
    return x;
}
