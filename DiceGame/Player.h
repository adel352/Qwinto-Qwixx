/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#ifndef Player_h
#define Player_h
#include "RollOfDice.h"

class Player {
protected:
    bool actif;
public:
    bool getActif();
    void setActif(bool statusActif);
    virtual void inputBeforeRoll(RollOfDice& rollOfDice) = 0;
    virtual void inputAfterRoll(RollOfDice& rollOfDice) = 0;
};

#endif /* Player_h */
