#include <iostream>
#include "PlayingPiece.h"

PlayingPiece* PlayingPiece::getPlayingPieceInstance(PIECETYPE ptype){

    if(ptype==PIECETYPE::X){
        return new PlayingPieceX();
    }
    else if(ptype==PIECETYPE::O){
        return new PlayingPieceO();
    }
    else if(ptype==PIECETYPE::_){
        return new PlayingPiece_();
    }
    return nullptr;
}