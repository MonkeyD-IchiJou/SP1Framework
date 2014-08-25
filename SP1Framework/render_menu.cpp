#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

void renderMenu (COORD c)
{
    
    gotoXY(c);
    colour(0xF);
    cout << ">>";
    
    gotoXY(30, 10);
    colour(0xA);
    cout << "Start Game";

    gotoXY(30, 15);
    cout << "Option";

    gotoXY(58, 25);
    colour(0xE);
    cout << "*Up/Down to select";

    gotoXY(58, 27);
    cout << "*Enter key to confirm";
}