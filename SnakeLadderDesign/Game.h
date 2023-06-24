#pragma once
#include <iostream>
#include <string>
#include <queue>
#include "Board.h"
#include "Dice.h"
#include "Cell.h"
#include "Player.h"

using namespace std;


class Game{
    Board* board;
    Dice* dice;
    int boardSize;
    queue<Player*> q;
    Player* winner;

    public:
        Game(int boardSize,int snake, int ladder, int diceCount){
            board = new Board(boardSize,snake,ladder);
            dice = new Dice(diceCount);
            this->boardSize = boardSize;
            winner = nullptr;
            addPlayer();
        }
        private:
            void addPlayer(){
                Player* p1 = new Player("Player A",0);
                Player* p2 = new Player("Player B",0);
                q.push(p1);
                q.push(p2);
            }

            Player* findPlayerTurn(){
                Player* p = q.front();
                q.pop();
                q.push(p);
                return p;
            }

            int jumpCheck(int playerNewPos){

                if(playerNewPos>boardSize*boardSize-1) return playerNewPos;

                Cell* cell = board->getCell(playerNewPos);
                if(cell->jump!=nullptr &&  cell->jump->start==playerNewPos){
                    std::string jumpBy = (cell->jump->start < cell->jump->end) ? "ladder" : "snake";
                    std::cout<<"\nJump by "<<jumpBy<<" from "<<cell->jump->start<<" to "<<cell->jump->end<<std::endl;
                    return cell->jump->end;
                }

                return playerNewPos;
            }

        public:

            void startGame(){

                while(winner==nullptr){
                    //find whose turn is it

                    Player* p = findPlayerTurn();
                    std::cout<<"It is "<<p->name<<" turn & current position is "<<p->currPos<<std::endl;
                    //roll dice
                    int newPos = dice->rollDice()+p->currPos;
                    newPos = jumpCheck(newPos);
                    p->currPos = newPos;
                    std::cout<<"New position of "<<p->name<<" is "<<p->currPos<<std::endl;

                    if(newPos>boardSize*boardSize-1){
                        winner = p;
                        break;
                    }
                }

                std::cout<<"Winner is "<<winner->name<<std::endl;
            }
        

};