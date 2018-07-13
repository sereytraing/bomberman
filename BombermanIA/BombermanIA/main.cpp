//
//  main.cpp
//  BombermanIA
//
//  Created by TRAING Serey on 13/07/2018.
//  Copyright © 2018 AlkRox. All rights reserved.
//

#include <iostream>
#include <random>

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
    
    string idPlayer = "";
    int turn = 1;
    int randomValue = 0;
    int min = 0;
    int max = 5;
    string lineSettings = "";
    string choices[] = {"U", "D", "L", "R", "B", "NOACTION"};
    
    //Players
    nextInputMustBe("START player");
    getline(cin, idPlayer);
    nextInputMustBe("STOP player");
    
    //Setting
    nextInputMustBe("START settings");
    while(lineSettings != "STOP settings") {
        getline(cin, lineSettings);
    }
    
    while(true) {
        nextInputMustBe("START turn " + to_string(turn));
        //No need height width / grille
        while(lineSettings != "STOP turn " + to_string(turn)) {
            getline(cin, lineSettings);
        }
        cout << "START action " << to_string(turn) << endl;
        srand(time(NULL));
        randomValue = rand()%(max-min + 1) + min;
        cout << choices[randomValue] << endl;
        cout << "STOP action " << to_string(turn) << endl;
        turn += 1;
    }
    
    return 0;
}
