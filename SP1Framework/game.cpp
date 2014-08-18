// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include "tetris.h"
//#include <iostream>
//#include <iomanip>

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD charLocation;
COORD consoleSize;

void init()
{
    // Set precision for floating point output
    std::cout << std::fixed << std::setprecision(3);

    SetConsoleTitle(L"SP1 Framework");

    // Sets the console size, this is the biggest so far.
    setConsoleSize(50, 28);

    // Get console width and height
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */     

    /* get the number of character cells in the current buffer */ 
    GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
    consoleSize.X = csbi.srWindow.Right + 1;
    consoleSize.Y = csbi.srWindow.Bottom + 1;
    
    // set the character to be in the center of the screen.
    charLocation.X = consoleSize.X / 2;
    charLocation.Y = consoleSize.Y / 2;

    elapsedTime = 0.0;
}

void shutdown()
{
    // Reset to white text on black background
    colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void getInput()
{    
    keyPressed[K_UP] = isKeyPressed(VkKeyScan('w'));
    keyPressed[K_DOWN] = isKeyPressed(VkKeyScan('s'));
    keyPressed[K_LEFT] = isKeyPressed(VkKeyScan('a'));
    keyPressed[K_RIGHT] = isKeyPressed(VkKeyScan('d'));
    keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
}

void update(double dt)
{
    // get the delta time
    elapsedTime += dt;
    deltaTime = dt;

    // Updating the location of the character based on the key press
    if (keyPressed[K_UP] && charLocation.Y > 0)
    {
        Beep(1000, 100);
        charLocation.Y--; 
    }
    if (keyPressed[K_LEFT] && charLocation.X > 0)
    {
        Beep(1000, 100);
        charLocation.X--; 
    }
    if (keyPressed[K_DOWN] && charLocation.Y < consoleSize.Y - 1)
    {
        Beep(1000, 100);
        charLocation.Y++; 
    }
    if (keyPressed[K_RIGHT] && charLocation.X < consoleSize.X - 1)
    {
        Beep(1000, 100);
        charLocation.X++; 
    }

    // Pauses the game if player hits the escape key
    if (keyPressed[K_ESCAPE])
        system("pause");
}

void render()
{
    // clear previous screen
    cls();
    
    //render time taken to calculate this frame
    gotoXY(40, 0);
    colour(0x1A);
    std::cout << 1.0 / deltaTime << "fps" << std::endl;

    gotoXY(0, 0);
    colour(0x59);
    std::cout << elapsedTime << "secs" << std::endl;
	colour(0x0C);
<<<<<<< 0bd2a6a8efe758294cede3307fe50fdbe99aaa28
=======
    */

    /*// render character
    gotoXY(charLocation);
    colour(0x0C);
    std::cout << (char)1;*/
	
	colour(0x00D);
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
>>>>>>> 6742002588d4dd56b365fefd1fb3d941971c5e3a

    /*// render character
    gotoXY(charLocation);
    colour(0x0C);
    std::cout << (char)1;*/


    //render test screen code (not efficient at all)
    const WORD colors[] =   {
        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6,
    };

    tetris_info();      //Info is here 
    tetris_screen();    //Gameplay Map is here
    

<<<<<<< 1ccf3a0e5f3d1119a3fe5bd3c9f3f434b2fd88c4
	_getch();
=======
<<<<<<< 0bd2a6a8efe758294cede3307fe50fdbe99aaa28
	//_getch();
>>>>>>> 8713d293563d28b08034e2ad6cf23375b5c66b01

	//colour(0x0C);
<<<<<<< ab4bafbca8a531a53f3ed3c66f3a0cb405b23de2
=======

    // render character
<<<<<<< 1ccf3a0e5f3d1119a3fe5bd3c9f3f434b2fd88c4
    
=======
    /*gotoXY(charLocation);
    colour(0x0C);
    std::cout << (char)1;*/
=======
        for(int j = 0; j < 23; j++)
        {
            std::cout << tetris_map[i][j];
        }
        std::cout << std::endl;
    }

	colour(0x00E);
	gotoXY(18,0);
	std::cout << "ICHIproduction";

	gotoXY(60,4);
	std::cout << "Next in line Block"; 

	gotoXY(8, 3);
	std::cout << "TETRIS";

	gotoXY(30,6);
	std::cout << "Next in line Block";  

	gotoXY(30,16);
	std::cout << "Hold Block"; 


	gotoXY(0, 26);
	std::cout << "Your score is: ";
	getch();

	char block = '*';
>>>>>>> 6742002588d4dd56b365fefd1fb3d941971c5e3a
>>>>>>> 8713d293563d28b08034e2ad6cf23375b5c66b01
>>>>>>> ea2d4a382fce1ccde880b03d8604f8205b95d1f9
}
