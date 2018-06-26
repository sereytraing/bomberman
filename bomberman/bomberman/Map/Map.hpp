//
//  map.hpp
//  bomberman
//
//  Created by TRAING Serey on 23/05/2018.
//  Copyright © 2018 AlkRox. All rights reserved.
//

#ifndef map_hpp
#define map_hpp

#include <stdio.h>
#include <iostream>
#include "Player.hpp"

using namespace std;

class Map {
private:
    static const int nbCases = 11;
    static const int nbPlayers = 4;
    int indexTabPlayers = 0;
    string tab[nbCases][nbCases];
    Player players[nbPlayers];
public:
    Map() {}
    int getNbCases();
    int getIndexTabPlayers();
    void setIndexTabPlayers(int i);
    void initMap();
    void showMap();
    void addPlayer(Player player);
};

#endif /* map_hpp */
