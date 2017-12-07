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

/*
 * Classe QwintoRow est une rangé de points du jeux Qwinto qui implémente le template Colour
 */
template <Colour colour>
class QwintoRow {
    private:
    //Array filled with 0 values in the beginning
    std::array<int,10> arrayRow = {0};
    
    public:
    //Overload de l'opérateur
    inline int& operator[] (const int position){
        return arrayRow[position];
    }

    /*
     * Vérifie si l'entré est valide dans la rangé du jeux Qwinto
     * @param RollOfDice rollOfDice
     * @param int position
     * @return bool
     */
    bool validate (RollOfDice rollOfDice, int position);
    
     //Overloading insertion operator
    friend std::ostream& operator<<(std::ostream& os, const QwintoRow<colour> arrayRow);
    
};

#endif /* QwintoRow_h */
