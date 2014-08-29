#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"

const char cornerA = (char)201; //╔
const char cornerB = (char)187; //╗
const char cornerC = (char)200; //╚
const char cornerD = (char)188; //╝
const char borderUP = (char)205; //═
const char borderSide = (char)186; //↕

const char shape = 'o';
const char normal = '.';
 
COORD DataBlocks[blocksType][orientation][coordinates];

char map[height][width] = 
{
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
    "0000000000",
};

char border[borderheight][borderwidth];

void DrawMap(COORD c)
{
    colour(White);
    for(int i = 0; i < height; i++)
    {
        gotoXY(c.X, c.Y+i);
        for(int j = 0; j < width; j++)
        {
            switch(map[i][j])
            {
                case '0':
                    cout << normal;
                    break;

                case '1':
                    cout << shape;
                    break;
            }
        }

        cout << endl;
    }
}

void DrawBorder(COORD c)
{
    for(int i = 0; i < 22; i++)
        for(int i = 0; i < borderheight; i++)
        {
            gotoXY(c.X, c.Y+i);
            for(int j = 0; j < borderwidth; j++)
            {

                switch(map[i][j])
                {
                case '=':
                    cout << (char)205; //═
                    break;
                    border[0][j] = borderUP;
                    border[22][j] = borderUP;

                    border[i][0] = borderSide; 
                    border[i][12] = borderSide;

                    border[0][0] = cornerA;
                    border[0][12] = cornerB;
                    border[22][0] = cornerC;
                    border[22][12] = cornerD;

                    cout << border[i][j];
                }

                cout << endl;
            }
        }
}

void initiate(int type, COORD c)
{
    switch (type)
    {
    case LONG_TYPE:
        // for I blocks
        for (int i = 0; i < 4; i++)                 // first orientation
        {
            DataBlocks[type][0][i].X = c.X-2+i; 
            DataBlocks[type][0][i].Y = c.Y;
        }

        for (int i = 0; i < 4; i++)                // second orientation
        {
            DataBlocks[type][1][i].X = c.X; 
            DataBlocks[type][1][i].Y = c.Y-2+i;
        }

        for (int i = 0; i < 4; i++)               // third orientation
        {
            DataBlocks[type][2][i].X = c.X-2+i; 
            DataBlocks[type][2][i].Y = c.Y;
        }

        for (int i = 0; i < 4; i++)             // fourth orientation
        {
            DataBlocks[type][3][i].X = c.X - 1; 
            DataBlocks[type][3][i].Y = c.Y-1+i;
        }

        break;

    case Z_TYPE:
        // for Z blocks
        for (int i = 0; i < 4; i++)                 // first orientation
        {
            if (i < 2)
            {
                DataBlocks[type][0][i].X = c.X-1+i; 
                DataBlocks[type][0][i].Y = c.Y;
            }

            if (i >= 2)
            {
                DataBlocks[type][0][i].X = c.X-2+i; 
                DataBlocks[type][0][i].Y = c.Y+1;
            }
        }

        for (int i = 0; i < 4; i++)                // second orientation
        {
            if (i < 2)
            {
                DataBlocks[type][1][i].X = c.X; 
                DataBlocks[type][1][i].Y = c.Y-1+i;
            }

            if (i >= 2)
            {
                DataBlocks[type][1][i].X = c.X-1; 
                DataBlocks[type][1][i].Y = c.Y-2+i;
            }
        }

        break;

    case L_TYPE:
        //for L blocks
        for (int i = 0; i < 4; i++)                 // first orientation
        {
            if(i < 3)
            {
                DataBlocks[type][0][i].X = c.X-1+i; 
                DataBlocks[type][0][i].Y = c.Y;
            }

            DataBlocks[type][0][3].X = c.X-1; 
            DataBlocks[type][0][3].Y = c.Y-1;
        }

        for (int i = 0; i < 4; i++)                 // second orientation
        {
            if(i < 3)
            {
                DataBlocks[type][1][i].X = c.X; 
                DataBlocks[type][1][i].Y = c.Y-1+i;
            }

            DataBlocks[type][1][3].X = c.X+1; 
            DataBlocks[type][1][3].Y = c.Y-1;
        }

        for (int i = 0; i < 4; i++)                // third orientation
        {
            if(i < 3)
            {
                DataBlocks[type][2][i].X = c.X-1+i; 
                DataBlocks[type][2][i].Y = c.Y;
            }

            DataBlocks[type][2][3].X = c.X+1; 
            DataBlocks[type][2][3].Y = c.Y+1;
        }

        for (int i = 0; i < 4; i++)                 // fourth orientation
        {
            if(i < 3)
            {
                DataBlocks[type][3][i].X = c.X; 
                DataBlocks[type][3][i].Y = c.Y-1+i;
            }

            DataBlocks[type][3][3].X = c.X-1; 
            DataBlocks[type][3][3].Y = c.Y+1;
        }
        break;

    case Sq_TYPE:
        for (int i = 0; i < 4; i++)                 // first orientation
        {
            if (i < 2)
            {
                DataBlocks[type][0][i].X = c.X+i; 
                DataBlocks[type][0][i].Y = c.Y;
            }

            if (i >= 2)
            {
                DataBlocks[type][0][i].X = c.X-2+i; 
                DataBlocks[type][0][i].Y = c.Y+1;
            }
        }
        break;

    case T_TYPE:
        for (int i = 0; i < 4; i++)                 // first orientation
        {
            if(i < 3)
            {
                DataBlocks[type][0][i].X = c.X-1+i; 
                DataBlocks[type][0][i].Y = c.Y;
            }

            DataBlocks[type][0][3].X = c.X; 
            DataBlocks[type][0][3].Y = c.Y-1;
        }

        for (int i = 0; i < 4; i++)                 // second orientation
        {
            if(i < 3)
            {
                DataBlocks[type][1][i].X = c.X; 
                DataBlocks[type][1][i].Y = c.Y-1+i;
            }

            DataBlocks[type][1][3].X = c.X+1; 
            DataBlocks[type][1][3].Y = c.Y;
        }

        for (int i = 0; i < 4; i++)                // third orientation
        {
            if(i < 3)
            {
                DataBlocks[type][2][i].X = c.X-1+i; 
                DataBlocks[type][2][i].Y = c.Y;
            }

            DataBlocks[type][2][3].X = c.X; 
            DataBlocks[type][2][3].Y = c.Y+1;
        }

        for (int i = 0; i < 4; i++)                 // fourth orientation
        {
            if(i < 3)
            {
                DataBlocks[type][3][i].X = c.X; 
                DataBlocks[type][3][i].Y = c.Y-1+i;
            }

            DataBlocks[type][3][3].X = c.X-1; 
            DataBlocks[type][3][3].Y = c.Y;
        }
        break;
    }

}

