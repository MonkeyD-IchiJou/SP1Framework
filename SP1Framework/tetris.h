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
const int t_mY = 16;

struct blocks
{
    char tetris_map[t_mX][t_mY];

    char square_block[3][4];

    char L_block[4][4];
	char Lrot1_block[3][5];
	char Lrot2_block[4][4];
	char Lrot3_block[3][5];

	char T_block[3][5];
	char Trot1_block[4][5];
	char Trot2_block[3][5];
	char Trot3_block[4][5];

	char N_block[4][4];
	char Nrot1_block[3][5];
	char Nrot2_block[4][4];
	char Nrot3_block[3][5];

	char I_block[5][3];
	char Irot1_block[2][6];
	char Irot2_block[5][3];
	char Irot3_block[2][6];

	char RL_block[4][4];
	char RLrot1_block[3][5];
	char RLrot2_block[4][4];
	char RLrot3_block[3][5];

	char RN_block[4][4];
	char RNrot1_block[3][5];
	char RNrot2_block[4][4];
	char RNrot3_block[3][5];

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
/////////// L Blocks and Rotation ////////////////////////////
blocks getLblocks();

blocks getLrot1blocks();

blocks getLrot2blocks();

blocks getLrot3blocks();
/////////// T Blocks and Rotation /////////////////////////////
blocks getTblocks();

blocks getTrot1blocks();

blocks getTrot2blocks();

blocks getTrot3blocks();

/////////// N Blocks and Rotation ///////////////////////////

blocks getNblocks();

blocks getNrot1blocks();

blocks getNrot2blocks();

blocks getNrot3blocks();

/////////// I Blocks and Rotation ///////////////////////////

blocks getIblocks();

blocks getIrot1blocks();

blocks getIrot2blocks();

blocks getIrot3blocks();

/////////// RL Blocks and Rotation ///////////////////////////

blocks getRLblocks();

blocks getRLrot1blocks();

blocks getRLrot2blocks();

blocks getRLrot3blocks();

/////////// RN Blocks and Rotation ///////////////////////////

blocks getRNblocks();

blocks getRNrot1blocks();

blocks getRNrot2blocks();

blocks getRNrot3blocks();

#endif //_MAIN_H