/*
 * CSI 2772 - Projet
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#include <iostream>
#include <cstdlib>

enum Colour {RED, YELLOW, GREEN, BLUE, WHITE};

struct Dice{
    const Colour col;
    int face;
    
    //Constructor
    Dice(Colour c, int f): col(c), face(f) {};
    
    //Roll function implementation
    int roll(){
        face = rand() % 6 + 1;
        return face;
    }
    
    //Overloading insertion function
    friend std::ostream &operator<<(std::ostream& os, const Dice &dc)
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
};


int main() {
    
    Dice d(Colour::RED, 0);
    d.roll();
    
    std::cout << d << std::endl;
    return 0;
}
