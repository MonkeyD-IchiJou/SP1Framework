#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

void MenuScreen()
{
    //Title of the game
	std::ifstream MenuScreen;
	std::string data;
	MenuScreen.open("tetris_ascii.txt");
	while(!MenuScreen.eof())
	{
		getline(MenuScreen, data);
		cout << data << endl;
	}
	MenuScreen.close();
	
	//Menu Functions
	gotoXY(21, 10);
	cout << "Press Enter to play game!" << endl;
	gotoXY(20, 15);
	cout << "Press Esc to exit the game!" << endl;
}
