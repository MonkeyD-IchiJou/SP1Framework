#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

void Paused_Screen()
{
	//Title of the game
	std::ifstream Paused_Screen;
	std::string pause;
	Paused_Screen.open("Pause.txt");
	while (!Paused_Screen.eof()) 
	{
		getline(Paused_Screen, pause);
		cout << pause << endl;
	}
	Paused_Screen.close();

	//Pause functions
	gotoXY(20, 10);
	std::cout << "Continue Game[ENTER]" << endl;
	gotoXY(20, 15);
	std::cout << "Return to Main Menu[TAB]" << endl << endl;
}
