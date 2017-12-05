/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

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
    std::string getPlayerName();
    
    bool score(RollOfDice rd,  Colour cl, int positionFromLeft);
    int setTotal();
    virtual int calcTotal() = 0;
    
    virtual bool const operator !();
    //Note that we can't overload the insertion operator since this is an abstract class, it will be implemented in the children classes
protected:
    virtual bool validate(RollOfDice rd,  Colour cl, int positionFromLeft) = 0;//Pure virtual function to b implemented in children classes
};

#endif /* ScoreSheet_h */
