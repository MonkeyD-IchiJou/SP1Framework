#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"

extern StopWatch g_timer;
extern bool g_quitGame;

enum Keys
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_ESCAPE,
    K_ENTER,
<<<<<<< f897789d76384a4889dc460c6c982dfab283b8bb
    K_COUNT,
	K_PAUSE
=======
	K_MUSIC,
	K_SMUSIC,
    K_COUNT
>>>>>>> c07aca0ed68dba55af91dd0658bf315516b717bb
};

void init();                // initialize your variables, allocate memory, etc
void getInput();            // get input from player
void update(double dt);     // update the game and the state of the game
void render();              // renders the current state of the game to the console
void shutdown();            // do clean up, free memory
<<<<<<< f897789d76384a4889dc460c6c982dfab283b8bb
void PauseData();
=======
void MenuData();                // file streams/file data here
>>>>>>> c07aca0ed68dba55af91dd0658bf315516b717bb

#endif // _GAME_H