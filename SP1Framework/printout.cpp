#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

blocks tetris_game_map()
{
    blocks tmap;
    blocks wall;

    tmap.tetris_map;

    wall.boundaries1 = 186;
    wall.boundaries2 = 201;
    wall.boundaries3 = 200;
    wall.boundaries4 = 187;
    wall.boundaries5 = 188;
    wall.boundaries6 = 205;

    wall.insideB = '.';
    wall.stop = '+';

    for(int i = 1; i < 23; i++)
    {
        for(int j = 1; j < 16; j++)
        {
            tmap.tetris_map[0][j] = wall.boundaries6;
            tmap.tetris_map[21][j] = wall.boundaries6;
           
            tmap.tetris_map[i][1] = wall.boundaries1; 
            tmap.tetris_map[i][14] = wall.boundaries1;

            if (j > 1 && j < 14 && i > 0 && i < 24)
            {
                tmap.tetris_map[i][j] = wall.insideB; 
            }
            
        }
    }
    

    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            tmap.tetris_map[i][0] = '+';
            tmap.tetris_map[i][15] = '+';
        }
    }

    // + for detecting
    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            tmap.tetris_map[22][j] = wall.stop;
        }
    }

    tmap.tetris_map[0][1] = wall.boundaries2;
    tmap.tetris_map[21][1] = wall.boundaries3;
    tmap.tetris_map[0][14] = wall.boundaries4;
    tmap.tetris_map[21][14] = wall.boundaries5;

    return tmap;
}

blocks getSquareBlocks()
{
    blocks square;
    blocks pattern;

    square.square_block;

    pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

    square.square_block[0][0] = pattern.collisioncheck;
    square.square_block[0][1] = pattern.blockshape;
    square.square_block[0][2] = pattern.blockshape;
    square.square_block[0][3] = pattern.collisioncheck;

    square.square_block[1][0] = pattern.collisioncheck;
    square.square_block[1][1] = pattern.blockshape;
    square.square_block[1][2] = pattern.blockshape;
    square.square_block[1][3] = pattern.collisioncheck;

    square.square_block[2][0] = pattern.collisioncheck;
    square.square_block[2][1] = pattern.collisioncheck;
    square.square_block[2][2] = pattern.collisioncheck;
    square.square_block[2][3] = pattern.collisioncheck;

    return square;
}

blocks DelSquareBlocks()
{
    blocks square;
    blocks pattern;

    square.square_block;

    pattern.blockshape = ' ';
    pattern.collisioncheck = '.';

    square.square_block[0][0] = pattern.collisioncheck;
    square.square_block[0][1] = pattern.collisioncheck;
    square.square_block[0][2] = pattern.collisioncheck;
    square.square_block[0][3] = pattern.collisioncheck;

    square.square_block[1][0] = pattern.collisioncheck;
    square.square_block[1][1] = pattern.collisioncheck;
    square.square_block[1][2] = pattern.collisioncheck;
    square.square_block[1][3] = pattern.collisioncheck;

    square.square_block[2][0] = pattern.collisioncheck;
    square.square_block[2][1] = pattern.collisioncheck;
    square.square_block[2][2] = pattern.collisioncheck;
    square.square_block[2][3] = pattern.collisioncheck;

    return square;
}

blocks getLblocks()
{
	blocks L;
    blocks pattern;

    L.L_block;

    pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	L.L_block[0][0] = pattern.collisioncheck;
    L.L_block[0][1] = pattern.blockshape;
	L.L_block[0][2] = pattern.collisioncheck;
    L.L_block[0][3] = pattern.collisioncheck;

    L.L_block[1][0] = pattern.collisioncheck;
    L.L_block[1][1] = pattern.blockshape;
    L.L_block[1][2] = pattern.collisioncheck;
    L.L_block[1][3] = pattern.collisioncheck;

    L.L_block[2][0] = pattern.collisioncheck;
    L.L_block[2][1] = pattern.blockshape;
    L.L_block[2][2] = pattern.blockshape;
    L.L_block[2][3] = pattern.collisioncheck;

	L.L_block[3][0] = pattern.collisioncheck;
    L.L_block[3][1] = pattern.collisioncheck;
    L.L_block[3][2] = pattern.collisioncheck;
    L.L_block[3][3] = pattern.collisioncheck;

    return L;
}

