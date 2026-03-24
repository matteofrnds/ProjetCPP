#pragma once

#include <string>

#include "Mascotte.h"
#include "../prestige/PrestigeManager.h"

class Menu
{
public:
    Menu();
    void display(const Mascotte& mascotte, const PrestigeManager& prestigeManager) const;

private:
    std::string title;
};