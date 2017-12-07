/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#ifndef QwixxRow_h
#define QwixxRow_h
#include "Colour.h"
#include "RollOfDice.h"
#include <vector>
#include <list>

/*
 * Classe QwixxRow est une rangé de points du jeux Qwixx qui implémente le template Colour
 */
template <class T, Colour colour>
class QwixxRow {
    
public:
    T container ;
    
    //Overload de l'opérateur
    inline QwixxRow<T,colour> operator+=(RollOfDice &rd);
    
    //Overload opératuer insertion
    friend std::ostream& operator<<(std::ostream& os, QwixxRow &arrayRow);
    
    /*
     * Chercher le string de la rangé du jeux qwixx
     * @return std::string
     */
    std::string getRowString();
    
    /*
     * Cherche les valeurs obtenues par l'utilisateur
     * @return *bool
     */
    bool *getValuesObtainedByUser();
};

#endif /* QwixxRow_h */
