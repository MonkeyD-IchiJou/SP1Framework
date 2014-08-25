#ifndef _TETRIS_H
#define _TETRIS_H

#include <iostream>
#include <iomanip>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

const size_t height = 21;
const size_t width = 11;

const size_t borderheight = 23;
const size_t borderwidth = 13; 

const size_t blocksSize = 5;

const size_t blocksType = 7;
const size_t orientation = 4;
const size_t coordinates = 4;

extern char map[height][width];

extern COORD DataBlocks[blocksType][orientation][coordinates];

struct Location
{
    COORD MmLocation;   // main menu screen
    COORD OptLocation;  // option screen (havent done yet)
    COORD TmLocation;   //tetris map 
<<<<<<< f64eb5a5d5352954ac1b8203c61f771e5459eaf0
	COORD PsLocation;   // pause screen
=======
    COORD BdLocation;   //border location
>>>>>>> 7afc92211722e54167ffb698e4488cfedb9389ed
};

struct Blocks
{
    COORD Sq_shape;     // square blocks coordinate
    COORD L_shape;      // L-shape blocks coordinate
    COORD Z_shape;      // N-shape blocks coordinate
    COORD l_shape;      // long-shape blocks coordinate

    char l_blocks[blocksSize];   //shape for L blocks
};

enum gameState
{
    START_SCREEN,
    MENU_SCREEN,
    GAMEPLAY_SCREEN,
    OPTION_SCREEN,
	PAUSE_SCREEN
};

void FPSInfo();
void TIMINGInfo();

// in render_menu.cpp
void renderMenu(COORD c);

// in render_start_screen.cpp
void renderStartScreen(COORD c);

// in render_gameplay.cpp
void printTetrisMap(COORD c);
void DrawMap(COORD c);
void DrawBorder(COORD c);

void initiate(COORD l, COORD Z, COORD L);

void print_l_blocks(int change);
void print_Z_blocks(int change);

// in render_pause_screen.cpp
void RenderPauseScreen(COORD c);

#endif // _TETRIS_H