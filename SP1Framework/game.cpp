// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];

COORD charLocation[10000];
COORD consoleSize;

bool press = false;
bool pause = false;
bool pressmusic = false;
bool stopmusic = false;

int A = 0;

unsigned char gameState;


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
    charLocation[A].X = 20;
    charLocation[A].Y = 5;

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
	keyPressed[K_QUIT] = isKeyPressed(VK_BACK);
	keyPressed[K_RETURN] = isKeyPressed(VK_TAB);
	keyPressed[K_HELP] = isKeyPressed(VK_LSHIFT);
	keyPressed[K_MUSICSCR] = isKeyPressed(VK_F1);
	keyPressed[K_MUSIC] = isKeyPressed(VK_F2);
	keyPressed[K_SMUSIC] = isKeyPressed(VK_SPACE);
}

void update(double dt)
{
    // get the delta time
    elapsedTime += dt;
    deltaTime = dt;


    // Updating the location of the character based on the key press
    /*
    if (keyPressed[K_UP] && charLocation.Y > 20)
    {
        Beep(1440, 30);
        charLocation.Y--; 
    }*/

    charLocation[A].Y++;

    if (keyPressed[K_LEFT] && charLocation[A].X > 17 && charLocation[A].Y < 21)
    {
        Beep(1440, 30);
        charLocation[A].X--;
    }

    if (keyPressed[K_DOWN] && charLocation[A].Y < consoleSize.Y - 1 && charLocation[A].Y < 21)
    {
        Beep(1440, 30);
        charLocation[A].Y++;
    }

    if (keyPressed[K_RIGHT] && charLocation[A].X < 23 && charLocation[A].Y < 21)
	{
		Beep(1440, 30);
        charLocation[A].X++;
	}
	// opens the game if player hits the enter key
    /*if (keyPressed[K_ENTER])
    {
        press = true;
    }*/

    // quits the game if player hits the escape key
    if (keyPressed[K_ESCAPE])
    {
		gameState = 4;
    }
    
    if (keyPressed[K_ENTER])
    {
        gameState = 1;
    }

	if(keyPressed[K_HELP])
	{
		gameState = 3;
	}

    
    if (charLocation[A].Y > 21)
    {
        charLocation[A].Y--;
        charLocation[A+=1].Y++;
        init();
    }


	if(keyPressed[K_QUIT])
	{
		g_quitGame = true;
	}

	if(keyPressed[K_RETURN])
	{
		gameState = 5;
		//update(0);
	}


}

void PauseData()
{
	std::ifstream Paused_Screen;
	std::string pause;
	Paused_Screen.open ("Pause.txt");
	while (!Paused_Screen.eof()) 

	if(keyPressed[K_MUSICSCR])

	{
		gameState = 1;
	}
	//Music plays when left shift is pressed
	if(keyPressed[K_MUSIC])
	{
		pressmusic = true;
		menu_music();
	}

}

