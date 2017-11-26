//
//  QwintoRow.cpp
//  DiceGame
//
//  Created by Alexandre Prud'Homme on 2017-11-25.
//  Copyright © 2017 Adel Araji. All rights reserved.
//

#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "RollofDice.h"
#include "QwintoRow.h"

//https://stackoverflow.com/questions/15723850/why-does-this-code-give-the-error-template-specialization-requires-template
template<>
bool QwintoRow<RED>::validate(RollOfDice rollOfDice, int position) {
    //might have to make a flag
    if (position > 0 && position < 13) {
        
    } else {
        return false;
    }
}

template<>
bool QwintoRow<YELLOW>::validate(RollOfDice rollOfDice, int position) {
    
}

template<>
bool QwintoRow<BLUE>::validate(RollOfDice rollOfDice, int position) {
    
}


