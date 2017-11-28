//
//  QwintoRow.h
//  DiceGame
//
//  Created by Alexandre Prud'Homme on 2017-11-25.
//  Copyright © 2017 Adel Araji. All rights reserved.
//

#ifndef QwintoRow_h
#define QwintoRow_h
#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <array>
#include "Colour.h"
#include "RollofDice.h"

template <Colour colour>
class QwintoRow {
    private:
    //Array filled with 0 values in the beginning
    std::array<int,10> arrayRow = {0};
    
    public:
    inline int& operator[] (const int position){
        return arrayRow[position];
    }

    bool validate (RollOfDice rollOfDice, int position);
    friend std::ostream& operator<<(std::ostream& os, const QwintoRow<colour> arrayRow);
};

#endif /* QwintoRow_h */
