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
#include <string>
#include <vector>

#include "Player.hpp"

using namespace std;

class Map {
private:
    static const int nbCases = 11;
    int nbPlayers;
    int nbBombs = 10;
    int bombDuration = 3;
    int bombRadius = 3;
    int indexTabPlayers = 0;
    string tab[nbCases][nbCases];
public:
    vector<Player> players;
    
    Map() {}
    int getNbCases();
    int getIndexTabPlayers();
    int getNbBombs();
    int getBombDuration();
    int getBombRadius();
    void setNbPlayers(int nb);
    void setIndexTabPlayers(int i);
    void initMap();
    void showMap();
    void addPlayer(Player player);
    void playerActions(Player player, string action);
};

#endif /* map_hpp */
