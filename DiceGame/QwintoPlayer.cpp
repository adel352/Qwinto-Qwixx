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
    //will implement once I understand how the main works
    //Enter the colour of dices you would like to roll
    //I need a if else for active. cause is changes accordingly
    
    int inputNombreDice;
    std::string inputCouleur = "";
    std::string inputProchainCouleur;
    
    std::cout << "Entrer les couleurs des dés voulues dans une ligne séparé par des espaces.\nVous avez le droit de choisir un, deux trois dés, mais chaque couleur bleu, jaune et rouge doivent être unique." << std::endl;
    std::cin >> inputCouleur;
    std::transform(inputCouleur.begin(), inputCouleur.end(), inputCouleur.begin(), ::tolower);
    //idée check le manuel afin de faire un triple cin
    
    /*
    std::cout << "Entrer le nombre de dés voulant être utilisé. Vous pouvez choisir 1, 2 ou 3 dés." << std::endl;
    std::cin >> inputNombreDice;
    //source pour cette section du code https://stackoverflow.com/questions/18728754/checking-input-value-is-an-integer
    while (inputNombreDice != 1 && inputNombreDice != 2 && inputNombreDice != 3) {
        std::cout << "Entrée non valide. Entrer le nombre de joueurs avec une valeur numérique 1, 2, ou 3." << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> inputNombreDice;
    }
    std::cout << "Entrer votre chois de couleur unique bleu, jaune ou rouge" << std::endl;
    for (int i = 0; i < inputNombreDice; i++) {
        std::cout << "Entrer la couleur " << i+1 << std::endl;
        std::cin >> inputCouleur;
        while (inputCouleur != "bleu" && inputCouleur != "jaune" && inputCouleur != "rouge") {
            std::cout << "Erreur. Entrer la couleur." << std::endl;
        }
    }
     */
    
    std::cout << "les couleurs sont " << inputCouleur  << std::endl;
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
