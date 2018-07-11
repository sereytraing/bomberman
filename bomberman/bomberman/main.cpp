//
//  main.cpp
//  bomberman
//
//  Created by TRAING Serey on 23/05/2018.
//  Copyright © 2018 AlkRox. All rights reserved.
//

#include <iostream>
#include "map.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Map map = Map();
    Player p1 = Player(1);
    Player p2 = Player(2);
    map.initMap();
    map.addPlayer(p1);
    map.addPlayer(p2);
    return 0;
}
