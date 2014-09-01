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
        writeToBuffer(c, text, 0x1D);
        c.Y++;
    }
    instruction.close();

    c.Y = 8;
    writeToBuffer(c, "How to play? ", 0x1A);
    c.Y = 9;
    writeToBuffer(c,"- Try to fill as many row as possible to attain score, up to 4 rows can be broken at once. ", 0x1A);
    c.Y = 11;
    writeToBuffer(c,"- More rows broken = more score! But watch out!", 0x1A);
    c.Y = 12;                                                 
    writeToBuffer(c,"If any blocks touches the top, the game is over!", 0x1A);
    c.Y = 14;
    writeToBuffer(c,"Controls : ", 0x1A);
    c.Y = 15;
    writeToBuffer(c,"Go left - Left arrow key", 0x1A);
    c.Y = 16;
    writeToBuffer(c,"Go right - Right arrow key", 0x1A);
    c.Y = 17;
    writeToBuffer(c,"Rotate - Up arrow key", 0x1A);
    c.Y = 18;
    writeToBuffer(c,"Hold Block - Left/Right Shift", 0x1A);

    
    
    c.X = 18;
    c.Y = 24;
    writeToBuffer(c, " Press ENTER to return ", 0x1A);
}