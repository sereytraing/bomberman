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

void nextInputMustBe(string value) {
    string val = "";
    getline(cin, val);
    if (val != value) {
        cerr << "expected input was '" << value << "' instead of '" << val << "'" << endl;
        exit(EXIT_FAILURE);
    }
    return;
}

int main(int argc, const char * argv[]) {
    int nbPlayers = 2;
    string nbPlayersResponse = "";
    int turn = 1;
    string action = "";
    Map map = Map();
    
    //Players
    nextInputMustBe("START players");
    getline(cin, nbPlayersResponse);
    nbPlayers = stoi(nbPlayersResponse);
    map.setNbPlayers(nbPlayers);
    nextInputMustBe("STOP players");
    
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
    
    //Run
    while(true) {
        map.triggerBomb();
        for(int i = 0; i < map.players.size(); i++) {
            cout << "START turn " << turn << " " << map.players[i].getId() << endl;
            if (map.isWinner()) {
                cout << "WINNER " << map.players[i].getId() << endl;
            } else {
                cout << map.getNbCases() << " "<< map.getNbCases() << endl; // height and width
                map.showMap();
            }
            cout << "STOP turn " << turn << " " << map.players[i].getId() << endl;
            
            nextInputMustBe("START actions " + to_string(turn) + " " + to_string(map.players[i].getId()) );
            getline(cin, action);
            if (map.players[i].getIsAlive()) {
                map.playerActions(map.players[i], action);
            }
            nextInputMustBe("STOP actions " + to_string(turn) + " " + to_string(map.players[i].getId()) );
            
        }
        if (map.isWinner()) {
            return 0;
        }
        turn += 1;
    }
    
    return 0;
}
