//
//  ScoreSheet.cpp
//  DiceGame
//
//  Created by Adel Araji on 2017-11-27.
//  Copyright © 2017 Adel Araji. All rights reserved.
//

#include <stdio.h>
#include "ScoreSheet.h"


ScoreSheet::ScoreSheet(){
    
}

ScoreSheet::~ScoreSheet(){
    
}



/**
 A score is entered using this method, sets an individual score for one roll of dice

 @param rd : Roll fo Dice
 @param cl : Colour of Dice
 @param positionFromLeft : Position From Left, set to -1 in case of Qwixx
 @return boolean to check if it is possible to score or note
 */
bool ScoreSheet::score(RollOfDice rd, Colour cl, int positionFFromLeft = -1){
    return validate(rd, cl, positionFFromLeft);
}


/**
 Sets and returns the FINAL score

 @return int, the final score score of the game
 */
int ScoreSheet::setTotal(){
    return calcTotal();
}



/**
 Overload the not operator

 @return True if Game has ended, false if not
 */
bool const ScoreSheet::operator!(){
    if (numberOfFailedAttempts == 4)
        return true;
    else
        return false;
}
