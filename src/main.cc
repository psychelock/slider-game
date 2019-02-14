#include "layout.hh"
#include <iostream>
#include <stdlib.h>

int main ()
{
    int lol = 1;
    Layout grid(3);
    while(lol)
    {
        system("clear");
        grid.dump();
        auto c = getchar();
        lol = grid.move(c);
        if(lol == 2)
            break;
        lol = grid.win_cond();
        if(lol == 0)
        {
            system("clear");
            grid.dump();
            std::cout << " WON ! WON ! WON !\n";
            std::cout << "Thanks for playing!\n";
            break;
        }
    }
}
