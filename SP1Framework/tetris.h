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
void exit();

blocks getSquareBlocks();
blocks DelSquareBlocks();

#endif //_MAIN_H