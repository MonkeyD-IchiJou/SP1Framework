#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

void renderStartScreen (COORD c)
{
    gotoXY(30, 10);
    colour(0xD);
    cout << "Priest press ENTER";
