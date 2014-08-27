#ifndef _GAMEPLAY_H
#define _GAMEPLAY_H

#include "tetris.h"

const size_t height = 23;
const size_t width = 13;

const size_t borderheight = 25;
const size_t borderwidth = 13; 

const size_t blocksSize = 5;

const size_t blocksType = 7;
const size_t orientation = 4;
const size_t coordinates = 4;

extern char map[height][width];

extern COORD DataBlocks[blocksType][orientation][coordinates];

extern COORD DataMap[height][width];

struct Blocks
{
    COORD Sq_shape;     // square blocks coordinate
    COORD L_shape;      // L-shape blocks coordinate
    COORD Z_shape;      // N-shape blocks coordinate
    COORD l_shape;      // long-shape blocks coordinate
    COORD T_shape;      // T-shape blocks coordinate

    char l_blocks[blocksSize];   //shape for L blocks
};

enum BlocksType
{
    LONG_TYPE,
    Z_TYPE,
    L_TYPE,
    Sq_TYPE,
    T_TYPE
};

enum Orientation
{
    FIRST,
    SECOND,
    THIRD,
    FOURTH
};

// in render_gameplay.cpp
void DrawBorder(COORD c);

void initiate(COORD l, COORD Z, COORD L, COORD S, COORD T);
void printBlocks(int type, int change);

void DrawMap(COORD c);
void initiateMap(COORD c);

void drawShape(int orientation , int x, int y);

#endif // _GAMEPLAY_H