/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#ifndef QwixxPlayer_h
#define QwixxPlayer_h
#include <iostream>
#include <string>
#include <sstream>
#include "Player.h"
#include "QwixxScoreSheet.h"
#include "RollOfDice.h"

class QwixxPlayer : public Player {

public:
    QwixxPlayer();
    QwixxPlayer(std::string name);
    QwixxScoreSheet qwixxScoreSheet;
    
    int scoreFromTwoWhiteDice = 0;
    
    void inputBeforeRoll(RollOfDice& rollOfDice);
    void inputAfterRoll(RollOfDice& rollOfDice);
};

#endif /* QwixxPlayer_h */
