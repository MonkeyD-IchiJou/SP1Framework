#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

void tetris_screen ()
{
    const int t_mX = 22;
    const int t_mY = 23;

    int sq_X = 2;
    int sq_Y = 2;

    //Tetris map
    char tetris_map[t_mX][t_mY];

    for(int i = 0; i < 22; i++)
    {
        for(int j = 0; j < 23; j++)
        {
            tetris_map[0][j] = '*';
            tetris_map[21][j] = '*';
            tetris_map[i][0] = '*';
            tetris_map[i][22] = '*';

            if (j > 0 && j < 22 && i > 0 && i < 21)
            {
                tetris_map[i][j] = ' '; 
            }
        }
    }

    //square block
    blocks square;

    square.square_block;

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
                square.square_block[i][j] = '*';
            }
        }
    }

    for(int i = 0; i < 22; i++)
    {
        gotoXY(0, 4 + i); 

        for(int j = 0; j < 23; j++)
        {
            cout << tetris_map[i][j];
        }
        cout << endl;
    }


///////////////////////////////////////////////////////////////////////////////////////////////////////////
    for(;;)
    {

        //updating
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                tetris_map[sq_X+i][sq_Y+j] = square.square_block[i][j];
            }
        }

///////////////////////////////////////////////////////////////////////////////////////////////////////////
        //animation downward

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
                    square.square_block[i][j] = ' ';
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                tetris_map[sq_X+i][sq_Y+j] = square.square_block[i][j];
            }
        }

        sq_X += 1;
        sq_Y += 0;

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
                    square.square_block[i][j] = '*';
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                tetris_map[sq_X+i][sq_Y+j] = square.square_block[i][j];
            }
            Sleep(150);
        }
        
        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if(GetAsyncKeyState(VK_RIGHT))
        {
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
                        square.square_block[i][j] = ' ';
                    }
                }
            }

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    tetris_map[sq_X+i][sq_Y+j] = square.square_block[i][j];
                }
            }

            sq_X += 0;
            sq_Y += 1;

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
                        square.square_block[i][j] = '*';
                    }
                }
            }

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    tetris_map[sq_X+i][sq_Y+j] = square.square_block[i][j];
                }
            }
        }

        if(GetAsyncKeyState(VK_LEFT))
        {
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
                        square.square_block[i][j] = ' ';
                    }
                }
            }

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    tetris_map[sq_X+i][sq_Y+j] = square.square_block[i][j];
                }
            }

            sq_X += 0;
            sq_Y -= 1;

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
                        square.square_block[i][j] = '*';
                    }
                }
            }

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    tetris_map[sq_X+i][sq_Y+j] = square.square_block[i][j];
                }
            }
        }

        //map screen
        for(int i = 0; i < 22; i++)
        {
            gotoXY(0, 4 + i); 

            for(int j = 0; j < 23; j++)
            {
                cout << tetris_map[i][j];
            }
            cout << endl;
        }
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			pause_screen();
			system("pause");
		}
    }
}

void tetris_info ()
{
    gotoXY(18,0);
    cout << "ICHIproduction"; 

    gotoXY(8, 3);
    cout << "TETRIS";

    gotoXY(30,6);
    cout << "Next in line Block";  

    gotoXY(30,16);
    cout << "Hold Block"; 

    gotoXY(0, 26);
    std::cout << "Your score is: ";

    char block = '*';
}

void square_block()
{
    blocks square;

    square.square_block;

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
                square.square_block[i][j] = '*';
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << square.square_block[i][j];
        }
        cout << endl;
    }
}

void welcome_screen()
{
	enum Sequence
	{
		NEWGAME = 1,
		CREDITS,
		EXITGAME
	};

{
	int choice = 0;
	while(NEWGAME != EXITGAME)
	{
		cout << "*******" << " *******" << " *******" << " ******   "  << " ******* " << "   ***** " << endl;
		cout << "   *   " << " *      " << "    *   " << " *     *  "  << "    *    " << "  *    *" << endl;
		cout << "   *   " << " *      " << "    *   " << " *     *  "  << "    *    " << "   *      " << endl;
		cout << "   *   " << " *******" << "    *   " << " ******   "  << "    *    " << "    *     " << endl;
		cout << "   *   " << " *      " << "    *   " << " *     *  "  << "    *    " << "     *    "<< endl;
		cout << "   *   " << " *      " << "    *   " << " *      * "  << "    *    " << " *    * "<< endl;
		cout << "   *   " << " *******" << "    *   " << " *       *"  << " ******* " << " ***** "<< endl;
		gotoXY(20, 10);
		cout << "(1)New Game" << endl;
		gotoXY(20, 12);
		cout << "(2)Credit" << endl;
		gotoXY(20, 14);
		cout << "(3)Exit Game" << endl << endl;
		gotoXY(14, 16);
		cout << "Press a number to start!" << endl;
		cin >> choice;
		cout << endl;
		switch(choice)
		{
		case NEWGAME: cout << "Let's start playing!" << endl << endl << endl;
			system("cls");
			return;
		case CREDITS: cout << "No credits. Fooled you. HAHA" << endl << endl << endl;
			break;
		case EXITGAME: cout <<		"Thank you playing! Please buy the game!" << endl;
					   cout <<		"              $          " << endl;
				       cout <<		"           ,$$$$$,       " << endl;
				       cout <<		"         ,$$$'$'$$$      " << endl;
				       cout <<		"         $$$  $   '      " << endl;
				       cout <<		"         '$$$,$          " << endl;
				       cout << 		"            $$$$,        " << endl;
				       cout <<		"             '$$$$,      " << endl;
				       cout <<		"              $ $$$,     " << endl;
				       cout <<		"          ,   $  $$$     " << endl;
				       cout <<		"          $$$ $.$$$      " << endl;
				       cout <<		"            $$$$$        " << endl;
				       cout <<		"              $          " << endl;
			break;
		}
	}
}

}

void pause_screen()
{
	const int p_mX = 22;
    const int p_mY = 23;

	//pause table
	gotoXY(15,10);
	char pause_screen[p_mX][p_mY];

    for(int i = 0; i < 22; i++)
    {
        for(int j = 0; j < 23; j++)
        {
            pause_screen[0][j] = '*';
            pause_screen[21][j] = '*';
            pause_screen[i][0] = '*';
            pause_screen[i][22] = '*';

            if (j > 0 && j < 22 && i > 0 && i < 21)
            {
               pause_screen[i][j] = ' '; 
            }
        }
    }

	enum Pause
	{
		CONTINUE = 1,
		ENDGAME
	};

	{
		int choice = 0;
			while (CONTINUE != ENDGAME)
			{
				gotoXY(20,10);
				cout << "(1)Continue Game" << endl;
				gotoXY(20,12);
				cout << "(2)End Game" << endl;
				cin >> choice;
				cout << endl;
				switch(choice)
				{
				case CONTINUE:
					return;

				case ENDGAME: cout << "ThankYou" << endl;
					system("cls");
					break;
				}
			}
	}

}