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

template <Colour colour>
class QwintoRow {
private: //Would this be private i am not sure
    int row[12];
    int operator[] (int position) {
        return row[position];
    }
public:
    bool validate (RollofDice rollOfDice, int position);
    friend std::ostream& operator<<(std::ostream& os, const QwintoRow& qwintoRow);
};


#endif /* QwintoRow_h */
