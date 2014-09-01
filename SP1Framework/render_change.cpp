#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"

void renderChange(COORD c)
{
	writeToBuffer(c, ">>", 0x1D);

	c.X = 20;
	c.Y = 5;
	writeToBuffer(c, " A shape ", 0x1A);
	c.Y++;

	c.X = 20;
	c.Y = 7;
	writeToBuffer(c, " # shape ", 0x1A);
	c.Y++;

	c.X = 20;
	c.Y = 9;
	writeToBuffer(c, " X shape ", 0x1A);
	c.Y++;

	c.X = 20;
	c.Y = 11;
	writeToBuffer(c, " O shape ", 0x1A);
	c.Y++;

	c.X = 20;
	c.Y = 13;
	writeToBuffer(c, " o shape ", 0x1A);
	c.Y++;

	c.X = 20;
	c.Y = 15;
	writeToBuffer(c, " Return to Main Menu ", 0x1A);
	c.Y++;
}