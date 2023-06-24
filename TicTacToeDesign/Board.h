#pragma once
#include <iostream>
#include <ostream>

#include "PlayingPiece.h"


class Board{
    int size;
    PlayingPiece*** board;

    public:
    Board(int boardSize) : size(boardSize) {
        board = new PlayingPiece**[size];
        for (int i = 0; i < size; i++) {
            board[i] = new PlayingPiece*[size];
            for (int j = 0; j < size; j++) {
                board[i][j] = PlayingPiece::getPlayingPieceInstance(PIECETYPE::_);
            }
        }
    }

        bool addPiece(int row, int col, PIECETYPE type){
            if(row<0 || row>=size || col<0 || col>=size) return false;

            PlayingPiece** currPiece = &board[row][col];
            if((*currPiece)->type==PIECETYPE::_){
                (*currPiece) = PlayingPiece::getPlayingPieceInstance(type);
                return true;
            }
            return false;
        }

        void printBoard(){

             for(int i = 0;i<size;i++){
                std::cout<<"|";
                for(int j = 0;j<size;j++){
                    board[i][j]->print();
                    std::cout<<"|";
                }
                std::cout<<endl;
            }           
        }

        bool isFull(){
            for(int i = 0;i<size;i++){
                for(int j = 0;j<size;j++){
                    if(board[i][j]->type==PIECETYPE::_) return false;
                }
            }
            return true;
        }
        PlayingPiece* getPlayingPiece(int row, int col){
            return board[row][col];
        }
        int getSize(){
            return size;
        }

        friend std::ostream& operator<<(ostream& stream,PIECETYPE type);

};

std::ostream& operator<<(std::ostream& stream, PIECETYPE& type) {
    switch (type) {
        case PIECETYPE::X:
            stream << "X";
            break;
        case PIECETYPE::O:
            stream << "O";
            break;
        case PIECETYPE::_:
            stream << "_";
            break;
        default:
            stream << "Unknown";
            break;
    }
    return stream;
}
