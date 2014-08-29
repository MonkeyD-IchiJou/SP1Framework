#ifndef _GAMEPLAY_H
#define _GAMEPLAY_H

#include "Framework\timer.h"

const size_t height = 22;
const size_t width = 11;

const size_t borderheight = 25;
const size_t borderwidth = 13; 

const size_t blocksSize = 5;

const size_t blocksType = 7;
const size_t orientation = 4;
const size_t coordinates = 4;

extern char map[height][width];

extern COORD DataBlocks[blocksType][orientation][coordinates];
extern int checkLnR[blocksType][orientation];

struct Blocks
{
    COORD Sq_shape;     // square blocks coordinate
    COORD L_shape;      // L-shape blocks coordinate
    COORD Z_shape;      // N-shape blocks coordinate
    COORD l_shape;      // long-shape blocks coordinate
    COORD T_shape;      // T-shape blocks coordinate
	COORD RZ_shape;
};

enum BlocksType
{
    LONG_TYPE,
    Z_TYPE,
    L_TYPE,
    Sq_TYPE,
    T_TYPE,
<<<<<<< 360d9ef454f103cc08fd1044c2fa70934a2d40b1
    L_REV_TYPE,
<<<<<<< 577c1c6ee86514be23a66501e64c3ab889843ffb
	Z_REV_TYPE
=======
    Z_REV_TYPE
>>>>>>> 420784b93cf8c1239e370af4a8d95e1b2dd717a9
=======
>>>>>>> a15b10704484e98ffab1d4792f52a503a5d1070a
};

enum Orientation
{
    FIRST,
    SECOND,
    THIRD,
    FOURTH
};

struct Block
{
    COORD location;
    BlocksType type;
    Orientation orientation; 
    WORD color;
};

struct collisionCheck
{
    int l;
    int Z;
    int L;
    int Sq;
    int T;
    int REVZ;

    int wallcollision;
};

// in render_gameplay.cpp
void DrawBorder(COORD c);
void SetMap();
void DrawMap(COORD c);

void initiate(int type, COORD c);
void printBlock(int type, int orientation);
void score(int type, int orientation, int x);

void UpdateMap(int type, int orientation, int x, int y);
void updateLONG();
void updateZ();
void updateL();
void updateSq();
void updateT();
#endif // _GAMEPLAY_H