
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
    int prestigeCost = 50; // Example cost for prestiging
    int prestigeMultiplier = 2; // Example multiplier for prestige points
    int maxPrestigeLevel = 10; // Example maximum prestige level
};