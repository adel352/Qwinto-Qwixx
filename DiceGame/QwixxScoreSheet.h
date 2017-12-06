//
//  QwixxScoreSheet.h
//  DiceGame
//
//  Created by Adel Araji on 2017-12-02.
//  Copyright © 2017 Adel Araji. All rights reserved.
//


#include "ScoreSheet.h"
#include "QwixxRow.h"
#include "Colour.h"
#include "RollOfDice.h"
#include <vector>
#include <list>

#ifndef QwixxScoreSheet_h
#define QwixxScoreSheet_h

class QwixxScoreSheet: public ScoreSheet{
    QwixxRow<std::vector<int>, RED> redRow;
    QwixxRow<std::vector<int>, YELLOW> yellowRow;
    QwixxRow<std::list<int>, BLUE> blueRow;
    QwixxRow<std::list<int>, GREEN> greenRow;
    
    
    
    
    int failedAttempts = ScoreSheet::getNumberOfFailedAttempts();
public:
    QwixxScoreSheet() = default;
    QwixxScoreSheet(std::string name): ScoreSheet(name) {};
    
    //boolean used for printing later
    bool redRowLocked = false;
    bool yellowRowLocked = false;
    bool greenRowLocked = false;
    bool blueRowLocked = false;
    
    virtual bool validate(RollOfDice rd, Colour cl, int positionFromLeft);
    virtual int calcTotal();
    friend std::ostream& operator<< (std::ostream& os, QwixxScoreSheet qw);
    
    void incrementFailedAttempts();
    std::string playerName = ScoreSheet::getPlayerName();
    
    void insertScoreInRow (int score, Colour cl);
};

#endif /* QwixxScoreSheet_h */

