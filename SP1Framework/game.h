#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
//#include <conio.h>

extern StopWatch g_timer;
extern bool g_quitGame;

enum Keys
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_ESCAPE,
    K_COUNT
};

struct blocks
{
    char square_block[5][5];
    char z_block[5][5];
};

void init();                // initialize your variables, allocate memory, etc
void getInput();            // get input from player
void update(double dt);     // update the game and the state of the game
void render();              // renders the current state of the game to the console
void shutdown();            // do clean up, free memory


void clearscreen();

#endif // _GAME_H