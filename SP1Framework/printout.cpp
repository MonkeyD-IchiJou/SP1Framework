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
        for(int j = 1; j < 25; j++)
        {
            tmap.tetris_map[0][j] = wall.boundaries6;
            tmap.tetris_map[21][j] = wall.boundaries6;
           
            tmap.tetris_map[i][1] = wall.boundaries1; 
            tmap.tetris_map[i][23] = wall.boundaries1;

            if (j > 1 && j < 24 && i > 0 && i < 22)
            {
                tmap.tetris_map[i][j] = wall.insideB; 
            }
            
        }
    }
    

    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            tmap.tetris_map[i][0] = '+';
            tmap.tetris_map[i][24] = '+';
        }
    }

    // + for detecting
    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            tmap.tetris_map[22][j] = wall.stop;
        }
    }

    tmap.tetris_map[0][1] = wall.boundaries2;
    tmap.tetris_map[21][1] = wall.boundaries3;
    tmap.tetris_map[0][23] = wall.boundaries4;
    tmap.tetris_map[21][23] = wall.boundaries5;

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

    //square.square_block[2][0] = pattern.collisioncheck;
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