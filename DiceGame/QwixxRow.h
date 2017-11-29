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


template <class T, Colour colour>
class QwixxRow {
    T container ;//Later on initialize this container to have 0 values
    
public:
    QwixxRow<T,colour> operator+=(RollOfDice &rd);
    friend std::ostream& operator<<(std::ostream& os, QwixxRow &arrayRow);
    std::string getRowString();
};

template<class T, Colour colour>
QwixxRow<T,colour> QwixxRow<T, colour>::operator+=(RollOfDice &rd)
{
    
    //If the RollOfDice does not contain 2 dice
    if (rd.getNumberOfDice() != 2)
        throw "RollOfDice is not of size 2";
    
    //RollOfDice should contain 1 white and one coloured dice
    if ((rd.getContainer()[0].getColour() != WHITE) && (rd.getContainer()[1].getColour() != WHITE))
        throw "Both of Dice are coloured, one of them should be white";
    
    //Check if sum of the 2 dice is correct or not
    if ((rd < 0) || (rd > 12))
        throw "Sum of the faces of the 2 dice is incorrect";
    
    //Adding the RollOfDice after checking for errors
    bool isOneOfDiceRed = (rd.getContainer()[0].getColour() == RED || rd.getContainer()[1].getColour() == RED);
    bool isOneOfDiceYellow = (rd.getContainer()[0].getColour() == YELLOW || rd.getContainer()[1].getColour() == YELLOW);
    bool isOneOfDiceGreen = (rd.getContainer()[0].getColour() == GREEN || rd.getContainer()[1].getColour() == GREEN);
    bool isOneOfDiceBlue = (rd.getContainer()[0].getColour() == BLUE || rd.getContainer()[1].getColour() == BLUE);
    
//    if (isOneOfDiceRed || isOneOfDiceYellow){
//        //If the container is a vector
//        if (typeid(container) == typeid(std::vector<int>)){
            int num = rd;
            std::vector<int> v;
            v.push_back(num);
            container = v;
//        }
//
//    }
//    else if (isOneOfDiceGreen || isOneOfDiceBlue){
//        container[10 - rd + 2] = rd;
//    }
    
    return *this;
}

//template<class T, Colour colour>
//std::ostream& operator<<(std::ostream& os, QwixxRow<T,colour> &arrayRow){
//    if(colour == RED){
//        os << "Red   ";
//        
//        
//        bool isValueObtainedByUser[11] = {false};
//        
//        //Check what values are obtained by the player with the roll of dice
//        for (std::vector<int>::const_iterator i =  arrayRow.getContainer.begin(); i != arrayRow.container.end(); ++i)
//            isValueObtainedByUser[*i-2] = true;
//        
//        for (int i = 0; i < 11; i++){
//            os << "|";
//            if(isValueObtainedByUser[i]){
//                os << "XX";
//            }else{
//                os << i + 2;
//            }
//        }
//        
//        os << "|";
//        
//        
//    }
//    
//    return os;
//}


#endif /* QwixxRow_h */
