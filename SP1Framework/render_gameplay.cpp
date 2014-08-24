#include "game.h"
#include "tetris.h"
#include "Framework\console.h"


char map[20][30] = {"XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X             P             X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "X                           X",
                    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX"};


void DrawArray(COORD c)
{
     for(int i =0; i < 20; i++)
     {
        gotoXY(c.X, c.Y+i);
        for(int j = 0; j < 30; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
     }
}

void DrawMap(COORD c)
{
    for(int i = 0; i < 20; i++)
    {
        gotoXY(c.X, c.Y+i);
        for(int j = 0; j < 30; j++)
        {
            switch(map[i][j])
            {
                case 'X':
                    cout << (char)1;
                    break;
                case ' ':
                    cout << (char)33;
                    break;
            }
        }

        cout << endl;
    }
}

void sqBlocks(COORD c)
{
    gotoXY(c.X,c.Y++);
	cout << BLocksShape();
	cout << BLocksShape();

	gotoXY(c.X,c.Y++);
	cout << BLocksShape();
	cout << BLocksShape();
}

char BLocksShape()
{
    char shape = 'o';
    return shape;
}