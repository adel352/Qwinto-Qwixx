//
//  RollofDice.h
//  DiceGame
//
//  Created by Alexandre Prud'Homme on 2017-11-25.
//  Copyright © 2017 Adel Araji. All rights reserved.
//

#ifndef RollofDice_h
#define RollofDice_h

struct RollOfDice {
private:
    std::vector<Dice> containerOfDice;
public:
    void roll();
    
    // Takes the colours of 2 dice and returns a RollOFDice containing them
    RollOfDice pair(Colour d1, Colour d2);
    
    //Conversion to int Operator
    operator int() const;
    
    //Overloading insertion operator
    friend std::ostream &operator<<(std::ostream& os, const RollOfDice &dc);
};

#endif /* RollofDice_h */
