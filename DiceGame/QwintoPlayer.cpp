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
//#include "QwintoScoreSheet.h"
#include "RollOfDice.h"

QwintoPlayer::QwintoPlayer() {
    actif = false;
}

void QwintoPlayer::inputBeforeRoll(RollOfDice& rollOfDice){
    
    int inputNombreDé = 0;
    std::string c1 = "";
    std::string c2 = "";
    std::string c3 = "";
    
    std::cout << "Entrer le nombre de dé. Vous pouvez entrer 1, 2 ou 3." << std::endl;
    std::cin >> inputNombreDé;
    while (inputNombreDé != 1 && inputNombreDé != 2 && inputNombreDé != 3){
        std::cout << "Erreur. Entrer 1, 2 ou 3." <<std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> inputNombreDé;
    }
    
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
    } else if (inputNombreDé == 2) {
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
    } else {
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
    }
    //Push the to a roll of dice so c1, c2, c3
}

void QwintoPlayer::inputAfterRoll(RollOfDice& rollOfDice){
    if (actif) {
        //method of something to loop all validations, if not validated then count towards non valide
        //get the dice colours that where rolled
        //while loop, demander quel couleur de rangé et quel colonne pour insérer. validate on tbe fly
    } else {
        std::string inputChoix;
        std::cout << "Entrer oui si vous voulez utiliser les dés roulés ou non si vous ne voulez pas les utiliser." << std::endl;
        std::cin >> inputChoix;
        inputChoix.erase(remove_if(inputChoix.begin(), inputChoix.end(), isspace), inputChoix.end());
        std::transform(inputChoix.begin(), inputChoix.end(), inputChoix.begin(), ::tolower);
        while (inputChoix != "oui" && inputChoix != "non") {
            std::cout << "Erreur, entrer oui ou non." << std::endl;
        }
        if (inputChoix == "oui") {
            //while demander quel couleur, quel colonne et valider
        }
    }
}