blocks getLrot1blocks()
{
	blocks Lrot1;
    blocks pattern;

    Lrot1.Lrot1_block;

    pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	Lrot1.Lrot1_block[0][0] = pattern.collisioncheck;
    Lrot1.Lrot1_block[0][1] = pattern.blockshape;
	Lrot1.Lrot1_block[0][2] = pattern.blockshape;
    Lrot1.Lrot1_block[0][3] = pattern.blockshape;
	Lrot1.Lrot1_block[0][4] = pattern.collisioncheck;

    Lrot1.Lrot1_block[1][0] = pattern.collisioncheck;
    Lrot1.Lrot1_block[1][1] = pattern.blockshape;
    Lrot1.Lrot1_block[1][2] = pattern.collisioncheck;
    Lrot1.Lrot1_block[1][3] = pattern.collisioncheck;
	Lrot1.Lrot1_block[1][4] = pattern.collisioncheck;

    Lrot1.Lrot1_block[2][0] = pattern.collisioncheck;
    Lrot1.Lrot1_block[2][1] = pattern.collisioncheck;
    Lrot1.Lrot1_block[2][2] = pattern.collisioncheck;
    Lrot1.Lrot1_block[2][3] = pattern.collisioncheck;
	Lrot1.Lrot1_block[2][4] = pattern.collisioncheck;

	return Lrot1;
}

blocks getLrot2blocks()
{
	blocks Lrot2;
    blocks pattern;

    Lrot2.Lrot2_block;

    pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	Lrot2.Lrot2_block[0][0] = pattern.collisioncheck;
    Lrot2.Lrot2_block[0][1] = pattern.blockshape;
	Lrot2.Lrot2_block[0][2] = pattern.blockshape;
    Lrot2.Lrot2_block[0][3] = pattern.collisioncheck;

    Lrot2.Lrot2_block[1][0] = pattern.collisioncheck;
    Lrot2.Lrot2_block[1][1] = pattern.collisioncheck;
    Lrot2.Lrot2_block[1][2] = pattern.blockshape;
    Lrot2.Lrot2_block[1][3] = pattern.collisioncheck;

    Lrot2.Lrot2_block[2][0] = pattern.collisioncheck;
    Lrot2.Lrot2_block[2][1] = pattern.collisioncheck;
    Lrot2.Lrot2_block[2][2] = pattern.blockshape;
    Lrot2.Lrot2_block[2][3] = pattern.collisioncheck;

	Lrot2.Lrot2_block[3][0] = pattern.collisioncheck;
    Lrot2.Lrot2_block[3][1] = pattern.collisioncheck;
    Lrot2.Lrot2_block[3][2] = pattern.collisioncheck;
    Lrot2.Lrot2_block[3][3] = pattern.collisioncheck;

	return Lrot2;
}

blocks getLrot3blocks()
{
	blocks Lrot3;
    blocks pattern;

    Lrot3.Lrot3_block;

    pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	Lrot3.Lrot3_block[0][0] = pattern.collisioncheck;
    Lrot3.Lrot3_block[0][1] = pattern.collisioncheck;
	Lrot3.Lrot3_block[0][2] = pattern.collisioncheck;
    Lrot3.Lrot3_block[0][3] = pattern.blockshape;
	Lrot3.Lrot3_block[0][4] = pattern.collisioncheck;

    Lrot3.Lrot3_block[1][0] = pattern.collisioncheck;
    Lrot3.Lrot3_block[1][1] = pattern.blockshape;
    Lrot3.Lrot3_block[1][2] = pattern.blockshape;
    Lrot3.Lrot3_block[1][3] = pattern.blockshape;
	Lrot3.Lrot3_block[1][4] = pattern.collisioncheck;

    Lrot3.Lrot3_block[2][0] = pattern.collisioncheck;
    Lrot3.Lrot3_block[2][1] = pattern.collisioncheck;
    Lrot3.Lrot3_block[2][2] = pattern.collisioncheck;
    Lrot3.Lrot3_block[2][3] = pattern.collisioncheck;
	Lrot3.Lrot3_block[2][4] = pattern.collisioncheck;


	return Lrot3;
}

