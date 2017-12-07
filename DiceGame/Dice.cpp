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
#include "Dice.h"

/*
 * Constructeur
 * @param c Colour
 * @param f int
 */
Dice::Dice(Colour c, int f): col(c), face(f) {};

/*
 * Implementation méthode roll
 * @return int
 */
int Dice::roll(){
    RandomDice *random = new RandomDice();
    face = random->roll();
    return face;
}

/*
 * Cherche la couleur
 * @return Colour
 */
Colour Dice::getColour() {
    return col;
}

/*
 * Cherche la valeur (face)
 * @return int
 */
int Dice::getFace(){
    return face;
}

//Overloading insertion function
std::ostream &operator<<(std::ostream& os, const Dice &dc)
{
    os<< "Dice with colour: ";
    
    switch(dc.col)
    {
        case RED:
            os << "RED";
            break;
        case YELLOW:
            os << "YELLOW";
            break;
        case GREEN:
            os << "GREEN";
            break;
        case BLUE:
            os << "BLUE";
            break;
        case WHITE:
            os << "WHITE";
            break;
    }
    os << " and face: " <<  dc.face;
    return os;
}

/*
 * Chercher la couleur avec un string
 * @return std::string
 */
std::string Dice::getStringColour() {
    if (col == 0) {
        return "rouge";
    } else if (col == 1) {
        return "jaune";
    } else if (col == 2) {
        return "vert";
    } else if (col == 3) {
        return "bleu";
    } else {
        return "blanc";
    }
    return "Erreur";
}
