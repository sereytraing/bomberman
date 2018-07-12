//
//  bomb.cpp
//  bomberman
//
//  Created by TRAING Serey on 12/07/2018.
//  Copyright © 2018 AlkRox. All rights reserved.
//

#include "bomb.hpp"

using namespace std;

int Bomb::getValue() {
    return this->value;
}

void Bomb::setValue(int value) {
    this->value = value;
}

int Bomb::getX() {
    return this->x;
}

void Bomb::setX(int x) {
    this->x = x;
}

int Bomb::getY() {
    return this->y;
}

void Bomb::setY(int y) {
    this->y = y;
}

int Bomb::getDuration() {
    return this->duration;
}

void Bomb::setDuration(int duration) {
    this->duration = duration;
}