void render()
{
    // clear previous screen
    cls();

    switch (gameState)
    {
    case 0: MenuScreen();
        break;
    case 1: tetris_standard_map(); render_longlineR(charLocation[0]); render_longline(charLocation[1]);
		break;
	case 2: MusicScreen();
		break;
	case 3: HelpScreen();
		break;
	case 4: Paused_Screen();
		system("pause");
		break;
	case 5: MenuScreen();
		update(0);
		break;
    }

	FPSInfo();
	TIMINGInfo();
	// plays the music if player hits the left shift key
	

    //render test screen code (not efficient at all)
    /*const WORD colors[] =   {
	                            0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	                            0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	                        };*/
    
    // render time taken to calculate this frame

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
    //charLocation.Y++;

    int coordinfox = 0;
    int coordinfoy = 0;

    if (charLocation.Y > 24)
    {
        charLocation.Y--;
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

void FPSInfo()
{
    gotoXY(60, 0);
    std::cout << 1.0 / deltaTime << "fps" << std::endl;
}

void TIMINGInfo()
{
    gotoXY(0, 0);
    std::cout << elapsedTime << "secs" << std::endl;
}

void render_longline(COORD c)
{
    gotoXY(c.X, c.Y);
    cout << BLocksShape();
    cout << BLocksShape();
    cout << BLocksShape();
    cout << BLocksShape();
}

void render_longlineR(COORD c)
{
    gotoXY(c.X, c.Y++);
    cout << BLocksShape();

    gotoXY(c.X, c.Y++);
    cout << BLocksShape();

    gotoXY(c.X, c.Y++);
    cout << BLocksShape();

    gotoXY(c.X, c.Y++);
    cout << BLocksShape();
}

<<<<<<< 360744cdeea9933183c8391ee2251402ed18b0a8
void spawn_new_block(COORD c)
{
   render_longlineR(c);
}

SetArt tetris_standard_map() 
{
    SetArt tmap;

    tmap.tetris_map[height][width];

    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            tmap.tetris_map[i][j] = '.';

            if (j > 0 && j < 13)
            {
                tmap.tetris_map[21][j] = 205;
                tmap.tetris_map[0][j] = 205;    
            }

            tmap.tetris_map[22][j] = '+';

            if (i < 22)
            {
                tmap.tetris_map[i][1] = 186;
                tmap.tetris_map[i][12] = 186;
            }
        }
    }

    tmap.tetris_map[0][1] = 201;
    tmap.tetris_map[0][12] = 187;

    tmap.tetris_map[21][12] = 188;
    tmap.tetris_map[21][1] = 200;
    
    for (int i = 0; i < 23; i++)
    {
        gotoXY(15, 4+i);

        for (int j = 0; j < 14; j++)
        {
            cout << tmap.tetris_map[i][j];
        }
        cout << endl;
    }

    return tmap;
}

char BLocksShape()
{
    const char shape = 'o'; 
    return shape;
}

void testingOnly(int x, int y)
{   
    gotoXY(x, y++);
    cout << BLocksShape();
    cout << BLocksShape();
    cout << BLocksShape();
    cout << BLocksShape();    
}
=======
void render_L(COORD c)
{
	gotoXY(c.X, c.Y++);
	cout <<BLocksShape();

	gotoXY(c.X, c.Y++);
	cout <<BLocksShape();

	gotoXY(c.X, c.Y++);
	cout <<BLocksShape() << BLocksShape();
}

void render_Lr1(COORD c)
{
	gotoXY(c.X,c.Y++);
	cout <<BLocksShape();
	gotoXY(c.X,c.Y++);
	cout << BLocksShape();
	cout << BLocksShape();
	cout << BLocksShape();
}

void render_Lr2(COORD c)
{
	gotoXY(c.X++,c.Y);
	cout << BLocksShape();
	gotoXY(c.X,c.Y++);
	cout << BLocksShape();
	gotoXY(c.X,c.Y++);
	cout << BLocksShape();
	gotoXY(c.X,c.Y++);
	cout << BLocksShape();
}

void render_Lr3(COORD c)
{
	gotoXY(c.X++,c.Y);
	cout << BLocksShape();

	gotoXY(c.X++, c.Y--);
	cout << BLocksShape() << BLocksShape();

	gotoXY(c.X++, c.Y);
	cout << BLocksShape();

}

void render_N(COORD c)
{
	gotoXY(c.X,c.Y++);
	cout << BLocksShape();

	gotoXY(c.X++,c.Y++);
	cout << BLocksShape();
	cout << BLocksShape();

	gotoXY(c.X,c.Y++);
	cout << BLocksShape();
}

void render_Nr1(COORD c)
{
	gotoXY(c.X++,c.Y--);
	cout <<BLocksShape() << BLocksShape();

	gotoXY(c.X++, c.Y);
	cout <<BLocksShape();

	gotoXY(c.X++, c.Y);
	cout <<BLocksShape();
}

void render_S(COORD c)
{
	gotoXY(c.X,c.Y++);
	cout << BLocksShape();
	cout << BLocksShape();

	gotoXY(c.X,c.Y++);
	cout << BLocksShape();
	cout << BLocksShape();
}

