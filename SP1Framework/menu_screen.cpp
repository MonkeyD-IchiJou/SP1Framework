#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

void MenuScreen()
{
    //Title of the game
	MenuData();
	gotoXY(21, 10);
	cout << "Press Enter to play game!" << endl;
	gotoXY(20, 15);
	cout << "Press Esc to exit the game!" << endl;
}
