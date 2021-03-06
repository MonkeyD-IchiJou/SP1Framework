﻿#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"

const char cornerA = (char)201; //╔
const char cornerB = (char)187; //╗
const char cornerC = (char)200; //╚
const char cornerD = (char)188; //╝
const char borderUP = (char)205; //═
const char borderSide = (char)186; //↕

const char shape = 254;
const char normal = '.';
 
COORD DataBlocks[blocksType][orientation][coordinates];

unsigned int score = 0;

bool combo;

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
    "0000000000"
};

char border[borderheight][borderwidth];

void Background(COORD c)
{
	ifstream background;
	string ground;

	background.open("background.txt");
	c.X = 45;
	c.Y = 5;
	while( !background.eof() )
	{
		getline(background, ground);
		writeToBuffer(c, ground, 0x0C);
		c.Y++;
	}

	background.close();
}

void DrawMap(COORD c, int type)
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {   
            c.X = j+25;
            c.Y= i+6;
            switch(map[i][j])
            {
                case '0':
                    writeToBuffer(c, normal, color.map);
                    break;

                case '1':
                    writeToBuffer(c, shape, color.l);
                    break;

                case '2':
                    writeToBuffer(c, shape, color.Z);
                    break;

                case '3':
                    writeToBuffer(c, shape, color.L);
                    break;

                case '4':
                    writeToBuffer(c, shape, color.Sq);
                    break;

                case '5':
                    writeToBuffer(c, shape, color.T);
                    break;

                case '6':
                    writeToBuffer(c, shape, color.RL);
                    break;

                case '7':
                    writeToBuffer(c, shape, color.RZ);
                    break;
            }
        }

        cout << endl;
    }
}

