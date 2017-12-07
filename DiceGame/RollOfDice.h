/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#ifndef RollofDice_h
#define RollofDice_h
#include "Dice.h"

/*
 * Strucute RollOfDice est un container de dés
 */
struct RollOfDice {

public:
    Colour couleur;
    int position;
    bool qwixxSecondRoll;
    std::vector<Dice> containerOfDice;
    bool choix;
    
    /*
     * Implementation méthode roll
     * @return void
     */
    void roll();
    
    /*
     * Recoit deux dés et retourne un RollOfDice qui les contients
     * @param Dice d1
     * @param Dice d2
     * @return RollOfDice
     */
    RollOfDice pair(Dice d1, Dice d2);
    
    //Conversion to int Operator
    operator int() const;
    
    //Overloading insertion operator
    friend std::ostream &operator<<(std::ostream& os, const RollOfDice &dc);
    
    /*
     * Chercher la grandeur du container
     * @return int
     */
    int getNumberOfDice();
    
    /*
     * Chercher le container
     * @return std::vectuer<Dice>
     */
    std::vector<Dice> getContainer();
};

#endif /* RollofDice_h */