blocks getTblocks()
{
	blocks T;
    blocks pattern;

	T.T_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	T.T_block[0][0] = pattern.collisioncheck;
	T.T_block[0][1] = pattern.collisioncheck;
	T.T_block[0][2] = pattern.blockshape;
	T.T_block[0][3] = pattern.collisioncheck;
	T.T_block[0][4] = pattern.collisioncheck;

	T.T_block[1][0] = pattern.collisioncheck;
	T.T_block[1][1] = pattern.blockshape;
	T.T_block[1][2] = pattern.blockshape;
	T.T_block[1][3] = pattern.blockshape;
	T.T_block[1][4] = pattern.collisioncheck;

	T.T_block[2][0] = pattern.collisioncheck;
	T.T_block[2][1] = pattern.collisioncheck;
	T.T_block[2][2] = pattern.collisioncheck;
	T.T_block[2][3] = pattern.collisioncheck;
	T.T_block[2][4] = pattern.collisioncheck;

	return T;
}

blocks getTrot1blocks()
{
	blocks Trot1;
    blocks pattern;

    Trot1.Trot1_block;

    pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	Trot1.Trot1_block[0][0] = pattern.collisioncheck;
    Trot1.Trot1_block[0][1] = pattern.blockshape;
	Trot1.Trot1_block[0][2] = pattern.collisioncheck;
    Trot1.Trot1_block[0][3] = pattern.collisioncheck;
	Trot1.Trot1_block[0][4] = pattern.collisioncheck;

    Trot1.Trot1_block[1][0] = pattern.collisioncheck;
    Trot1.Trot1_block[1][1] = pattern.blockshape;
    Trot1.Trot1_block[1][2] = pattern.blockshape;
    Trot1.Trot1_block[1][3] = pattern.collisioncheck;
	Trot1.Trot1_block[1][4] = pattern.collisioncheck;

    Trot1.Trot1_block[2][0] = pattern.collisioncheck;
    Trot1.Trot1_block[2][1] = pattern.blockshape;
    Trot1.Trot1_block[2][2] = pattern.collisioncheck;
    Trot1.Trot1_block[2][3] = pattern.collisioncheck;
	Trot1.Trot1_block[2][4] = pattern.collisioncheck;

	Trot1.Trot1_block[3][0] = pattern.collisioncheck;
    Trot1.Trot1_block[3][1] = pattern.collisioncheck;
    Trot1.Trot1_block[3][2] = pattern.collisioncheck;
    Trot1.Trot1_block[3][3] = pattern.collisioncheck;
	Trot1.Trot1_block[3][4] = pattern.collisioncheck;

	return Trot1;
}

blocks getTrot2blocks()
{
	blocks Trot2;
    blocks pattern;

    Trot2.Trot2_block;

    pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	Trot2.Trot2_block[0][0] = pattern.collisioncheck;
    Trot2.Trot2_block[0][1] = pattern.blockshape;
	Trot2.Trot2_block[0][2] = pattern.blockshape;
    Trot2.Trot2_block[0][3] = pattern.blockshape;
	Trot2.Trot2_block[0][4] = pattern.collisioncheck;

    Trot2.Trot2_block[1][0] = pattern.collisioncheck;
    Trot2.Trot2_block[1][1] = pattern.collisioncheck;
    Trot2.Trot2_block[1][2] = pattern.blockshape;
    Trot2.Trot2_block[1][3] = pattern.collisioncheck;
	Trot2.Trot2_block[1][4] = pattern.collisioncheck;

    Trot2.Trot2_block[2][0] = pattern.collisioncheck;
    Trot2.Trot2_block[2][1] = pattern.collisioncheck;
    Trot2.Trot2_block[2][2] = pattern.collisioncheck;
    Trot2.Trot2_block[2][3] = pattern.collisioncheck;
	Trot2.Trot2_block[2][4] = pattern.collisioncheck;

	return Trot2;
}

