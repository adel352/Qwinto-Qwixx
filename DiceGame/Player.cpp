/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Player.h"


bool Player::getActif() {
    return actif;
}

void Player::setActif(bool statusActif) {
    actif = statusActif;
}
