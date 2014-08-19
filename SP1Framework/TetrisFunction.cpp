#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

void tetris_screen ()
{
    //char tetris_map[22][23];
    
    char tetris_map[22][23] = {
        "**********************",
		"*                    *",
		"*                    *",
		"*                    *",
		"*                    *",
		"*                    *",
		"*                    *",
		"*                    *",
		"*                    *",
		"*                    *",
		"*                    *",
		"*                    *",
        "*                    *",
        "*                    *",
        "*                    *",
        "*                    *",
        "*                    *",
        "*                    *",
        "*                    *",
        "*                    *",
        "*                    *",
        "**********************"

    };
    /*
    for(int i = 0; i < 22; i++)
    {
		gotoXY(0, 4 + i); 

        for(int j = 0; j < 23; j++)
        {
            tetris_map[0][j] = '*';
            tetris_map[21][j] = '*';
        }
    }*/
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