blocks getTrot3blocks()
{
	blocks Trot3;
    blocks pattern;

    Trot3.Trot3_block;

    pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	Trot3.Trot3_block[0][0] = pattern.collisioncheck;
    Trot3.Trot3_block[0][1] = pattern.collisioncheck;
	Trot3.Trot3_block[0][2] = pattern.blockshape;
    Trot3.Trot3_block[0][3] = pattern.collisioncheck;
	Trot3.Trot3_block[0][4] = pattern.collisioncheck;

    Trot3.Trot3_block[1][0] = pattern.collisioncheck;
    Trot3.Trot3_block[1][1] = pattern.blockshape;
    Trot3.Trot3_block[1][2] = pattern.blockshape;
    Trot3.Trot3_block[1][3] = pattern.collisioncheck;
	Trot3.Trot3_block[1][4] = pattern.collisioncheck;

    Trot3.Trot3_block[2][0] = pattern.collisioncheck;
    Trot3.Trot3_block[2][1] = pattern.collisioncheck;
    Trot3.Trot3_block[2][2] = pattern.blockshape;
    Trot3.Trot3_block[2][3] = pattern.collisioncheck;
	Trot3.Trot3_block[2][4] = pattern.collisioncheck;

	Trot3.Trot3_block[3][0] = pattern.collisioncheck;
    Trot3.Trot3_block[3][1] = pattern.collisioncheck;
    Trot3.Trot3_block[3][2] = pattern.collisioncheck;
    Trot3.Trot3_block[3][3] = pattern.collisioncheck;
	Trot3.Trot3_block[3][4] = pattern.collisioncheck;

	return Trot3;
}

blocks getNblocks()
{
	blocks N;
    blocks pattern;

	N.N_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	N.N_block[0][0] = pattern.collisioncheck;
	N.N_block[0][1] = pattern.blockshape;
	N.N_block[0][2] = pattern.collisioncheck;
	N.N_block[0][3] = pattern.collisioncheck;

	N.N_block[1][0] = pattern.collisioncheck;
	N.N_block[1][1] = pattern.blockshape;
	N.N_block[1][2] = pattern.blockshape;
	N.N_block[1][3] = pattern.collisioncheck;

	N.N_block[2][0] = pattern.collisioncheck;
	N.N_block[2][1] = pattern.collisioncheck;
	N.N_block[2][2] = pattern.blockshape;
	N.N_block[2][3] = pattern.collisioncheck;

	N.N_block[3][0] = pattern.collisioncheck;
	N.N_block[3][1] = pattern.collisioncheck;
	N.N_block[3][2] = pattern.collisioncheck;
	N.N_block[3][3] = pattern.collisioncheck;

	return N;
}

blocks getNrot1blocks()
{
	blocks Nrot1;
    blocks pattern;

	Nrot1.Nrot1_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	Nrot1.Nrot1_block[0][0] = pattern.collisioncheck;
	Nrot1.Nrot1_block[0][1] = pattern.collisioncheck;
	Nrot1.Nrot1_block[0][2] = pattern.blockshape;
	Nrot1.Nrot1_block[0][3] = pattern.blockshape;
	Nrot1.Nrot1_block[0][4] = pattern.collisioncheck;

	Nrot1.Nrot1_block[1][0] = pattern.collisioncheck;
	Nrot1.Nrot1_block[1][1] = pattern.blockshape;
	Nrot1.Nrot1_block[1][2] = pattern.blockshape;
	Nrot1.Nrot1_block[1][3] = pattern.collisioncheck;
	Nrot1.Nrot1_block[1][4] = pattern.collisioncheck;

	Nrot1.Nrot1_block[2][0] = pattern.collisioncheck;
	Nrot1.Nrot1_block[2][1] = pattern.collisioncheck;
	Nrot1.Nrot1_block[2][2] = pattern.collisioncheck;
	Nrot1.Nrot1_block[2][3] = pattern.collisioncheck;
	Nrot1.Nrot1_block[2][4] = pattern.collisioncheck;

	return Nrot1;
}