void render_T(COORD c)
{
	gotoXY(c.X++,c.Y);
	cout << BLocksShape() << BLocksShape() << BLocksShape();

	gotoXY(c.X,c.Y++);
	gotoXY(c.X,c.Y++);
	cout << BLocksShape();
}

void render_Tr1(COORD c)
{
	gotoXY(c.X,c.Y++);
	cout << BLocksShape();

	gotoXY(c.X--,c.Y);
	cout << BLocksShape();

	gotoXY(c.X,c.Y++);
	cout << BLocksShape();

	gotoXY(c.X++,c.Y);
	gotoXY(c.X++,c.Y);
	cout << BLocksShape();
}

void render_Tr2(COORD c)
{
	gotoXY(c.X,c.Y++);
	cout << BLocksShape();

	gotoXY(c.X--,c.Y);
	gotoXY(c.X++,c.Y);
	cout << BLocksShape() << BLocksShape() << BLocksShape();
}

void render_Tr3(COORD c)
{
	gotoXY(c.X,c.Y++);
	cout << BLocksShape();

	gotoXY(c.X,c.Y++);
	cout << BLocksShape() << BLocksShape();

	gotoXY(c.X,c.Y++);
	cout << BLocksShape();
}

void render_RL(COORD c)
{
	gotoXY(c.X,c.Y++);
	cout << BLocksShape();

	gotoXY(c.X,c.Y++);
	cout << BLocksShape();

	gotoXY(c.X--,c.Y);
	cout << BLocksShape();

	gotoXY(c.X,c.Y++);
	cout << BLocksShape();
}

void render_RLr1(COORD c)
{
	gotoXY(c.X,c.Y++);
	cout << BLocksShape();

	gotoXY(c.X,c.Y++);
	cout << BLocksShape() << BLocksShape() << BLocksShape();
}

void render_RLr2(COORD c)
{
	gotoXY(c.X,c.Y++);
	cout << BLocksShape() << BLocksShape();

	gotoXY(c.X,c.Y++);
	cout << BLocksShape();

	gotoXY(c.X,c.Y++);
	cout << BLocksShape();
}

void render_RLr3(COORD c)
{
	gotoXY(c.X,c.Y++);
	cout << BLocksShape() << BLocksShape() << BLocksShape();

	gotoXY(c.X++,c.Y);

	gotoXY(c.X++,c.Y);

	gotoXY(c.X++,c.Y);
	cout << BLocksShape();
}

void render_RN(COORD c)
{
	gotoXY(c.X,c.Y++);
	cout << BLocksShape();

	gotoXY(c.X--,c.Y) ;
	cout << BLocksShape();

	gotoXY(c.X,c.Y++);
	cout << BLocksShape();

	gotoXY(c.X--,c.Y);
	cout << BLocksShape();
}

void render_RNr1(COORD c)
{
	gotoXY(c.X++,c.Y);
	cout << BLocksShape();
	cout << BLocksShape();

	gotoXY(c.X,c.Y++);

	gotoXY(c.X,c.Y++);
	cout << BLocksShape() << BLocksShape();


}
void spawn_new_block()
{	
	//render_longlineR(charLocation);
	//render_longline(charLocation);

	//render_L(charLocation);
	//render_Lr1(charLocation);
	//render_Lr2(charLocation);
	//render_Lr3(charLocation);

	//render_N(charLocation);
	//render_Nr1(charLocation);

	//render_S(charLocation);

	//render_T(charLocation);
	//render_Tr1(charLocation);
	//render_Tr2(charLocation);
	//render_Tr3(charLocation);

	//render_RL(charLocation);
	//render_RLr1(charLocation);
	//render_RLr2(charLocation);
	//render_RLr3(charLocation);

	//render_RN(charLocation);
	//render_RNr1(charLocation);
}	

>>>>>>> 1a29aecfd9ee90288cf99ccf75518755a7b8d212
