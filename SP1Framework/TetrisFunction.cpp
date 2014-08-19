#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

void tetris_screen ()
{
    blocks axis;
    blocks niceshape;

    axis.coord_x = 1;
    axis.coord_y = 9;

    blocks tmap = tetris_game_map();        //tetris map

    blocks square = getSquareBlocks();      //square blocks
    blocks delsquare = DelSquareBlocks();   //delete square blocks

    int block_h = 3;
    int block_width = 3;

/*/////START LOOP/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

    for(;;)
    {
        //updating
        for (int i = 0; i < block_h; i++)
        {
            for (int j = 0; j < block_width; j++)
            {
                tmap.tetris_map[axis.coord_x+i][axis.coord_y+j] = square.square_block[i][j];
            }
        }

/*------DOWNWARD ANIMATION------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

        //animation downward

        for (int i = 0; i < block_h; i++)
        {
            for (int j = 0; j < block_width; j++)
            {
                tmap.tetris_map[axis.coord_x+i][axis.coord_y+j] = delsquare.square_block[i][j];
            }
        }

        axis.coord_x += 1;
        axis.coord_y += 0;

        for (int i = 0; i < block_h; i++)
        {
            for (int j = 0; j < block_width; j++)
            {
                tmap.tetris_map[axis.coord_x+i][axis.coord_y+j] = square.square_block[i][j];
            }

            Sleep(100);
        }        
        
/*------PRESS RIGHT-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

        if(GetAsyncKeyState(VK_RIGHT))
        {
            sound();
            //animation to the right

            for (int i = 0; i < block_h; i++)
            {
                for (int j = 0; j < block_width; j++)
                {
                    tmap.tetris_map[axis.coord_x+i][axis.coord_y+j] = delsquare.square_block[i][j];
                }
            }

            axis.coord_x += 0;
            axis.coord_y += 1;

            for (int i = 0; i < block_h; i++)
            {
                for (int j = 0; j < block_width; j++)
                {
                    tmap.tetris_map[axis.coord_x+i][axis.coord_y+j] = square.square_block[i][j];
                }
            }
        }


/*------PRESS LEFT--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

        if(GetAsyncKeyState(VK_LEFT))
        {
            sound();
            //animation to the left

            for (int i = 0; i < block_h; i++)
            {
                for (int j = 0; j < block_width; j++)
                {
                    tmap.tetris_map[axis.coord_x+i][axis.coord_y+j] = delsquare.square_block[i][j];
                }
            }

            axis.coord_x += 0;
            axis.coord_y -= 1;

            for (int i = 0; i < block_h; i++)
            {
                for (int j = 0; j < block_width; j++)
                {
                    tmap.tetris_map[axis.coord_x+i][axis.coord_y+j] = square.square_block[i][j];
                }
            }
        }

/*------UPDATE MAP--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

        //map screen
        for(int i = 0; i < 22; i++)
        {
            gotoXY(0, 4 + i); 

            for(int j = 0; j < 23; j++)
            {
                cout << tmap.tetris_map[i][j];
            }
            cout << endl;
        }

		tetris_info ();

		if(GetAsyncKeyState(VK_ESCAPE))
		{
			pause_screen();
		}

/*/////LOOP WILL REPEAT FROM STARTING AGAIN//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
    
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

	    {
		int choice = 0;

			while (CONTINUE != ENDGAME)
			{
				cls();
				gotoXY(20,10);
				cout << "(1)Continue Game" << endl;

				gotoXY(20,12);
				cout << "(2)End Game" << endl;
				gotoXY(25,18);
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
			}
	}
}

void sound()
{
    Beep(1000, 100);
}

void menu_music()
{
    Beep(0,200);
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
