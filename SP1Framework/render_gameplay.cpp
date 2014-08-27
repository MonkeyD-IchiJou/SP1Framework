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

Blocks storedata;

COORD DataBlocks[blocksType][orientation][coordinates];
COORD DataMap[23][13];

char map[height][width] = { "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "300000000003",
                            "222222222222",};


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
                    cout << '.';
                    break;

                case '1':
                    cout << 'o';
                    break;

                case '2':
                    cout << ' ';

                case '3':
                    cout << ' ';

            }
        }

        cout << endl;
    }
    /*
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        { 
            DataMap[i][j].X = c.X+j;
            DataMap[i][j].Y = c.Y+i;
        }
    }*/
}

void initiateMap(COORD c)
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        { 
            DataMap[i][j].X = c.X+j;
            DataMap[i][j].Y = c.Y+i;
        }
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

void initiate(COORD l, COORD Z, COORD L, COORD S ,COORD T)
{
    // for I blocks
    for (int i = 0; i < 4; i++)                 // first orientation
    {
        DataBlocks[LONG_TYPE][0][i].X = l.X-1+i; 
        DataBlocks[LONG_TYPE][0][i].Y = l.Y;
    }

    for (int i = 0; i < 4; i++)                // second orientation
    {
        DataBlocks[LONG_TYPE][1][i].X = l.X; 
        DataBlocks[LONG_TYPE][1][i].Y = l.Y-1+i;
    }

    for (int i = 0; i < 4; i++)               // third orientation
    {
        DataBlocks[LONG_TYPE][2][i].X = l.X-2+i; 
        DataBlocks[LONG_TYPE][2][i].Y = l.Y;
    }

    for (int i = 0; i < 4; i++)             // fourth orientation
    {
        DataBlocks[LONG_TYPE][3][i].X = l.X; 
        DataBlocks[LONG_TYPE][3][i].Y = l.Y-2+i;
    }

    // for Z shape blocks

	 // first orientation

	DataBlocks[Z_TYPE][0][0].X = Z.X-1;
    DataBlocks[Z_TYPE][0][0].Y = Z.Y;

	DataBlocks[Z_TYPE][0][1].X = Z.X+1;
	DataBlocks[Z_TYPE][0][1].Y = Z.Y+1;
	
	DataBlocks[Z_TYPE][0][2].X = Z.X;
	DataBlocks[Z_TYPE][0][2].Y = Z.Y;
		
	DataBlocks[Z_TYPE][0][3].X = Z.X;
    DataBlocks[Z_TYPE][0][3].Y = Z.Y+1;

	
	// second orientation
              
	DataBlocks[Z_TYPE][1][0].X = Z.X-1; 
    DataBlocks[Z_TYPE][1][0].Y = Z.Y;

	DataBlocks[Z_TYPE][1][1].X = Z.X;
    DataBlocks[Z_TYPE][1][1].Y = Z.Y-1;

	DataBlocks[Z_TYPE][1][2].X = Z.X;
    DataBlocks[Z_TYPE][1][2].Y = Z.Y;

	DataBlocks[Z_TYPE][1][3].X = Z.X-1;
    DataBlocks[Z_TYPE][1][3].Y = Z.Y+1;
    
    
     // third orientation

	DataBlocks[Z_TYPE][2][0].X = Z.X-1;
    DataBlocks[Z_TYPE][2][0].Y = Z.Y;

	DataBlocks[Z_TYPE][2][1].X = Z.X+1;
	DataBlocks[Z_TYPE][2][1].Y = Z.Y+1;

	DataBlocks[Z_TYPE][2][2].X = Z.X;
	DataBlocks[Z_TYPE][2][2].Y = Z.Y;
		
	DataBlocks[Z_TYPE][2][3].X = Z.X; 
    DataBlocks[Z_TYPE][2][3].Y = Z.Y+1;

	// fourth orientation
	
	DataBlocks[Z_TYPE][3][0].X = Z.X-1; 
    DataBlocks[Z_TYPE][3][0].Y = Z.Y;

	DataBlocks[Z_TYPE][3][1].X = Z.X;
    DataBlocks[Z_TYPE][3][1].Y = Z.Y-1;

	DataBlocks[Z_TYPE][3][2].X = Z.X;
    DataBlocks[Z_TYPE][3][2].Y = Z.Y;

	DataBlocks[Z_TYPE][3][3].X = Z.X-1;
    DataBlocks[Z_TYPE][3][3].Y = Z.Y+1;       
   
	//For L shape blocks

	// first orientation
	
	DataBlocks[L_TYPE][0][0].X = L.X; 
    DataBlocks[2][0][0].Y = L.Y;

	DataBlocks[L_TYPE][0][1].X = L.X;
	DataBlocks[2][0][1].Y = L.Y-1;
	
	DataBlocks[L_TYPE][0][2].X = L.X;
	DataBlocks[L_TYPE][0][2].Y = L.Y+1;
		
	DataBlocks[L_TYPE][0][3].X = L.X+1;
    DataBlocks[L_TYPE][0][3].Y = L.Y+1;

	// second orientation

	DataBlocks[L_TYPE][1][0].X = L.X; 
    DataBlocks[L_TYPE][1][0].Y = L.Y;

	DataBlocks[L_TYPE][1][1].X = L.X-1;
	DataBlocks[L_TYPE][1][1].Y = L.Y;
	
	DataBlocks[L_TYPE][1][2].X = L.X-1;
	DataBlocks[L_TYPE][1][2].Y = L.Y+1;
		
	DataBlocks[L_TYPE][1][3].X = L.X+1;
    DataBlocks[L_TYPE][1][3].Y = L.Y;

	// third orientation
	
	DataBlocks[L_TYPE][2][0].X = L.X; 
    DataBlocks[L_TYPE][2][0].Y = L.Y;
	
	DataBlocks[L_TYPE][2][1].X = L.X;
	DataBlocks[L_TYPE][2][1].Y = L.Y-1;
	
	DataBlocks[L_TYPE][2][2].X = L.X;
	DataBlocks[L_TYPE][2][2].Y = L.Y+1;
		
	DataBlocks[L_TYPE][2][3].X = L.X-1;
    DataBlocks[L_TYPE][2][3].Y = L.Y-1;

	// fourth orientation
	
	DataBlocks[L_TYPE][3][0].X = L.X; 
    DataBlocks[L_TYPE][3][0].Y = L.Y;
	
	DataBlocks[L_TYPE][3][1].X = L.X-1;
	DataBlocks[L_TYPE][3][1].Y = L.Y;
	
	DataBlocks[L_TYPE][3][2].X = L.X+1;
	DataBlocks[L_TYPE][3][2].Y = L.Y;
		
	DataBlocks[L_TYPE][3][3].X = L.X+1;
    DataBlocks[L_TYPE][3][3].Y = L.Y-1;

	DataBlocks[Z_TYPE][0][0].X = Z.X-1;          // first orientation
    // first orientation

    DataBlocks[1][0][0].X = Z.X-1;
    DataBlocks[1][0][0].Y = Z.Y;

    DataBlocks[1][0][1].X = Z.X+1;
    DataBlocks[1][0][1].Y = Z.Y+1;

    DataBlocks[1][0][2].X = Z.X;
    DataBlocks[1][0][2].Y = Z.Y;

    DataBlocks[1][0][3].X = Z.X;
    DataBlocks[1][0][3].Y = Z.Y+1;

	DataBlocks[1][1][0].X = Z.X-1;          // second orientation

    // second orientation

    DataBlocks[1][1][0].X = Z.X-1; 
    DataBlocks[1][1][0].Y = Z.Y;

    DataBlocks[1][1][1].X = Z.X;
    DataBlocks[1][1][1].Y = Z.Y-1;

    DataBlocks[1][1][2].X = Z.X;
    DataBlocks[1][1][2].Y = Z.Y;

    DataBlocks[1][1][3].X = Z.X-1;
    DataBlocks[1][1][3].Y = Z.Y+1;

	DataBlocks[1][2][0].X = Z.X-1;          // third orientation

    // third orientation
    for (int i = 0; i < 4; i++)                 // first orientation
    {
        DataBlocks[1][0][i].X = Z.X-1+i; 
        DataBlocks[1][0][i].Y = Z.Y-i;
    }

    for (int i = 0; i < 4; i++)                // second orientation
    {
        DataBlocks[1][1][i].X = Z.X; 
        DataBlocks[1][1][i].Y = Z.Y-1+i;
    }

    DataBlocks[1][2][0].X = Z.X-1;
    DataBlocks[1][2][0].Y = Z.Y;

    DataBlocks[1][2][1].X = Z.X+1;
    DataBlocks[1][2][1].Y = Z.Y+1;

    DataBlocks[1][2][2].X = Z.X;
    DataBlocks[1][2][2].Y = Z.Y;

    DataBlocks[1][2][3].X = Z.X; 
    DataBlocks[1][2][3].Y = Z.Y+1;

	DataBlocks[1][3][0].X = Z.X-1;          // fourth orientation
    // fourth orientation

    DataBlocks[1][3][0].X = Z.X-1; 
    DataBlocks[1][3][0].Y = Z.Y;

    DataBlocks[1][3][1].X = Z.X;
    DataBlocks[1][3][1].Y = Z.Y-1;

    DataBlocks[1][3][2].X = Z.X;
    DataBlocks[1][3][2].Y = Z.Y;

    DataBlocks[1][3][3].X = Z.X-1;
    DataBlocks[1][3][3].Y = Z.Y+1;       

	DataBlocks[L_TYPE][0][0].X = L.X;        // first orientation
    //For L shape blocks

    // first orientation

    DataBlocks[2][0][0].X = L.X; 
    DataBlocks[2][0][0].Y = L.Y;

    DataBlocks[2][0][1].X = L.X;
    DataBlocks[2][0][1].Y = L.Y-1;

    DataBlocks[2][0][2].X = L.X;
    DataBlocks[2][0][2].Y = L.Y+1;

    DataBlocks[2][0][3].X = L.X+1;
    DataBlocks[2][0][3].Y = L.Y+1;

	DataBlocks[2][1][0].X = L.X;        // second orientation
    // second orientation

    DataBlocks[2][1][0].X = L.X; 
    DataBlocks[2][1][0].Y = L.Y;

    DataBlocks[2][1][1].X = L.X-1;
    DataBlocks[2][1][1].Y = L.Y;

    DataBlocks[2][1][2].X = L.X-1;
    DataBlocks[2][1][2].Y = L.Y+1;

    DataBlocks[2][1][3].X = L.X+1;
    DataBlocks[2][1][3].Y = L.Y;
    
    DataBlocks[2][2][0].X = L.X;        // third orientation

    // third orientation

    DataBlocks[2][2][0].X = L.X; 
    DataBlocks[2][2][0].Y = L.Y;

    DataBlocks[2][2][1].X = L.X;
    DataBlocks[2][2][1].Y = L.Y-1;

    DataBlocks[2][2][2].X = L.X;
    DataBlocks[2][2][2].Y = L.Y+1;

    DataBlocks[2][2][3].X = L.X-1;
    DataBlocks[2][2][3].Y = L.Y-1;
	
	DataBlocks[2][3][0].X = L.X;        // fourth orientation

    // fourth orientation

    DataBlocks[2][3][0].X = L.X; 
    DataBlocks[2][3][0].Y = L.Y;

    DataBlocks[2][3][1].X = L.X-1;
    DataBlocks[2][3][1].Y = L.Y;

    DataBlocks[2][3][2].X = L.X+1;
    DataBlocks[2][3][2].Y = L.Y;

    DataBlocks[2][3][3].X = L.X+1;
    DataBlocks[2][3][3].Y = L.Y-1;

	//For Square shape blocks

	// first orientation
	DataBlocks[Sq_TYPE][0][0].X = S.X; 
    DataBlocks[Sq_TYPE][0][0].Y = S.Y;

	DataBlocks[Sq_TYPE][0][1].X = S.X+1;
	DataBlocks[Sq_TYPE][0][1].Y = S.Y;
	
	DataBlocks[Sq_TYPE][0][2].X = S.X;
	DataBlocks[Sq_TYPE][0][2].Y = S.Y+1;
		
	DataBlocks[Sq_TYPE][0][3].X = S.X+1;
    DataBlocks[Sq_TYPE][0][3].Y = S.Y+1;

	// second orientation
	
	DataBlocks[Sq_TYPE][1][0].X = S.X; 
    DataBlocks[Sq_TYPE][1][0].Y = S.Y;

	DataBlocks[Sq_TYPE][1][1].X = S.X+1;
	DataBlocks[Sq_TYPE][1][1].Y = S.Y;
	
	DataBlocks[Sq_TYPE][1][2].X = S.X;
	DataBlocks[Sq_TYPE][1][2].Y = S.Y+1;
		
	DataBlocks[Sq_TYPE][1][3].X = S.X+1;
    DataBlocks[Sq_TYPE][1][3].Y = S.Y+1;

	// third orientation
	
	DataBlocks[Sq_TYPE][2][0].X = S.X;
    DataBlocks[Sq_TYPE][2][0].Y = S.Y;

	DataBlocks[Sq_TYPE][2][1].X = S.X+1;
	DataBlocks[Sq_TYPE][2][1].Y = S.Y;
	
	DataBlocks[Sq_TYPE][2][2].X = S.X;
	DataBlocks[Sq_TYPE][2][2].Y = S.Y+1;
		
	DataBlocks[Sq_TYPE][2][3].X = S.X+1;
    DataBlocks[Sq_TYPE][2][3].Y = S.Y+1;

	// fourth orientation
	
	DataBlocks[Sq_TYPE][3][0].X = S.X; 
    DataBlocks[Sq_TYPE][3][0].Y = S.Y;

	DataBlocks[Sq_TYPE][3][1].X = S.X+1;
	DataBlocks[Sq_TYPE][3][1].Y = S.Y;
	
	DataBlocks[Sq_TYPE][3][2].X = S.X;
	DataBlocks[Sq_TYPE][3][2].Y = S.Y+1;
		
	DataBlocks[Sq_TYPE][3][3].X = S.X+1;
    DataBlocks[Sq_TYPE][3][3].Y = S.Y+1;

    //For O shape blocks

    // first orientation
    DataBlocks[4][0][0].X = S.X; 
    DataBlocks[4][0][0].Y = S.Y;

    DataBlocks[4][0][1].X = S.X+1;
    DataBlocks[4][0][1].Y = S.Y;

    DataBlocks[4][0][2].X = S.X;
    DataBlocks[4][0][2].Y = S.Y+1;

    DataBlocks[4][0][3].X = S.X+1;
    DataBlocks[4][0][3].Y = S.Y+1;

    // second orientation

    DataBlocks[4][1][0].X = S.X; 
    DataBlocks[4][1][0].Y = S.Y;

    DataBlocks[4][1][1].X = S.X+1;
    DataBlocks[4][1][1].Y = S.Y;

    DataBlocks[4][1][2].X = S.X;
    DataBlocks[4][1][2].Y = S.Y+1;

    DataBlocks[4][1][3].X = S.X+1;
    DataBlocks[4][1][3].Y = S.Y+1;

    // third orientation

    DataBlocks[4][2][0].X = S.X;
    DataBlocks[4][2][0].Y = S.Y;

    DataBlocks[4][2][1].X = S.X+1;
    DataBlocks[4][2][1].Y = S.Y;

    DataBlocks[4][2][2].X = S.X;
    DataBlocks[4][2][2].Y = S.Y+1;

    DataBlocks[4][2][3].X = S.X+1;
    DataBlocks[4][2][3].Y = S.Y+1;

    // fourth orientation

    DataBlocks[4][3][0].X = S.X; 
    DataBlocks[4][3][0].Y = S.Y;

    DataBlocks[4][3][1].X = S.X+1;
    DataBlocks[4][3][1].Y = S.Y;

    DataBlocks[4][3][2].X = S.X;
    DataBlocks[4][3][2].Y = S.Y+1;

    DataBlocks[4][3][3].X = S.X+1;
    DataBlocks[4][3][3].Y = S.Y+1;

    // for T blocks

    DataBlocks[T_TYPE][0][0].X = T.X;                // first orientation
    DataBlocks[T_TYPE][0][0].Y = T.Y-1;

    for (int i = 1; i < 4; i++)
    {
        DataBlocks[T_TYPE][0][i].X = T.X+i-2;                
        DataBlocks[T_TYPE][0][i].Y = T.Y;
    }
    
    DataBlocks[T_TYPE][1][0].X = T.X+1;                // second orientation
    DataBlocks[T_TYPE][1][0].Y = T.Y;

    DataBlocks[5][1][0].X = T.X+1;                // second orientation
    DataBlocks[5][1][0].Y = T.Y;

    for (int i = 1; i < 4; i++)
    {
        DataBlocks[T_TYPE][1][i].X = T.X;                
        DataBlocks[T_TYPE][1][i].Y = T.Y+i-2;
    }

    DataBlocks[T_TYPE][2][0].X = T.X;              // third orientation
    DataBlocks[T_TYPE][2][0].Y = T.Y+1;

    for (int i = 1; i < 4; i++)
    {
        DataBlocks[T_TYPE][2][i].X = T.X+i-2;                
        DataBlocks[T_TYPE][2][i].Y = T.Y;
    }


    DataBlocks[T_TYPE][3][0].X = T.X-1;                // forth orientation
    DataBlocks[T_TYPE][3][0].Y = T.Y;

    for (int i = 1; i < 4; i++)
    {
        DataBlocks[T_TYPE][3][i].X = T.X;                
        DataBlocks[T_TYPE][3][i].Y = T.Y+i-2;
    }

}


