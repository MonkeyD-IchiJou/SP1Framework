#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

void renderMenu (COORD c)
{
    gotoXY(c);
	colour(0xF);
    cout << ">>";

    gotoXY(32, 5);
	colour(0xA);
    cout << "Start Game";

    gotoXY(32, 10);
    cout << "Option";

	gotoXY(32, 15);
	colour(0xB);
	cout << "Return to start screen";

	gotoXY(32, 20);
	colour(0xD);
	cout << "EXIT GAME";
	
	colour(0xE);
    gotoXY(58, 25);
    cout << "*Up/Down to select";

    gotoXY(58, 27);
    cout << "*Enter key to confirm";
}