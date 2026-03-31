
#pragma once

class PrestigeManager
{
public:
    PrestigeManager();
    void prestige();
    int getPrestigeLevel() const { return prestigeLevel; }
    int getPrestigePoints() const { return prestigePoints; }
    int getPrestigeCost() const { return prestigeCost; }

    void displayPrestigeInfo();



private:
    int prestigeLevel = 1;
    int prestigePoints = 0;
    int prestigeCost = 30; // Example cost for prestiging
    int prestigeMultiplier = 2; // Example multiplier for prestige points
        int maxPrestigeLevel = 5; // Example maximum prestige level
};