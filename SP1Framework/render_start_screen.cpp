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
	c.X = 11;
	c.Y = 6;
	while( !title.eof() )
	{
		getline(title, text);
		writeToBuffer(c, text, 0x0A);
		c.Y++;
	}
	title.close();

	c.X = 11;
	c.Y = 12;
	writeToBuffer(c, "=====================================", 0x0A);
	
	c.X = 7;
	c.Y = 1;
	writeToBuffer(c, "*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=", 0x0C);

	c.X = 7;
	c.Y = 32;
	writeToBuffer(c, "*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=", 0x0C);

	ifstream enter;
	string entertext;

	enter.open("enter.txt");
	c.X = 0;
	c.Y = 19;
	while( !enter.eof() )
	{
		getline(enter, entertext);
		writeToBuffer(c, entertext, 0x0B);
		c.Y++;
	}
	enter.close();
}
