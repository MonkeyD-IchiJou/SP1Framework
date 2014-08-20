#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <exception>
using std::cout;
using std::cin;
using std::endl;
using std::string;

const int t_mX = 23;
const int t_mY = 25;

const size_t blocksizeX = 3;
const size_t blocksizeY = 4;

struct blocks
{
    char tetris_map[t_mX][t_mY];

    char square_block[blocksizeX][blocksizeY];
    char z_block[blocksizeX][blocksizeY];

    char boundaries1;
    char boundaries2;
    char boundaries3;
    char boundaries4;
    char boundaries5;
    char boundaries6;
    char insideB;
    char stop;

    char blockshape;
    char collisioncheck;

    int coord_x;
    int coord_y;
};

void tetris_screen();
void welcome_screen();
void tetris_info();
void tetris_gameplay();
void pause_screen();
void menu_music();
void sound();
void exit();

blocks tetris_game_map();
blocks getSquareBlocks();
blocks DelSquareBlocks();

#endif //_MAIN_H