/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "RollofDice.h"
#include "QwintoRow.h"

/*
 * Validation de la méthode avec une rangé rouge
 * @param RollOfDice rollOfDice
 * @param int position
 * @return bool
 */
template<> bool QwintoRow<RED>::validate(RollOfDice rollOfDice, int position) {
    //The following are 3 eliminating conditions
    
    //Position 3 is blocked
    if (position == 3)
        return false;
    //Out of bounds condition
    else if (position < 0 || position > 9)
        return false;
    
    //Check that no values exist at and after the selected position
    for (int i = position ; i < 10; i++){
        if (arrayRow[i] != 0)
            return false;
    }
    
    bool isAddedValueBiggerThanPrevious = false;

    //In case the position is the one after the blocked cell
    for (int i = 0; i < position; i++)
    {
        if ((i != 3) && (arrayRow[i] > rollOfDice))
            return false;
        else
            isAddedValueBiggerThanPrevious = true;
    }

    return isAddedValueBiggerThanPrevious;
}

/*
 * Validation de la méthode avec une rangé jaune
 * @param RollOfDice rollOfDice
 * @param int position
 * @return bool
 */
template<> bool QwintoRow<YELLOW>::validate(RollOfDice rollOfDice, int position) {
    //The following are 3 eliminating conditions
    
    //Position 5 is blocked
    if (position == 5)
        return false;
    //Out of bounds condition
    else if (position < 0 || position > 9)
        return false;
    
    //Check that no values exist at and after the selected position
    for (int i = position ; i < 10; i++){
        if (arrayRow[i] != 0)
            return false;
    }
    
    bool isAddedValueBiggerThanPrevious = false;
    
    //In case the position is the one after the blocked cell
    for (int i = 0; i < position; i++)
    {
        if ((i != 5) && (arrayRow[i] > rollOfDice))
            return false;
        else
            isAddedValueBiggerThanPrevious = true;
    }
    
    return isAddedValueBiggerThanPrevious;
}

/*
 * Validation de la méthode avec une rangé bleu
 * @param RollOfDice rollOfDice
 * @param int position
 * @return bool
 */
template<> bool QwintoRow<BLUE>::validate(RollOfDice rollOfDice, int position) {
    //The following are 3 eliminating conditions
    
    //Position 4 is blocked
    if (position == 4)
        return false;
    //Out of bounds condition
    else if (position < 0 || position > 9)
        return false;
    
    //Check that no values exist at and after the selected position
    for (int i = position ; i < 10; i++){
        if (arrayRow[i] != 0)
            return false;
    }
    
    bool isAddedValueBiggerThanPrevious = false;
    
    //In case the position is the one after the blocked cell
    for (int i = 0; i < position; i++)
    {
        if ((i != 4) && (arrayRow[i] > rollOfDice))
            return false;
        else
            isAddedValueBiggerThanPrevious = true;
    }
    
    return isAddedValueBiggerThanPrevious;
}

//Output operator for Red Row
std::ostream& operator<<(std::ostream& os, const QwintoRow<RED> row){
    os << "Red      ";
    
    for (int i = 0; i < 10; i++){
        switch (i) {
            case 0:
                os << "|";
                break;
            case 1:
                os << "%";
                break;
            case 2:
                os << "%";
                break;
            case 3:
                os << "|XX";
                break;
            case 4:
                os << "|";
            case 5:
                os << "%";
                break;
            case 6:
                os << "%";
                break;
            default:
                os << "|";
                break;
        }
        
        if (i != 3){
            if (row.arrayRow[i] == 0)
                os << "  ";
            else if (row.arrayRow[i] <= 9)
                os << " " << row.arrayRow[i];
            else if (row.arrayRow[i] > 9)
                os << row.arrayRow[i];
        }
        
    }
    
    os << "|";
    
    return os;
}

//Output operator for Yellow Row
std::ostream& operator<<(std::ostream& os, const QwintoRow<YELLOW> row){
    os << "Yellow       ";
    
    for (int i = 0; i < 10; i++){
        switch (i) {
            case 5:
                os << "|XX";
                break;
            case 7:
                os << "%";
                break;
            case 8:
                os << "%";
                break;
            default:
                os << "|";
                break;
        }
        
        if (i != 5){
            if (row.arrayRow[i] == 0)
                os << "  ";
            else if (row.arrayRow[i] <= 9)
                os << " " << row.arrayRow[i];
            else if (row.arrayRow[i] > 9)
                os << row.arrayRow[i];
        }
        
    }
    
    os << "|";
    
    return os;
}

//Output operator for Blue Row
std::ostream& operator<<(std::ostream& os, const QwintoRow<BLUE> row){
    os << "Blue            ";
    
    for (int i = 0; i < 10; i++){
        switch (i) {
            case 2:
                os << "%";
                break;
            case 3:
                os << "%";
                break;
            case 4:
                os << "|XX";
                break;
            case 9:
                os << "%";
                break;
            default:
                os << "|";
                break;
        }
        
        if (i != 4){
            if (row.arrayRow[i] == 0)
                os << "  ";
            else if (row.arrayRow[i] <= 9)
                os << " " << row.arrayRow[i];
            else if (row.arrayRow[i] > 9)
                os << row.arrayRow[i];
        }
        
    }
    
    os << "%";
    
    return os;
}

