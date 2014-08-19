#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
#include <iomanip>
#include <conio.h>

using std::cout;
using std::endl;

struct blocks
{
    char square_block[4][4];
    char z_block[4][4];
};

void tetris_screen();
void tetris_info();
void tetris_gameplay();

void square_block();
void z_block();

#endif //_MAIN_H