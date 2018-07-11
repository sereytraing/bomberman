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

int Player::getX() {
    return this->x;
}

void Player::setX(int x) {
    this->x = x;
}

int Player::getY() {
    return this->y;
}

void Player::setY(int y) {
    this->y = y;
}

string Player::getIdStr() {
    return to_string(this->id);
}
