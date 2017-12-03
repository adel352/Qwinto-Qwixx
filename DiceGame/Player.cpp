//
//  Player.cpp
//  DiceGame
//
//  Created by Alexandre Prud'Homme on 2017-11-29.
//  Copyright © 2017 Adel Araji. All rights reserved.
//

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
