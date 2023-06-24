#pragma once
#include <iostream>
#include "RandomNum.h"

class Dice {
    int diceCount;

public:
    Dice(int diceCount) : diceCount(diceCount){}

    int rollDice() {
        int diceNum = 0;
        for (int i = 0; i < diceCount; i++) {
            diceNum += randomNumGen(1,6);
        }
        return diceNum;
    }
};
