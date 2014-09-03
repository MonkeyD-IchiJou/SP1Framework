#ifndef _GAMEPLAY_H
#define _GAMEPLAY_H

#include "Framework\timer.h"

const size_t height = 23;
const size_t width = 11;

const size_t borderheight = 25;
const size_t borderwidth = 13; 

const size_t blocksSize = 5;

const size_t blocksType = 7;
const size_t orientation = 4;
const size_t coordinates = 4;

extern char map[height][width];
extern char border[borderheight][borderwidth];

extern COORD DataBlocks[blocksType][orientation][coordinates];
extern int checkLnR[blocksType][orientation];

extern int checkscore[height];

extern const char shape;

extern unsigned int score;

extern bool combo;

struct Blocks
{
    COORD Sq_shape;     // square blocks coordinate
    COORD L_shape;      // L-shape blocks coordinate
    COORD Z_shape;      // N-shape blocks coordinate
    COORD l_shape;      // long-shape blocks coordinate
    COORD T_shape;      // T-shape blocks coordinate
	COORD RZ_shape;     // Z-reverse blocks coordinate
	COORD RL_shape;     // L-reverse blocks coordinate

};

enum BlocksType
{
    LONG_TYPE,
    Z_TYPE,
    L_TYPE,
    Sq_TYPE,
    T_TYPE,
    L_REV_TYPE,
	Z_REV_TYPE
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
	int RZ;
	int RL;
    int wallcollision;
};

struct blockcolor
{
    int l;
    int Z;
    int L;
    int Sq;
    int T;
	int RZ;
	int RL;

    int map;
	int border;
};  

extern blockcolor color;

// in render_gameplay.cpp
void DrawBorder(COORD c);                                   //tetris map border            
void DrawMap(COORD c, int type);

void initiate(int type, COORD c);                           //initiate for all the orientation and blocks coordinates here
void printBlock(int type, int orientation, int color);      //spawn blocks on the top of the map
void receive(int type, int orientation, int x);        
void calculate(int x);

void UpdateMap(int type, int orientation, int x, int y);    //update map when blocks reach the obstacle

void showScore(COORD c, int x);         //print out score 

void Background(COORD c);               //tetris word at the background

#endif // _GAMEPLAY_H