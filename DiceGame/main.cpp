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
#include "QwintoScoreSheet.h"
#include "QwixxScoreSheet.h"
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
    
    //Using this for now. Can keep or maybe there is a better way for the while loop. Inc is increment to keep track
    //of the players
    bool flag = true;
    int i = 0;
    
    //While qui roule le jeux
    while (flag) {
        flag = false;
        
        //auto &s = vecteurScoreSheet[i];
        
        //Créer le roll of dice
        RollOfDice* rollOfDice = new RollOfDice();
        
        //Set un joueur comme actif
        if (inputVersion == "qwinto") {
            vecteurQwintoPlayer[i]->setActif(true);
        } else {
            vecteurQwixxPlayer[i]->setActif(true);
        }
        
        //Joueur actif joue
        std::cout << "did i get here5" << std::endl;
        if (inputVersion == "qwinto") {
            vecteurQwintoPlayer[i]->inputBeforeRoll(*rollOfDice);
            std::cout << "Votre sélection de dés sont: " << std::endl;
            rollOfDice->roll();
            std::cout << *rollOfDice << std::endl;
            std::cout << "Votre score sheet est: " << std::endl;
            std::cout << *vecteurQwintoScoreSheet[i] << std::endl;
            vecteurQwintoPlayer[i]->inputAfterRoll(*rollOfDice);
            if (!vecteurQwintoScoreSheet[i]->validate(*rollOfDice, rollOfDice->couleur, rollOfDice->position)) {
                vecteurFaillite[i]++;
            }
            //
            //
            // Insert score in scoresheet
            //
            //
        } else {
            vecteurQwixxPlayer[i]->inputBeforeRoll(*rollOfDice);
            std::cout << "Votre sélection de dés sont: " << std::endl;
            rollOfDice->roll();
            std::cout << *rollOfDice << std::endl;
            std::cout << "Votre score sheet est: " << std::endl;
            std::cout << *vecteurQwixxScoreSheet[i] << std::endl;
            vecteurQwixxPlayer[i]->inputAfterRoll(*rollOfDice);
            if (!vecteurQwixxScoreSheet[i]->validate(*rollOfDice, rollOfDice->couleur, rollOfDice->position)) {
                vecteurFaillite[i]++;
            }
            //
            //
            // Insert score in scoresheet
            //
            //
            vecteurQwixxPlayer[i]->setActif(false);
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
        }
        
        //Les joueurs non actifs jouent
        for (int j = 0; j < inputNumberPlayers; j++) {
            if (inputVersion == "qwinto") {
                if (vecteurQwintoPlayer[j]->getActif() == false){
                    std::cout << "Votre sélection de dés sont: " << std::endl;
                    rollOfDice->roll();
                    std::cout << *rollOfDice << std::endl;
                    std::cout << "Votre score sheet est: " << std::endl;
                    std::cout << *vecteurQwintoScoreSheet[j] << std::endl;
                    vecteurQwintoPlayer[j]->inputAfterRoll(*rollOfDice);
                    if (!vecteurQwintoScoreSheet[j]->validate(*rollOfDice, rollOfDice->couleur, rollOfDice->position)) {
                        vecteurFaillite[j]++;
                    }
                    //
                    //
                    // Insert score in scoresheet
                    //
                    //
                }
            } else {
                if (vecteurQwixxPlayer[j]->getActif() == false){
                    std::cout << "Votre sélection de dés sont: " << std::endl;
                    rollOfDice->roll();
                    std::cout << *rollOfDice << std::endl;
                    std::cout << "Votre score sheet est: " << std::endl;
                    std::cout << *vecteurQwixxScoreSheet[i] << std::endl;
                    vecteurQwixxPlayer[j]->inputAfterRoll(*rollOfDice);
                    if (rollOfDice->qwixxSecondRoll == true) {
                        if (!vecteurQwintoScoreSheet[j]->validate(*rollOfDice, rollOfDice->couleur, rollOfDice->position)) {
                            vecteurFaillite[j]++;
                        }
                    }

                    //
                    //
                    // Insert score in scoresheet
                    //
                    //
                }
            }
        }
        
        //Désactive le joueur actif
        if (inputVersion == "qwinto") {
            vecteurQwintoPlayer[i]->setActif(false);
        } else {
            vecteurQwixxPlayer[i]->setActif(false);
        }
        
        //Incrémente le compteur pour tenir compte du prochain joueur actif
        i = (i+1) % inputNumberPlayers;
        
        for (int k = 0; k < vecteurFaillite.size(); k++){
            if (vecteurFaillite[k] == 4) {
                flag = false;
            }
        }
    }
    
    int sum = 0;
    std::string winner = "";
    
    //Calculer le score total et déterminer le gagnant
    for (int j = 0; j < inputNumberPlayers; i++) {
        //auto &s = vecteurScoreSheet[j];
        if (inputVersion == "qwinto") {
            //dynamic_cast<QwintoScoreSheet*>(s)->calcTotal();
            std::cout << vecteurQwintoScoreSheet[i] << std::endl;
            //cast get total, if total > sum, sum = total, winner = getname
        } else {
            //dynamic_cast<QwixxScoreSheet*>(s)->calcTotal();
            std::cout << vecteurQwixxScoreSheet[i] << std::endl;
            //cast get total, if total > sum, sum = total, winner = getname
        }
    }
    
    //Afficher le gagnant
    std::cout << "Bravo " << winner << " tu as gagné!" << std::endl;
    std::cout << "********** Fin du jeux de dés Qwinto-Qwixx **********" << std::endl;
    
    return 0;
}