void DrawBorder(COORD c)
{
    for(int i = 0; i < borderwidth - 1; i++)
    {	
		for(int j = 0; j < borderheight; j++)
		{
			c.X = 24 + i;
			c.Y = 5;
			writeToBuffer(c, borderUP, color.border); // top border

			c.X = 24 + i;
			c.Y = 29;
			writeToBuffer(c, borderUP, color.border); // bottom border

			c.X = 24;
			c.Y = 5 + j;
			writeToBuffer(c, borderSide, color.border); // left side border

			c.X = 35;
			c.Y = 5 + j;
			writeToBuffer(c, borderSide, color.border); // right side border

			c.X = 24;
			c.Y = 5;
			writeToBuffer(c, cornerA, color.border); // left corner

			c.X = 35;
			c.Y = 5;
			writeToBuffer(c, cornerB, color.border); // right corner

			c.X = 24;
			c.Y = 29;
			writeToBuffer(c, cornerC, color.border); // bottom left corner

			c.X = 35;
			c.Y = 29;
			writeToBuffer(c, cornerD, color.border); // bottom right corner
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

        for (int i = 0; i < 4; i++)                 // second orientation
        {
            DataBlocks[type][1][i].X = c.X; 
            DataBlocks[type][1][i].Y = c.Y-2+i;
        }

        for (int i = 0; i < 4; i++)                 // near left obstacle orientation
        {
            DataBlocks[type][2][i].X = c.X+i; 
            DataBlocks[type][2][i].Y = c.Y;
        }

        for (int i = 0; i < 4; i++)                 // fourth orientation
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
        for (int i = 0; i < 2; i++)                 // first orientation
        {
            DataBlocks[type][0][i].X = c.X-1+i; 
            DataBlocks[type][0][i].Y = c.Y;
        }

        for (int i = 0; i < 2; i++)      
        {
            DataBlocks[type][0][i+2].X = c.X-1+i; 
            DataBlocks[type][0][i+2].Y = c.Y+1;
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

    case L_REV_TYPE:
        for (int i = 0; i < 4; i++)                // first orientation
        {
            if(i < 3)
            {
                DataBlocks[type][0][i].X = c.X-1+i; 
                DataBlocks[type][0][i].Y = c.Y;
            }

            DataBlocks[type][0][3].X = c.X+1; 
            DataBlocks[type][0][3].Y = c.Y-1;
        }

		for (int i = 0; i < 4; i++)                 // second orientation
        {
            if(i < 3)
            {
                DataBlocks[type][1][i].X = c.X; 
                DataBlocks[type][1][i].Y = c.Y-1+i;
            }
        } 
        DataBlocks[type][1][3].X = c.X+1; 
        DataBlocks[type][1][3].Y = c.Y+1;

        for (int i = 0; i < 4; i++)                // third orientation
        {
            if(i < 3)
            {
                DataBlocks[type][2][i].X = c.X-1+i; 
                DataBlocks[type][2][i].Y = c.Y;
            }

            DataBlocks[type][2][3].X = c.X-1; 
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
            DataBlocks[type][3][3].Y = c.Y-1;
        }
        break;

	case Z_REV_TYPE:
		for(int i = 0; i < 2; i++)                  //first orientation
		{
            DataBlocks[type][0][i].X = c.X + 1 - i;
            DataBlocks[type][0][i].Y = c.Y;

            DataBlocks[type][0][2+i].X = c.X - i; 
            DataBlocks[type][0][2+i].Y = c.Y + 1;
		}

		for(int i = 0; i < 2; i++)                  //second orientation
		{
            DataBlocks[type][1][i].X = c.X -1 + i;
            DataBlocks[type][1][i].Y = c.Y;

            DataBlocks[type][1][2+i].X = c.X - i; 
            DataBlocks[type][1][2+i].Y = c.Y + 1 - (i*2) ;
		}
		break;
    }

}

void printBlock(int type, int orientation, int color)
{
    for (int i = 0; i < 4; i++)
    {
        writeToBuffer(DataBlocks[type][orientation][i], shape, color);
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
                    map[x-1][y+i] = '2';
                }
                
                if (i > 1 && i < 4)
                {
                    map[x][y+i] = '2';
                }
            }

            break;

        case SECOND:
            for (int i = 0; i < 4; i++)
            {
                if (i > 0 && i < 3)
                {
                    map[x-i][y+2] = '2';
                }
                
                if (i >= 0 && i < 2)
                {
                    map[x-i][y+1] = '2';
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
                map[x][y+i] = '3';
                map[x-1][y] = '3';
            }
            break;

        case SECOND:
            for (int i = 0; i < 2; i++)
            {
                map[x+i][y] = '3';
                map[x-1][y+i] = '3';
            }
            break;

        case THIRD:
            for (int i = 0; i < 3; i++)
            {
                map[x-1][y+i] = '3';
                map[x][y+2] = '3';
            }
            break;

        case FOURTH:
            for (int i = 0; i < 3; i++)
            {
                map[x-i][y+1] = '3';
                map[x][y] = '3';
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
                    map[x-1][y+i] = '4';
                    map[x][y+i] = '4';
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
                map[x+1][y+i] = '5';
                map[x][y+1] = '5';
            }
            break;

        case SECOND:
            for (int i = 0; i < 3; i++)
            {
                map[x-1+i][y] = '5';
                map[x][y+1] = '5';
            }
            break;

        case THIRD:
            for (int i = 0; i < 3; i++)
            {
                map[x][y+i] = '5';
                map[x+1][y+1] = '5';
            }
            break;

        case FOURTH:
            for (int i = 0; i < 3; i++)
            {
                map[x-1+i][y+1] = '5';
                map[x][y] = '5';
            }
            break;
        }
        break;

	case Z_REV_TYPE:
		switch(orientation)
        {
        case FIRST:
            for (int i = 1; i < 3; i++)
            {
				map[x - 1][y + 1 + i] = '7';
				map[x][y+i] = '7';
            }

            break;

        case SECOND:
				map[x - 1][y + 1] = '7';
				map[x][y + 1] = '7';
				map[x - 2][y] = '7';
				map[x - 1][y] = '7';

            break;
		}
		break;

	case L_REV_TYPE:
		switch(orientation)
		{
	    case FIRST:
            for (int i = 0; i < 3; i++)
            {
                map[x][y - i] = '6';
                map[x - 1][y] = '6';
            }
            break;

        case SECOND:
            for (int i = 0; i < 3; i++)
            {
                map[x+i][y] = '6';
                
            }map[x+2][y+1] = '6';
            break;

        case THIRD:
            for (int i = 0; i < 3; i++)
            {
                map[x-1][y + 2 + i] = '6';
                map[x][y+2] = '6';
            }
            break;

        case FOURTH:
            for (int i = 0; i < 3; i++)
            {
                map[x+i][y] = '6';
                
            }map[x][y-1] = '6';
            break;
		}
		break;
    }
}

