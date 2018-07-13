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

int Map::getIndexTabBomb() {
    return this->indexTabBomb;
}

int Map::getNbBombs() {
    return this->nbBombs;
}

int Map::getBombDuration() {
    return this->bombDuration;
}

int Map::getBombRadius() {
    return this->bombRadius;
}

void Map::setNbPlayers(int nb) {
    this->nbPlayers = nb;
}

void Map::setIndexTabBomb(int i) {
    this->indexTabBomb = i;
}

void Map::initMap() {
    
    for (int i = 0; i < this->nbCases; i++) {
        for(int j = 0; j < this->nbCases; j++) {
            if ((j == 0) || (j==nbCases-1)) {
                this->tab[j][i] = "#";
            } else {
                if (i%2 == 0) {
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
        this->tab[i][0] = "#";
    }
    
    for (int i = 0; i < this->nbCases; i++) {
        this->tab[i][this->nbCases - 1] = "#";
    }
    
    for(int i = 0; i < this->nbBombs; i++) {
        this->bombs[i] = Bomb();
    }
}

void Map::showMap() {
    for (int i = 0; i < this->nbCases; i++) {
        for(int j = 0; j < this->nbCases; j++) {
            cout<< this->tab[j][i];
        }
        cout << endl;
    }
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
            player.setY(j);
            player.setX(i);
            this->players.push_back(player);
            return;
        }
    }
}

void Map::playerActions(Player player, string action) {
    if (action == "NOACTION") {
        return;
    }
    
    if (!(player.getIsAlive())) {
        return;
    }
    
    if ((action == "U") && (this->tab[player.getX()][player.getY() - 1] == "_")) {
        if (this->tab[player.getX()][player.getY()] == player.getIdStr()) {
            this->tab[player.getX()][player.getY()] = "_";
        }
        this->tab[player.getX()][player.getY() - 1] = player.getIdStr();
        this->players[player.getId() - 1].setY(player.getY() - 1);
    }
    
    else if ((action == "D") && (this->tab[player.getX()][player.getY() + 1] == "_")){
        if (this->tab[player.getX()][player.getY()] == player.getIdStr()) {
            this->tab[player.getX()][player.getY()] = "_";
        }
        this->tab[player.getX()][player.getY() + 1] = player.getIdStr();
        this->players[player.getId() - 1].setY(player.getY() + 1);
    }
    
    else if ((action == "L") && (this->tab[player.getX() - 1][player.getY()] == "_")){
        if (this->tab[player.getX()][player.getY()] == player.getIdStr()) {
            this->tab[player.getX()][player.getY()] = "_";
        }
        this->tab[player.getX() - 1][player.getY()] = player.getIdStr();
        this->players[player.getId() - 1].setX(player.getX() - 1);
    }
    
    else if ((action == "R") && (this->tab[player.getX() + 1][player.getY()] == "_")){
        if (this->tab[player.getX()][player.getY()] == player.getIdStr()) {
            this->tab[player.getX()][player.getY()] = "_";
        }
        this->tab[player.getX() + 1][player.getY()] = player.getIdStr();
        this->players[player.getId() - 1].setX(player.getX() + 1);
    }
    
    else if ((action == "B") && (this->tab[player.getX()][player.getY()] != "o")){
        // Pas fini, gerer gestion max bomb
        if (indexTabBomb < nbBombs) {
            this->tab[player.getX()][player.getY()] = "o";
            this->bombs[this->indexTabBomb] = Bomb(player.getId() + 4, player.getX(), player.getY(), this->getBombDuration(), this->indexTabBomb);
            this->indexTabBomb += 1;
        }
    }
}

bool Map::isWinner() {
    int count = 0;
    for(int i = 0; i < this->players.size(); i++) {
        if (this->players[i].getIsAlive()) {
            count += 1;
        }
    }
    return count == 1;
}

void Map::triggerBomb() {
    for(int i = 0; i < this->nbBombs; i++) {
        if (this->bombs[i].getDuration() > (-1)) { //Valeur par defaut quand initialise

            this->bombs[i].setDuration(this->bombs[i].getDuration() - 1);
            if (this->bombs[i].getDuration() == 0) {
                
                for(int radius = 0; radius <= this->getBombRadius(); radius++) {
                    if((this->bombs[i].getY() - radius >= 0) &&
                       (this->bombs[i].getY() - radius < nbCases) &&
                       (this->tab[this->bombs[i].getX()][this->bombs[i].getY() - radius] != "#") &&
                       (this->tab[this->bombs[i].getX()][this->bombs[i].getY() - radius] != "_") &&
                       (this->tab[this->bombs[i].getX()][this->bombs[i].getY() - radius] != "o")) {
                        string idPlayer = this->tab[this->bombs[i].getX()][this->bombs[i].getY() - radius];

                        try {
                            if (stoi(idPlayer) <= this->nbPlayers) {
                                this->players[stoi(idPlayer) - 1].setIsAlive(false);
                                int x = this->players[stoi(idPlayer) - 1].getX();
                                int y = this->players[stoi(idPlayer) - 1].getY();
                                this->tab[x][y] = "_";
                                
                            }
                        }
                        catch(int i) {
                            
                        }
                        catch(string s) {
                            cout << "Invalid input for stoi " << s;
                        }
                    }
                    
                    if((this->bombs[i].getY() + radius >= 0) &&
                       (this->bombs[i].getY() + radius < nbCases) &&
                       (this->tab[this->bombs[i].getX()][this->bombs[i].getY() + radius] != "#") &&
                       (this->tab[this->bombs[i].getX()][this->bombs[i].getY() + radius] != "_") &&
                       (this->tab[this->bombs[i].getX()][this->bombs[i].getY() + radius] != "o")) {
                        string idPlayer = this->tab[this->bombs[i].getX()][this->bombs[i].getY() + radius];
                        try {
                            if (stoi(idPlayer) <= this->nbPlayers) {
                                this->players[stoi(idPlayer) - 1].setIsAlive(false);
                                int x = this->players[stoi(idPlayer) - 1].getX();
                                int y = this->players[stoi(idPlayer) - 1].getY();
                                this->tab[x][y] = "_";
                            }
                        }
                        catch(int i) {
                            
                        }
                        catch(string s) {
                            cout << "Invalid input for stoi " << s;
                        }
                    }
                    
                    if((this->bombs[i].getX() - radius >= 0) &&
                       (this->bombs[i].getX() - radius < nbCases) &&
                       (this->tab[this->bombs[i].getX() - radius][this->bombs[i].getY()] != "#") &&
                       (this->tab[this->bombs[i].getX() - radius][this->bombs[i].getY()] != "_") &&
                       (this->tab[this->bombs[i].getX() - radius][this->bombs[i].getY()] != "o")) {
                        string idPlayer = this->tab[this->bombs[i].getX() - radius][this->bombs[i].getY()];
                        try {
                            if (stoi(idPlayer) <= this->nbPlayers) {
                                this->players[stoi(idPlayer) - 1].setIsAlive(false);
                                int x = this->players[stoi(idPlayer) - 1].getX();
                                int y = this->players[stoi(idPlayer) - 1].getY();
                                this->tab[x][y] = "_";
                            }
                        }
                        catch(int i) {
                            
                        }
                        catch(string s) {
                            cout << "Invalid input for stoi " << s;
                        }
                    }
                    
                    if((this->bombs[i].getX() + radius >= 0) &&
                       (this->bombs[i].getX() + radius < nbCases) &&
                       (this->tab[this->bombs[i].getX() + radius][this->bombs[i].getY()] != "#") &&
                       (this->tab[this->bombs[i].getX() + radius][this->bombs[i].getY()] != "_") &&
                       (this->tab[this->bombs[i].getX() + radius][this->bombs[i].getY()] != "o")) {
                        string idPlayer = this->tab[this->bombs[i].getX() + radius][this->bombs[i].getY()];
                        try {
                            if (stoi(idPlayer) <= this->nbPlayers) {
                                this->players[stoi(idPlayer) - 1].setIsAlive(false);
                                int x = this->players[stoi(idPlayer) - 1].getX();
                                int y = this->players[stoi(idPlayer) - 1].getY();
                                this->tab[x][y] = "_";
                            }
                        }
                        catch(int i) {
                            
                        }
                        catch(string s) {
                            cout << "Invalid input for stoi " << s;
                        }
                    }
                    
                } //for
                this->tab[this->bombs[i].getX()][this->bombs[i].getY()] = "_";
                this->bombs[i] = Bomb();
                this->indexTabBomb -= 1;
            } // if bomb duration == 0
        }
    }
}





