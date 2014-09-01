#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"

void renderMenu(COORD c)
{
	writeToBuffer(c, ">>", 0x1D);

	ifstream menu;
	string text;
	menu.open("menu.txt");
	c.X = 9;
	c.Y = 1;
	while( !menu.eof() )
	{
		getline(menu, text);
		writeToBuffer(c, text, 0x1D);
		c.Y++;
	}
	menu.close();
	/*
	if(c.X == 25 && c.Y == 10)
		{
			writeToBuffer(c, " START GAME ", 0x1C);
		}
		else
		{
			writeToBuffer(c, " Start Game ", 0x1A);
		}

		if(c.X == 25 && c.Y == 15)
		{
			writeToBuffer(c, " INSTRUCTIONS ", 0x1C);
		}
		else
		{
			writeToBuffer(c, " Instructions ", 0x1A);
		}
		if(c.X == 25 && c.Y == 20)
		{
			writeToBuffer(c, " EXIT GAME ", 0x1C);
		}
		else
		{
			writeToBuffer(c, " Exit Game ", 0x1A);
		}*/
	

	c.X = 25;
	c.Y = 10;
	writeToBuffer(c, " Start Game ", 0x1A);
	c.Y++;

	c.X = 25;
	c.Y = 15;
	writeToBuffer(c, " Instructions ", 0x1A);
	c.Y++;
	
	c.X = 25;
	c.Y = 20;
    
	writeToBuffer(c, " Exit Game ", 0x1A);
	c.Y++;
}