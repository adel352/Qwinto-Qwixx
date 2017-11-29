//
//  QwintoScoreSheet.h
//  DiceGame
//
//  Created by Adel Araji on 2017-11-28.
//  Copyright © 2017 Adel Araji. All rights reserved.
//

#include "ScoreSheet.h"
#include "QwintoRow.h"
#include "Colour.h"
#include "RollOfDice.h"

#ifndef QwintoScoreSheet_h
#define QwintoScoreSheet_h


class QwintoScoreSheet: public ScoreSheet {
    
    QwintoRow<RED> redRow;
    QwintoRow<YELLOW> yellowRow;
    QwintoRow<BLUE> blueRow;
    
    int findMax(int a, int b, int c);
    std::string playerName = ScoreSheet::getPlayerName();
    int failedAttempts = ScoreSheet::getNumberOfFailedAttempts();
    
    
public:
    QwintoScoreSheet(std::string name): ScoreSheet(name) {};
    
    virtual bool validate(RollOfDice rd, Colour cl, int positionFromLeft);
    virtual int calcTotal();
    friend std::ostream& operator<< (std::ostream& os, QwintoScoreSheet qw);
    
    
    
};

#endif /* QwintoScoreSheet_h */
