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
<<<<<<< 5dc86eaab5edc1afec5d375f4492ecfbd94bc861
<<<<<<< 8c841f004b38fa2b30a2b5482e038c79e0b0b9d7
<<<<<<< 0b85bcc1a6609350f7a4b09707f93d942c690c47
=======
=======
<<<<<<< 8d59e3cc1206155ee65fb0dd250b9834595be412
>>>>>>> 33ba33da6af0ed1fc793b4ca3b1231e6f916911f
=======
>>>>>>> 56e85a7f90f2825769d897d9515d2d1aabc4704c

	/*case Z_REV_TYPE:
		for(int i = 0; i < 4; i++)                  //first orientation
		{
			if(i < 2)
			{
				DataBlocks[type][0][i].X = c.X + 1 + i;
				DataBlocks[type][0][i].Y = c.Y;
			}
			if (i >= 2)
            {
                DataBlocks[type][0][i].X = c.X + 2+i; 
                DataBlocks[type][0][i].Y = c.Y + 1;
            }
		}

		for (int i = 0; i < 4; i++)                // second orientation
        {
            if (i < 2)
            {
                DataBlocks[type][1][i].X = c.X; 
                DataBlocks[type][1][i].Y = c.Y - 1 + i;
            }

            if (i >= 2)
            {
                DataBlocks[type][1][i].X = c.X + 1; 
                DataBlocks[type][1][i].Y = c.Y - 2 + i;
            }
        }
		break;
        /*
    case Z_TYPE:
        // for Z shape blocks

	    // first orientation

	    DataBlocks[Z_TYPE][0][0].X = c.X-1;
        DataBlocks[Z_TYPE][0][0].Y = c.Y;

	    DataBlocks[Z_TYPE][0][1].X = c.X+1;
	    DataBlocks[Z_TYPE][0][1].Y = c.Y+1;
	
	    DataBlocks[Z_TYPE][0][2].X = c.X;
	    DataBlocks[Z_TYPE][0][2].Y = c.Y;
		
	    DataBlocks[Z_TYPE][0][3].X = c.X;
        DataBlocks[Z_TYPE][0][3].Y = c.Y+1;

	
	    // second orientation
              
	    DataBlocks[Z_TYPE][1][0].X = c.X-1; 
        DataBlocks[Z_TYPE][1][0].Y = c.Y;

	    DataBlocks[Z_TYPE][1][1].X = c.X;
        DataBlocks[Z_TYPE][1][1].Y = c.Y-1;

	    DataBlocks[Z_TYPE][1][2].X = c.X;
        DataBlocks[Z_TYPE][1][2].Y = c.Y;

	    DataBlocks[Z_TYPE][1][3].X = c.X-1;
        DataBlocks[Z_TYPE][1][3].Y = c.Y+1;
    
    
        // third orientation

	    DataBlocks[Z_TYPE][2][0].X = c.X-1;
        DataBlocks[Z_TYPE][2][0].Y = c.Y;

	    DataBlocks[Z_TYPE][2][1].X = c.X+1;
	    DataBlocks[Z_TYPE][2][1].Y = c.Y+1;

	    DataBlocks[Z_TYPE][2][2].X = c.X;
	    DataBlocks[Z_TYPE][2][2].Y = c.Y;
		
	    DataBlocks[Z_TYPE][2][3].X = c.X; 
        DataBlocks[Z_TYPE][2][3].Y = c.Y+1;

	    // fourth orientation
	
	    DataBlocks[Z_TYPE][3][0].X = c.X-1; 
        DataBlocks[Z_TYPE][3][0].Y = c.Y;

	    DataBlocks[Z_TYPE][3][1].X = c.X;
        DataBlocks[Z_TYPE][3][1].Y = c.Y-1;

	    DataBlocks[Z_TYPE][3][2].X = c.X;
        DataBlocks[Z_TYPE][3][2].Y = c.Y;

	    DataBlocks[Z_TYPE][3][3].X = c.X-1;
        DataBlocks[Z_TYPE][3][3].Y = c.Y+1;   

        break;
<<<<<<< 5dc86eaab5edc1afec5d375f4492ecfbd94bc861
   
    case L_TYPE:

        /*
	//For L shape blocks

	// first orientation
	
	DataBlocks[L_TYPE][0][0].X = c.X; 
    DataBlocks[L_TYPE][0][0].Y = c.Y;

	DataBlocks[L_TYPE][0][1].X = c.X;
	DataBlocks[L_TYPE][0][1].Y = c.Y-1;
	
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

        break;

    case T_TYPE:
    // for T blocks

<<<<<<< 87aa194b1bd5ed24b346043231c8a90fe4dec7a9
        DataBlocks[T_TYPE][0][0].X = c.X;                // first orientation
        DataBlocks[T_TYPE][0][0].Y = c.Y-1;
=======
    DataBlocks[T_TYPE][0][0].X = T.X;                // first orientation
    DataBlocks[T_TYPE][0][0].Y = T.Y-1; 
>>>>>>> 1b56e6007d753729b21158fb42aec75e1377bf55

        for (int i = 1; i < 4; i++)
        {
            DataBlocks[T_TYPE][0][i].X = c.X+i-2;                
            DataBlocks[T_TYPE][0][i].Y = c.Y;
        }
    
        DataBlocks[T_TYPE][1][0].X = c.X+1;                // second orientation
        DataBlocks[T_TYPE][1][0].Y = c.Y;

        DataBlocks[5][1][0].X = c.X+1;                // second orientation
        DataBlocks[5][1][0].Y = c.Y;

        for (int i = 1; i < 4; i++)
        {
            DataBlocks[T_TYPE][1][i].X = c.X;                
            DataBlocks[T_TYPE][1][i].Y = c.Y+i-2;
        }

        DataBlocks[T_TYPE][2][0].X = c.X;              // third orientation
        DataBlocks[T_TYPE][2][0].Y = c.Y+1;

        for (int i = 1; i < 4; i++)
        {
            DataBlocks[T_TYPE][2][i].X = c.X+i-2;                
            DataBlocks[T_TYPE][2][i].Y = c.Y;
        }

        DataBlocks[T_TYPE][3][0].X = c.X-1;                // forth orientation
        DataBlocks[T_TYPE][3][0].Y = c.Y;

        for (int i = 1; i < 4; i++)
        {
            DataBlocks[T_TYPE][3][i].X = c.X;                
            DataBlocks[T_TYPE][3][i].Y = c.Y+i-2;
        }*/
<<<<<<< 8c841f004b38fa2b30a2b5482e038c79e0b0b9d7
>>>>>>> 8d59e3cc1206155ee65fb0dd250b9834595be412
=======
=======
>>>>>>> 0698cb49d5c3180f962311604c02fc4f2b324207
>>>>>>> 33ba33da6af0ed1fc793b4ca3b1231e6f916911f
=======
   */
     
>>>>>>> 56e85a7f90f2825769d897d9515d2d1aabc4704c
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