blocks getNrot2blocks()
{
	blocks Nrot2;
    blocks pattern;

	Nrot2.Nrot2_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	Nrot2.Nrot2_block[0][0] = pattern.collisioncheck;
	Nrot2.Nrot2_block[0][1] = pattern.blockshape;
	Nrot2.Nrot2_block[0][2] = pattern.collisioncheck;
	Nrot2.Nrot2_block[0][3] = pattern.collisioncheck;

	Nrot2.Nrot2_block[1][0] = pattern.collisioncheck;
	Nrot2.Nrot2_block[1][1] = pattern.blockshape;
	Nrot2.Nrot2_block[1][2] = pattern.blockshape;
	Nrot2.Nrot2_block[1][3] = pattern.collisioncheck;

	Nrot2.Nrot2_block[2][0] = pattern.collisioncheck;
	Nrot2.Nrot2_block[2][1] = pattern.collisioncheck;
	Nrot2.Nrot2_block[2][2] = pattern.blockshape;
	Nrot2.Nrot2_block[2][3] = pattern.collisioncheck;

	Nrot2.Nrot2_block[3][0] = pattern.collisioncheck;
	Nrot2.Nrot2_block[3][1] = pattern.collisioncheck;
	Nrot2.Nrot2_block[3][2] = pattern.collisioncheck;
	Nrot2.Nrot2_block[3][3] = pattern.collisioncheck;

	return Nrot2;
}

blocks getNrot3blocks()
{
	blocks Nrot3;
    blocks pattern;

	Nrot3.Nrot3_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	Nrot3.Nrot3_block[0][0] = pattern.collisioncheck;
	Nrot3.Nrot3_block[0][1] = pattern.collisioncheck;
	Nrot3.Nrot3_block[0][2] = pattern.blockshape;
	Nrot3.Nrot3_block[0][3] = pattern.blockshape;
	Nrot3.Nrot3_block[0][4] = pattern.collisioncheck;

	Nrot3.Nrot3_block[1][0] = pattern.collisioncheck;
	Nrot3.Nrot3_block[1][1] = pattern.blockshape;
	Nrot3.Nrot3_block[1][2] = pattern.blockshape;
	Nrot3.Nrot3_block[1][3] = pattern.collisioncheck;
	Nrot3.Nrot3_block[1][4] = pattern.collisioncheck;

	Nrot3.Nrot3_block[2][0] = pattern.collisioncheck;
	Nrot3.Nrot3_block[2][1] = pattern.collisioncheck;
	Nrot3.Nrot3_block[2][2] = pattern.collisioncheck;
	Nrot3.Nrot3_block[2][3] = pattern.collisioncheck;
	Nrot3.Nrot3_block[2][4] = pattern.collisioncheck;

	return Nrot3;
}

blocks getIblocks()
{
	blocks I;
    blocks pattern;

	I.I_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	I.I_block[0][0] = pattern.collisioncheck;
	I.I_block[0][1] = pattern.blockshape;
	I.I_block[0][2] = pattern.collisioncheck;

	I.I_block[1][0] = pattern.collisioncheck;
	I.I_block[1][1] = pattern.blockshape;
	I.I_block[1][2] = pattern.collisioncheck;

	I.I_block[2][0] = pattern.collisioncheck;
	I.I_block[2][1] = pattern.blockshape;
	I.I_block[2][2] = pattern.collisioncheck;

	I.I_block[3][0] = pattern.collisioncheck;
	I.I_block[3][1] = pattern.blockshape;
	I.I_block[3][2] = pattern.collisioncheck;

	I.I_block[4][0] = pattern.collisioncheck;
	I.I_block[4][1] = pattern.collisioncheck;
	I.I_block[4][2] = pattern.collisioncheck;
	
	return I;
}

blocks getIrot1blocks()
{
	blocks Irot1;
    blocks pattern;

	Irot1.Irot1_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	Irot1.Irot1_block[0][0] = pattern.collisioncheck;
	Irot1.Irot1_block[0][1] = pattern.blockshape;
	Irot1.Irot1_block[0][2] = pattern.blockshape;
	Irot1.Irot1_block[0][3] = pattern.blockshape;
	Irot1.Irot1_block[0][4] = pattern.blockshape;
	Irot1.Irot1_block[0][5] = pattern.collisioncheck;

	Irot1.Irot1_block[1][0] = pattern.collisioncheck;
	Irot1.Irot1_block[1][1] = pattern.collisioncheck;
	Irot1.Irot1_block[1][2] = pattern.collisioncheck;
	Irot1.Irot1_block[1][3] = pattern.collisioncheck;
	Irot1.Irot1_block[1][4] = pattern.collisioncheck;
	Irot1.Irot1_block[1][5] = pattern.collisioncheck;
	
	return Irot1;
}