void printBlock(int type, int orientation)
{
    for (int i = 0; i < 4; i++)
    {
        gotoXY(DataBlocks[type][orientation][i].X, DataBlocks[type][orientation][i].Y);
        cout << shape;
    }
}

void UpdateMap(int type, int orientation, int x, int y)
{
    switch(type)
    {
    case LONG_TYPE:
        switch(orientation)
        {
        case FIRST:
            for (int i = 0; i < 4; i++)
            {
                map[x][y+i] = '1';
            }

            break;

        case SECOND:
            for (int i = 0; i < 4; i++)
            {
                map[x-i][y] = '1';
            }

            break;

        case THIRD:
            for (int i = 0; i < 4; i++)
            {
                map[x][y+i] = '1';
            }

            break;

        case FOURTH:
            for (int i = 0; i < 4; i++)
            {
                map[x-i][y] = '1';
            }

            break;
        }
        break;

    case Z_TYPE:
        switch(orientation)
        {
        case FIRST:
            for (int i = 0; i < 4; i++)
            {
                if (i > 0 && i < 3)
                {
                    map[x-1][y+i] = '1';
                }
                
                if (i > 1 && i < 4)
                {
                    map[x][y+i] = '1';
                }
            }

            break;

        case SECOND:
            for (int i = 0; i < 4; i++)
            {
                if (i > 0 && i < 3)
                {
                    map[x-i][y+2] = '1';
                }
                
                if (i >= 0 && i < 2)
                {
                    map[x-i][y+1] = '1';
                }
            }

            break;
        }
        break;

    case L_TYPE:
        switch(orientation)
        {
        case FIRST:
            for (int i = 0; i < 3; i++)
            {
                map[x][y+i] = '1';
                map[x-1][y] = '1';
            }
            break;

        case SECOND:
            for (int i = 0; i < 3; i++)
            {
                map[x+i][y] = '1';
                if (i < 2)
                {
                    map[x-1][y+i] = '1';
                }
            }
            break;

        case THIRD:
            for (int i = 0; i < 3; i++)
            {
                map[x-1][y+i] = '1';
                map[x][y+2] = '1';
            }
            break;

        case FOURTH:
            for (int i = 0; i < 3; i++)
            {
                map[x-i][y+1] = '1';
                map[x][y] = '1';
            }
            break;
        }
        break;

    case Sq_TYPE:
        switch(orientation)
        {
        case FIRST:
            for (int i = 0; i < 4; i++)
            {
                if (i > 0 && i < 3)
                {
                    map[x-1][y+i] = '1';
                    map[x][y+i] = '1';
                }
            }

            break;
        }
        break;

    case T_TYPE:
        switch(orientation)
        {
        case FIRST:
            for (int i = 0; i < 3; i++)
            {
                map[x+1][y+i] = '1';
                map[x][y+1] = '1';
            }
            break;

        case SECOND:
            for (int i = 0; i < 3; i++)
            {
                map[x-1+i][y] = '1';
                map[x][y+1] = '1';
            }
            break;

        case THIRD:
            for (int i = 0; i < 3; i++)
            {
                map[x][y+i] = '1';
                map[x+1][y+1] = '1';
            }
            break;

        case FOURTH:
            for (int i = 0; i < 3; i++)
            {
                map[x-1+i][y+1] = '1';
                map[x][y] = '1';
            }
            break;
        }
        break;
    }
}

void score(int type, int orientation, int x)
{

    map[x-1][0] = '0';
}
     
/*FOR EASIER REFERENCE PLEASE DON'T DELETE (CAN MOVE) - JUNYAN

        O-block - Yellow
        I-block - Cyan
        J-block - Blue
        L-block - Orange
        S-block - Green
        T-block - Purple
        Z-block - Red
        
        */