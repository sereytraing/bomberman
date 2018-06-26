//
//  Player.cpp
//  bomberman
//
//  Created by TRAING Serey on 23/05/2018.
//  Copyright © 2018 AlkRox. All rights reserved.
//

#include "Player.hpp"
using namespace std;

int Player::getId() {
    return this->id;
}

void Player::setId(int id) {
    this->id = id;
}

string Player::getIdStr() {
    return to_string(this->id);
}
