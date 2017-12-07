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

/*
 * Classe abstraite ScoreSheet. ScoreSheet contient des méthodes virtuelles pures qui vont être implémenté
 * dans QwintoScoreSheet et QwixxScoreSheet
 */
class ScoreSheet {
    std::string nameOfPlayer;
    int numberOfFailedAttempts;
    int overallScore;
    
public:
    //Constructuer défaut
    ScoreSheet()=default;
    ScoreSheet(std::string name);
    //Destructeur
    ~ScoreSheet();
    
    int getNumberOfFailedAttempts();
    void setFinalScore(int score);
    int getFinalScore();
    std::string getPlayerName();
    void incrementFailedAttempts();
    bool score(RollOfDice rd,  Colour cl, int positionFromLeft);
    int setTotal();
    virtual int calcTotal() = 0;
    
    //Overload de l'opérateur
    virtual bool const operator !();
protected:
    virtual bool validate(RollOfDice rd,  Colour cl, int positionFromLeft) = 0;
};

#endif /* ScoreSheet_h */
