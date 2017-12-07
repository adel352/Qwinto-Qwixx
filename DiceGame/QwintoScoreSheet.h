/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#include "ScoreSheet.h"
#include "QwintoRow.h"
#include "Colour.h"
#include "RollOfDice.h"

#ifndef QwintoScoreSheet_h
#define QwintoScoreSheet_h

/*
 * Classe QwintoScoreSheet crée la feuille de points pour le jeux de dés Qwinto
 * QwintoScoreSheet sous classe de ScoreSheet
 */
class QwintoScoreSheet: public ScoreSheet {
    
    QwintoRow<RED> redRow;
    QwintoRow<YELLOW> yellowRow;
    QwintoRow<BLUE> blueRow;
    
    int findMax(int a, int b, int c);
    int failedAttempts = ScoreSheet::getNumberOfFailedAttempts();
public:
    
    QwintoScoreSheet() = default;
    QwintoScoreSheet(std::string name): ScoreSheet(name) {
    };
    
    std::string playerName = ScoreSheet::getPlayerName();
    bool isRedRowLocked();
    bool isBlueRowLocked();
    bool isYellowRowLocked();
    
    virtual bool validate(RollOfDice rd, Colour cl, int positionFromLeft);
    virtual int calcTotal();
    friend std::ostream& operator<< (std::ostream& os, QwintoScoreSheet qw);
    void incrementFailedAttempts();
    void insertScoreInRow (int score, Colour cl, int position);
};

#endif /* QwintoScoreSheet_h */
