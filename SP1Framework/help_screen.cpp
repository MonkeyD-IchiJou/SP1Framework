#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

void HelpScreen()
{
	//Title of screen
	std::ifstream Help;
	std::string data;
	Help.open("help.txt");
	while(!Help.eof())
	{
		getline(Help, data);
		cout << data << endl;
	}
	Help.close();

	//Rules or help for game
	gotoXY(5, 10);
	cout << "******This screen is to help players in the game.******" << endl;
	gotoXY(3, 15);
	cout << "Controls: " << endl;
	gotoXY(6, 18);
	cout << "Moving of Blocks: Left Key, Right key, Down Key" << endl;

	gotoXY(3, 21);
	cout << "Press Enter to play the game!" << endl;

	gotoXY(3, 23);
	cout << "Press Backspace to exit the program!" << endl;
}