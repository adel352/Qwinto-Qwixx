//
//  Player.h
//  DiceGame
//
//  Created by Alexandre Prud'Homme on 2017-11-29.
//  Copyright © 2017 Adel Araji. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include "RollOfDice.h"

class Player {
private:
    bool actif;
public:
    bool getActif();
    void setActif(bool statusActif);
    virtual void inputBeforeRoll(RollOfDice rollOfDice);
    virtual void inputAfterRoll(RollOfDice rollOfDice);
};

#endif /* Player_h */
