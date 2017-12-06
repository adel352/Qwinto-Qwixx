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
#include "QwintoScoreSheet.h"
#include "QwixxScoreSheet.h"


/**
    Checks conditions and returns true or false depending if the Qwinto game has ended or not
 */
bool hasGameEndedForQwinto(std::vector<QwintoScoreSheet*> vec, int numOfPlayers){
    
    bool condition = false;
    for (int i = 0; i < numOfPlayers; i++){
        bool twoRowsLocked = false;
        int counter = 0;
        
        bool reachedFailedAttempts = false;
        
        if(vec[i]->isBlueRowLocked())
            counter++;
        if(vec[i]->isRedRowLocked())
            counter++;
        if(vec[i]->isYellowRowLocked())
            counter++;
        
        if(counter >=2)
            twoRowsLocked = true;
        
        if(vec[i]->getNumberOfFailedAttempts() ==4)
            reachedFailedAttempts = true;
        
        if (twoRowsLocked || reachedFailedAttempts){
            condition = true;
            break;
        }
    }
    return condition;
}

bool hasGameEndedForQwixx(std::vector<QwixxScoreSheet*> vec, int numOfPlayers){
    bool condition = false;
    for (int i = 0; i < numOfPlayers; i++){
        bool twoRowsLocked = false;
        int counter = 0;
        
        bool reachedFailedAttempts = false;
        
        if(vec[i]->blueRowLocked)
            counter++;
        if(vec[i]->redRowLocked)
            counter++;
        if(vec[i]->yellowRowLocked)
            counter++;
        if(vec[i]->greenRowLocked)
            counter++;
        
        if(counter >=2)
            twoRowsLocked = true;
        
        if(vec[i]->getNumberOfFailedAttempts() ==4)
            reachedFailedAttempts = true;
        
        if (twoRowsLocked || reachedFailedAttempts){
            condition = true;
            break;
        }
        
    }
    return condition;
}

