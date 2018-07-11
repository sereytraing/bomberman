//
//  map.cpp
//  bomberman
//
//  Created by TRAING Serey on 23/05/2018.
//  Copyright © 2018 AlkRox. All rights reserved.
//

#include "Map.hpp"
#include "Player.hpp"
#include <random>

using namespace std;

int Map::getNbCases() {
    return this->nbCases;
}

int Map::getIndexTabPlayers() {
    return this->indexTabPlayers;
}

void Map::setIndexTabPlayers(int i) {
    this->indexTabPlayers = i;
}

void Map::initMap() {
    
    for (int i = 0; i < this->nbCases; i++) {
        this->tab[0][i] = "#";
    }
    for (int i = 0; i < this->nbCases; i++) {
        for(int j = 0; j < this->nbCases; j++) {
            if ((j == 0) || (j==nbCases-1)) {
                this->tab[j][i] = "#";
            } else {
                if (i%2 == 1) {
                    if (j%2 == 0) {
                        this->tab[j][i] = "#";
                    } else {
                        this->tab[j][i] = "_";
                    }
                } else {
                    this->tab[j][i] = "_";
                }
            }
        }
    }
    for (int i = 0; i < this->nbCases; i++) {
        this->tab[this->nbCases - 1][i] = "#";
    }
}

void Map::showMap() {
    for (int i = 0; i < this->nbCases; i++) {
        cout<< this->tab[0][i];
    }
    printf("\n");
    for (int i = 0; i < this->nbCases; i++) {
        for(int j = 0; j < this->nbCases; j++) {
            if ((j == 0) || (j==nbCases-1)) {
                cout<< this->tab[j][i];
            } else {
                if (i%2 == 1) {
                    if (j%2 == 0) {
                        cout<< this->tab[j][i];
                    } else {
                        cout<< this->tab[j][i];
                    }
                } else {
                    cout<< this->tab[j][i];
                }
            }
        }
        printf("\n");
    }
    for (int i = 0; i < this->nbCases; i++) {
        cout<< this->tab[this->nbCases - 1][i];
    }
    printf("\n");
}

void Map::addPlayer(Player player) {
    int i, j;
    int min = 0;
    int max = this->nbCases;
    while(1) {
        srand( (unsigned int) time(NULL));
        i = rand()%(max-min + 1) + min;
        j = rand()%(max-min + 1) + min;
        if (this->tab[i][j] == "_") {
            this->tab[i][j] = player.getIdStr();
            player.setY(j + 1); // car la premiere ligne de # et la derniere ne comptent pas dans le tableau
            player.setX(i);
            this->players[this->indexTabPlayers] = player;
            this->indexTabPlayers += 1;
            this->showMap();
            return;
        }
    }
}

