#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"

void renderOption(COORD c)
{
	writeToBuffer(c, ">>", 0x1A);

	ifstream option;
	string text;

	option.open("option.txt");
	c.X = 5;
	c.Y = 0;
	while( !option.eof() )
	{
		getline(option, text);
		writeToBuffer(c, text, 0x1A);
		c.Y++;
	}

	option.close();

	c.X = 20;
	c.Y = 10;
	writeToBuffer(c, " Change Blocks Shape " , 0x1A);

	c.X = 20;
	c.Y = 15; 
	writeToBuffer(c, " Return to Main Menu " , 0x1A); 
}
