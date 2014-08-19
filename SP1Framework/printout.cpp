#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

blocks tetris_game_map()
{
    blocks tmap;
    blocks wall;

    tmap.tetris_map;

    wall.boundaries = '*';
    wall.insideB = ' ';

    for(int i = 0; i < 22; i++)
    {
        for(int j = 0; j < 23; j++)
        {
            tmap.tetris_map[0][j] = wall.boundaries;
            tmap.tetris_map[21][j] = wall.boundaries;
            tmap.tetris_map[i][0] = wall.boundaries;
            tmap.tetris_map[i][22] = wall.boundaries;

            if (j > 0 && j < 22 && i > 0 && i < 21)
            {
                tmap.tetris_map[i][j] = wall.insideB; 
            }
        }
    }

    return tmap;
}

blocks getSquareBlocks()
{
    blocks square;
    blocks pattern;

    square.square_block;

    pattern.blockshape = 'o';
    pattern.collisioncheck = ' ';

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
    pattern.collisioncheck = ' ';

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