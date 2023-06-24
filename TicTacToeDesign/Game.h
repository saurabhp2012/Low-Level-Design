#pragma once
#include <iostream>
#include <queue>
#include "PlayingPiece.h"
#include "Player.h"
#include "Board.h"

class Game{
    Board* board;
    queue<Player*> playerQueue;

    public:
        Game(){
            board = new Board(3);
            PlayingPiece* crossPiece = PlayingPiece::getPlayingPieceInstance(PIECETYPE::X);
            Player* p1 = new Player("Player 1",crossPiece);

            PlayingPiece* zeroPiece = PlayingPiece::getPlayingPieceInstance(PIECETYPE::O);
            Player* p2 = new Player("Player 2",zeroPiece);

            playerQueue.push(p1);
            playerQueue.push(p2);
        }

        bool isThereWinner(int row, int col, PIECETYPE type){
            //check row
            bool rowWin = true;
            bool colWin = true;
            bool diag1Win = true;
            bool diag2Win = true;
            for(int i= 0;i<board->getSize();i++){
                if(board->getPlayingPiece(row,i)->type!=type){
                    rowWin = false;
                    break;
                }
            }

            //check col
            for(int i= 0;i<board->getSize();i++){
                if(board->getPlayingPiece(i,col)->type!=type){
                    colWin = false;
                    break;
                }
            }
            //check diag-1
            for(int i= 0,j=0;i<board->getSize();i++,j++){
                if(board->getPlayingPiece(i,j)->type!=type){
                    diag1Win = false;
                    break;
                }
            }
            //check diag-2
            for(int i= 0,j=board->getSize()-1;i<board->getSize();i++,j--){
                if(board->getPlayingPiece(i,j)->type!=type){
                    diag2Win = false;
                    break;
                }
            }
            return rowWin|| colWin|| diag1Win || diag2Win;
        }

        void startGame(){
            bool noWinner = true;
            bool samePlayerTurn = false;
            while(noWinner){

                Player* currPlayer;
                if(!samePlayerTurn){
                    currPlayer = playerQueue.front();
                    playerQueue.pop();
                    samePlayerTurn = false;
                }

                board->printBoard();

                bool boardFull = board->isFull();

                if(boardFull){
                    std::cout<<" Match tie\n";
                    noWinner = false;
                    continue;
                }
                int inputRow , inputCol ;
                
                std::cout<<currPlayer->getPlayerName()<<" turn, Enter row, col: \n";
                std::cin>>inputRow>>inputCol; 


                bool addPieceSuccess = board->addPiece(inputRow,inputCol,currPlayer->getPlayingPiece()->type);

                if(!addPieceSuccess){
                    std::cout<<"Incorrect position, try again\n";
                    samePlayerTurn = true;
                    continue;
                }
                playerQueue.push(currPlayer);
                bool winner = isThereWinner(inputRow,inputCol,currPlayer->getPlayingPiece()->type);
                if(winner){
                    std::cout<<"Player "<<currPlayer->getPlayerName()<<" wins\n";
                    break;
                }
            }

        }
};