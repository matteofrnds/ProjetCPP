
#include "menu/Menu.h"
#include "menu/Mascotte.h"
#include "prestige/PrestigeManager.h"

#include <iostream>

int main(int argc, char* argv[])
{
  Menu menu;
  Mascotte mascotte;
  PrestigeManager prestigeManager;

  while (true)
  {
    menu.display(mascotte, prestigeManager);
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    switch (choice)
    {
        case 1:
            std::cout << "Game Mode selected" << std::endl;
            break;
        case 2:
            std::cout << "View Prestige Info" << std::endl;
            prestigeManager.displayPrestigeInfo();
            break;
        case 3:
            std::cout << "Enable/Disable Mascotte selected" << std::endl;
            mascotte.toggle();
            break;
        case 4:
            std::cout << "Quit selected" << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice, please try again." << std::endl;
    }
  }
  
}