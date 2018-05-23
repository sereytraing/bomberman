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
using namespace std;

class Map {
private:
    int nbCases = 11;
public:
    Map() {}
    Map(int nbCases) {
        this->nbCases = nbCases;
    }
    int getNbCases();
    void setNbCases(int nb);
    void initMap();
};

#endif /* map_hpp */
