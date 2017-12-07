/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#ifndef QwintoPlayer_h
#define QwintoPlayer_h
#include <iostream>
#include <string>
#include <sstream>
#include "Player.h"
#include "QwintoScoreSheet.h"
#include "RollOfDice.h"

class QwintoPlayer : public Player {
    
public:
    QwintoPlayer();
    QwintoPlayer(std::string name);
    
    QwintoScoreSheet qwintoScoreSheet;
    
    void inputBeforeRoll(RollOfDice& rollOfDice);
    void inputAfterRoll(RollOfDice& rollOfDice);
    
    void setPlayerNameInScoreSheet(std::string name);
};

#endif /* QwintoPlayer_h */
