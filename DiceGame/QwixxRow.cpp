/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#include <stdio.h>
#include "QwixxRow.h"


template<> bool *QwixxRow<std::vector<int>, RED>::getValuesObtainedByUser(){
    bool isValueObtainedByUser[11] = {false};
    
    for (std::vector<int>::const_iterator i =  container.begin(); i != container.end(); ++i)
        isValueObtainedByUser[*i-2] = true;
    
    return isValueObtainedByUser;
}

//Not sure about this
template<> bool *QwixxRow<std::list<int>, RED>::getValuesObtainedByUser(){
    bool isValueObtainedByUser[11] = {false};
    
    for (std::list<int>::const_iterator i =  container.begin(); i != container.end(); ++i)
        isValueObtainedByUser[*i-2] = true;
    
    return isValueObtainedByUser;
}

template<> bool *QwixxRow<std::vector<int>, YELLOW>::getValuesObtainedByUser(){
    bool isValueObtainedByUser[11] = {false};
    
    for (std::vector<int>::const_iterator i =  container.begin(); i != container.end(); ++i)
        isValueObtainedByUser[*i-2] = true;
    
    return isValueObtainedByUser;
}

//Not sure about this
template<> bool *QwixxRow<std::list<int>, YELLOW>::getValuesObtainedByUser(){
    bool isValueObtainedByUser[11] = {false};
    
    for (std::list<int>::const_iterator i =  container.begin(); i != container.end(); ++i)
        isValueObtainedByUser[*i-2] = true;
    
    return isValueObtainedByUser;
}

template<> bool *QwixxRow<std::list<int>, BLUE>::getValuesObtainedByUser(){
    bool isValueObtainedByUser[11] = {false};
    
    for (std::list<int>::const_iterator i =  container.begin(); i != container.end(); ++i)
        isValueObtainedByUser[12 - *i] = true;
    
    return isValueObtainedByUser;
}

//Not sure about this
template<> bool *QwixxRow<std::vector<int>, BLUE>::getValuesObtainedByUser(){
    bool isValueObtainedByUser[11] = {false};
    
    for (std::vector<int>::const_iterator i =  container.begin(); i != container.end(); ++i)
        isValueObtainedByUser[12 - *i] = true;
    
    return isValueObtainedByUser;
}

template<> bool *QwixxRow<std::list<int>, GREEN>::getValuesObtainedByUser(){
    bool isValueObtainedByUser[11] = {false};
    
    for (std::list<int>::const_iterator i =  container.begin(); i != container.end(); ++i)
        isValueObtainedByUser[12 - *i] = true;
    
    return isValueObtainedByUser;
}

//Not sure about this
template<> bool *QwixxRow<std::vector<int>, GREEN>::getValuesObtainedByUser(){
    bool isValueObtainedByUser[11] = {false};
    
    for (std::vector<int>::const_iterator i =  container.begin(); i != container.end(); ++i)
        isValueObtainedByUser[12 - *i] = true;
    
    return isValueObtainedByUser;
}

//Check for error
template<class T, Colour colour> void QwixxRow<T, colour>::checkForErrors(RollOfDice &rd){
    //If the RollOfDice does not contain 2 dice
    if (rd.getNumberOfDice() != 2)
        throw "RollOfDice is not of size 2";
    
    //RollOfDice should contain 1 white and one coloured dice
    if ((rd.getContainer()[0].getColour() != WHITE) && (rd.getContainer()[1].getColour() != WHITE))
        throw "Both of Dice are coloured, one of them should be white";
    
    //Check if sum of the 2 dice is correct or not
    if ((rd < 0) || (rd > 12))
        throw "Sum of the faces of the 2 dice is incorrect";
}


template<class T, Colour colour>
std::string QwixxRow<T, colour>::getRowString(){
    
    std::string returnValue;
    //Check if container is a vector
    bool containerIsVector = false;
    if(typeid(container) == typeid(std::vector<int>))
        containerIsVector = true;
    
    
    if (colour == RED)
        returnValue = "Red    ";
    else if (colour == BLUE)
        returnValue = "Blue   ";
    else if (colour == GREEN)
        returnValue = "Green  ";
    else if (colour == YELLOW)
        returnValue = "Yellow ";
    
    bool *isValueObtainedByUser;
    
    
    
    if ((colour == RED) || (colour == YELLOW)){
        //Check what values are obtained by the player with the roll of dice
        isValueObtainedByUser = getValuesObtainedByUser();
        
        //Condition array
        bool condition[11]={false};
        
        for (int i=0; i<11;i++){
            condition[i] = isValueObtainedByUser[i];
        }
  
        
        for (int i = 0; i < 11; i++){
            returnValue.append("|");
            
            if(condition[i]){
                returnValue.append("XX");
            }else{
                if(i+2 <= 9){
                    returnValue.append(" ");
                    returnValue.append(std::to_string(i + 2));
                }else
                    returnValue.append(std::to_string(i + 2));
            }
        }
    }else if ((colour == GREEN) || (colour == BLUE)){
        
        //Check what values are obtained by the player with the roll of dice
        isValueObtainedByUser = getValuesObtainedByUser();
        
        //Condition Array, filled with true in the indexes that are filled with values
        bool condition[11]={false};
        
        for (int i=0; i<11;i++){
            condition[i] = isValueObtainedByUser[i];
        }
        
        for (int i = 0; i < 11; i++){
            returnValue.append("|");
            if(condition[i]){
                returnValue.append("XX");
            }else{
                if (12-i <= 9){
                    returnValue.append(" ");
                    returnValue.append(std::to_string(12 - i));
                } else
                    returnValue.append(std::to_string(12 - i));
            }
        }
    }
    
    returnValue.append("|");
    
    
    return returnValue;
    
}

