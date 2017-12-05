/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#ifndef QwintoRow_h
#define QwintoRow_h
#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <array>
#include "Colour.h"
#include "RollOfDice.h"

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
