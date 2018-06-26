//
//  map.cpp
//  bomberman
//
//  Created by TRAING Serey on 23/05/2018.
//  Copyright © 2018 AlkRox. All rights reserved.
//

#include "Map.hpp"
using namespace std;

int Map::getNbCases() {
    return this->nbCases;
}

void Map::setNbCases(int nb) {
    this->nbCases = nb;
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

