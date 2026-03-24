
#include "Mascotte.h"

#include <iostream>

Mascotte::Mascotte()
{
}

void Mascotte::display(int prestigeLevel) const
{
    if (prestigeLevel == 1)
    {
        std::cout << "  /\\_/\\  " << std::endl;
        std::cout << " ( o.o ) " << std::endl;
        std::cout << "  > ^ <  " << std::endl;
    }
    if (prestigeLevel == 2)
    {
        std::cout << "  /\\_/\\  " << std::endl;
        std::cout << " ( o.o ) " << std::endl;
        std::cout << "  > ^ <  " << std::endl;
        std::cout << "   /|\\   " << std::endl;
    }
    if (prestigeLevel >= 3)
    {
        std::cout << "  /\\_/\\  " << std::endl;
        std::cout << " ( o.o ) " << std::endl;
        std::cout << "  > ^ <  " << std::endl;
        std::cout << "   /|\\   " << std::endl;
        std::cout << "  / | \\  " << std::endl;
    }
    
}
    
