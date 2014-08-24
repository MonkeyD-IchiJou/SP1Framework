#ifndef _TETRIS_H
#define _TETRIS_H

#include <iostream>
#include <iomanip>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

const size_t height = 23;
const size_t width = 14;

extern char map[20][30];

struct Location
{
    COORD MmLocation;   // main menu screen
    COORD OptLocation;  // option screen (havent done yet)
    COORD TmLocation;   //tetris map 
};

struct Blocks
{
    COORD Sq_shape;     // square blocks coordinate
    COORD L_shape;      // L-shape blocks coordinate
    COORD Z_shape;      // N-shape blocks coordinate
    COORD l_shape;      // long-shape blocks coordinate
};

enum gameState
{
    START_SCREEN,
    MENU_SCREEN,
    GAMEPLAY_SCREEN,
    OPTION_SCREEN
};

void FPSInfo();
void TIMINGInfo();

// in render_menu.cpp
void renderMenu(COORD c);

// in render_start_screen.cpp
void renderStartScreen(COORD c);

// in render_gameplay.cpp
void sqBlocks(COORD c);
void LBlocks(COORD c);
void ZBlocks(COORD c);
void printTetrisMap(COORD c);
char BLocksShape();

void DrawArray(COORD c);
void DrawMap(COORD c);
void Map();

#endif // _TETRIS_H