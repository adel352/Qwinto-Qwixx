/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#include <iostream>
#include "RollOfDice.h"
#include "Colour.h"

#ifndef ScoreSheet_h
#define ScoreSheet_h

/*
 * Classe abstraite ScoreSheet. ScoreSheet contient des méthodes virtuelles pures qui vont être implémenté
 * dans QwintoScoreSheet et QwixxScoreSheet
 */
class ScoreSheet {
    //Variables d'instance
    std::string nameOfPlayer;
    int numberOfFailedAttempts;
    int overallScore;
    
public:
    //Constructuer défaut
    ScoreSheet()=default;
    
    /*
     * Constructeur
     * @param std::string name
     */
    ScoreSheet(std::string name);
    
    //Destructeur
    ~ScoreSheet();
    
    /*
     * Cherche le nombre de faillites
     * @return int
     */
    int getNumberOfFailedAttempts();
    
    /*
     * Attribuer le pointage final
     * @param int score
     * @return void
     */
    void setFinalScore(int score);
    
    /*
     * Cherche le nom du joueur
     * @return std::string
     */
    std::string getPlayerName();
    
    /*
     * Calcule et vérifie le score dans la rangé
     * @param RollOfDice rd
     * @param Colour c1
     * @param int positionFromLeft
     * @return bool
     */
    bool score(RollOfDice rd,  Colour cl, int positionFromLeft);
    
    /*
     * Attribue le pointage total
     * @return int
     */
    int setTotal();
    
    /*
     * Calcul le pointage total
     * @return int
     */
    virtual int calcTotal() = 0;
    
    //Overload de l'opérateur
    virtual bool const operator !();
    //Note that we can't overload the insertion operator since this is an abstract class, it will be implemented in the children classes
protected:
    
    /*
     * Voir si l'entré du pointage dans l'emplacement est valide
     * @param RollOfDice rd
     * @param Colour c1
     * @param int positionFromLeft
     * @return bool
     */
    virtual bool validate(RollOfDice rd,  Colour cl, int positionFromLeft) = 0;//Pure virtual function to b implemented in children classes
};

#endif /* ScoreSheet_h */
