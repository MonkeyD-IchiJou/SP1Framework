// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

#include "blocksUI.h"
#include <fstream>
#include <string>

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD charLocation;
COORD consoleSize;

bool press = false;
bool pause = false;
bool pressmusic = false;
bool stopmusic = false;

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

    // set the character to be in the center of the gameplay screen.
    charLocation.X = 20;
    charLocation.Y = 5;

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

	keyPressed[K_MUSIC] = isKeyPressed(VK_LSHIFT);
	keyPressed[K_SMUSIC] = isKeyPressed(VK_RSHIFT);
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

    if (keyPressed[K_RIGHT] && charLocation.X < 26 && charLocation.Y != 24)
	{
		Beep(1440, 30);
        charLocation.X++;
	}

	// opens the game if player hits the enter key
    if (keyPressed[K_ENTER])
    {
        //press = true;
        Standard();
		FPSInfo();
		TIMINGInfo();
        TetrisMap();
		TetrisGameplay();
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

    // plays the music if player hits the left shift key
	if(keyPressed[K_MUSIC])
	{
		pressmusic = true;
	}

	if(keyPressed[K_SMUSIC])
	{
		stopmusic = true;
	}
}

void render()
{
    // clear previous screen
	//Standard();
	FPSInfo();
	TIMINGInfo();
    
    

    //render test screen code (not efficient at all)
    const WORD colors[] =   {
	                            0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	                            0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	                        };
    
    // render time taken to calculate this frame

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*Put function here*/

    //MenuScreen();
        
	if (pause == true)
	{
		Paused_Screen();
    }

    if(press == true)
	{ 
        //TetrisMap();
		FPSInfo();
		TIMINGInfo();
		TetrisGameplay();
	}

	if(g_quitGame == true)
	{
		exit(0);
	}

	while(pressmusic != stopmusic)
	{
		if(pressmusic == true)
		{
			menu_music();
			if(stopmusic == true)
			{
				exit(0);
			}
		}
	}
}

void MenuData()
{
	std::ifstream MenuScreen;
	std::string data;
	MenuScreen.open("tetris_ascii.txt");
	while(!MenuScreen.eof())
	{
		getline(MenuScreen, data);
		cout << data << endl;
	}

	MenuScreen.close();
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
    if (1 == 1)
    {
        gotoXY(charLocation);
        LONGLINE();
    }
   
    charLocation.Y++;

    int coordinfox = 0;
    int coordinfoy = 0;

    if (charLocation.Y > 24)
    {
        charLocation.Y--;
        coordinfox = charLocation.X;
        coordinfoy = charLocation.Y;

        charLocation.X = 20;
        charLocation.Y = 5;
        TetrisMap(coordinfox, coordinfoy);
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
    colour(0x1A);
    std::cout << elapsedTime << "secs" << std::endl;
}

void Standard()
{
    colour(0000);
    cls();
}

void LONGLINE()
{
    cout << BLocksShape();
    cout << BLocksShape();
    cout << BLocksShape();
    cout << BLocksShape();
}