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
#include <array>
#include "Colour.h"
#include "Dice.h"
#include "RandomDice.h"
#include "RollOfDice.h"
#include "QwintoRow.h"
#include "QwixxRow.h"

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
    
    
    //QwixxRow TEST
    
    QwixxRow<std::vector<int>,RED> redQuixxRow;
    QwixxRow<std::vector<int>,GREEN> greenQuixxRow;
    
    //Have a rollOdice with white and red
    
    Dice redDice(Colour::RED, 5);
    Dice greenDice(Colour::GREEN, 6);
    Dice whiteDice(Colour::WHITE, 6);
    
    RollOfDice yoo;
    yoo.containerOfDice.push_back(redDice);
    yoo.containerOfDice.push_back(whiteDice);
    
    RollOfDice greenYo;
    greenYo.containerOfDice.push_back(greenDice);
    greenYo.containerOfDice.push_back(whiteDice);
    
    std::cout << yoo.getNumberOfDice() << std::endl;
    
    try {
        redQuixxRow += yoo;
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
    
    
    std::cout << redQuixxRow << std::endl;
    
    try {
        greenQuixxRow += greenYo;
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
    std::cout << greenQuixxRow << std::endl;
    */
    
    std::string inputVersion;
    int inputNumberPlayers;
    std::string inputPlayerName;
    std::vector<std::string> vectorNomJoueur;
    
    std::cout << "********** Bienvenue au jeux de dés Qwinto-Qwixx **********" << std::endl;
    std::cout << std::endl;
    std::cout << "Le jeux a deux versions, Qwinto et Qwixx. Entrer Qwinto ou Qwixx pour la version désiré:" << std::endl;
    std::cin >> inputVersion;
    std::cout << std::endl;
    std::transform(inputVersion.begin(), inputVersion.end(), inputVersion.begin(), ::tolower);
    std::cout << "Entrer le nombre de joueurs qui veulent participer. Entrer une valeur numérique." << std::endl;
    std::cin >> inputNumberPlayers;
    std::cout << std::endl;
    for (int i = 0; i < inputNumberPlayers; i++) {
        std::cout << "Entrer le nom du joueur " << i << std::endl;
        std::cin >> inputPlayerName;
        vectorNomJoueur.push_back(inputPlayerName);
    }
    
    
    
    
    
    
    
    return 0;
}
