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
public:
    Player() {}
    Player(int id) {
        this->id = id;
    }
    int getId();
    void setId(int id);
};

#endif /* Player_hpp */
