#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"

void RenderPauseScreen(COORD c)
{
	writeToBuffer(c, ">>", 0x1D);

	ifstream pause;
	string text;

	pause.open("pause.txt");
	c.X = 17;
	c.Y = 1;
	while( !pause.eof() )
	{
		getline(pause, text);
		writeToBuffer(c, text, 0x1D);
		c.Y++;
	}

	pause.close();

	c.X = 25;
	c.Y = 10;
    writeToBuffer(c, " Resume Game ", 0x1A);
	c.Y++;

	c.X = 25;
	c.Y = 15;
	writeToBuffer(c, " Restart Game ", 0x1A);
	c.Y++;

	c.X = 25;
	c.Y = 20;
	writeToBuffer(c, " Exit to Main Menu ", 0x1A);
	c.Y++;
}