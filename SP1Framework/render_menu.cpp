#include "game.h"
#include "Framework\console.h"
#include "tetris.h"
#include "Gameplay.h"

void renderMenu (COORD c)
{
    gotoXY(c);
	colour(White);
    cout << ">>";
    
    gotoXY(32, 5);
    colour(Green);
    cout << "Start Game";

    gotoXY(32, 10);
    cout << "Option";

	gotoXY(32, 15);
	colour(Cyan);
	cout << "Return to start screen";

	gotoXY(32, 20);
	colour(Magenta);
	cout << "EXIT GAME";
	
	colour(0xE);
    gotoXY(58, 25);
    colour(Yellow);
    cout << "*Up/Down to select";

    gotoXY(58, 27);
    cout << "*Enter key to confirm";
}