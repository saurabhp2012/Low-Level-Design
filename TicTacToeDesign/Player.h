#pragma once
#include <iostream>
#include <string>
#include "PlayingPiece.h"

using namespace std;

class Player{
    string player;
    PlayingPiece* piece;

    public:
        Player(string name, PlayingPiece* p):player(name),piece(p){}

        string getPlayerName(){
            return player;
        }
        PlayingPiece* getPlayingPiece(){
            return piece;
        }
};
