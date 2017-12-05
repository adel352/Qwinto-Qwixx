/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */


#ifndef QwixxRow_h
#define QwixxRow_h
#include "Colour.h"
#include "RollOfDice.h"
#include <vector>
#include <list>


template <class T, Colour colour>
class QwixxRow {
    T container ;//Later on initialize this container to have 0 values
    
public:
    inline QwixxRow<T,colour> operator+=(RollOfDice &rd);
    friend std::ostream& operator<<(std::ostream& os, QwixxRow &arrayRow);
    
    std::string getRowString();
    bool *getValuesObtainedByUser();
    void checkForErrors(RollOfDice &rd);
    
};





#endif /* QwixxRow_h */
