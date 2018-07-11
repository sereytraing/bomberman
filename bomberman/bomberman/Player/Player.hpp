//
//  Player.hpp
//  bomberman
//
//  Created by TRAING Serey on 23/05/2018.
//  Copyright © 2018 AlkRox. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Player {
private:
    int id;
    int x;
    int y;
public:
    Player() {}
    Player(int id) {
        this->id = id;
    }
    int getId();
    string getIdStr();
    void setId(int id);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
};

#endif /* Player_hpp */