//Container: Vector; Colour RED
std::ostream& operator<<(std::ostream& os, QwixxRow<std::vector<int>, RED> &arrayRow){
    os << arrayRow.getRowString();
    return os;
}

//Container: Vector; Colour YELLOW
std::ostream& operator<<(std::ostream& os, QwixxRow<std::vector<int>, YELLOW> &arrayRow){
    os << arrayRow.getRowString();
    return os;
}

//Container: Vector; Colour GREEN
std::ostream& operator<<(std::ostream& os, QwixxRow<std::vector<int>, GREEN> &arrayRow){
    os << arrayRow.getRowString();
    return os;
}

//Container: Vector; Colour BLUE
std::ostream& operator<<(std::ostream& os, QwixxRow<std::vector<int>, BLUE> &arrayRow){
    os << arrayRow.getRowString();
    return os;
}

//Container: List; Colour RED
std::ostream& operator<<(std::ostream& os, QwixxRow<std::list<int>, RED> &arrayRow){
    os << arrayRow.getRowString();
    return os;
}

//Container: List; Colour YELLOW
std::ostream& operator<<(std::ostream& os, QwixxRow<std::list<int>, YELLOW> &arrayRow){
    os << arrayRow.getRowString();
    return os;
}

//Container: List; Colour GREEN
std::ostream& operator<<(std::ostream& os, QwixxRow<std::list<int>, GREEN> &arrayRow){
    os << arrayRow.getRowString();
    return os;
}

//Container: List; Colour BLUE
std::ostream& operator<<(std::ostream& os, QwixxRow<std::list<int>, BLUE> &arrayRow){
    os << arrayRow.getRowString();
    return os;
}

//+= operators

//Vector, RED

template<> QwixxRow<std::vector<int>,RED> QwixxRow<std::vector<int>,RED>::operator+=(RollOfDice &rd){
    
    checkForErrors(rd);
    container.push_back(rd);
    
    return *this;
}

//Vector, YELLOW
template<>
QwixxRow<std::vector<int>,YELLOW> QwixxRow<std::vector<int>,YELLOW>::operator+=(RollOfDice &rd){
    
    checkForErrors(rd);
    container.push_back(rd);
    
    return *this;
}

//Vector, GREEN
template<>
QwixxRow<std::vector<int>,GREEN> QwixxRow<std::vector<int>,GREEN>::operator+=(RollOfDice &rd){
    
   checkForErrors(rd);
   container.push_back(rd);
    
    return *this;
}

//Vector, BLUE
template<>
QwixxRow<std::vector<int>,BLUE> QwixxRow<std::vector<int>,BLUE>::operator+=(RollOfDice &rd){

    checkForErrors(rd);
    container.push_back(rd);

    return *this;
}

//List, GREEN
template<>
QwixxRow<std::list<int>,GREEN> QwixxRow<std::list<int>,GREEN>::operator+=(RollOfDice &rd){

    checkForErrors(rd);
    container.push_back(rd);

    return *this;
}

//List, RED
template<>
QwixxRow<std::list<int>,RED> QwixxRow<std::list<int>,RED>::operator+=(RollOfDice &rd){

    checkForErrors(rd);
    container.push_back(rd);

    return *this;
}

//List, YELLOW
template<>
QwixxRow<std::list<int>,YELLOW> QwixxRow<std::list<int>,YELLOW>::operator+=(RollOfDice &rd){

    checkForErrors(rd);
    container.push_back(rd);

    return *this;
}

//List, BLUE
template<>
QwixxRow<std::list<int>,BLUE> QwixxRow<std::list<int>,BLUE>::operator+=(RollOfDice &rd){

    checkForErrors(rd);
    container.push_back(rd);

    return *this;
}


