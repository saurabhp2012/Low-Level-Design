#include <iostream>
#include "Board.h"
#include "Dice.h"
#include "Cell.h"
#include "Player.h"
#include "Game.h"

int main(){

// Dice* dice = new Dice(1);

// for(int i = 0;i<15;i++){
//     std::cout<<dice->rollDice()<<endl;
// }

Game* game = new Game(10,8,6,1);

game->startGame();
   

}