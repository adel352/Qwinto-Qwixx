//
//  QwixxRow.h
//  DiceGame
//
//  Created by Adel Araji on 2017-11-27.
//  Copyright © 2017 Adel Araji. All rights reserved.
//


#ifndef QwixxRow_h
#define QwixxRow_h
#include "Colour.h"
#include "RollOfDice.h"
#include <vector>
#include <list>


template <class T, Colour colour>
class QwixxRow {
    
    
public:
    inline QwixxRow<T,colour> operator+=(RollOfDice &rd);
    friend std::ostream& operator<<(std::ostream& os, QwixxRow &arrayRow);
    
    T container ;//Later on initialize this container to have 0 values
    std::string getRowString();
    bool *getValuesObtainedByUser();
    void checkForErrors(RollOfDice &rd);
    
};





#endif /* QwixxRow_h */
