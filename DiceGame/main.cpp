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
#include <string>
#include <sstream>
#include "Colour.h"
#include "Dice.h"
#include "RandomDice.h"
#include "RollOfDice.h"
#include "QwintoRow.h"
#include "QwixxRow.h"
#include "QwintoPlayer.h"
#include "QwixxPlayer.h"
#include "ScoreSheet.h"
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
    
    //Variables d'instance
    std::string inputVersion;
    int inputNumberPlayers;
    std::string inputPlayerName;
    std::vector<Player*> vecteurPlayer;
    std::vector<ScoreSheet*> vecteurScoreSheet;
    
    //Titre de bienvenue
    std::cout << "********** Bienvenue au jeux de dés Qwinto-Qwixx **********" << std::endl;
    std::cout << std::endl;
    
    //Choisir Qwinto ou Qwixx
    std::cout << "Le jeux a deux versions, Qwinto et Qwixx. Entrer Qwinto ou Qwixx pour la version désiré:" << std::endl;
    std::cin >> inputVersion;
    inputVersion.erase(remove_if(inputVersion.begin(), inputVersion.end(), isspace), inputVersion.end());
    std::transform(inputVersion.begin(), inputVersion.end(), inputVersion.begin(), ::tolower);
    while (!(inputVersion == "qwinto" || inputVersion == "qwixx")) {
        std::cout << "Entrée non valide. Entrer Qwinto ou Qwixx pour la version désiré:" << std::endl;
        std::cin >> inputVersion;
        inputVersion.erase(remove_if(inputVersion.begin(), inputVersion.end(), isspace), inputVersion.end());
        std::transform(inputVersion.begin(), inputVersion.end(), inputVersion.begin(), ::tolower);
    }
    
    //Choisir le nombre de joueurs
    std::cout << "Entrer le nombre de joueurs qui veulent participer. Entrer une valeur numérique 1, 2 ou 3." << std::endl;
    std::cin >> inputNumberPlayers;
    //source pour cette section du code https://stackoverflow.com/questions/18728754/checking-input-value-is-an-integer
    /*
    while (std::cin.fail()) {
        std::cout << "Entrée non valide. Entrer le nombre de joueurs avec une valeur numérique" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> inputNumberPlayers;
    }
    */
    while (inputNumberPlayers != 1 && inputNumberPlayers != 2 && inputNumberPlayers != 3) {
        std::cout << "Entrée non valide. Entrer le nombre de joueurs avec une valeur numérique" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> inputNumberPlayers;
    }
    
    //Entrer le noms des joueurs
    for (int i = 0; i < inputNumberPlayers; i++) {
        std::cout << "Entrer le nom du joueur " << i+1 << std::endl;
        std::cin >> inputPlayerName;
        //New QwintoScoreSheet() then add the name to it to initialise the vecteur de scoresheet
        //vecteurScoreSheet.push_back(new );
    }
    
    //Créer les joueurs soient qwinto ou qwixx dans un vecteur de pointeurs
    if (inputVersion == "qwinto"){
        for (int i = 0; i < inputNumberPlayers; i++) {
            vecteurPlayer.push_back(new QwintoPlayer);
        }
    } else if (inputVersion == "qwixx") {
        for (int i = 0; i < inputNumberPlayers; i++) {
            vecteurPlayer.push_back(new QwixxPlayer());
        }
    } else {
        std::cout << "Erreur" << std::endl;
        return 0;
    }
    
    //Créer les roll of dices dans un vectuer de pointeurs
    std::vector<RollOfDice*> vecteurRollOfDice;
    for (int i = 0; i < inputNumberPlayers; i++) {
        vecteurRollOfDice.push_back(new RollOfDice());
    }
    
    //Using this for now. Can keep or maybe there is a better way for the while loop. Inc is increment to keep track
    //of the players
    bool flag = true;
    int i = 0;
    
    while (flag) {
        //for loop number of players? could just control with mod
        vecteurPlayer[i]->setActif(true);
        flag = false;
        auto &p = vecteurPlayer[i];
        auto &s = vecteurScoreSheet[i];
        if (inputVersion == "qwinto") {
            dynamic_cast<QwintoPlayer*>(p)->inputBeforeRoll(<#RollOfDice &rollOfDice#>);
            //roll the dice
            //dynamic_cast<Qwinto ScoreSheet*>(s)->   print
            dynamic_cast<QwintoPlayer*>(p)->Player::inputAfterRoll(<#RollOfDice &rollOfDice#>);
        } else {
            dynamic_cast<QwixxPlayer*>(p)->inputBeforeRoll(<#RollOfDice &rollOfDice#>);
            //roll the dice
            //dynamic_cast<QwixxScoreSheet*>(s)->   print
            dynamic_cast<QwixxPlayer*>(p)->inputAfterRoll(<#RollOfDice &rollOfDice#>);
        }
        for (int j = 0; j < inputNumberPlayers; j++) {
            if (vecteurPlayer[j]->getActif() == false) {
                if (inputVersion == "qwinto") {
                    //dynamic_cast<Qwinto ScoreSheet*>(s)->   print
                    dynamic_cast<QwintoPlayer*>(p)->Player::inputAfterRoll(<#RollOfDice &rollOfDice#>);
                } else {
                    //dynamic_cast<QwixxScoreSheet*>(s)->   print
                    dynamic_cast<QwixxPlayer*>(p)->inputAfterRoll(<#RollOfDice &rollOfDice#>);
                }
            }
        }
        vecteurPlayer[i]->setActif(false);
        i = (i+1) % inputNumberPlayers;
        //if (number fails == number fails) {flag = false;}
    }
    
    //***** Me testing shit ******
    RollOfDice* r = new RollOfDice();
    for (auto &i : vecteurPlayer) {
        dynamic_cast<QwintoPlayer*>(i)->inputBeforeRoll(*r);
    }
    
    return 0;
}
