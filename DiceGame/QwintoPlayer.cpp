//
//  QwintoPlayer.cpp
//  DiceGame
//
//  Created by Alexandre Prud'Homme on 2017-11-29.
//  Copyright © 2017 Adel Araji. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include "QwintoPlayer.h"
#include "RollOfDice.h"


QwintoPlayer::QwintoPlayer(std::string name){
    actif = false;
    qwintoScoreSheet = QwintoScoreSheet(name);
}

QwintoPlayer::QwintoPlayer() {
    
    actif = false;
}


void QwintoPlayer::inputBeforeRoll(RollOfDice& rollOfDice){
    
    if (actif) {
        int inputNombreDé = 0;
        std::string c1 = "";
        std::string c2 = "";
        std::string c3 = "";
        
        //Chosir le nombre de dés
        std::cout << "Entrer le nombre de dés. Vous pouvez entrer 1, 2 ou 3." << std::endl;
        std::cin >> inputNombreDé;
        while (inputNombreDé != 1 && inputNombreDé != 2 && inputNombreDé != 3){
            std::cout << "Erreur. Entrer 1, 2 ou 3." <<std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> inputNombreDé;
        }
        
        //Choisir couleur 1 dé
        if (inputNombreDé == 1) {
            std::cout << "Enter une couleur unique soit Bleu, Rouge ou Jaune." << std::endl;
            std::cin >> c1;
            c1.erase(remove_if(c1.begin(), c1.end(), isspace), c1.end());
            std::transform(c1.begin(), c1.end(), c1.begin(), ::tolower);
            while (c1 != "bleu" && c1 != "rouge" && c1 != "jaune") {
                std::cout << "Erreur. Entrer une couleur soit Bleu, Rouge ou Jaune." << std::endl;
                std::cin >> c1;
                c1.erase(remove_if(c1.begin(), c1.end(), isspace), c1.end());
                std::transform(c1.begin(), c1.end(), c1.begin(), ::tolower);
            }
            if (c1 == "bleu") {
                Dice d(Colour::BLUE, 0);
                rollOfDice.containerOfDice.push_back(d);
            } else if (c1 == "rouge"){
                Dice d(Colour::RED, 0);
                rollOfDice.containerOfDice.push_back(d);
            } else {
                Dice d(Colour::YELLOW, 0);
                rollOfDice.containerOfDice.push_back(d);
            }
        } else if (inputNombreDé == 2) { //choisir couleur 2 dé
            bool flag = true;
            while (flag) {
                std::cout << "Enter deux couleurs uniques soit Bleu, Rouge ou Jaune." << std::endl;
                std::cin >> c1 >> c2;
                c1.erase(remove_if(c1.begin(), c1.end(), isspace), c1.end());
                std::transform(c1.begin(), c1.end(), c1.begin(), ::tolower);
                c2.erase(remove_if(c2.begin(), c2.end(), isspace), c2.end());
                std::transform(c2.begin(), c2.end(), c2.begin(), ::tolower);
                while (c1 != "bleu" && c1 != "rouge" && c1 != "jaune") {
                    std::cout << "Erreur. Entrer pour la couleur 1 soit Bleu, Rouge ou Jaune." << std::endl;
                    std::cin >> c1;
                    c1.erase(remove_if(c1.begin(), c1.end(), isspace), c1.end());
                    std::transform(c1.begin(), c1.end(), c1.begin(), ::tolower);
                }
                while (c2 != "bleu" && c2 != "rouge" && c2 != "jaune") {
                    std::cout << "Erreur. Entrer pour la couleur 2 soit Bleu, Rouge ou Jaune." << std::endl;
                    std::cin >> c2;
                    c2.erase(remove_if(c2.begin(), c2.end(), isspace), c2.end());
                    std::transform(c2.begin(), c2.end(), c2.begin(), ::tolower);
                }
                if (c1 != c2) {
                    flag = false;
                }
            }
            if (c1 == "bleu") {
                Dice d(Colour::BLUE, 0);
                rollOfDice.containerOfDice.push_back(d);
            } else if (c1 == "rouge"){
                Dice d(Colour::RED, 0);
                rollOfDice.containerOfDice.push_back(d);
            } else {
                Dice d(Colour::YELLOW, 0);
                rollOfDice.containerOfDice.push_back(d);
            }
            if (c2 == "bleu") {
                Dice d(Colour::BLUE, 0);
                rollOfDice.containerOfDice.push_back(d);
            } else if (c2 == "rouge"){
                Dice d(Colour::RED, 0);
                rollOfDice.containerOfDice.push_back(d);
            } else {
                Dice d(Colour::YELLOW, 0);
                rollOfDice.containerOfDice.push_back(d);
            }
        } else { //choisir couleur 3 dés
            bool flag = true;
            while (flag) {
                std::cout << "Enter trois couleurs uniques soit Bleu, Rouge ou Jaune." << std::endl;
                std::cin >> c1 >> c2 >> c3;
                c1.erase(remove_if(c1.begin(), c1.end(), isspace), c1.end());
                std::transform(c1.begin(), c1.end(), c1.begin(), ::tolower);
                c2.erase(remove_if(c2.begin(), c2.end(), isspace), c2.end());
                std::transform(c2.begin(), c2.end(), c2.begin(), ::tolower);
                c3.erase(remove_if(c3.begin(), c3.end(), isspace), c3.end());
                std::transform(c3.begin(), c3.end(), c3.begin(), ::tolower);
                while (c1 != "bleu" && c1 != "rouge" && c1 != "jaune") {
                    std::cout << "Erreur. Entrer pour la couleur 1 soit Bleu, Rouge ou Jaune." << std::endl;
                    std::cin >> c1;
                    c1.erase(remove_if(c1.begin(), c1.end(), isspace), c1.end());
                    std::transform(c1.begin(), c1.end(), c1.begin(), ::tolower);
                }
                while (c2 != "bleu" && c2 != "rouge" && c2 != "jaune") {
                    std::cout << "Erreur. Entrer pour la couleur 2 soit Bleu, Rouge ou Jaune." << std::endl;
                    std::cin >> c2;
                    c2.erase(remove_if(c2.begin(), c2.end(), isspace), c2.end());
                    std::transform(c2.begin(), c2.end(), c2.begin(), ::tolower);
                }
                while (c3 != "bleu" && c3 != "rouge" && c3 != "jaune") {
                    std::cout << "Erreur. Entrer pour la couleur 3 soit Bleu, Rouge ou Jaune." << std::endl;
                    std::cin >> c3;
                    c3.erase(remove_if(c3.begin(), c3.end(), isspace), c3.end());
                    std::transform(c3.begin(), c3.end(), c3.begin(), ::tolower);
                }
                if (c1 != c2 && c1 != c3 && c2 != c3) {
                    flag = false;
                }
            }
            if (c1 == "bleu") {
                Dice d(Colour::BLUE, 0);
                rollOfDice.containerOfDice.push_back(d);
            } else if (c1 == "rouge"){
                Dice d(Colour::RED, 0);
                rollOfDice.containerOfDice.push_back(d);
            } else {
                Dice d(Colour::YELLOW, 0);
                rollOfDice.containerOfDice.push_back(d);
            }
            if (c2 == "bleu") {
                Dice d(Colour::BLUE, 0);
                rollOfDice.containerOfDice.push_back(d);
            } else if (c2 == "rouge"){
                Dice d(Colour::RED, 0);
                rollOfDice.containerOfDice.push_back(d);
            } else {
                Dice d(Colour::YELLOW, 0);
                rollOfDice.containerOfDice.push_back(d);
            }
            if (c3 == "bleu") {
                Dice d(Colour::BLUE, 0);
                rollOfDice.containerOfDice.push_back(d);
            } else if (c3 == "rouge"){
                Dice d(Colour::RED, 0);
                rollOfDice.containerOfDice.push_back(d);
            } else {
                Dice d(Colour::YELLOW, 0);
                rollOfDice.containerOfDice.push_back(d);
            }
        }
    }
}

