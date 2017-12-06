//
//  QwintoPlayer.h
//  DiceGame
//
//  Created by Alexandre Prud'Homme on 2017-11-29.
//  Copyright © 2017 Adel Araji. All rights reserved.
//

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
