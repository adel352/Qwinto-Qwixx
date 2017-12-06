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
    
    ScoreSheet()=default;
    ScoreSheet(std::string name);
    ~ScoreSheet();
    
    int getNumberOfFailedAttempts();
    void setFinalScore(int score);
    int getFinalScore();
    std::string getPlayerName();
    void incrementFailedAttempts();
    
    bool score(RollOfDice rd,  Colour cl, int positionFromLeft);
    int setTotal();
    virtual int calcTotal() = 0;
    
    virtual bool const operator !();
    //Note that we can't overload the insertion operator since this is an abstract class, it will be implemented in the children classes
protected:
    virtual bool validate(RollOfDice rd,  Colour cl, int positionFromLeft) = 0;//Pure virtual function to b implemented in children classes
};

#endif /* ScoreSheet_h */
