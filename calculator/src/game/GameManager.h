
#pragma once

#include "../prestige/PrestigeManager.h"

#include "Problem.h"

#include <random>

class GameManager
{
public:
    GameManager();
    void startGame(PrestigeManager& prestigeManager);
private:
    std::mt19937 rng;
};