int main() {

    //Variables d'instance
    std::string inputVersion;
    int inputNumberPlayers;
    std::string inputPlayerName;
    std::vector<QwintoPlayer*> vecteurQwintoPlayer;
    std::vector<QwixxPlayer*> vecteurQwixxPlayer;
    std::vector<QwintoScoreSheet*> vecteurQwintoScoreSheet;
    std::vector<QwixxScoreSheet*> vecteurQwixxScoreSheet;
    std::vector<int> vecteurFaillite;

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

    //Choisir le nombre de joueurs
    //source pour cette section du code https://stackoverflow.com/questions/18728754/checking-input-value-is-an-integer
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
        if (inputVersion == "qwinto") {
            vecteurQwintoScoreSheet.push_back(new QwintoScoreSheet(inputPlayerName));
        } else {
            vecteurQwixxScoreSheet.push_back(new QwixxScoreSheet(inputPlayerName));
        }
        vecteurFaillite.push_back(0);
        std::cin.clear();
        std::cin.ignore(256,'\n');
    }

    //Créer les joueurs soient qwinto ou qwixx dans un vecteur de pointeurs
    if (inputVersion == "qwinto"){
        for (int i = 0; i < inputNumberPlayers; i++) {
            vecteurQwintoPlayer.push_back(new QwintoPlayer);
        }
    } else if (inputVersion == "qwixx") {
        for (int i = 0; i < inputNumberPlayers; i++) {
            vecteurQwixxPlayer.push_back(new QwixxPlayer());
        }
    } else {
        std::cout << "Erreur" << std::endl;
        return 0;
    }

    //While loop for qwinto and qwix, qwixx to be added later
    //i indexes the player in the vectors, 0 means player 1
    int i = 0;
    int loopCounter = 0;
    bool loopCondition = false;
    if(inputVersion == "qwinto")
        loopCondition = !hasGameEndedForQwinto(vecteurQwintoScoreSheet, inputNumberPlayers);
    else if (inputVersion == "qwixx")
        loopCondition = !hasGameEndedForQwixx(vecteurQwixxScoreSheet, inputNumberPlayers);

    while(loopCondition){

        //Set turn to next player unless the game just started
        if (loopCounter != 0){
            if(inputNumberPlayers == 2){
                if(i == 0)
                    i++;
                else if (i == 1)
                    i = 0;
            }
            
            if(inputNumberPlayers == 3){
                if((i == 0) || (i == 1))
                    i++;
                else if (i == 2)
                    i = 0;
            }
        }
       


        //Créer le roll of dice
        RollOfDice* rollOfDice = new RollOfDice();

        //Set un joueur comme actif
        if (inputVersion == "qwinto") {
            vecteurQwintoPlayer[i]->setActif(true);
        } else {
            vecteurQwixxPlayer[i]->setActif(true);
        }

        //Joueur actif joue

        if (inputVersion == "qwinto") {//QWINTO IMPLEMETATION start
            vecteurQwintoPlayer[i]->setActif(true);
            //Print player number and name
            std::cout << "                         *********** ACTIVE PLAYER " << i + 1 <<": " << vecteurQwintoScoreSheet[i]->playerName << " **********" << std::endl;
            vecteurQwintoPlayer[i]->inputBeforeRoll(*rollOfDice);
            std::cout << "Votre sélection de dés sont: " << std::endl;
            rollOfDice->roll();
            std::cout << *rollOfDice << std::endl;
            std::cout << "Votre score sheet est: " << std::endl;
            std::cout << *vecteurQwintoScoreSheet[i] << std::endl;
            vecteurQwintoPlayer[i]->inputAfterRoll(*rollOfDice);
            if (!vecteurQwintoScoreSheet[i]->validate(*rollOfDice, rollOfDice->couleur, rollOfDice->position)) {
                vecteurFaillite[i]++;
                //Increment failed attempts
                vecteurQwintoScoreSheet[i]->incrementFailedAttempts();
                std::cout << "INVALID SCORE, 1 failed attempt" << std::endl;
            }else{
                //Score is valid and should be inserted in scoresheet
                if(rollOfDice->couleur == RED)
                    vecteurQwintoScoreSheet[i]->insertScoreInRow(*rollOfDice, RED, rollOfDice->position);
                else if (rollOfDice->couleur == YELLOW)
                    vecteurQwintoScoreSheet[i]->insertScoreInRow(*rollOfDice, YELLOW, rollOfDice->position);
                else if (rollOfDice->couleur == BLUE)
                    vecteurQwintoScoreSheet[i]->insertScoreInRow(*rollOfDice, BLUE, rollOfDice->position);

                
                
                //player set to non-active
                vecteurQwintoPlayer[i]->setActif(false);
                

                //Check if game ended after entering score
                if (hasGameEndedForQwinto(vecteurQwintoScoreSheet, inputNumberPlayers))
                    break;
            }//QWINTO IMPLEMETATION end
            
        } else {//QWIXX IMPLEMENTATION, active player
            vecteurQwixxPlayer[i]->setActif(true);
            //Print player number and name:
            std::cout << "                         *********** ACTIVE PLAYER " << i + 1 <<": " << vecteurQwixxScoreSheet[i]->playerName << " **********" << std::endl;
            
            vecteurQwixxPlayer[i]->inputBeforeRoll(*rollOfDice);
            std::cout << "Votre sélection de dés sont: " << std::endl;
            rollOfDice->roll();
            std::cout << *rollOfDice << std::endl;
            std::cout << "Votre score sheet est: " << std::endl;
            std::cout << *vecteurQwixxScoreSheet[i] << std::endl;
            vecteurQwixxPlayer[i]->inputAfterRoll(*rollOfDice);
            if (!vecteurQwixxScoreSheet[i]->validate(*rollOfDice, rollOfDice->couleur, rollOfDice->position)) {
                vecteurFaillite[i]++;
                //Increment failed attempts
                vecteurQwixxScoreSheet[i]->incrementFailedAttempts();
                std::cout << "INVALID SCORE, 1 failed attempt" << std::endl;
            }else{
                //Score is valid and should be inserted in scoresheet
                if(rollOfDice->couleur == RED)
//                    vecteurQwixxScoreSheet[i]->insertScoreInRow(*rol, <#Colour cl#>)
                
                
                //player set to non-active
                vecteurQwixxPlayer[i]->setActif(false);
                
                
                //Check if game ended after entering score
                if (hasGameEndedForQwixx(vecteurQwixxScoreSheet, inputNumberPlayers))
                    break;
            }
            
            //Second roll for qwixx
            if (rollOfDice->qwixxSecondRoll == true) {
                vecteurQwixxPlayer[i]->inputAfterRoll(*rollOfDice);
                if (!vecteurQwixxScoreSheet[i]->validate(*rollOfDice, rollOfDice->couleur, rollOfDice->position)) {
                    vecteurFaillite[i]++;
                }
            }
            //
            //
            // Insert score in scoresheet
            //
            //
            vecteurQwixxPlayer[i]->setActif(true);
        }//END OF QWIXX IMPLEMENTATION
        
        //Les joueurs non actifs jouent
        int numberOfInactivePlayers = inputNumberPlayers - 1;
        
        //k is used to index the upcoming inactive users
        int k = i;
        for (int j = 0; j < numberOfInactivePlayers; j++) {
            if(k == inputNumberPlayers - 1)
                k = 0;
            else
                k++;
            
            if (inputVersion == "qwinto") {
                vecteurQwintoPlayer[k]->setActif(false);
                    std::cout << "                         *********** INACTIVE PLAYER " << k + 1 << ": "<< vecteurQwintoScoreSheet[k]->playerName << " **********" << std::endl;
                    std::cout << "Votre sélection de dés sont: " << std::endl;
                    std::cout << *rollOfDice << std::endl;
                    std::cout << "Votre score sheet est: " << std::endl;
                    std::cout << *vecteurQwintoScoreSheet[k] << std::endl;
                    vecteurQwintoPlayer[k]->inputAfterRoll(*rollOfDice);
                    if (!vecteurQwintoScoreSheet[k]->validate(*rollOfDice, rollOfDice->couleur, rollOfDice->position)) {
                        //SHOULD REMOVE failed attempts here
                        vecteurFaillite[k]++;
                        
                        //Increment failed attempts
                        vecteurQwintoScoreSheet[k]->incrementFailedAttempts();
                        std::cout << "INVALID SCORE, 1 failed attempt" << std::endl;
                    }else{
                        //Score is valid and should be inserted in scoresheet
                        if(rollOfDice->couleur == RED)
                            vecteurQwintoScoreSheet[k]->insertScoreInRow(*rollOfDice, RED, rollOfDice->position);
                        else if (rollOfDice->couleur == YELLOW)
                            vecteurQwintoScoreSheet[k]->insertScoreInRow(*rollOfDice, YELLOW, rollOfDice->position);
                        else if (rollOfDice->couleur == BLUE)
                            vecteurQwintoScoreSheet[k]->insertScoreInRow(*rollOfDice, BLUE, rollOfDice->position);
                        
                        
                        
                        
                        //Check if game ended after entering score
                        if (hasGameEndedForQwinto(vecteurQwintoScoreSheet, inputNumberPlayers))
                            break;
                    }
                
            } else {//QWIXX IMPLEMENTATION start
               
            }//QWIXX IMPLEMENTATION end
        }
        loopCounter++;
    }
    
    int mediator = 0;
    int mediatorIndex = 0;
    int max =0;
    int winnerIndex = 0;
    std::vector<int> results;
    
    //Calculer le score total et déterminer le gagnant
    std::cout << "************************************** Résultas finaux **************************************" << std::endl;
    for (int i = 0; i < inputNumberPlayers; i++) {
        if (inputVersion == "qwinto") {
            std::cout << *vecteurQwintoScoreSheet[i] << std::endl;
            results.push_back(vecteurQwintoScoreSheet[i]->calcTotal());
        } else {
            std::cout << *vecteurQwixxScoreSheet[i] << std::endl;
            results.push_back(vecteurQwixxScoreSheet[i]->calcTotal());
        }
    }
    
    //Determine max
    if(inputNumberPlayers == 1){
        max = results[0];
        winnerIndex = 0;
    }else if (inputNumberPlayers == 2){
        if(results[0] > results [1]){
            max = results[0];
            winnerIndex = 0;
        }
        else{
            max = results[1];
            winnerIndex = 1;
        }
    }else if (inputNumberPlayers == 3){
        if(results[0] > results [1]){
            mediator = results[0];
            mediatorIndex = 0;
        }else{
            mediator = results[1];
            mediatorIndex = 1;
        }
        
        if(results[2] > mediator){
            max = results[2];
            winnerIndex = 2;
        }else{
            max = mediator;
            winnerIndex = mediatorIndex;
        }
    }
        
    
    //Afficher le gagnant
    std::cout << "Bravo " << vecteurQwintoScoreSheet[winnerIndex]->playerName<< ",tu as gagné!" << std::endl;
    std::cout << "********** Fin du jeux de dés Qwinto-Qwixx **********" << std::endl;
    
    return 0;
}
