/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#ifndef RollofDice_h
#define RollofDice_h
#include "Dice.h"
#include "Colour.h"

struct RollOfDice {
private:
//    std::vector<Dice> containerOfDice;
public:
    Colour couleur;
    int position;
    bool qwixxSecondRoll;
    
    std::vector<Dice> containerOfDice;
    void roll();
    
    // Takes the colours of 2 dice and returns a RollOFDice containing them
    RollOfDice pair(Colour d1, Colour d2);
    
    //Conversion to int Operator
    operator int() const;
    
    //Overloading insertion operator
    friend std::ostream &operator<<(std::ostream& os, const RollOfDice &dc);
    
    //Getting the size of the container
    int getNumberOfDice();
    
    //Getting the vector back
    std::vector<Dice> getContainer();
};

#endif /* RollofDice_h */
