//
//  QwixxPlayer.h
//  DiceGame
//
//  Created by Alexandre Prud'Homme on 2017-11-29.
//  Copyright © 2017 Adel Araji. All rights reserved.
//

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
    void inputBeforeRoll(RollOfDice& rollOfDice);
    void inputAfterRoll(RollOfDice& rollOfDice);
};

#endif /* QwixxPlayer_h */
