/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#ifndef Dice_h
#define Dice_h
#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Colour.h"
#include "RandomDice.h"

/*
 * Structure dice contient toute les propriétés d'un dé pour le jeux.
 */
struct Dice{
    
private:
    //Variable d'instance
    const Colour col;
    int face;
    
public:
    //Default Constructor
    Dice() = default;
    
    /*
     * Constructeur
     * @param c Colour
     * @param f int
     */
    Dice(Colour c, int f);
    
    /*
     * Implementation méthode roll
     * @return int
     */
    int roll();
    
    /*
     * Cherche la couleur
     * @return Colour
     */
    Colour getColour();
    
    /*
     * Cherche la valeur (face)
     * @return int
     */
    int getFace();
    
    //Overloading insertion function
    friend std::ostream &operator<<(std::ostream& os, const Dice &dc);
    
    /*
     * Chercher la couleur avec un string
     * @return std::string
     */
    std::string getStringColour();
};

#endif /* Dice_h */