void receive (int type, int orientation, int x)
{
    switch (type)
    {
    case LONG_TYPE:
        switch (orientation)
        {
        case FIRST:
            checkscore[x] += 4;
            break;

        case SECOND:
            for (int i = 0; i < 4; i++)
            {
                checkscore[x-i]++;
            }
            break;

        case THIRD:
            checkscore[x] += 4;
            break;

        case FOURTH:
            for (int i = 0; i < 4; i++)
            {
                checkscore[x-i]++;
            }
            break;
        }
        break;

    case Z_TYPE:
        switch (orientation)
        {
        case FIRST:
            checkscore[x-1] += 2;
            checkscore[x] += 2;
            break;

        case SECOND:
            checkscore[x]++;
            checkscore[x-1] += 2;
            checkscore[x-2]++;
            break;
        }
        break;

    case L_TYPE:
        switch (orientation)
        {
        case FIRST:
            checkscore[x] += 3;
            checkscore[x-1] ++;
            break;

        case SECOND:
            checkscore[x]++;
            checkscore[x-1] ++;
            checkscore[x-2]+=2;
            break;

        case THIRD:
            checkscore[x] ++;
            checkscore[x-1] +=3;
            break;

        case FOURTH:
            checkscore[x]+=2;
            checkscore[x-1] ++;
            checkscore[x-2]++;
            break;
        }
        break;

    case Sq_TYPE:
        switch (orientation)
        {
        case FIRST:
            checkscore[x] += 2;
            checkscore[x-1] += 2;
            break;
        }
        break;

    case T_TYPE:
        switch (orientation)
        {
        case FIRST:
            checkscore[x] += 3;
            checkscore[x-1] ++;
            break;

        case SECOND:
            checkscore[x]++;
            checkscore[x-1] += 2;
            checkscore[x-2]++;
            break;

        case THIRD:
            checkscore[x] ++;
            checkscore[x-1] +=3;
            break;

        case FOURTH:
            checkscore[x]++;
            checkscore[x-1] +=2;
            checkscore[x-2]++;
            break;
        }
        break;

    case L_REV_TYPE:
        switch (orientation)
        {
        case FIRST:
            checkscore[x] += 3;
            checkscore[x-1] ++;
            break;

        case SECOND:
            checkscore[x]+=2;
            checkscore[x-1]++;
            checkscore[x-2]++;
            break;

        case THIRD:
            checkscore[x]++;
            checkscore[x-1]+=3;
            break;

        case FOURTH:
            checkscore[x]++;
            checkscore[x-1]++;
            checkscore[x-2]+=2;
            break;
        }
        break;

    case Z_REV_TYPE:
        switch (orientation)
        {
        case FIRST:
            checkscore[x-1] += 2;
            checkscore[x] += 2;
            break;

        case SECOND:
            checkscore[x]++;
            checkscore[x-1] += 2;
            checkscore[x-2]++;
            break;
        }
        break;
    }
}

