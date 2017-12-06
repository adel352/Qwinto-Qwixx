//
//  RollofDice.h
//  DiceGame
//
//  Created by Alexandre Prud'Homme on 2017-11-25.
//  Copyright © 2017 Adel Araji. All rights reserved.
//

#ifndef RollofDice_h
#define RollofDice_h
#include "Dice.h"

struct RollOfDice {
private:
//    std::vector<Dice> containerOfDice;
public:
    Colour couleur;
    int position;
    bool qwixxSecondRoll;
    
    std::vector<Dice> containerOfDice;
    void roll();
    
    // Takes 2 dice and returns a RollOFDice containing them
    RollOfDice pair(Dice d1, Dice d2);
    
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
