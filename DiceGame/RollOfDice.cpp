/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#include <stdio.h>
#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Dice.h"
#include "RollOfDice.h"

/*
 * Implementation méthode roll
 * @return void
 */
void RollOfDice::roll() {
    for (Dice d: containerOfDice){
        d.roll();
    }
}

/*
 * Recoit la couleur de deux dés et retourne un RollOfDice qui les contients
 * @param Colour d1
 * @param Colour d2
 * @return RollOfDice
 */
RollOfDice RollOfDice::pair(Colour d1, Colour d2)
{
    RollOfDice returnValue;
    //Search for the appropriate colour
    for (Dice d: containerOfDice){
        if((d.getColour() == d1) || (d.getColour() == d2))
            //Add dice if the colour is matched
            returnValue.containerOfDice.push_back(d);
    }
    
    return returnValue;
}

//Conversion to int Operator
RollOfDice::operator int() const {
    int sum = 0;
    
    for (Dice d: containerOfDice)
    {
        sum = sum + d.getFace();
    }
    return sum;
}

//Overloading insertion operator
//https://stackoverflow.com/questions/35904143/friend-not-allowed-outside-of-a-class-definition
std::ostream &operator<<(std::ostream& os, const RollOfDice &dc)
{
    //Print all dices stored in the container
    for (Dice d: dc.containerOfDice){
        os << d << "\n";
    }
    
    return os;
}

/*
 * Chercher la grandeur du container
 * @return int
 */
int RollOfDice::getNumberOfDice()
{
    return containerOfDice.size();
}

/*
 * Chercher le container
 * @return std::vectuer<Dice>
 */
std::vector<Dice> RollOfDice::getContainer()
{
    return containerOfDice;
}

