#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"

void RenderPauseScreen(COORD c)
{
    writeToBuffer(c, (char)1);
}