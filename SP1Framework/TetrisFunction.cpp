#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

const int t_mX = 22;
const int t_mY = 23;

void tetris_screen ()
{
    blocks axis;
    blocks niceshape;

    niceshape.blockshape = 'o';
    axis.sq_x = 2;
    axis.sq_y = 2;
	

    const int t_mX = 22;
    const int t_mY = 23;

    blocks square = getSquareBlocks();
    blocks delsquare = DelSquareBlocks();

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
    
    for(int i = 0; i < 22; i++)
    {
        gotoXY(0, 4 + i); 

        for(int j = 0; j < 23; j++)
        {
            cout << tetris_map[i][j];
        }
        cout << endl;
    }

/*/////START LOOP/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

    for(;;)
    {
        //updating
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                tetris_map[axis.sq_x+i][axis.sq_y+j] = square.square_block[i][j];
            }
        }

/*------DOWNWARD ANIMATION------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        
        //animation downward

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                tetris_map[axis.sq_x+i][axis.sq_y+j] = delsquare.square_block[i][j];
            }
        }

        axis.sq_x += 1;
        axis.sq_y += 0;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                tetris_map[axis.sq_x+i][axis.sq_y+j] = square.square_block[i][j];
            }

            Sleep(150);
        }
        
        
/*------PRESS RIGHT-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

        if(GetAsyncKeyState(VK_RIGHT))
        {
            sound();
            //animation to the right

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    tetris_map[axis.sq_x+i][axis.sq_y+j] = delsquare.square_block[i][j];
                }
            }

            axis.sq_x += 0;
            axis.sq_y += 1;

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    tetris_map[axis.sq_x+i][axis.sq_y+j] = square.square_block[i][j];
                }
            }
        }

/*------PRESS LEFT--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        
        if(GetAsyncKeyState(VK_LEFT))
        {
            sound();
            //animation to the left

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    tetris_map[axis.sq_x+i][axis.sq_y+j] = delsquare.square_block[i][j];
                }
            }

            axis.sq_x += 0;
            axis.sq_y -= 1;

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    tetris_map[axis.sq_x+i][axis.sq_y+j] = square.square_block[i][j];
                }
            }
        }

/*/////ENDLOOP//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

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

		tetris_info ();

		if(GetAsyncKeyState(VK_ESCAPE))
		{
			pause_screen();
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

void welcome_screen()
{
	enum Sequence
	{
		NEWGAME = 1,
		CREDITS,
		EXITGAME
	};

	int choice = 0;
		//Title of the game
		cout << endl;
		cout << "*******" << " *******" << " *******" << " ******   "  << " ******* " << "   ***** " << endl;
		cout << "   *   " << " *      " << "    *   " << " *     *  "  << "    *    " << "  *    *" << endl;
		cout << "   *   " << " *      " << "    *   " << " *     *  "  << "    *    " << "   *      " << endl;
		cout << "   *   " << " *******" << "    *   " << " ******   "  << "    *    " << "    *     " << endl;
		cout << "   *   " << " *      " << "    *   " << " *     *  "  << "    *    " << "     *    "<< endl;
		cout << "   *   " << " *      " << "    *   " << " *      * "  << "    *    " << " *    * "<< endl;
		cout << "   *   " << " *******" << "    *   " << " *       *"  << " ******* " << " ***** "<< endl;

	while(NEWGAME != EXITGAME)
	{
        //PlaySound(menu_music(), NULL, menu_music());

		//Start game function
		gotoXY(20, 10);
		cout << "(1)New Game" << endl;
		
		//Credit function
		gotoXY(20, 12);
		cout << "(2)Credit" << endl;

		//Exiting the game function
		gotoXY(20, 14);
		cout << "(3)Exit Game" << endl << endl;

		//Function for players to choose
		gotoXY(14, 16);
		cout << "Pick a number to start!" << endl;
		gotoXY(25,18);
		cin >> choice;
		cout << endl;

		//How the function works
		switch(choice)
		{
		case NEWGAME: system("cls");
			return tetris_screen();

		case CREDITS: system("cls");
			gotoXY(25, 9);
			cout <<"No credits. Fooled you. HAHA" << endl << endl;
			exit(0);

		case EXITGAME: system("cls");
			gotoXY(25, 9);
			cout << "Thank you playing!" << endl << endl;
			exit(0);

		default: system("cls");
			cout << "This game will shut down." << endl;
			exit(0);
		}
	}
}

void pause_screen()
{
	//pause table
	enum Pause
	{
		CONTINUE = 1,
		ENDGAME
	};

	//{
		int choice = 0;

			/*while (CONTINUE != ENDGAME)
			{*/
				cls();
				gotoXY(20,10);
				cout << "(1)Continue Game" << endl;

				gotoXY(20,12);
				cout << "(2)End Game" << endl;
				cin >> choice;
				cout << endl;

				switch(choice)
				{
					cls();

				case CONTINUE:
					cls();
					return;

				case ENDGAME: 
					cls();
					return welcome_screen();

				}
			//}
	//}
    

}

void sound()
{
    Beep(1000, 100);
}

void menu_music()
{

    Beep(1650,100);Sleep(150);
    Beep(1500,100);Sleep(150);
    Beep(1250,100);Sleep(150);
    Beep(1500,100);Sleep(150);
    Beep(1650,100);Sleep(150);
    Beep(1650,100);Sleep(150);
    Beep(1650,100);Sleep(150);
    Beep(1500,100);Sleep(150);
    Beep(1500,100);Sleep(150);
    Beep(1500,100);Sleep(150);
    Beep(1650,100);Sleep(150);
    Beep(1650,100);Sleep(150);
    Beep(1650,100);Sleep(300);
    Beep(1650,100);Sleep(150);
    Beep(1500,100);Sleep(150);
    Beep(1250,100);Sleep(150);
    Beep(1500,100);Sleep(150);
    Beep(1650,100);Sleep(150);
    Beep(1650,100);Sleep(150);
    Beep(1650,100);Sleep(150);
    Beep(1500,100);Sleep(150);
    Beep(1500,100);Sleep(150);
    Beep(1650,100);Sleep(150);
    Beep(1500,100);Sleep(150);
    Beep(1250,100);Sleep(150);
}
