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

struct Dice{
    const Colour col;
    int face;
    
    //Constructor
    Dice(Colour c, int f): col(c), face(f) {};
    
    //Roll function implementation
    int roll(){
        RandomDice *random = new RandomDice();
        face = random->roll();
        std::cout << "face in roll " << face << std::endl;
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

struct RollOfDice {
    std::vector<Dice> containerOfDice;
    
    void roll() {
        for (Dice d: containerOfDice){
            d.roll();
        }
    }
    
    // Takes the colours of 2 dice and returns a RollOFDice containing them
    RollOfDice pair(Colour d1, Colour d2)
    {
        RollOfDice returnValue;
        //Search for the appropriate colour
        for (Dice d: containerOfDice){
            if((d.col == d1) || (d.col == d2))
                //Add dice if the colour is matched
                returnValue.containerOfDice.push_back(d);
        }
        
        return returnValue;
    }
    
    //Conversion to int Operator
    operator int() const {
        int sum = 0;
        
        for (Dice d: containerOfDice)
        {
            sum = sum + d.face;
        }
        return sum;
    }
    
    //Overloading insertion operator
    friend std::ostream &operator<<(std::ostream& os, const RollOfDice &dc)
    {
        //Print all dices stored in the container
        for (Dice d: dc.containerOfDice){
            os << d;
        }
  
        return os;
    }
};


int main() {
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
    return 0;
}
