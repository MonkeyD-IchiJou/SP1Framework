#include "game.h"
#include "Framework\console.h"
#include "tetris.h"


void Paused_Screen()
{
	//Title of the game
	PauseData();

	gotoXY(20, 10);
	std::cout << "Continue Game" << endl;

	gotoXY(20,12);
	std::cout << "End Game" << endl;
}
