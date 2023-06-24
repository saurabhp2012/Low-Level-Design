#pragma once
#include <iostream>
#include <string>

using namespace std;

enum class PIECETYPE{
    _,
    X,
    O
};
class PlayingPiece{
    
    public:
    PIECETYPE type;
    static PlayingPiece* getPlayingPieceInstance(PIECETYPE ptype);
    void virtual print() = 0;

};

class PlayingPieceX:public PlayingPiece{
    public:
        PlayingPieceX(){
            type = PIECETYPE::X;
        }
        void print(){
            std::cout<<"X";
        }
};

class PlayingPieceO:public PlayingPiece{
    public:
        PlayingPieceO(){
            type = PIECETYPE::O;
        }
        void print(){
            std::cout<<"O";
        }
};
class PlayingPiece_:public PlayingPiece{
    public:
        PlayingPiece_(){
            type = PIECETYPE::_;
        }
        void print(){
            std::cout<<"_";
        }
};