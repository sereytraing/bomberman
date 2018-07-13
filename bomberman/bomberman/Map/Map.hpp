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
#include "bomb.hpp"

using namespace std;

class Map {
private:
    static const int nbCases = 11;
    int nbPlayers;
    static const int nbBombs = 10;
    static const int bombDuration = 3;
    static const int bombRadius = 3;
    int indexTabBomb = 0;
    string tab[nbCases][nbCases];
    
public:
    vector<Player> players;
    Bomb bombs[nbBombs];
    
    Map() {}
    int getNbCases();
    int getIndexTabBomb();
    int getNbBombs();
    int getBombDuration();
    int getBombRadius();
    void setNbPlayers(int nb);
    void setIndexTabBomb(int i);
    void initMap();
    void showMap();
    void addPlayer(Player player);
    void playerActions(Player player, string action);
    bool isWinner();
    void triggerBomb();
    bool isDraw();
};

#endif /* map_hpp */