blocks getIrot2blocks()
{
	blocks Irot2;
    blocks pattern;

	Irot2.Irot2_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	Irot2.Irot2_block[0][0] = pattern.collisioncheck;
	Irot2.Irot2_block[0][1] = pattern.blockshape;
	Irot2.Irot2_block[0][2] = pattern.collisioncheck;

	Irot2.Irot2_block[1][0] = pattern.collisioncheck;
	Irot2.Irot2_block[1][1] = pattern.blockshape;
	Irot2.Irot2_block[1][2] = pattern.collisioncheck;

	Irot2.Irot2_block[2][0] = pattern.collisioncheck;
	Irot2.Irot2_block[2][1] = pattern.blockshape;
	Irot2.Irot2_block[2][2] = pattern.collisioncheck;

	Irot2.Irot2_block[3][0] = pattern.collisioncheck;
	Irot2.Irot2_block[3][1] = pattern.blockshape;
	Irot2.Irot2_block[3][2] = pattern.collisioncheck;

	Irot2.Irot2_block[4][0] = pattern.collisioncheck;
	Irot2.Irot2_block[4][1] = pattern.collisioncheck;
	Irot2.Irot2_block[4][2] = pattern.collisioncheck;

	return Irot2;
}

blocks getIrot3blocks()
{
	blocks Irot3;
    blocks pattern;

	Irot3.Irot3_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	Irot3.Irot3_block[0][0] = pattern.collisioncheck;
	Irot3.Irot3_block[0][1] = pattern.blockshape;
	Irot3.Irot3_block[0][2] = pattern.blockshape;
	Irot3.Irot3_block[0][3] = pattern.blockshape;
	Irot3.Irot3_block[0][4] = pattern.blockshape;
	Irot3.Irot3_block[0][5] = pattern.collisioncheck;

	Irot3.Irot3_block[1][0] = pattern.collisioncheck;
	Irot3.Irot3_block[1][1] = pattern.collisioncheck;
	Irot3.Irot3_block[1][2] = pattern.collisioncheck;
	Irot3.Irot3_block[1][3] = pattern.collisioncheck;
	Irot3.Irot3_block[1][4] = pattern.collisioncheck;
	Irot3.Irot3_block[1][5] = pattern.collisioncheck;
	
	return Irot3;
}

blocks getRLblocks()
{
	blocks RL;
    blocks pattern;

	RL.RL_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	RL.RL_block[0][0] = pattern.collisioncheck;
    RL.RL_block[0][1] = pattern.collisioncheck;
	RL.RL_block[0][2] = pattern.blockshape;
    RL.RL_block[0][3] = pattern.collisioncheck;

    RL.RL_block[1][0] = pattern.collisioncheck;
    RL.RL_block[1][1] = pattern.collisioncheck;
	RL.RL_block[1][2] = pattern.blockshape;
    RL.RL_block[1][3] = pattern.collisioncheck;

    RL.RL_block[2][0] = pattern.collisioncheck;
    RL.RL_block[2][1] = pattern.blockshape;
    RL.RL_block[2][2] = pattern.blockshape;
	RL.RL_block[2][3] = pattern.collisioncheck;

	RL.RL_block[3][0] = pattern.collisioncheck;
    RL.RL_block[3][1] = pattern.collisioncheck;
    RL.RL_block[3][2] = pattern.collisioncheck;
    RL.RL_block[3][3] = pattern.collisioncheck;

	return RL;
}

blocks getRLrot1blocks()
{
	blocks RLrot1;
    blocks pattern;

	RLrot1.RLrot1_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	RLrot1.RLrot1_block[0][0] = pattern.collisioncheck;
    RLrot1.RLrot1_block[0][1] = pattern.blockshape;
	RLrot1.RLrot1_block[0][2] = pattern.collisioncheck;
    RLrot1.RLrot1_block[0][3] = pattern.collisioncheck;
	RLrot1.RLrot1_block[0][4] = pattern.collisioncheck;

    RLrot1.RLrot1_block[1][0] = pattern.collisioncheck;
    RLrot1.RLrot1_block[1][1] = pattern.blockshape;
	RLrot1.RLrot1_block[1][2] = pattern.blockshape;
    RLrot1.RLrot1_block[1][3] = pattern.blockshape;
	RLrot1.RLrot1_block[1][4] = pattern.collisioncheck;

    RLrot1.RLrot1_block[2][0] = pattern.collisioncheck;
    RLrot1.RLrot1_block[2][1] = pattern.collisioncheck;
    RLrot1.RLrot1_block[2][2] = pattern.collisioncheck;
	RLrot1.RLrot1_block[2][3] = pattern.collisioncheck;
	RLrot1.RLrot1_block[2][4] = pattern.collisioncheck;

	return RLrot1;
}

