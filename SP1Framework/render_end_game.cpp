#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"

void renderResult(COORD c)
{
	writeToBuffer(c, ">>" , 0x0A);

	ifstream end;
	string endtext;

	end.open("end.txt");
	c.X = 2;
	c.Y = 0;
	while( !end.eof() )
	{
		getline(end, endtext);
		writeToBuffer(c, endtext, Cyan);
		c.Y++;
	}

	end.close();

    std::ostringstream ss;
    ss.str("");
	c.X = 20;
	c.Y = 12;
    ss << "Your HighScore is " << score;
    writeToBuffer(c, ss.str(), 0x0B);

	c.X = 23;
	c.Y = 20;
	writeToBuffer(c, " Play Again ", 0x0E);

	c.X = 23;
	c.Y = 24;
	writeToBuffer(c, " Return to Main Menu ", 0x0C);
}