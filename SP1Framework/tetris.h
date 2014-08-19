#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
#include <iomanip>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;

const size_t blocksize = 4;

struct blocks
{
    char square_block[blocksize][blocksize];
    char z_block[blocksize][blocksize];

    char blockshape;
    int sq_x;
    int sq_y;
};

void tetris_screen();
void welcome_screen();
void tetris_info();
void tetris_gameplay();
void pause_screen();
void menu_music();
void sound();

blocks getSquareBlocks();
blocks DelSquareBlocks();

#endif //_MAIN_H