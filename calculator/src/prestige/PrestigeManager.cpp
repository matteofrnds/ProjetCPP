
#include "PrestigeManager.h"

#include <iostream>

PrestigeManager::PrestigeManager()
{

}

void PrestigeManager::prestige()
{
    if (prestigeLevel < maxPrestigeLevel)
    {

    prestigePoints += 10;
        if (prestigePoints >= prestigeCost)
        {
            prestigeLevel++;
            prestigePoints -= prestigeCost;
            prestigeCost *= 2; // Increase cost for next prestige
        }
    }
}

void PrestigeManager::displayPrestigeInfo()
{
    std::cout << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "Prestige Level: " << prestigeLevel << std::endl;
    std::cout << "Prestige Points: " << prestigePoints << std::endl;
    std::cout << "Next Prestige Cost: " << prestigeCost << std::endl;
}