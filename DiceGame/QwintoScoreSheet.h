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
    //Variable d'instance
    QwintoRow<RED> redRow;
    QwintoRow<YELLOW> yellowRow;
    QwintoRow<BLUE> blueRow;
    
    /*
     * Trouver le maximum de trois entrées
     * @param int a
     * @param int b
     * @param int c
     * @return int
     */
    int findMax(int a, int b, int c);
    
    //Variable d'instance
    std::string playerName = ScoreSheet::getPlayerName();
    int failedAttempts = ScoreSheet::getNumberOfFailedAttempts();
    
    
public:
    
    //Constructeur
    QwintoScoreSheet(std::string name): ScoreSheet(name) {};
    
    /*
     * Voir si l'entré du pointage dans l'emplacement est valide
     * @param RollOfDice rd
     * @param Colour c1
     * @param int positionFromLeft
     * @return bool
     */
    virtual bool validate(RollOfDice rd, Colour cl, int positionFromLeft);
    
    /*
     * Calcul le pointage total
     * @return int
     */
    virtual int calcTotal();
    
    //Overload opérateur d'insertion
    friend std::ostream& operator<< (std::ostream& os, QwintoScoreSheet qw);
    
    
    
};

#endif /* QwintoScoreSheet_h */
