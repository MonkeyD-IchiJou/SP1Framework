#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"

void renderStartScreen(COORD c)
{
    writeToBuffer(c, (char)4);
}