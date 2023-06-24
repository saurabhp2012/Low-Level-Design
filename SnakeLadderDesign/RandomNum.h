#pragma once
#include <iostream>
#include <random>

int randomNumGen(int low, int high) {
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<int> dis(low, high);

    return dis(gen);
}
