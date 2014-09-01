#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"


void renderInstruction(COORD c)
{
    std::ostringstream ss;
    ss.str("");
    ss << "";
    c.X = 30;
    c.Y = 1;
    writeToBuffer(c, ss.str(), BlueBg);
    //writeToBuffer(c, (char)4);
}