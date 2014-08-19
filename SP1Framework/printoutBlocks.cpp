#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

blocks getSquareBlocks()
{
    blocks square;
    blocks niceshape;

    square.square_block;
    niceshape.blockshape = 'o';
    

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            square.square_block[0][j] = ' ';
            square.square_block[3][j] = ' ';
            square.square_block[i][0] = ' ';
            square.square_block[i][3] = ' ';

            if (j > 0 && j < 3 && i > 0 && i < 3)
            {
                square.square_block[i][j] = niceshape.blockshape;
            }
        }
    }

    return square;
}

blocks DelSquareBlocks()
{
    blocks square;
    blocks niceshape;

    square.square_block;
    niceshape.blockshape = ' ';
    

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            square.square_block[0][j] = ' ';
            square.square_block[3][j] = ' ';
            square.square_block[i][0] = ' ';
            square.square_block[i][3] = ' ';

            if (j > 0 && j < 3 && i > 0 && i < 3)
            {
                square.square_block[i][j] = niceshape.blockshape;
            }
        }
    }

    return square;
}