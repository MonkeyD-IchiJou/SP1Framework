#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

void renderOption (COORD c)
{
    gotoXY(c);
    cout << ">>";

    gotoXY(30, 10);
    cout << "Start Game";

    gotoXY(30, 15);
    cout << "Option";

    gotoXY(58, 25);
    cout << "*Up/Down to select";

    gotoXY(58, 27);
    cout << "*Enter key to confirm";
}