#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

const char cornerA = (char)201; //╔
const char cornerB = (char)187; //╗
const char cornerC = (char)200; //╚
const char cornerD = (char)188; //╝
const char borderUP = (char)205; //═
const char borderSide = (char)186; //↕

const char shape = 'o';

Blocks storedata;
COORD DataBlocks[blocksType][orientation][coordinates];

char map[height][width] = { "0000000000",
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
                            "0000000000"};

char border[borderheight][borderwidth];


void DrawMap(COORD c)
{
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
            }
        }

        cout << endl;
    }
}

void DrawBorder(COORD c)
{
    for(int i = 0; i < borderheight; i++)
    {
        gotoXY(c.X, c.Y+i);
        for(int j = 0; j < borderwidth; j++)
        {
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

void initiate(COORD l, COORD Z, COORD L, COORD S ,COORD T)
{
    // for long shape blocks
    for (int i = 0; i < 4; i++)                 // first orientation
    {
        DataBlocks[0][0][i].X = l.X-1+i; 
        DataBlocks[0][0][i].Y = l.Y;
    }
    
    for (int i = 0; i < 4; i++)                // second orientation
    {
        DataBlocks[0][1][i].X = l.X; 
        DataBlocks[0][1][i].Y = l.Y-1+i;
    }

    for (int i = 0; i < 4; i++)               // third orientation
    {
        DataBlocks[0][2][i].X = l.X-2+i; 
        DataBlocks[0][2][i].Y = l.Y;
    }

    for (int i = 0; i < 4; i++)             // fourth orientation
    {
        DataBlocks[0][3][i].X = l.X; 
        DataBlocks[0][3][i].Y = l.Y-2+i;
    }

    // for Z shape blocks

	 // first orientation

	DataBlocks[1][0][0].X = Z.X-1;
    DataBlocks[1][0][0].Y = Z.Y;

	DataBlocks[1][0][1].X = Z.X+1;
	DataBlocks[1][0][1].Y = Z.Y+1;
	
	DataBlocks[1][0][2].X = Z.X;
	DataBlocks[1][0][2].Y = Z.Y;
		
	DataBlocks[1][0][3].X = Z.X;
    DataBlocks[1][0][3].Y = Z.Y+1;

	
	// second orientation
              
	DataBlocks[1][1][0].X = Z.X-1; 
    DataBlocks[1][1][0].Y = Z.Y;

	DataBlocks[1][1][1].X = Z.X;
    DataBlocks[1][1][1].Y = Z.Y-1;

	DataBlocks[1][1][2].X = Z.X;
    DataBlocks[1][1][2].Y = Z.Y;

	DataBlocks[1][1][3].X = Z.X-1;
    DataBlocks[1][1][3].Y = Z.Y+1;
    
    
     // third orientation

	DataBlocks[1][2][0].X = Z.X-1;
    DataBlocks[1][2][0].Y = Z.Y;

	DataBlocks[1][2][1].X = Z.X+1;
	DataBlocks[1][2][1].Y = Z.Y+1;

	DataBlocks[1][2][2].X = Z.X;
	DataBlocks[1][2][2].Y = Z.Y;
		
	DataBlocks[1][2][3].X = Z.X; 
    DataBlocks[1][2][3].Y = Z.Y+1;

	// fourth orientation
	
	DataBlocks[1][3][0].X = Z.X-1; 
    DataBlocks[1][3][0].Y = Z.Y;

	DataBlocks[1][3][1].X = Z.X;
    DataBlocks[1][3][1].Y = Z.Y-1;

	DataBlocks[1][3][2].X = Z.X;
    DataBlocks[1][3][2].Y = Z.Y;

	DataBlocks[1][3][3].X = Z.X-1;
    DataBlocks[1][3][3].Y = Z.Y+1;       
   
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

	// second orientation

	DataBlocks[2][1][0].X = L.X; 
    DataBlocks[2][1][0].Y = L.Y;

	DataBlocks[2][1][1].X = L.X-1;
	DataBlocks[2][1][1].Y = L.Y;
	
	DataBlocks[2][1][2].X = L.X-1;
	DataBlocks[2][1][2].Y = L.Y+1;
		
	DataBlocks[2][1][3].X = L.X+1;
    DataBlocks[2][1][3].Y = L.Y;

	// third orientation
	
	DataBlocks[2][2][0].X = L.X; 
    DataBlocks[2][2][0].Y = L.Y;
	
	DataBlocks[2][2][1].X = L.X;
	DataBlocks[2][2][1].Y = L.Y-1;
	
	DataBlocks[2][2][2].X = L.X;
	DataBlocks[2][2][2].Y = L.Y+1;
		
	DataBlocks[2][2][3].X = L.X-1;
    DataBlocks[2][2][3].Y = L.Y-1;

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

    DataBlocks[5][0][0].X = T.X;                // first orientation
    DataBlocks[5][0][0].Y = T.Y-1;

    for (int i = 1; i < 4; i++)
    {
        DataBlocks[5][0][i].X = T.X+i-2;                
        DataBlocks[5][0][i].Y = T.Y;
    }
    
    DataBlocks[5][1][0].X = T.X+1;                // second orientation
    DataBlocks[5][1][0].Y = T.Y;

    for (int i = 1; i < 4; i++)
    {
        DataBlocks[5][1][i].X = T.X;                
        DataBlocks[5][1][i].Y = T.Y+i-2;
    }

    DataBlocks[5][2][0].X = T.X;              // third orientation
    DataBlocks[5][2][0].Y = T.Y+1;

    for (int i = 1; i < 4; i++)
    {
        DataBlocks[5][2][i].X = T.X+i-2;                
        DataBlocks[5][2][i].Y = T.Y;
    }
    

    DataBlocks[5][3][0].X = T.X-1;                // forth orientation
    DataBlocks[5][3][0].Y = T.Y;

    for (int i = 1; i < 4; i++)
    {
        DataBlocks[5][3][i].X = T.X;                
        DataBlocks[5][3][i].Y = T.Y+i-2;
    }

}

void printBlocks(int type, int change)
{
    switch(change)
    {
    case 1:
        for (int i = 0; i < 4; i++)
        {
            gotoXY(DataBlocks[type][0][i]);
            cout << shape;
        }
        break;

    case 2:
        for (int i = 0; i < 4; i++)
        {
            gotoXY(DataBlocks[type][1][i]);
            cout << shape;
        }
        break;

    case 3:
        for (int i = 0; i < 4; i++)
        {
            gotoXY(DataBlocks[type][2][i]);
            cout << shape;
        }
        break;

    case 4:
        for (int i = 0; i < 4; i++)
        {
            gotoXY(DataBlocks[type][3][i]);
            cout << shape;
        }
        break;
    }
}