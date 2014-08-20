#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

blocks tetris_game_map()
{
	/*
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
    tmap.tetris_map[21][14] = wall.boundaries5;*/
	
	blocks tmap;
    blocks wall;

    tmap.tetris_map;

	wall.boundaries1 = 186; // ||
    wall.boundaries2 = 201; // top left corner
    wall.boundaries3 = 200; // bot left corner
    wall.boundaries4 = 187; // top right corner
    wall.boundaries5 = 188; // bot right corner
    wall.boundaries6 = 205; //	=

    wall.insideB = '.';
    wall.stop = '+';

	tmap.tetris_map[0][0] = wall.stop;
	tmap.tetris_map[0][1] = wall.boundaries2;
	tmap.tetris_map[0][2] = wall.boundaries6;
	tmap.tetris_map[0][3] = wall.boundaries6;
	tmap.tetris_map[0][4] = wall.boundaries6;
	tmap.tetris_map[0][5] = wall.boundaries6;
	tmap.tetris_map[0][6] = wall.boundaries6;
	tmap.tetris_map[0][7] = wall.boundaries6;
	tmap.tetris_map[0][8] = wall.boundaries6;
	tmap.tetris_map[0][9] = wall.boundaries6;
	tmap.tetris_map[0][10] = wall.boundaries6;
	tmap.tetris_map[0][11] = wall.boundaries6;
	tmap.tetris_map[0][12] = wall.boundaries6;
	tmap.tetris_map[0][13] = wall.boundaries6;
	tmap.tetris_map[0][14] = wall.boundaries4;
	tmap.tetris_map[0][15] = wall.stop;

	tmap.tetris_map[1][0] = wall.stop;
	tmap.tetris_map[1][1] = wall.boundaries1;
	tmap.tetris_map[1][2] = wall.insideB;
	tmap.tetris_map[1][3] = wall.insideB;
	tmap.tetris_map[1][4] = wall.insideB;
	tmap.tetris_map[1][5] = wall.insideB;
	tmap.tetris_map[1][6] = wall.insideB;
	tmap.tetris_map[1][7] = wall.insideB;
	tmap.tetris_map[1][8] = wall.insideB;
	tmap.tetris_map[1][9] = wall.insideB;
	tmap.tetris_map[1][10] = wall.insideB;
	tmap.tetris_map[1][11] = wall.insideB;
	tmap.tetris_map[1][12] = wall.insideB;
	tmap.tetris_map[1][13] = wall.insideB;
	tmap.tetris_map[1][14] = wall.boundaries1;
	tmap.tetris_map[1][15] = wall.stop;

	tmap.tetris_map[2][0] = wall.stop;
	tmap.tetris_map[2][1] = wall.boundaries1;
	tmap.tetris_map[2][2] = wall.insideB;
	tmap.tetris_map[2][3] = wall.insideB;
	tmap.tetris_map[2][4] = wall.insideB;
	tmap.tetris_map[2][5] = wall.insideB;
	tmap.tetris_map[2][6] = wall.insideB;
	tmap.tetris_map[2][7] = wall.insideB;
	tmap.tetris_map[2][8] = wall.insideB;
	tmap.tetris_map[2][9] = wall.insideB;
	tmap.tetris_map[2][10] = wall.insideB;
	tmap.tetris_map[2][11] = wall.insideB;
	tmap.tetris_map[2][12] = wall.insideB;
	tmap.tetris_map[2][13] = wall.insideB;
	tmap.tetris_map[2][14] = wall.boundaries1;
	tmap.tetris_map[2][15] = wall.stop;

	tmap.tetris_map[3][0] = wall.stop;
	tmap.tetris_map[3][1] = wall.boundaries1;
	tmap.tetris_map[3][2] = wall.insideB;
	tmap.tetris_map[3][3] = wall.insideB;
	tmap.tetris_map[3][4] = wall.insideB;
	tmap.tetris_map[3][5] = wall.insideB;
	tmap.tetris_map[3][6] = wall.insideB;
	tmap.tetris_map[3][7] = wall.insideB;
	tmap.tetris_map[3][8] = wall.insideB;
	tmap.tetris_map[3][9] = wall.insideB;
	tmap.tetris_map[3][10] = wall.insideB;
	tmap.tetris_map[3][11] = wall.insideB;
	tmap.tetris_map[3][12] = wall.insideB;
	tmap.tetris_map[3][13] = wall.insideB;
	tmap.tetris_map[3][14] = wall.boundaries1;
	tmap.tetris_map[3][15] = wall.stop;

	tmap.tetris_map[4][0] = wall.stop;
	tmap.tetris_map[4][1] = wall.boundaries1;
	tmap.tetris_map[4][2] = wall.insideB;
	tmap.tetris_map[4][3] = wall.insideB;
	tmap.tetris_map[4][4] = wall.insideB;
	tmap.tetris_map[4][5] = wall.insideB;
	tmap.tetris_map[4][6] = wall.insideB;
	tmap.tetris_map[4][7] = wall.insideB;
	tmap.tetris_map[4][8] = wall.insideB;
	tmap.tetris_map[4][9] = wall.insideB;
	tmap.tetris_map[4][10] = wall.insideB;
	tmap.tetris_map[4][11] = wall.insideB;
	tmap.tetris_map[4][12] = wall.insideB;
	tmap.tetris_map[4][13] = wall.insideB;
	tmap.tetris_map[4][14] = wall.boundaries1;
	tmap.tetris_map[4][15] = wall.stop;

	tmap.tetris_map[5][0] = wall.stop;
	tmap.tetris_map[5][1] = wall.boundaries1;
	tmap.tetris_map[5][2] = wall.insideB;
	tmap.tetris_map[5][3] = wall.insideB;
	tmap.tetris_map[5][4] = wall.insideB;
	tmap.tetris_map[5][5] = wall.insideB;
	tmap.tetris_map[5][6] = wall.insideB;
	tmap.tetris_map[5][7] = wall.insideB;
	tmap.tetris_map[5][8] = wall.insideB;
	tmap.tetris_map[5][9] = wall.insideB;
	tmap.tetris_map[5][10] = wall.insideB;
	tmap.tetris_map[5][11] = wall.insideB;
	tmap.tetris_map[5][12] = wall.insideB;
	tmap.tetris_map[5][13] = wall.insideB;
	tmap.tetris_map[5][14] = wall.boundaries1;
	tmap.tetris_map[5][15] = wall.stop;

	tmap.tetris_map[6][0] = wall.stop;
	tmap.tetris_map[6][1] = wall.boundaries1;
	tmap.tetris_map[6][2] = wall.insideB;
	tmap.tetris_map[6][3] = wall.insideB;
	tmap.tetris_map[6][4] = wall.insideB;
	tmap.tetris_map[6][5] = wall.insideB;
	tmap.tetris_map[6][6] = wall.insideB;
	tmap.tetris_map[6][7] = wall.insideB;
	tmap.tetris_map[6][8] = wall.insideB;
	tmap.tetris_map[6][9] = wall.insideB;
	tmap.tetris_map[6][10] = wall.insideB;
	tmap.tetris_map[6][11] = wall.insideB;
	tmap.tetris_map[6][12] = wall.insideB;
	tmap.tetris_map[6][13] = wall.insideB;
	tmap.tetris_map[6][14] = wall.boundaries1;
	tmap.tetris_map[6][15] = wall.stop;

	tmap.tetris_map[7][0] = wall.stop;
	tmap.tetris_map[7][1] = wall.boundaries1;
	tmap.tetris_map[7][2] = wall.insideB;
	tmap.tetris_map[7][3] = wall.insideB;
	tmap.tetris_map[7][4] = wall.insideB;
	tmap.tetris_map[7][5] = wall.insideB;
	tmap.tetris_map[7][6] = wall.insideB;
	tmap.tetris_map[7][7] = wall.insideB;
	tmap.tetris_map[7][8] = wall.insideB;
	tmap.tetris_map[7][9] = wall.insideB;
	tmap.tetris_map[7][10] = wall.insideB;
	tmap.tetris_map[7][11] = wall.insideB;
	tmap.tetris_map[7][12] = wall.insideB;
	tmap.tetris_map[7][13] = wall.insideB;
	tmap.tetris_map[7][14] = wall.boundaries1;
	tmap.tetris_map[7][15] = wall.stop;

	tmap.tetris_map[8][0] = wall.stop;
	tmap.tetris_map[8][1] = wall.boundaries1;
	tmap.tetris_map[8][2] = wall.insideB;
	tmap.tetris_map[8][3] = wall.insideB;
	tmap.tetris_map[8][4] = wall.insideB;
	tmap.tetris_map[8][5] = wall.insideB;
	tmap.tetris_map[8][6] = wall.insideB;
	tmap.tetris_map[8][7] = wall.insideB;
	tmap.tetris_map[8][8] = wall.insideB;
	tmap.tetris_map[8][9] = wall.insideB;
	tmap.tetris_map[8][10] = wall.insideB;
	tmap.tetris_map[8][11] = wall.insideB;
	tmap.tetris_map[8][12] = wall.insideB;
	tmap.tetris_map[8][13] = wall.insideB;
	tmap.tetris_map[8][14] = wall.boundaries1;
	tmap.tetris_map[8][15] = wall.stop;

	tmap.tetris_map[9][0] = wall.stop;
	tmap.tetris_map[9][1] = wall.boundaries1;
	tmap.tetris_map[9][2] = wall.insideB;
	tmap.tetris_map[9][3] = wall.insideB;
	tmap.tetris_map[9][4] = wall.insideB;
	tmap.tetris_map[9][5] = wall.insideB;
	tmap.tetris_map[9][6] = wall.insideB;
	tmap.tetris_map[9][7] = wall.insideB;
	tmap.tetris_map[9][8] = wall.insideB;
	tmap.tetris_map[9][9] = wall.insideB;
	tmap.tetris_map[9][10] = wall.insideB;
	tmap.tetris_map[9][11] = wall.insideB;
	tmap.tetris_map[9][12] = wall.insideB;
	tmap.tetris_map[9][13] = wall.insideB;
	tmap.tetris_map[9][14] = wall.boundaries1;
	tmap.tetris_map[9][15] = wall.stop;

	tmap.tetris_map[10][0] = wall.stop;
	tmap.tetris_map[10][1] = wall.boundaries1;
	tmap.tetris_map[10][2] = wall.insideB;
	tmap.tetris_map[10][3] = wall.insideB;
	tmap.tetris_map[10][4] = wall.insideB;
	tmap.tetris_map[10][5] = wall.insideB;
	tmap.tetris_map[10][6] = wall.insideB;
	tmap.tetris_map[10][7] = wall.insideB;
	tmap.tetris_map[10][8] = wall.insideB;
	tmap.tetris_map[10][9] = wall.insideB;
	tmap.tetris_map[10][10] = wall.insideB;
	tmap.tetris_map[10][11] = wall.insideB;
	tmap.tetris_map[10][12] = wall.insideB;
	tmap.tetris_map[10][13] = wall.insideB;
	tmap.tetris_map[10][14] = wall.boundaries1;
	tmap.tetris_map[10][15] = wall.stop;

	tmap.tetris_map[11][0] = wall.stop;
	tmap.tetris_map[11][1] = wall.boundaries1;
	tmap.tetris_map[11][2] = wall.insideB;
	tmap.tetris_map[11][3] = wall.insideB;
	tmap.tetris_map[11][4] = wall.insideB;
	tmap.tetris_map[11][5] = wall.insideB;
	tmap.tetris_map[11][6] = wall.insideB;
	tmap.tetris_map[11][7] = wall.insideB;
	tmap.tetris_map[11][8] = wall.insideB;
	tmap.tetris_map[11][9] = wall.insideB;
	tmap.tetris_map[11][10] = wall.insideB;
	tmap.tetris_map[11][11] = wall.insideB;
	tmap.tetris_map[11][12] = wall.insideB;
	tmap.tetris_map[11][13] = wall.insideB;
	tmap.tetris_map[11][14] = wall.boundaries1;
	tmap.tetris_map[11][15] = wall.stop;

	tmap.tetris_map[12][0] = wall.stop;
	tmap.tetris_map[12][1] = wall.boundaries1;
	tmap.tetris_map[12][2] = wall.insideB;
	tmap.tetris_map[12][3] = wall.insideB;
	tmap.tetris_map[12][4] = wall.insideB;
	tmap.tetris_map[12][5] = wall.insideB;
	tmap.tetris_map[12][6] = wall.insideB;
	tmap.tetris_map[12][7] = wall.insideB;
	tmap.tetris_map[12][8] = wall.insideB;
	tmap.tetris_map[12][9] = wall.insideB;
	tmap.tetris_map[12][10] = wall.insideB;
	tmap.tetris_map[12][11] = wall.insideB;
	tmap.tetris_map[12][12] = wall.insideB;
	tmap.tetris_map[12][13] = wall.insideB;
	tmap.tetris_map[12][14] = wall.boundaries1;
	tmap.tetris_map[12][15] = wall.stop;

	tmap.tetris_map[13][0] = wall.stop;
	tmap.tetris_map[13][1] = wall.boundaries1;
	tmap.tetris_map[13][2] = wall.insideB;
	tmap.tetris_map[13][3] = wall.insideB;
	tmap.tetris_map[13][4] = wall.insideB;
	tmap.tetris_map[13][5] = wall.insideB;
	tmap.tetris_map[13][6] = wall.insideB;
	tmap.tetris_map[13][7] = wall.insideB;
	tmap.tetris_map[13][8] = wall.insideB;
	tmap.tetris_map[13][9] = wall.insideB;
	tmap.tetris_map[13][10] = wall.insideB;
	tmap.tetris_map[13][11] = wall.insideB;
	tmap.tetris_map[13][12] = wall.insideB;
	tmap.tetris_map[13][13] = wall.insideB;
	tmap.tetris_map[13][14] = wall.boundaries1;
	tmap.tetris_map[13][15] = wall.stop;

	tmap.tetris_map[14][0] = wall.stop;
	tmap.tetris_map[14][1] = wall.boundaries1;
	tmap.tetris_map[14][2] = wall.insideB;
	tmap.tetris_map[14][3] = wall.insideB;
	tmap.tetris_map[14][4] = wall.insideB;
	tmap.tetris_map[14][5] = wall.insideB;
	tmap.tetris_map[14][6] = wall.insideB;
	tmap.tetris_map[14][7] = wall.insideB;
	tmap.tetris_map[14][8] = wall.insideB;
	tmap.tetris_map[14][9] = wall.insideB;
	tmap.tetris_map[14][10] = wall.insideB;
	tmap.tetris_map[14][11] = wall.insideB;
	tmap.tetris_map[14][12] = wall.insideB;
	tmap.tetris_map[14][13] = wall.insideB;
	tmap.tetris_map[14][14] = wall.boundaries1;
	tmap.tetris_map[14][15] = wall.stop;

	tmap.tetris_map[15][0] = wall.stop;
	tmap.tetris_map[15][1] = wall.boundaries1;
	tmap.tetris_map[15][2] = wall.insideB;
	tmap.tetris_map[15][3] = wall.insideB;
	tmap.tetris_map[15][4] = wall.insideB;
	tmap.tetris_map[15][5] = wall.insideB;
	tmap.tetris_map[15][6] = wall.insideB;
	tmap.tetris_map[15][7] = wall.insideB;
	tmap.tetris_map[15][8] = wall.insideB;
	tmap.tetris_map[15][9] = wall.insideB;
	tmap.tetris_map[15][10] = wall.insideB;
	tmap.tetris_map[15][11] = wall.insideB;
	tmap.tetris_map[15][12] = wall.insideB;
	tmap.tetris_map[15][13] = wall.insideB;
	tmap.tetris_map[15][14] = wall.boundaries1;
	tmap.tetris_map[15][15] = wall.stop;

	tmap.tetris_map[16][0] = wall.stop;
	tmap.tetris_map[16][1] = wall.boundaries1;
	tmap.tetris_map[16][2] = wall.insideB;
	tmap.tetris_map[16][3] = wall.insideB;
	tmap.tetris_map[16][4] = wall.insideB;
	tmap.tetris_map[16][5] = wall.insideB;
	tmap.tetris_map[16][6] = wall.insideB;
	tmap.tetris_map[16][7] = wall.insideB;
	tmap.tetris_map[16][8] = wall.insideB;
	tmap.tetris_map[16][9] = wall.insideB;
	tmap.tetris_map[16][10] = wall.insideB;
	tmap.tetris_map[16][11] = wall.insideB;
	tmap.tetris_map[16][12] = wall.insideB;
	tmap.tetris_map[16][13] = wall.insideB;
	tmap.tetris_map[16][14] = wall.boundaries1;
	tmap.tetris_map[16][15] = wall.stop;

	tmap.tetris_map[17][0] = wall.stop;
	tmap.tetris_map[17][1] = wall.boundaries1;
	tmap.tetris_map[17][2] = wall.insideB;
	tmap.tetris_map[17][3] = wall.insideB;
	tmap.tetris_map[17][4] = wall.insideB;
	tmap.tetris_map[17][5] = wall.insideB;
	tmap.tetris_map[17][6] = wall.insideB;
	tmap.tetris_map[17][7] = wall.insideB;
	tmap.tetris_map[17][8] = wall.insideB;
	tmap.tetris_map[17][9] = wall.insideB;
	tmap.tetris_map[17][10] = wall.insideB;
	tmap.tetris_map[17][11] = wall.insideB;
	tmap.tetris_map[17][12] = wall.insideB;
	tmap.tetris_map[17][13] = wall.insideB;
	tmap.tetris_map[17][14] = wall.boundaries1;
	tmap.tetris_map[17][15] = wall.stop;

	tmap.tetris_map[18][0] = wall.stop;
	tmap.tetris_map[18][1] = wall.boundaries1;
	tmap.tetris_map[18][2] = wall.insideB;
	tmap.tetris_map[18][3] = wall.insideB;
	tmap.tetris_map[18][4] = wall.insideB;
	tmap.tetris_map[18][5] = wall.insideB;
	tmap.tetris_map[18][6] = wall.insideB;
	tmap.tetris_map[18][7] = wall.insideB;
	tmap.tetris_map[18][8] = wall.insideB;
	tmap.tetris_map[18][9] = wall.insideB;
	tmap.tetris_map[18][10] = wall.insideB;
	tmap.tetris_map[18][11] = wall.insideB;
	tmap.tetris_map[18][12] = wall.insideB;
	tmap.tetris_map[18][13] = wall.insideB;
	tmap.tetris_map[18][14] = wall.boundaries1;
	tmap.tetris_map[18][15] = wall.stop;

	tmap.tetris_map[19][0] = wall.stop;
	tmap.tetris_map[19][1] = wall.boundaries1;
	tmap.tetris_map[19][2] = wall.insideB;
	tmap.tetris_map[19][3] = wall.insideB;
	tmap.tetris_map[19][4] = wall.insideB;
	tmap.tetris_map[19][5] = wall.insideB;
	tmap.tetris_map[19][6] = wall.insideB;
	tmap.tetris_map[19][7] = wall.insideB;
	tmap.tetris_map[19][8] = wall.insideB;
	tmap.tetris_map[19][9] = wall.insideB;
	tmap.tetris_map[19][10] = wall.insideB;
	tmap.tetris_map[19][11] = wall.insideB;
	tmap.tetris_map[19][12] = wall.insideB;
	tmap.tetris_map[19][13] = wall.insideB;
	tmap.tetris_map[19][14] = wall.boundaries1;
	tmap.tetris_map[19][15] = wall.stop;

	tmap.tetris_map[20][0] = wall.stop;
	tmap.tetris_map[20][1] = wall.boundaries1;
	tmap.tetris_map[20][2] = wall.insideB;
	tmap.tetris_map[20][3] = wall.insideB;
	tmap.tetris_map[20][4] = wall.insideB;
	tmap.tetris_map[20][5] = wall.insideB;
	tmap.tetris_map[20][6] = wall.insideB;
	tmap.tetris_map[20][7] = wall.insideB;
	tmap.tetris_map[20][8] = wall.insideB;
	tmap.tetris_map[20][9] = wall.insideB;
	tmap.tetris_map[20][10] = wall.insideB;
	tmap.tetris_map[20][11] = wall.insideB;
	tmap.tetris_map[20][12] = wall.insideB;
	tmap.tetris_map[20][13] = wall.insideB;
	tmap.tetris_map[20][14] = wall.boundaries1;
	tmap.tetris_map[20][15] = wall.stop;

	tmap.tetris_map[21][0] = wall.stop;
	tmap.tetris_map[21][1] = wall.boundaries3;
	tmap.tetris_map[21][2] = wall.boundaries6;
	tmap.tetris_map[21][3] = wall.boundaries6;
	tmap.tetris_map[21][4] = wall.boundaries6;
	tmap.tetris_map[21][5] = wall.boundaries6;
	tmap.tetris_map[21][6] = wall.boundaries6;
	tmap.tetris_map[21][7] = wall.boundaries6;
	tmap.tetris_map[21][8] = wall.boundaries6;
	tmap.tetris_map[21][9] = wall.boundaries6;
	tmap.tetris_map[21][10] = wall.boundaries6;
	tmap.tetris_map[21][11] = wall.boundaries6;
	tmap.tetris_map[21][12] = wall.boundaries6;
	tmap.tetris_map[21][13] = wall.boundaries6;
	tmap.tetris_map[21][14] = wall.boundaries5;
	tmap.tetris_map[21][15] = wall.stop;

	tmap.tetris_map[22][0] = wall.stop;
	tmap.tetris_map[22][1] = wall.stop;
	tmap.tetris_map[22][2] = wall.stop;
	tmap.tetris_map[22][3] = wall.stop;
	tmap.tetris_map[22][4] = wall.stop;
	tmap.tetris_map[22][5] = wall.stop;
	tmap.tetris_map[22][6] = wall.stop;
	tmap.tetris_map[22][7] = wall.stop;
	tmap.tetris_map[22][8] = wall.stop;
	tmap.tetris_map[22][9] = wall.stop;
	tmap.tetris_map[22][10] = wall.stop;
	tmap.tetris_map[22][11] = wall.stop;
	tmap.tetris_map[22][12] = wall.stop;
	tmap.tetris_map[22][13] = wall.stop;
	tmap.tetris_map[22][14] = wall.stop;
	tmap.tetris_map[22][15] = wall.stop;

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
