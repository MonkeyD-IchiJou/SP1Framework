#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

void tetris_screen ()
{
    blocks axis;
    //blocks niceshape;

    axis.coord_x = 1;
    axis.coord_y = 9;

    blocks tmap = tetris_game_map();        //tetris map

    blocks square = getSquareBlocks();      //square blocks
    blocks delsquare = DelSquareBlocks();   //delete square blocks

    int block_h = 3;
    int block_width = 4;

    int speed = 0;

/*/////START LOOP/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

    for(;;)
    {
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
                Sleep(speed);
                //sides
                square.square_block[0][0] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i]; 
                square.square_block[1][0] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];
                square.square_block[0][3] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];
                square.square_block[1][3] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];        //dunno why like this, in the future will check this out

                //below
                square.square_block[2][0] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];        //dunno why like this, in the future will check this out
                square.square_block[2][1] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];
                square.square_block[2][2] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];
                square.square_block[2][3] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];

                for (int j = 0; j < block_width; j++)
                {
                    if (i >= 0 && i < 3 && j > 0 && j < 4 )
                    {
                        tmap.tetris_map[axis.coord_x+i][axis.coord_y+j] = square.square_block[i][j]; 
                    }
                }

                if (tmap.tetris_map[axis.coord_x+i+1][axis.coord_y+i] == '+')
                {
                        cin.ignore();
                }
            } 
        
        
/*------PRESS RIGHT-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
   
        if(GetAsyncKeyState(VK_RIGHT))
        {
            speed = 0;
            sound();
            //animation to the right

            for (int i = 0; i < block_h; i++)
            {
                for (int j = 0; j < block_width; j++)
                {
                    if (i >= 0 && i < 3 && j > 0 && j < 4 )
                    {
                        tmap.tetris_map[axis.coord_x+i][axis.coord_y+j] = delsquare.square_block[i][j];
                    }
                }
            }

            axis.coord_x += 0;
            axis.coord_y += 1;

            for (int i = 0; i < block_h; i++)
            {
                //sides
                square.square_block[0][0] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];
                square.square_block[1][0] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];
                square.square_block[0][3] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];
                square.square_block[1][3] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];        //dunno why like this, in the future will check this out

                //below
                square.square_block[2][0] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];        //dunno why like this, in the future will check this out
                square.square_block[2][1] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];
                square.square_block[2][2] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];
                square.square_block[2][3] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];

                for (int j = 0; j < block_width; j++)
                {
                    if (i >= 0 && i < 3 && j > 0 && j < 4 )
                    {
                        tmap.tetris_map[axis.coord_x+i][axis.coord_y+j] = square.square_block[i][j]; 
                    }
                }

                if (tmap.tetris_map[axis.coord_x+i][axis.coord_y+i+3] == '+')
                {
                    cin.ignore();
                }
            }
        }

        else 
        {
            speed = 0;
        }
        
/*------PRESS LEFT--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

        if(GetAsyncKeyState(VK_LEFT))
        {
            sound();
            speed = 0;
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
                Sleep(speed);
                //sides
                square.square_block[0][0] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i]; 
                square.square_block[1][0] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];
                square.square_block[0][3] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];
                square.square_block[1][3] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];        //dunno why like this, in the future will check this out

                //below
                square.square_block[2][0] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];        //dunno why like this, in the future will check this out
                square.square_block[2][1] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];
                square.square_block[2][2] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];
                square.square_block[2][3] = tmap.tetris_map[axis.coord_x+i][axis.coord_y+i];

                for (int j = 0; j < block_width; j++)
                {
                    if (i >= 0 && i < 3 && j > 0 && j < 4 )
                    {
                        tmap.tetris_map[axis.coord_x+i][axis.coord_y+j] = square.square_block[i][j]; 
                    }
                }

                if (tmap.tetris_map[axis.coord_x+i][axis.coord_y+i-2] == '+')
                {
                        cin.ignore();
                }
            }
        }

        else 
        {
            speed = 0;
        }
        

/*------PRESS DOWN--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

        if(GetAsyncKeyState(VK_DOWN))
        {
            sound();
            speed = 0;
        }

        else 
        {
            speed = 0;
        }
        
/*------UPDATE MAP--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

        //map screen
           
        for(int i = 0; i < t_mX; i++)
        {
            gotoXY(0, 4 + i); 

            for(int j = 0; j < t_mY; j++)
            {
                cout << tmap.tetris_map[i][j];
            }
            cout << endl;
        }
        
		tetris_info ();

		if(GetAsyncKeyState(VK_ESCAPE))
		{
			//pause_screen();
            system("pause");
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

    gotoXY(0, 27);
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

        //Menu Beep Music
        int k;
        gotoXY(0,20);
        cout << "Do you want to listen to epic theme song of TETRIS? \n                Yes = '1',  No = '0' - ";
        cin >> k;
        if(k == 1)
        {
            menu_music();
        }
        
        
           
        
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
    
    Beep(0,100);
    Beep(1320, 500);
    Beep(990, 250);
    Beep(1056, 250);
    Beep(1188, 250);
    Beep(1320, 125);
    Beep(1188, 125);
    Beep(1056, 250);
    Beep(990, 250);
    Beep(880, 500);
    Beep(880, 250);
    Beep(1056, 250);
    Beep(1320, 500);
    Beep(1188, 250);
    Beep(1056, 250);
    Beep(990, 750);
    Beep(1056, 250);
    Beep(1188, 500);
    Beep(1320, 500);
    Beep(1056, 500);
    Beep(880, 500);
    Beep(880, 500);
    Sleep(250);
    Beep(1188, 500);
    Beep(1408, 250);
    Beep(1760, 500);
    Beep(1584, 250);
    Beep(1408, 250);
    Beep(1320, 750);
    Beep(1056, 250);
    Beep(1320, 500);
    Beep(1188, 250);
    Beep(1056, 250);
    Beep(990, 500);
    Beep(990, 250);
    Beep(1056, 250);
    Beep(1188, 500);
    Beep(1320, 500);
    Beep(1056, 500);
    Beep(880, 500);
    Beep(880, 500);
    Sleep(500);
    Beep(1320, 500);
    Beep(990, 250);
    Beep(1056, 250);
    Beep(1188, 250);
    Beep(1320, 125);
    Beep(1188, 125);
    Beep(1056, 250);
    Beep(990, 250);
    Beep(880, 500);
    Beep(880, 250);
    Beep(1056, 250);
    Beep(1320, 500);
    Beep(1188, 250);
    Beep(1056, 250);
    Beep(990, 750);
    Beep(1056, 250);
    Beep(1188, 500);
    Beep(1320, 500);
    Beep(1056, 500);
    Beep(880, 500);
    Beep(880, 500);
    Sleep(250);
    Beep(1188, 500);
    Beep(1408, 250);
    Beep(1760, 500);
    Beep(1584, 250);
    Beep(1408, 250);
    Beep(1320, 750);
    Beep(1056, 250);
    Beep(1320, 500);
    Beep(1188, 250);
    Beep(1056, 250);
    Beep(990, 500);
    Beep(990, 250);
    Beep(1056, 250);
    Beep(1188, 500);
    Beep(1320, 500);
    Beep(1056, 500);
    Beep(880, 500);
    Beep(880, 500);
    Sleep(500);
    Beep(660, 1000);
    Beep(528, 1000);
    Beep(594, 1000);
    Beep(495, 1000);
    Beep(528, 1000);
    Beep(440, 1000);
    Beep(419, 1000);
    Beep(495, 1000);
    Beep(660, 1000);
    Beep(528, 1000);
    Beep(594, 1000);
    Beep(495, 1000);
    Beep(528, 500);
    Beep(660, 500);
    Beep(880, 1000);
    Beep(838, 2000);
    Beep(660, 1000);
    Beep(528, 1000);
    Beep(594, 1000);
    Beep(495, 1000);
    Beep(528, 1000);
    Beep(440, 1000);
    Beep(419, 1000);
    Beep(495, 1000);
    Beep(660, 1000);
    Beep(528, 1000);
    Beep(594, 1000);
    Beep(495, 1000);
    Beep(528, 500);
    Beep(660, 500);
    Beep(880, 1000);
    Beep(838, 2000);
}
