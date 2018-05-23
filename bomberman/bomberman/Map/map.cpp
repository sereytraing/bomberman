//
//  map.cpp
//  bomberman
//
//  Created by TRAING Serey on 23/05/2018.
//  Copyright © 2018 AlkRox. All rights reserved.
//

#include "map.hpp"

int Map::getNbCases() {
    return this->nbCases;
}

void Map::setNbCases(int nb) {
    this->nbCases = nb;
}

void Map::initMap() {
    for (int i = 0; i < this->nbCases; i++) {
        printf("#");
    }
    printf("\n");
    for (int i = 0; i < this->nbCases; i++) {
        for(int j = 0; j < this->nbCases; j++) {
            if ((j == 0) || (j==nbCases-1)) {
                printf("#");
            } else {
                if (i%2 == 1) {
                    if (j%2 == 0) {
                        printf("#");
                    } else {
                        printf(" ");
                    }
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    for (int i = 0; i < this->nbCases; i++) {
        printf("#");
    }
}