blocks getRLrot2blocks()
{
	blocks RLrot2;
    blocks pattern;

	RLrot2.RLrot2_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	RLrot2.RLrot2_block[0][0] = pattern.collisioncheck;
    RLrot2.RLrot2_block[0][1] = pattern.blockshape;
	RLrot2.RLrot2_block[0][2] = pattern.blockshape;
    RLrot2.RLrot2_block[0][3] = pattern.collisioncheck;

    RLrot2.RLrot2_block[1][0] = pattern.collisioncheck;
    RLrot2.RLrot2_block[1][1] = pattern.blockshape;
	RLrot2.RLrot2_block[1][2] = pattern.collisioncheck;
    RLrot2.RLrot2_block[1][3] = pattern.collisioncheck;

    RLrot2.RLrot2_block[2][0] = pattern.collisioncheck;
    RLrot2.RLrot2_block[2][1] = pattern.blockshape;
    RLrot2.RLrot2_block[2][2] = pattern.collisioncheck;
	RLrot2.RLrot2_block[2][3] = pattern.collisioncheck;

	RLrot2.RLrot2_block[3][0] = pattern.collisioncheck;
    RLrot2.RLrot2_block[3][1] = pattern.collisioncheck;
    RLrot2.RLrot2_block[3][2] = pattern.collisioncheck;
    RLrot2.RLrot2_block[3][3] = pattern.collisioncheck;

	return RLrot2;

}

blocks getRLrot3blocks()
{
	blocks RLrot3;
    blocks pattern;

	RLrot3.RLrot3_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	
	RLrot3.RLrot3_block[0][0] = pattern.collisioncheck;
    RLrot3.RLrot3_block[0][1] = pattern.blockshape;
	RLrot3.RLrot3_block[0][2] = pattern.blockshape;
    RLrot3.RLrot3_block[0][3] = pattern.blockshape;
	RLrot3.RLrot3_block[0][4] = pattern.collisioncheck;

    RLrot3.RLrot3_block[1][0] = pattern.collisioncheck;
    RLrot3.RLrot3_block[1][1] = pattern.collisioncheck;
	RLrot3.RLrot3_block[1][2] = pattern.collisioncheck;
    RLrot3.RLrot3_block[1][3] = pattern.blockshape;
	RLrot3.RLrot3_block[1][4] = pattern.collisioncheck;

    RLrot3.RLrot3_block[2][0] = pattern.collisioncheck;
    RLrot3.RLrot3_block[2][1] = pattern.collisioncheck;
    RLrot3.RLrot3_block[2][2] = pattern.collisioncheck;
	RLrot3.RLrot3_block[2][3] = pattern.collisioncheck;
	RLrot3.RLrot3_block[2][4] = pattern.collisioncheck;

	return RLrot3;
}

blocks getRNblocks()
{
	blocks RN;
    blocks pattern;

	RN.RN_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	RN.RN_block[0][0] = pattern.collisioncheck;
	RN.RN_block[0][1] = pattern.collisioncheck;
	RN.RN_block[0][2] = pattern.blockshape;
	RN.RN_block[0][3] = pattern.collisioncheck;

	RN.RN_block[1][0] = pattern.collisioncheck;
	RN.RN_block[1][1] = pattern.blockshape;
	RN.RN_block[1][2] = pattern.blockshape;
	RN.RN_block[1][3] = pattern.collisioncheck;

	RN.RN_block[2][0] = pattern.collisioncheck;
	RN.RN_block[2][1] = pattern.blockshape;
	RN.RN_block[2][2] = pattern.collisioncheck;
	RN.RN_block[2][3] = pattern.collisioncheck;

	RN.RN_block[3][0] = pattern.collisioncheck;
	RN.RN_block[3][1] = pattern.collisioncheck;
	RN.RN_block[3][2] = pattern.collisioncheck;
	RN.RN_block[3][3] = pattern.collisioncheck;
	
	return RN;
}

