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
#include "RandomDice.h"

/*
 * Roll() obtient une valeur aléatoire du dé
 * @return int
 */
int RandomDice::roll() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(1,6);
    int x  = dis(gen);
    //std::cout << "x in random dice" << x << std::endl;
    return x;
}
//Générateur suggérer par AE au site https://stackoverflow.com/questions/29580865/how-to-use-a-random-generator-as-a-class-member-in-c11
