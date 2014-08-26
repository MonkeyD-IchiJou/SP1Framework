#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

void renderPause(COORD c)
{
	gotoXY(c);
	colour(0xF);
    cout << ">>";

	gotoXY(32, 10);
	colour(0xA);
	cout << "Continue Game" << endl;

	gotoXY(32, 15);
	colour(0x5);
	cout << "Exit Game" << endl;
}