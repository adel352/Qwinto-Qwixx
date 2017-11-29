//
//  QwixxPlayer.h
//  DiceGame
//
//  Created by Alexandre Prud'Homme on 2017-11-29.
//  Copyright © 2017 Adel Araji. All rights reserved.
//

#ifndef QwixxPlayer_h
#define QwixxPlayer_h
#include "Player.h"
//#include "QwixxScoreSheet.h"
#include "RollOfDice.h"

class QwixxPlayer : Player {
private:
    //QwixxScoreSheet qwixxtoScoreSheet;
public:
    void inputBeforeRoll(RollOfDice rollOfDice);
    void inputAfterRoll(RollOfDice rollOfDice);
};

#endif /* QwixxPlayer_h */
