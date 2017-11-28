/*
 * CSI 2772 - Projet
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Colour.h"
#include "Dice.h"
#include "RandomDice.h"
#include "RollOfDice.h"
#include "QwintoRow.h"

int main() {
    /*
    Dice d(Colour::RED, 0);
    d.roll();
    std::cout << d << std::endl;
    d.roll();
    std::cout << d << std::endl;
    d.roll();
    std::cout << d << std::endl;
    d.roll();
    std::cout << d << std::endl;
    d.roll();
    std::cout << d << std::endl;
     */
    
    Dice d1(Colour::RED, 3);
    d1.roll();
    
    Dice d2(Colour::BLUE, 4);
    d2.roll();
    
    RollOfDice rd;
    
    rd.containerOfDice.push_back(d1);
    rd.containerOfDice.push_back(d2);
    
    std::cout << rd << std::endl;
    
    int total = rd;
    
    std::cout << "total is: " << total << std::endl;
    
    QwintoRow<RED> redRow;
    redRow[1]=5;
    redRow[5] = 10;
    
    
    std::cout << redRow.validate(rd,7) << std::endl;
    
    std::cout << redRow << std::endl;
    
    QwintoRow<YELLOW> yellowRow;
    
    yellowRow[0]=1;
    yellowRow[1]=3;
    yellowRow[2]=5;
    yellowRow[6]=12;
    yellowRow[7]=13;
    
    std::cout << yellowRow << std::endl;
    
    QwintoRow<BLUE> blueRow;
    
    blueRow[0] = 1;
    blueRow[1] = 4;
    blueRow[2] = 5;
    blueRow[7] = 14;
    
    std::cout << blueRow << std::endl;
    
    return 0;
}
