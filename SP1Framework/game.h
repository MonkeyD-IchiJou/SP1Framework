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
	K_SPACE,
    K_SHIFT,
    K_COUNT
};

enum stages
{
    START_SCREEN,
    MAIN_MENU,
    INSTRUCTION,
    HIGHSCORE_MODE,
    PAUSE_SCREEN,
    END_GAME,
    CREDIT
};

enum SoundType
{
    S_JJ,
	S_ROTATE,
	S_STOP,
    S_LAND,
    S_COUNT
};

void init();                // initialize your variables, allocate memory, etc
void getInput();            // get input from player
void update(double dt);     // update the game and the state of the game
void render();              // renders the current state of the game to the console
void shutdown();            // do clean up, free memory

void initCheck();               //inside init()
void initBlockLocation();
void random();

void playGameSound(SoundType sound); // play this sound type
void playNote(char note); // play this note
void FPSinfo(COORD c);
void TIMINGInfo(COORD c);

#endif // _GAME_H