void printBlocks(int type, int change)
{
    
    switch(change)
    {
    case 0:
        for (int i = 0; i < 4; i++)
        {
            gotoXY(DataBlocks[type][0][i]);
            cout << shape;
        }
        break;

    case 1:
        for (int i = 0; i < 4; i++)
        {
            gotoXY(DataBlocks[type][1][i]);
            cout << shape;
        }
        break;

    case 2:
        for (int i = 0; i < 4; i++)
        {
            gotoXY(DataBlocks[type][2][i]);
            cout << shape;
        }
        break;

    case 3:
        for (int i = 0; i < 4; i++)
        {
            gotoXY(DataBlocks[type][3][i]);
            cout << shape;
        }
        break;
    }
    /*
    for (int i = 0; i < 4; i++)
    {
        gotoXY(DataBlocks[type][change][i]);
        cout << shape;
    }*/
}

void drawShape(int orientation, int x, int y)
{
    switch(orientation)
    {
    case 0:
        for (int i = 0; i < 4; i++)
        {
            map[x][y+i] = '1';
        }

        break;

    case 1:
        for (int i = 0; i < 4; i++)
        {
            map[x-i][y] = '1';
        }

        break;

    case 2:
        for (int i = 0; i < 4; i++)
        {
            map[x][y+i] = '1';
        }

        break;

    case 3:
        for (int i = 0; i < 4; i++)
        {
            map[x-i][y] = '1';
        }

        break;
    }
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

