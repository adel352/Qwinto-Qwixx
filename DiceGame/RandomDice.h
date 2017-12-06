/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#ifndef RandomDice_h
#define RandomDice_h
#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>

/*
 * Structure RandomDice permet de rouler et obtenir une valeur aléatoire
 */
struct RandomDice {
public:
    /*
     * Roll() obtient une valeur aléatoire du dé
     * @return int
     */
    int roll();
};

#endif /* RandomDice_h */
