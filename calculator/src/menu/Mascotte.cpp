
#include "Mascotte.h"

#include <iostream>

Mascotte::Mascotte()
{
}

void Mascotte::display(int prestigeLevel) const
{
    if (prestigeLevel < 1)
    {
        prestigeLevel = 1;
    }
    if (prestigeLevel > 5)
    {
        prestigeLevel = 5;
    }

    switch (prestigeLevel)
    {
        case 1:
            std::cout << "   /\\_/\\   " << std::endl;
            std::cout << "  ( o.o )  " << std::endl;
            std::cout << "   > ^ <   " << std::endl;
            break;

        case 2:
            std::cout << "   /\\_/\\   " << std::endl;
            std::cout << "  ( o.o )  " << std::endl;
            std::cout << "  /  ^  \\  " << std::endl;
            std::cout << " /\\_---_/\\ " << std::endl;
            break;

        case 3:
            std::cout << "    /\\_/\\    " << std::endl;
            std::cout << "   ( o.o )   " << std::endl;
            std::cout << "   /  ^  \\   " << std::endl;
            std::cout << "  /|  _  |\\  " << std::endl;
            std::cout << "   /_/ \\_\\   " << std::endl;
            break;

        case 4:
            std::cout << "    /\\_/\\    " << std::endl;
            std::cout << "   ( o.o )   " << std::endl;
            std::cout << "   /  ^  \\   " << std::endl;
            std::cout << "  /|  _  |\\  " << std::endl;
            std::cout << "   /_/ \\_\\   " << std::endl;
            std::cout << "    /___\\    " << std::endl;
            break;

        case 5:
        default:
            std::cout << "     .-^-.-^-.. " << std::endl;
            std::cout << "    /\\_/\\     " << std::endl;
            std::cout << "   ( o.o )    " << std::endl;
            std::cout << "   /  ^  \\    " << std::endl;
            std::cout << "  /|  _  |\\   " << std::endl;
            std::cout << "   /_/ \\_\\    " << std::endl;
            std::cout << "    \\___/     " << std::endl;
            break;
    }
}
    
