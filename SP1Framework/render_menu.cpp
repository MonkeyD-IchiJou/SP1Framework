#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"

void renderMenu(COORD c)
{
	writeToBuffer(c, ">", 0x0E);

	// for Menu title
	ifstream menu;
	string text;
	menu.open("menu.txt");
	c.X = 9;
	c.Y = 1;
	while( !menu.eof() )
	{
		getline(menu, text);
		writeToBuffer(c, text, 0x0D);
		c.Y++;
	}
	menu.close();

	// for start game
	ifstream start;
	string starttext;

	start.open("start.txt");
	c.X = 11;
	c.Y = 7;
	while( !start.eof() )
	{
		getline(start, starttext);
		writeToBuffer(c, starttext, 0x0A);
		c.Y++;
	}
	start.close();

	// for instructions
	ifstream instruct;
	string intext;

	instruct.open("instruct.txt");
	c.X = 8;
	c.Y = 14;
	while( !instruct.eof() )
	{
		getline(instruct, intext);
		writeToBuffer(c, intext, 0x0B);
		c.Y++;
	}
	instruct.close();

	// for options
	ifstream options;
	string opttext;

	options.open("opttext.txt");
	c.X = 10;
	c.Y = 21;
	while( !options.eof() )
	{
		getline(options, opttext);
		writeToBuffer(c, opttext, 0x0E);
		c.Y++;
	}
	options.close();

	// for exit game
	ifstream exit;
	string exittext;

	exit.open("exit.txt");
	c.X = 15;
	c.Y = 28;
	while( !exit.eof() )
	{
		getline(exit, exittext);
		writeToBuffer(c, exittext, 0x0F);
		c.Y++;
	}
	exit.close();

}