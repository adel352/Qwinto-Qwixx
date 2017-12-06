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

/*
 * Classe QwixxoScoreSheet crée la feuille de points pour le jeux de dés Qwixx
 * QwixxoScoreSheet sous classe de ScoreSheet
 */
class QwixxScoreSheet: public ScoreSheet{
    
    //Variables de vecteur d'instances
    QwixxRow<std::vector<int>, RED> redRow;
    QwixxRow<std::vector<int>, YELLOW> yellowRow;
    QwixxRow<std::list<int>, BLUE> blueRow;
    QwixxRow<std::list<int>, GREEN> greenRow;
    
    //boolean used for printing later
    bool redRowLocked = false;
    bool yellowRowLocked = false;
    bool greenRowLocked = false;
    bool blueRowLocked = false;
    
    //Variable d'instance
    std::string playerName = ScoreSheet::getPlayerName();
    int failedAttempts = ScoreSheet::getNumberOfFailedAttempts();
public:
    //Constructeur
    QwixxScoreSheet(std::string name): ScoreSheet(name) {};
    
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
    
    //Overload l'opératuer d'insertion
    friend std::ostream& operator<< (std::ostream& os, QwixxScoreSheet qw);
    
   
};

#endif /* QwixxScoreSheet_h */