blocks getRNrot1blocks()
{
	blocks RNrot1;
    blocks pattern;

	RNrot1.RNrot1_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	RNrot1.RNrot1_block[0][0] = pattern.collisioncheck;
	RNrot1.RNrot1_block[0][1] = pattern.blockshape;
	RNrot1.RNrot1_block[0][2] = pattern.blockshape;
	RNrot1.RNrot1_block[0][3] = pattern.collisioncheck;
	RNrot1.RNrot1_block[0][4] = pattern.collisioncheck;

	RNrot1.RNrot1_block[1][0] = pattern.collisioncheck;
	RNrot1.RNrot1_block[1][1] = pattern.collisioncheck;
	RNrot1.RNrot1_block[1][2] = pattern.blockshape;
	RNrot1.RNrot1_block[1][3] = pattern.blockshape;
	RNrot1.RNrot1_block[1][4] = pattern.collisioncheck;

	RNrot1.RNrot1_block[2][0] = pattern.collisioncheck;
	RNrot1.RNrot1_block[2][1] = pattern.collisioncheck;
	RNrot1.RNrot1_block[2][2] = pattern.collisioncheck;
	RNrot1.RNrot1_block[2][3] = pattern.collisioncheck;
	RNrot1.RNrot1_block[2][4] = pattern.collisioncheck;

	return RNrot1;
}
blocks getRNrot2blocks()
{
	blocks RNrot2;
    blocks pattern;

	RNrot2.RNrot2_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	RNrot2.RNrot2_block[0][0] = pattern.collisioncheck;
	RNrot2.RNrot2_block[0][1] = pattern.collisioncheck;
	RNrot2.RNrot2_block[0][2] = pattern.blockshape;
	RNrot2.RNrot2_block[0][3] = pattern.collisioncheck;

	RNrot2.RNrot2_block[1][0] = pattern.collisioncheck;
	RNrot2.RNrot2_block[1][1] = pattern.blockshape;
	RNrot2.RNrot2_block[1][2] = pattern.blockshape;
	RNrot2.RNrot2_block[1][3] = pattern.collisioncheck;

	RNrot2.RNrot2_block[2][0] = pattern.collisioncheck;
	RNrot2.RNrot2_block[2][1] = pattern.blockshape;
	RNrot2.RNrot2_block[2][2] = pattern.collisioncheck;
	RNrot2.RNrot2_block[2][3] = pattern.collisioncheck;

	RNrot2.RNrot2_block[3][0] = pattern.collisioncheck;
	RNrot2.RNrot2_block[3][1] = pattern.collisioncheck;
	RNrot2.RNrot2_block[3][2] = pattern.collisioncheck;
	RNrot2.RNrot2_block[3][3] = pattern.collisioncheck;
	
	return RNrot2;
}

blocks getRNrot3blocks()
{
	blocks RNrot3;
    blocks pattern;

	RNrot3.RNrot3_block;

	pattern.blockshape = 'o';
    pattern.collisioncheck = '-';

	RNrot3.RNrot3_block[0][0] = pattern.collisioncheck;
	RNrot3.RNrot3_block[0][1] = pattern.blockshape;
	RNrot3.RNrot3_block[0][2] = pattern.blockshape;
	RNrot3.RNrot3_block[0][3] = pattern.collisioncheck;
	RNrot3.RNrot3_block[0][4] = pattern.collisioncheck;

	RNrot3.RNrot3_block[1][0] = pattern.collisioncheck;
	RNrot3.RNrot3_block[1][1] = pattern.collisioncheck;
	RNrot3.RNrot3_block[1][2] = pattern.blockshape;
	RNrot3.RNrot3_block[1][3] = pattern.blockshape;
	RNrot3.RNrot3_block[1][4] = pattern.collisioncheck;

	RNrot3.RNrot3_block[2][0] = pattern.collisioncheck;
	RNrot3.RNrot3_block[2][1] = pattern.collisioncheck;
	RNrot3.RNrot3_block[2][2] = pattern.collisioncheck;
	RNrot3.RNrot3_block[2][3] = pattern.collisioncheck;
	RNrot3.RNrot3_block[2][4] = pattern.collisioncheck;

	return RNrot3;
}
