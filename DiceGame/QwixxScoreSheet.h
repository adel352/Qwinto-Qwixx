/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

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
    
public:
    QwixxScoreSheet() = default;
    QwixxScoreSheet(std::string name): ScoreSheet(name) {};
    
    std::string playerName = ScoreSheet::getPlayerName();
    std::vector<int> getVectorElementsInRow(Colour cl);
    std::list<int> getListElementsInRow(Colour cl);
    bool redRowLocked = false;
    bool yellowRowLocked = false;
    bool greenRowLocked = false;
    bool blueRowLocked = false;
    
    virtual bool validate(RollOfDice rd, Colour cl, int positionFromLeft);
    virtual int calcTotal();
    friend std::ostream& operator<< (std::ostream& os, QwixxScoreSheet qw);
    void incrementFailedAttempts();
    void insertScoreInRow (int score, Colour cl);  
};

#endif /* QwixxScoreSheet_h */

