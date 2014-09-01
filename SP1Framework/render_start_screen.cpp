#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"

void renderStartScreen(COORD c)
{
	ifstream title;
	string text;
	ifstream bg;
	string bgtext;

	title.open("title.txt");
	c.X = 12;
	c.Y = 3;
	while( !title.eof() )
	{
		getline(title, text);
		writeToBuffer(c, text, 0x1A);
		c.Y++;
	}
	title.close();
	
	/*bg.open("bg.txt");
	c.X = 1;
	c.Y = 0;
	while( !bg.eof() )
	{
		getline(bg, bgtext);
		writeToBuffer(c, bgtext, 0xA);
		c.Y++;
	}

	bg.close();*/

	std::stringstream key;
	key << "Please Press Enter!" << endl;
	c.X = 20;
	c.Y = 15;
	writeToBuffer(c, key.str(), 0x1B);
}
