//
//  QwixxRow.cpp
//  DiceGame
//
//  Created by Adel Araji on 2017-11-27.
//  Copyright © 2017 Adel Araji. All rights reserved.
//

#include <stdio.h>
#include "QwixxRow.h"


template<class T, Colour colour>
std::string QwixxRow<T, colour>::getRowString(){
    
    std::string returnValue;
    //Check if container is a vector
    bool containerIsVector = false;
    if(typeid(container) == typeid(std::vector<int>))
        containerIsVector = true;
    
    if (containerIsVector) {
        if (colour == RED)
            returnValue = "Red   ";
        else if (colour == BLUE)
            returnValue = "Blue ";
        else if (colour == GREEN)
            returnValue = "Green ";
        else if (colour == YELLOW)
            returnValue = "Yellow ";
        
        bool isValueObtainedByUser[11] = {false};
        
        
        
        if ((colour == RED) || (colour == YELLOW)){
            //Check what values are obtained by the player with the roll of dice
            for (std::vector<int>::const_iterator i =  container.begin(); i != container.end(); ++i)
                isValueObtainedByUser[*i-2] = true;
            
            for (int i = 0; i < 11; i++){
                returnValue.append("|");
                if(isValueObtainedByUser[i]){
                    returnValue.append("XX");
                }else{
                    if(i+2 < 9){
                        returnValue.append(" ");
                        returnValue.append(std::to_string(i + 2));
                    }else
                        returnValue.append(std::to_string(i + 2));
                }
            }
        }else if ((colour == GREEN) || (colour == BLUE)){
            
            //Check what values are obtained by the player with the roll of dice
            for (std::vector<int>::const_iterator i =  container.begin(); i != container.end(); ++i)
                isValueObtainedByUser[12 - *i] = true;
            
            for (int i = 0; i < 11; i++){
                returnValue.append("|");
                if(isValueObtainedByUser[i]){
                    returnValue.append("XX");
                }else{
                    if (12-i < 9){
                        returnValue.append(" ");
                        returnValue.append(std::to_string(12 - i));
                    } else
                        returnValue.append(std::to_string(12 - i));
                }
            }
        }
        
        returnValue.append("|");
    }
    
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