void calculate(int x) //Score System
{
    if (checkscore[x] == 10 && checkscore[x-1] == 10 && checkscore[x-2] == 10 && checkscore[x-3] == 10)  //4 line Strike 
    {
        for (int k = 0; k < 4; k++)
        {
            for (int i = 0; i < x; i++)
            {
                for(int j = 0; j < width-1; j++)
                {
                    map[x-i][j] = map[x-i-1][j];
                    checkscore[x-i] = checkscore[x-1-i];
                }
            }
        }
        playGameSound(S_CLEAR);
        score += 550;
        combo = true;
    }

    else if (checkscore[x] == 10 && checkscore[x-1] == 10 && checkscore[x-2] == 10) //3 line Strke
    {
        for (int k = 0; k < 3; k++)
        {
            for (int i = 0; i < x; i++)
            {
                for(int j = 0; j < width-1; j++)
                {
                    map[x-i][j] = map[x-i-1][j];
                    checkscore[x-i] = checkscore[x-1-i];
                }
            }
        }
        playGameSound(S_CLEAR);
        score += 400;
        combo = true;
    }

    else if (checkscore[x] == 10 && checkscore[x-2] == 10 && checkscore[x-3] == 10)  
    {
        for (int k = 0; k < 3; k++)
        {
            for (int i = 0; i < x; i++)
            {
                for(int j = 0; j < width-1; j++)
                {
                    if (i != 1)
                    {
                        map[x-i][j] = map[x-i-1][j];
                        checkscore[x-i] = checkscore[x-i-1];
                    }
                }
            }
        }

        for (int i = 0; i < x; i++)
        {
            for(int j = 0; j < width-1; j++)
            {
                map[x-i][j] = map[x-i-1][j];
                checkscore[x-i] = checkscore[x-i-1];

            }
        }
        playGameSound(S_CLEAR);
        score += 400;
        combo = true;
    }
    
    else if (checkscore[x] == 10 && checkscore[x-2] == 10)  
    {
        for (int k = 0; k < 1; k++)
        {
            for (int i = 0; i < x; i++)
            {
                for(int j = 0; j < width-1; j++)
                {
                    if (i != 1)
                    {
                        map[x-i][j] = map[x-i-1][j];
                        checkscore[x-i] = checkscore[x-i-1];
                    }

                    else 
                    {
                        continue;
                    }
                }
            }
        }
        
        for (int i = 0; i < x; i++)
        {
            for(int j = 0; j < width-1; j++)
            {
                map[x-i][j] = map[x-i-1][j];
                checkscore[x-i] = checkscore[x-i-1];
            }
        }
        playGameSound(S_CLEAR);
        score += 250;
        combo = true;
    }
    
    else if (checkscore[x] == 10 && checkscore[x-3] == 10)  
    {
        for (int k = 0; k < 1; k++)
        {
            for (int i = 0; i < x; i++)
            {
                for(int j = 0; j < width-1; j++)
                {
                    if (i != 1 && i != 2)
                    {
                        map[x-i][j] = map[x-i-1][j];
                        checkscore[x-i] = checkscore[x-i-1];
                    }

                    else 
                    {
                        continue;
                    }
                }
            }
        }

        for (int i = 0; i < x; i++)
        {
            for(int j = 0; j < width-1; j++)
            {
                map[x-i][j] = map[x-i-1][j];
                checkscore[x-i] = checkscore[x-i-1];

            }
        }
        playGameSound(S_CLEAR);
        score += 250;
        combo = true;
    }

    /////
    
    else if (checkscore[x-1] == 10 && checkscore[x-3] == 10) 
    {
        x-=1;
        for (int k = 0; k < 2; k++)
        {
            for (int i = 0; i < x; i++)
            {
                for(int j = 0; j < width-1; j++)
                {
                    if (i != 1)
                    {
                        map[x-i][j] = map[x-i-1][j];
                        checkscore[x-i] = checkscore[x-i-1];
                    }
                }
            }
        }

        for (int i = 0; i < x; i++)
        {
            for(int j = 0; j < width-1; j++)
            {
                map[x-i][j] = map[x-i-1][j];
                checkscore[x-i] = checkscore[x-i-1];

            }
        }
        playGameSound(S_CLEAR);
        score += 250;
        combo = true;
    }

    ////
    
    else if (checkscore[x] == 10 && checkscore[x-1] == 10) //2 line Strike
    {
        for (int k = 0; k < 2; k++)
        {
            for (int i = 0; i < x; i++)
            {
                for(int j = 0; j < width-1; j++)
                {
                    map[x-i][j] = map[x-i-1][j];
                    checkscore[x-i] = checkscore[x-1-i];
                }
            }
        }
        playGameSound(S_CLEAR);
        score += 250;
        combo = true;
    }
    
    else if (checkscore[x-1] == 10 && checkscore[x-2] == 10 && checkscore[x-3] == 10) 
    {
        x-=1;
        for (int k = 0; k < 3; k++)
        {
            for (int i = 0; i < x; i++)
            {
                for(int j = 0; j < width-1; j++)
                {
                    map[x-i][j] = map[x-i-1][j];
                    checkscore[x-i] = checkscore[x-1-i];
                }
            }
        }
        playGameSound(S_CLEAR);
        score += 400;
        combo = true;
    }
    
    else if (checkscore[x-1] == 10 && checkscore[x-2] == 10) 
    {
        x-=1;
        for (int k = 0; k < 2; k++)
        {
            for (int i = 0; i < x; i++)
            {
                for(int j = 0; j < width-1; j++)
                {
                    map[x-i][j] = map[x-i-1][j];
                    checkscore[x-i] = checkscore[x-1-i];
                }
            }
        }
        playGameSound(S_CLEAR);
        score += 250;
        combo = true;
    }

    else if (checkscore[x-2] == 10 && checkscore[x-3] == 10) 
    {
        x-=2;
        for (int k = 0; k < 2; k++)
        {
            for (int i = 0; i < x; i++)
            {
                for(int j = 0; j < width-1; j++)
                {
                    map[x-i][j] = map[x-i-1][j];
                    checkscore[x-i] = checkscore[x-1-i];
                }
            }
        }
        playGameSound(S_CLEAR);
        score += 250;
        combo = true;
    }

    else if (checkscore[x] == 10)
    {
        for (int i = 0; i < x; i++)
        {
            for(int j = 0; j < width-1; j++)
            {
                map[x-i][j] = map[x-i-1][j];
                checkscore[x-i] = checkscore[x-1-i];
            }
        } 
        playGameSound(S_CLEAR);
        score += 100;
        combo = true;
    }

    else if (checkscore[x-1] == 10)
    {
        x-=1;
        for (int i = 0; i < x; i++)
        {
            for(int j = 0; j < width-1; j++)
            {
                map[x-i][j] = map[x-i-1][j];
                checkscore[x-i] = checkscore[x-1-i];
            }
        }
        playGameSound(S_CLEAR);
        score += 100;
        combo = true;
    }

    else if (checkscore[x-2] == 10)
    {
        x-=2;
        for (int i = 0; i < x; i++)
        {
            for(int j = 0; j < width-1; j++)
            {
                map[x-i][j] = map[x-i-1][j];
                checkscore[x-i] = checkscore[x-1-i];
            }
        }
        playGameSound(S_CLEAR);
        score += 100;
        combo = true;
    }

    else if (checkscore[x-3] == 10)
    {
        x-=3;
        for (int i = 0; i < x; i++)
        {
            for(int j = 0; j < width-1; j++)
            {
                map[x-i][j] = map[x-i-1][j];
                checkscore[x-i] = checkscore[x-1-i];
            }
        }
        playGameSound(S_CLEAR);
        score += 100;
        combo = true;
    }
}

void showScore(COORD c, int x)
{
	c.X = 4;
	c.Y = 30;
    std::ostringstream ss;
    ss.str("");
    ss << x << " POINTS";
    writeToBuffer(c, ss.str(), 0x0E);
}