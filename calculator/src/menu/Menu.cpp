
#include "Menu.h"


#include <iostream>

Menu::Menu() : title("Calculator Game Menu")
{
}

void Menu::display(const Mascotte& mascotte, const PrestigeManager& prestigeManager) const
{
    std::cout << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << title << std::endl;
    if (mascotte.enable)
    {
        mascotte.display(prestigeManager.getPrestigeLevel());
    }
    std::cout << "1. Game Mode" << std::endl;
    std::cout << "2. Prestige" << std::endl;
    std::cout << "3. Enable/Disable Lapinou" << std::endl;
    std::cout << "4. Quit" << std::endl;
}