/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include "QwixxPlayer.h"
//#include "QwixxScoreSheet.h"
#include "RollOfDice.h"

QwixxPlayer::QwixxPlayer() {
    actif = false;
}

void QwixxPlayer::inputBeforeRoll(RollOfDice& rollOfDice){
    if (actif){
        Dice dr(Colour::RED, 0);
        Dice dy(Colour::YELLOW, 0);
        Dice dg(Colour::GREEN, 0);
        Dice db(Colour::BLUE, 0);
        Dice dw(Colour::WHITE, 0);
        Dice dw2(Colour::WHITE, 0);
        rollOfDice.containerOfDice.push_back(dr);
        rollOfDice.containerOfDice.push_back(dy);
        rollOfDice.containerOfDice.push_back(dg);
        rollOfDice.containerOfDice.push_back(db);
        rollOfDice.containerOfDice.push_back(dw);
        rollOfDice.containerOfDice.push_back(dw2);
    }
}

void QwixxPlayer::inputAfterRoll(RollOfDice& rollOfDice){
    if (actif) {
        std::string inputCouleur;
        
        std::cout << "Entrer la couleur de la rangé dont vous voulez entrer les points." << std::endl;
        std::cout << "Vous pouvez choisir ";
        for (int i = 0; i < rollOfDice.getNumberOfDice(); i++) {
            if (rollOfDice.containerOfDice[i].getStringColour() != "blanc"){
                std::cout << rollOfDice.containerOfDice[i].getStringColour() << " ";
            }
        }
        bool flag = true;
        std::cout << "." << std::endl;
        std::cin >> inputCouleur;
        inputCouleur.erase(remove_if(inputCouleur.begin(), inputCouleur.end(), isspace), inputCouleur.end());
        std::transform(inputCouleur.begin(), inputCouleur.end(), inputCouleur.begin(), ::tolower);
        while (flag) {
            for (int i = 0; i < rollOfDice.getNumberOfDice(); i++) {
                if (inputCouleur == rollOfDice.containerOfDice[i].getStringColour()){
                    flag = false;
                    break;
                }
            }
            if (flag) {
                std::cout << "Erreur, entrer la couleur à nouveau." << std::endl;
                std::cin >> inputCouleur;
                inputCouleur.erase(remove_if(inputCouleur.begin(), inputCouleur.end(), isspace), inputCouleur.end());
                std::transform(inputCouleur.begin(), inputCouleur.end(), inputCouleur.begin(), ::tolower);
            }
        }
        if (inputCouleur == "bleu") {
            rollOfDice.couleur = Colour::BLUE;
        } else if (inputCouleur == "rouge") {
            rollOfDice.couleur = Colour::RED;
        } else if (inputCouleur == "jaune") {
            rollOfDice.couleur = Colour::YELLOW;
        } else {
            rollOfDice.couleur = Colour::GREEN;
        }
        int inputColonne;
        std::cout << "Entrer la colonne pour le score sheet. Vous pouvez choisir 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 ou 12." << std::endl;
        std::cin >> inputColonne;
        while (inputColonne != 2 && inputColonne != 3 && inputColonne != 4 && inputColonne != 5 && inputColonne != 6 && inputColonne != 7 && inputColonne != 8 && inputColonne != 9 && inputColonne != 10 && inputColonne != 11 && inputColonne != 12){
            std::cout << "Erreur. Entrer 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 ou 12." <<std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> inputColonne;
        }
        rollOfDice.position = inputColonne;
        std::string inputChoix;
        std::cout << "Entrer oui ou non si vous voulez entrer vos points une deuxième fois." << std::endl;
        std::cin >> inputChoix;
        inputChoix.erase(remove_if(inputChoix.begin(), inputChoix.end(), isspace), inputChoix.end());
        std::transform(inputChoix.begin(), inputChoix.end(), inputChoix.begin(), ::tolower);
        while (inputChoix != "oui" && inputChoix != "non") {
            std::cout << "Erreur, entrer oui ou non." << std::endl;
            std::cin >> inputChoix;
        }
        if (inputChoix == "oui") {
            rollOfDice.qwixxSecondRoll = true;
        }
    } else {
        std::string inputChoix;
        std::cout << "Entrer oui si vous voulez utiliser les dés roulés ou non si vous ne voulez pas les utiliser." << std::endl;
        std::cin >> inputChoix;
        inputChoix.erase(remove_if(inputChoix.begin(), inputChoix.end(), isspace), inputChoix.end());
        std::transform(inputChoix.begin(), inputChoix.end(), inputChoix.begin(), ::tolower);
        while (inputChoix != "oui" && inputChoix != "non") {
            std::cout << "Erreur, entrer oui ou non." << std::endl;
            std::cin >> inputChoix;
        }
        if (inputChoix == "oui") {
            std::string inputCouleur;
            
            std::cout << "Entrer la couleur de la rangé dont vous voulez entrer les points." << std::endl;
            std::cout << "Vous pouvez choisir ";
            for (int i = 0; i < rollOfDice.getNumberOfDice(); i++) {
                if (rollOfDice.containerOfDice[i].getStringColour() != "blanc"){
                    std::cout << rollOfDice.containerOfDice[i].getStringColour() << " ";
                }
            }
            bool flag = true;
            std::cout << "." << std::endl;
            std::cin >> inputCouleur;
            inputCouleur.erase(remove_if(inputCouleur.begin(), inputCouleur.end(), isspace), inputCouleur.end());
            std::transform(inputCouleur.begin(), inputCouleur.end(), inputCouleur.begin(), ::tolower);
            while (flag) {
                for (int i = 0; i < rollOfDice.getNumberOfDice(); i++) {
                    if (inputCouleur == rollOfDice.containerOfDice[i].getStringColour()){
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    std::cout << "Erreur, entrer la couleur à nouveau." << std::endl;
                    std::cin >> inputCouleur;
                    inputCouleur.erase(remove_if(inputCouleur.begin(), inputCouleur.end(), isspace), inputCouleur.end());
                    std::transform(inputCouleur.begin(), inputCouleur.end(), inputCouleur.begin(), ::tolower);
                }
            }
            if (inputCouleur == "bleu") {
                rollOfDice.couleur = Colour::BLUE;
            } else if ( inputCouleur == "rouge") {
                rollOfDice.couleur = Colour::RED;
            } else {
                rollOfDice.couleur = Colour::YELLOW;
            }
            int inputColonne;
            std::cout << "Entrer la colonne pour le score sheet. Vous pouvez choisir 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 ou 12." << std::endl;
            std::cin >> inputColonne;
            while (inputColonne != 2 && inputColonne != 3 && inputColonne != 4 && inputColonne != 5 && inputColonne != 6 && inputColonne != 7 && inputColonne != 8 && inputColonne != 9 && inputColonne != 10 && inputColonne != 11 && inputColonne != 12){
                std::cout << "Erreur. Entrer 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 ou 12." <<std::endl;
                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cin >> inputColonne;
            }
            rollOfDice.position = inputColonne;
        } else {
            rollOfDice.qwixxSecondRoll = false;
            std::cout << std::endl;
        }
    }
}
