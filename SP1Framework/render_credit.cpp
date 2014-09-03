#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"

void renderCredit(COORD c)
{
    ifstream credit;
    string credittext;

    credit.open("credittext.txt");
    c.X = 0;
    c.Y = 0;

    while( !credit.eof() )
    {
        getline(credit, credittext);
        writeToBuffer(c, credittext, 0x0E);
        c.Y++;
    }

    credit.close();

    c.X = 0;
	c.Y = 7;
	writeToBuffer(c, "*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=", 0x0C);

	c.X = 0;
	c.Y = 30;
	writeToBuffer(c, "*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=", 0x0C);

    c.X = 17;
    c.Y = 10;
    writeToBuffer(c, "Done By: ", 0x0A);

    c.X = 24;
    c.Y = 12;
    writeToBuffer(c, "Chuk Yih Jou", 0x0A);

    c.X = 24;
    c.Y = 14;
    writeToBuffer(c, "Lim Jin", 0x0A);

    c.X = 24;
    c.Y = 16;
    writeToBuffer(c, "Tan Jun Yan", 0x0A);

    c.X = 24;
    c.Y = 18;
    writeToBuffer(c, "Lukriscifer Seah", 0x0A);

    c.X = 15;
    c.Y = 22;
    writeToBuffer(c, "Special Thanks to: ", 0x0E);

    c.X = 24;
    c.Y = 24;
    writeToBuffer(c, "Mr Sim Tze Jan", 0x0E);
}