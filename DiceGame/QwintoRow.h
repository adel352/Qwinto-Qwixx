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
#include "Colour.h"
#include "RollofDice.h"

template <Colour colour>
class QwintoRow {
    private:
        int qwintoRow[12];
        int operator[] (int position) {
            return qwintoRow[position];
        }
    public:
        bool validate (RollOfDice rollOfDice, int position);
        friend std::ostream& operator<<(std::ostream& os, const QwintoRow& qwintoRow);
};

#endif /* QwintoRow_h */
