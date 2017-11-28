//
//  ScoreSheet.h
//  DiceGame
//
//  Created by Adel Araji on 2017-11-27.
//  Copyright © 2017 Adel Araji. All rights reserved.
//
#include <iostream>
#include "RollOfDice.h"
#include "Colour.h"

#ifndef ScoreSheet_h
#define ScoreSheet_h

class ScoreSheet {
    std::string nameOfPlayer;
    int numberOfFailedAttempts;
    int overallScore;
    
public:
    bool score(RollOfDice rd,  Colour cl, int positionFromLeft = -1);
    int setTotal();
    
};

#endif /* ScoreSheet_h */