void QwintoPlayer::inputAfterRoll(RollOfDice& rollOfDice){
    if (actif) {
        std::string inputCouleur;
        
        std::cout << "Ton roll est: "<< (int)rollOfDice << " ,entrer la couleur de la rangé dont vous voulez entrer les points." << std::endl;
        std::cout << "Vous pouvez choisir ";
        for (int i = 0; i < rollOfDice.getNumberOfDice(); i++) {
            std::cout << rollOfDice.containerOfDice[i].getStringColour() << " ";
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
        std::cout << "Entrer la colonne pour le score sheet. Vous pouvez choisir 1, 2, 3, 4, 5, 6, 7, 8, 9 ou 10." << std::endl;
        std::cin >> inputColonne;
            
        
        while (inputColonne != 1 && inputColonne != 2 && inputColonne != 3 && inputColonne != 4 && inputColonne != 5 && inputColonne != 6 && inputColonne != 7 && inputColonne != 8 && inputColonne != 9 && inputColonne != 10){
            std::cout << "Erreur. Entrer 1, 2, 3, 4, 5, 6, 7, 8, 9 ou 10." <<std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> inputColonne;
        }
        rollOfDice.position = inputColonne - 1;
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
            
            std::cout << "Ton roll est: "<< (int)rollOfDice << " ,entrer la couleur de la rangé dont vous voulez entrer les points." << std::endl;
            std::cout << "Vous pouvez choisir ";
            for (int i = 0; i < rollOfDice.getNumberOfDice(); i++) {
                std::cout << rollOfDice.containerOfDice[i].getStringColour() << " ";
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
            std::cout << "Entrer la colonne pour le score sheet. Vous pouvez choisir 1, 2, 3, 4, 5, 6, 7, 8, 9 ou 10." << std::endl;
            std::cin >> inputColonne;
            while (inputColonne != 1 && inputColonne != 2 && inputColonne != 3 && inputColonne != 4 && inputColonne != 5 && inputColonne != 6 && inputColonne != 7 && inputColonne != 8 && inputColonne != 9 && inputColonne != 10){
                std::cout << "Erreur. Entrer 1, 2, 3, 4, 5, 6, 7, 8, 9 ou 10." <<std::endl;
                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cin >> inputColonne;
            }
            rollOfDice.position = inputColonne - 1;
        }
    }
}
