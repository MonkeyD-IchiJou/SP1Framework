#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"

void renderResult(COORD c)
{
    std::ostringstream ss;
    ss.str("");
    ss << "Your HighScore is " << score;
    writeToBuffer(c, ss.str(), 0x09);
}