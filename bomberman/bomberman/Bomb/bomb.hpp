//
//  bomb.hpp
//  bomberman
//
//  Created by TRAING Serey on 12/07/2018.
//  Copyright © 2018 AlkRox. All rights reserved.
//

#ifndef bomb_hpp
#define bomb_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Bomb {
private:
    int value;
    int x;
    int y;
    int duration;
    
public:
    Bomb() {
        this->value = -1;
        this->x = -1;
        this->y = -1;
        this->duration = -1;
    }
    Bomb(int value, int x, int y, int duration) {
        this->value = value;
        this->x = x;
        this->y = y;
        this->duration = duration;
    }
    int getValue();
    void setValue(int value);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    int getDuration();
    void setDuration(int duration);
};

#endif /* bomb_hpp */
