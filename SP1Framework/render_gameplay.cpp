#include "game.h"
#include "tetris.h"
#include "Framework\console.h"


char map[22][20] = {"A=================B",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "# 0 0 0 0 0 0 0 0 #",
                    "C=================D",};

char Sq[4][8] = {"0 0 0 0",
                 "0 222 0",
                 "0 111 0",
                 "0 0 0 0",};


void DrawArray(COORD c)
{
     for(int i =0; i < 22; i++)
     {
        gotoXY(c.X, c.Y+i);
        for(int j = 0; j < 20; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
     }
}

void DrawMap(COORD c)
{
    for(int i = 0; i < 22; i++)
    {
        gotoXY(c.X, c.Y+i);
        for(int j = 0; j < 20; j++)
        {
            switch(map[i][j])
            {
                case '=':
                    cout << (char)205; //═
                    break;

                case '#':
                    cout << (char)186; //↕
                    break;

                case ' ':
                    cout << ' ';
                    break;

                case '0':
                    cout << '.';
                    break;

                case 'A':
                    cout << (char)201; //╔
                    break;

                case 'B':
                    cout << (char)187; //╗
                    break;

                case 'C':
                    cout << (char)200; //╚
                    break;

                case 'D':
                    cout << (char)188; //╝
                    break;

                case '1':
                    cout << (char)219;
                    break;

                case '2':
                    cout << (char)220;
                    break;
            }
        }

        cout << endl;
    }
}

void sqBlocks(COORD c)
{
    for(int i = 0; i < 4; i++)
    {
        gotoXY(c.X,c.Y++);
        for(int j = 0; j < 6; j++)
        {
            switch(Sq[i][j])
            {
            case ' ':
                cout << ' ';
                break;
            case '1':
                cout << (char)219;
                break;
            case '2':
                cout << (char)220;
                break;
            case '0':
                cout << '.'; //═
                break;
            }
        }
    }
}

void sqBlocks()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            switch(Sq[i][j])
            {
            case ' ':
                cout << ' ';
                break;
            case '1':
                cout << (char)219;
                break;
            case '2':
                cout << (char)220;
                break;
            case '0':
                cout << '.'; //═
                break;
            }
        }
    }
}