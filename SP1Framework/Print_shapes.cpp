//This file mainly on return char or print map
//
//
//

#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

SetArt tetris_standard_map() 
{
    SetArt tmap;

    tmap.tetris_map[height][width];

    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            tmap.tetris_map[i][j] = '.';

            if (j > 0 && j < 13)
            {
                tmap.tetris_map[21][j] = 205;
                tmap.tetris_map[0][j] = 205;    
            }

            tmap.tetris_map[22][j] = '+';

            if (i < 22)
            {
                tmap.tetris_map[i][1] = 186;
                tmap.tetris_map[i][12] = 186;
            }
        }
    }

    tmap.tetris_map[0][1] = 201;
    tmap.tetris_map[0][12] = 187;

    tmap.tetris_map[21][12] = 188;
    tmap.tetris_map[21][1] = 200;

    for (int i = 0; i < 23; i++)
    {
        gotoXY(15, 4+i);

        for (int j = 0; j < 14; j++)
        {
            cout << tmap.tetris_map[i][j];
        }
        cout << endl;
    }

    return tmap;
}
char BLocksShape()
{
    const char shape = 'o'; 
    return shape;
}