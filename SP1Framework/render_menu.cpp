#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

void renderMenu (COORD c)
{
    gotoXY(c);
	colour(0xF);
    cout << ">>";

    gotoXY(35, 10);
	colour(0xA);
    cout << "Start Game";

    gotoXY(35, 15);
    cout << "Option";

	colour(0xE);
    gotoXY(58, 25);
    cout << "*Up/Down to select";

    gotoXY(58, 27);
    cout << "*Enter key to confirm";
}