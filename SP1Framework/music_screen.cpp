#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

void MusicScreen()
{
    //Title of the game
	std::ifstream MusicScreen;
	std::string data;
	MusicScreen.open("music.txt");
	while(!MusicScreen.eof())
	{
		getline(MusicScreen, data);
		cout << data << endl;
	}
	MusicScreen.close();
	
	//Menu Functions
	gotoXY(23, 15);
	cout << "Press F2 to play music!\n                (BTW, it can't be stopped after 1 minute)" << endl;
	gotoXY(23, 20);
	cout << "Press backspace to leave the game!" << endl;
}