// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include "tetris.h"
<<<<<<< bd4cbfb6287179dbfd666aad9e8e624f0e06f995
#include "blocksUI.h"
=======
#include <fstream>
#include <string>
>>>>>>> c04850209f6581973917a7b3c25c47a7d9f6a81c

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD charLocation;
COORD consoleSize;

bool press = false;
bool pause = false;

void init()
{
    // Set precision for floating point output
    std::cout << std::fixed << std::setprecision(3);

    SetConsoleTitle(L"SP1 Framework");

    // Sets the console size, this is the biggest so far.
    setConsoleSize(68, 30);

    // Get console width and height
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */     

    /* get the number of character cells in the current buffer */ 
    GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
    consoleSize.X = csbi.srWindow.Right + 1;
    consoleSize.Y = csbi.srWindow.Bottom + 1;

    // set the character to be in the center of the screen.
    charLocation.X = 22;
    charLocation.Y = 4;

    elapsedTime = 0.0;
}

void shutdown()
{
    // Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void getInput()
{    
    keyPressed[K_UP] = isKeyPressed(VK_UP);
    keyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
    keyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
    keyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
    keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
    keyPressed[K_ENTER] = isKeyPressed(VK_RETURN);
	keyPressed[K_PAUSE] = isKeyPressed(VK_BACK);
}

void update(double dt)
{
    // get the delta time
    elapsedTime += dt;
    deltaTime = dt;

    FindCoordinates (2, 3);

    // Updating the location of the character based on the key press
    /*
    if (keyPressed[K_UP] && charLocation.Y > 20)
    {
        Beep(1440, 30);
        charLocation.Y--; 
    }*/

    if (keyPressed[K_LEFT] && charLocation.X > 17 && charLocation.Y != 24)
    {
        Beep(1440, 30);
        charLocation.X--; 
    }

    if (keyPressed[K_DOWN] && charLocation.Y < consoleSize.Y - 1 && charLocation.Y != 24)
    {
        Beep(1440, 30);
        charLocation.Y++; 
    }

<<<<<<< bd4cbfb6287179dbfd666aad9e8e624f0e06f995
    if (keyPressed[K_RIGHT] && charLocation.X < 26 && charLocation.Y != 24)
    {
=======

    if (keyPressed[K_RIGHT] && charLocation.X < 26)//consoleSize.X - 1)
	{
>>>>>>> c04850209f6581973917a7b3c25c47a7d9f6a81c
        Beep(1440, 30);
        charLocation.X++;
    }

    // quits the game if player hits the escape key
    if (keyPressed[K_ESCAPE])
    {
        g_quitGame = true;    
    }
    
    if (keyPressed[K_ENTER])
    {
        press = true;
    }

	if (keyPressed[K_PAUSE])
	{
		pause = true;
	}
}

void PauseData()
{
	std::ifstream Paused_Screen;
	std::string pause;
	Paused_Screen.open ("Pause.txt");
	while (!Paused_Screen.eof()) 
	{
		getline (Paused_Screen, pause);
		cout << pause << endl;
	}
	Paused_Screen.close ();
}

void render()
{
    // clear previous screen
    
    Standard();
    
    //render the game
    //MenuScreen();
    //render test screen code (not efficient at all)
    const WORD colors[] =   {
	                            0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	                            0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	                        };
    
    // render time taken to calculate this frame

    FPSInfo();
    TIMINGInfo();


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*Put function here*/

<<<<<<< bd4cbfb6287179dbfd666aad9e8e624f0e06f995
    TetrisGameplay();
    Sleep(200);    
=======
        TIMINGInfo();
        FPSInfo();

        TetrisGameplay();
    }
	if (pause == true)
	{
		Paused_Screen();
	}
>>>>>>> c04850209f6581973917a7b3c25c47a7d9f6a81c
}

COORD FindCoordinates (short n1, short n2)
{
    COORD location;

    location.X = n1; 
    location.Y = n2;

    return location;
}

void TetrisGameplay()
{
    TetrisMap();

    gotoXY(charLocation);
    if (1 == 1)
    {
        SQUARE();
    }

    charLocation.Y++;

    short coordinfox = 0;
    short coordinfoy = 0;
    
    if (charLocation.Y > 24)
    {
        Standard();
        //TetrisMap();
        FPSInfo();
        TIMINGInfo();

        
        charLocation.Y--;

        coordinfox = charLocation.X;
        coordinfoy = charLocation.Y;

        gotoXY(coordinfox, coordinfoy);
        SQUARE();

        charLocation.X = 19;
        charLocation.Y = 6;
    }
}

void FPSInfo()
{
    gotoXY(60, 0);
    colour(0x1A);
    std::cout << 1.0 / deltaTime << "fps" << std::endl;
}

void TIMINGInfo()
{
    gotoXY(0, 0);
    colour(0x59);
    std::cout << elapsedTime << "secs" << std::endl;
}

void Standard()
{
    colour(0x0F);
    cls();
}

void SQUARE()
{
    cout << BLocksShape();
    cout << BLocksShape();
    cout << BLocksShape();
    cout << BLocksShape();
}
