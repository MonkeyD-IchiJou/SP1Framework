#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"


void renderInstruction(COORD c)
{
    ifstream instruction;
    string text;
    instruction.open("instruction.txt");
    c.X = 3;
    c.Y = 0;
    while( !instruction.eof() )
    {
        getline(instruction, text);
        writeToBuffer(c, text, 0x0D);
        c.Y++;
    }
    instruction.close();
	
	c.X = 0;
	c.Y = 7;
	writeToBuffer(c, "*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=", 0x0C);

	c.X = 0;
	c.Y = 30;
	writeToBuffer(c, "*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=", 0x0C);

	c.X = 7;
    c.Y = 9;
    writeToBuffer(c, "How to play: ", 0x0A);
	
	c.X = 14;
    c.Y = 11;
    writeToBuffer(c,"- Score as much as you can!! ", 0x0A);

	c.X = 14;
    c.Y = 13;
    writeToBuffer(c,"- More rows broken = MORE SCORE!!", 0x0A);

	c.X = 14;
    c.Y = 15;                                                 
    writeToBuffer(c,"- If blocks touches the top, it's GAME OVER!!", 0x0A);

	c.X = 7;
    c.Y = 18;
    writeToBuffer(c,"Controls: ", 0x0A);

	c.X = 14;
    c.Y = 20;
    writeToBuffer(c,"Go left - Left arrow key", 0x0A);

	c.X = 14;
    c.Y = 22;
    writeToBuffer(c,"Go right - Right arrow key", 0x0A);

	c.X = 14;
    c.Y = 24;
    writeToBuffer(c,"Rotate - Up arrow key", 0x0A);

	c.X = 14;
    c.Y = 26;
    writeToBuffer(c,"Hold Block - Left/Right Shift", 0x0A);

	c.X = 14;
	c.Y = 28;
	writeToBuffer(c,"Instant Drop - Space Bar", 0x0A);
	
    c.X = 18;
    c.Y = 32;
    writeToBuffer(c, " Press ENTER to return ", 0x0A);
}