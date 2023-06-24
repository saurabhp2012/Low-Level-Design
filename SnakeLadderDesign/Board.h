#pragma once
#include <iostream>
#include <string>
#include "RandomNum.h"
#include "Cell.h"
#include "Jump.h"

using namespace std;

class Board{
    //2d array of cells
    Cell** cells;
    int boardSize;
    int snake;
    int ladder;

    public:
    Board(int boardSize, int snake, int ladder):boardSize(boardSize),snake(snake),ladder(ladder){
        
        cells = new Cell*[boardSize];
        for(int i = 0;i<boardSize;i++){
            cells[i] = new Cell[boardSize];
        }

        addSnakeLadder();
    }
    Cell* getCell(int playerPos){
        int boardRow = playerPos/boardSize;
        int boardCol = playerPos%boardSize;
        return &cells[boardRow][boardCol];
    }
    

    private:
    void addSnakeLadder(){
        while(snake>0){
            int snakeHead = randomNumGen(1,boardSize*boardSize-1);
            int snakeTail = randomNumGen(1,boardSize*boardSize-1);

            if(snakeTail>=snakeHead) continue;

            Cell* currCell = getCell(snakeHead);

            if(currCell->jump!=nullptr) continue;

            Jump* snakeObj = new Jump();
            snakeObj->start = snakeHead;
            snakeObj->end = snakeTail;           
            currCell->jump = snakeObj;
            std::cout<<"Snake inserted at "<<snakeHead<<" ending at "<<snakeTail<<std::endl;
            snake--;
        }
        while(ladder>0){
            int ladderHead = randomNumGen(1,boardSize*boardSize-1);
            int ladderTail = randomNumGen(1,boardSize*boardSize-1);

            if(ladderHead>=ladderTail) continue;

            Cell* currCell = getCell(ladderHead);

            if(currCell->jump!=nullptr) continue;
            
            Jump* ladderObj = new Jump();
            ladderObj->start = ladderHead;
            ladderObj->end = ladderTail;
            
            currCell->jump = ladderObj;
            std::cout<<"Ladder inserted at "<<ladderHead<<" ending at "<<ladderTail<<std::endl;
            ladder--;
        }
    }


};