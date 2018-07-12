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
    /*Map map = Map();
    Player p1 = Player(1);
    Player p2 = Player(2);
    map.initMap();
    map.addPlayer(p1);
    map.addPlayer(p2);*/
    
    int nbPlayers = 4;
    int turn = 1;
    string action;
    Map map = Map();
    
    //Players
    cout << "START players" << endl;
    //cin >> nbPlayers;
    map.setNbPlayers(nbPlayers);
    cout << "STOP players" << endl;
    
    //Settings
    cout << "START settings" << endl;
    cout << "BOMB_DURATION " << map.getBombDuration() << endl;
    cout << "NB_BOMBS " << map.getNbBombs() << endl;
    cout << "BOMB_RADIUS " << map.getBombRadius() << endl;
    cout << "STOP settings" << endl;
    map.initMap();
    
    //Players position random
    for (int i = 0; i < nbPlayers; i++) {
        map.addPlayer(Player(i + 1));
    }
    
    while(true) {
        for(int i = 0; i < map.players.size(); i++) {
            cout << "START turn " << turn << " " << map.players[i].getId() << endl;
            map.showMap();
            cout << "STOP turn " << turn << " " << map.players[i].getId() << endl;
            
            cout << "START actions " << turn << " " << map.players[i].getId() << endl;
            cin >> action >> ws;
            map.playerActions(map.players[i], action);
            cout << "STOP actions " << turn << " " << map.players[i].getId() << endl;

        }
        if (map.isWinner()) {
            break;
        }
        turn += 1;
    }
    
    return 0;
}
