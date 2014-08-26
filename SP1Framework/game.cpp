// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include "tetris.h"
#include "Gameplay.h"

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];

Location screen;
Blocks blocks;

COORD consoleSize;

gameState stage;

int x, y;
int speed;

const int defaultX = 30;
const int defaultY = 0;

const int Long_shapedefaultX = 4;
const int Long_shapedefaultY = 0;

int Long_right;
int Long_left;

const int down = 21;

int rotate[7] = {0, 0, 0, 0, 0, 0, 0};

void init()
{
    // Set precision for floating point output
    std::cout << std::fixed << std::setprecision(3);

    SetConsoleTitle(L"Tetris");

    // Sets the console size, this is the biggest so far.
    setConsoleSize(79, 28);

    // Get console width and height
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */   

    /* get the number of character cells in the current buffer */ 
    GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );

    // set the size for the game
    consoleSize.X = csbi.srWindow.Right + 1;
    consoleSize.Y = csbi.srWindow.Bottom + 1;
    
    // default location.
    screen.MmLocation.X = 28;       //for main menu
    screen.MmLocation.Y = 5;

	screen.OptLocation.X = 29;      //for options
	screen.OptLocation.Y = 10;

	screen.PsLocation.X = 28;       // for pause
	screen.PsLocation.Y = 10;  

    screen.TmLocation.X = defaultX;       //for tetris map
    screen.TmLocation.Y = defaultY;

    screen.BdLocation.X = 25;       //for border
    screen.BdLocation.Y = 2;
    /*
    blocks.Sq_shape.X = defaultX;         //for square blocks
    blocks.Sq_shape.Y = defaultY+20;          

    blocks.L_shape.X = defaultX;          //for L-shape
    blocks.L_shape.Y = defaultY;

    blocks.Z_shape.X = defaultX;          //for N-blocks
    blocks.Z_shape.Y = defaultY+5;
    */
    blocks.l_shape.X = defaultX + Long_shapedefaultX;          //for l-shape
    blocks.l_shape.Y = defaultY + Long_shapedefaultY;
    /*
    blocks.T_shape.X = defaultX;          //for T-shape
    blocks.T_shape.Y = defaultY+15;*/

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
	keyPressed[K_SPACE] = isKeyPressed(VK_SPACE);
    keyPressed[K_ENTER] = isKeyPressed(VK_RETURN);
}

void update(double dt)
{
    // get the delta time

    switch (stage)
    {
    case START_SCREEN: // For start screen
		 elapsedTime += dt;
         deltaTime = dt;
        if (keyPressed[K_ENTER])
        {
            stage = MENU_SCREEN;
        }

        break;

    case MENU_SCREEN: // For main menu screen
		 elapsedTime += dt;
         deltaTime = dt;
        if (keyPressed[K_UP] && screen.MmLocation.Y > 5)
        {
            Beep(1440, 30);
            screen.MmLocation.Y -= 5; 
        }

        if (keyPressed[K_DOWN] && screen.MmLocation.Y < 20)
        {
            Beep(1440, 30);
            screen.MmLocation.Y += 5; 
        }

        if (keyPressed[K_ENTER] && screen.MmLocation.Y == 5)
        {
            stage = GAMEPLAY_SCREEN;
        }

        if (keyPressed[K_ENTER] && screen.MmLocation.Y == 10)
        {
            stage = OPTION_SCREEN;
        }

		if (keyPressed[K_ENTER] && screen.MmLocation.Y == 15)
        {
            stage = START_SCREEN;
        }

		if (keyPressed[K_ENTER] && screen.MmLocation.Y == 20)
		{
			g_quitGame = true;
		}
        break;

    case GAMEPLAY_SCREEN: // For gameplay screen
        elapsedTime += dt;
        deltaTime = dt;
        speed = static_cast<int>(elapsedTime*10);
        
        if (speed % 5  == 0 && DataBlocks[LONG_TYPE][rotate[LONG_TYPE]][1].Y != defaultY + down) // DataBlocks[LONG_TYPE][0][1] == blocks.l_shape.Y // second coordinate
        {
            blocks.l_shape.Y++;
        }

        // Updating Gameplay screen by pressing buttons

        // for long shape
        if (rotate[LONG_TYPE] == 0)
        {
            Long_right = 7;
            Long_left = 1;
        }

        if (rotate[LONG_TYPE] == 1)
        {
            Long_right = 9;
            Long_left = 0;
        } 

        if (rotate[LONG_TYPE] == 2)
        {
            Long_right = 7;
            Long_left = 1;
        } 

        if (rotate[LONG_TYPE] == 3)
        {
            Long_right = 9;
            Long_left = 0;
        }

        if (keyPressed[K_UP] && DataBlocks[LONG_TYPE][rotate[LONG_TYPE]][1].Y > 0) // Rotation button
        {
            Beep(1440, 30);
            rotate[LONG_TYPE]++;

            if (rotate[LONG_TYPE] == 4)
            {
                rotate[LONG_TYPE] = 0;
            }
        }

        if (keyPressed[K_LEFT] && DataBlocks[LONG_TYPE][rotate[LONG_TYPE]][1].X != defaultX + Long_left)
        {
            Beep(1440, 30);
            blocks.l_shape.X--;
        }
        
        if (keyPressed[K_DOWN] && DataBlocks[LONG_TYPE][rotate[LONG_TYPE]][1].Y != defaultY + down)
        {
            Beep(1440, 30);
            blocks.l_shape.Y++; 
        }

        if (keyPressed[K_RIGHT] && DataBlocks[LONG_TYPE][rotate[LONG_TYPE]][1].X != defaultX + Long_right)
        {
            Beep(1440, 30);
            blocks.l_shape.X++;
        }

        if (DataBlocks[LONG_TYPE][rotate[LONG_TYPE]][1].Y >= 21)
        {
            blocks.l_shape.X = defaultX + Long_shapedefaultX;          //for l-shape
            blocks.l_shape.Y = defaultY + Long_shapedefaultY;
            map[21][3] = '1';
        }

        /*
        // for z-shape
        if (keyPressed[K_UP] && blocks.Z_shape.Y > 0) // Rotation button
        {
            rotate[Z_TYPE]++;

            if (rotate[Z_TYPE]== 5)
            {
                rotate[Z_TYPE] = 1;
            }
        }

        if (keyPressed[K_LEFT] && blocks.Z_shape.X > screen.TmLocation.X)
        {
            blocks.Z_shape.X--;
        }
        
        if (keyPressed[K_DOWN] && blocks.Z_shape.Y < consoleSize.Y - 1)
        {
            Beep(1440, 30);
            blocks.Z_shape.Y++; 
        }

        if (keyPressed[K_RIGHT] && blocks.Z_shape.X < screen.TmLocation.X + 12)
        {
            blocks.Z_shape.X++;
        }

        // for L-shape
        if (keyPressed[K_UP] && blocks.L_shape.Y > 0) // Rotation button
        {
            rotate[L_TYPE]++;

            if (rotate[L_TYPE] == 5)
            {
                rotate[L_TYPE] = 1;
            }
        }

        if (keyPressed[K_LEFT] && blocks.L_shape.X > screen.TmLocation.X)
        {
            blocks.L_shape.X--;
        }
        
        if (keyPressed[K_DOWN] && blocks.L_shape.Y < consoleSize.Y - 1)
        {
            blocks.L_shape.Y++; 
        }

        if (keyPressed[K_RIGHT] && blocks.L_shape.X < screen.TmLocation.X + 12)
        {
            blocks.L_shape.X++;
        }

        // For square-shape
        if (keyPressed[K_UP] && blocks.Sq_shape.Y > 0) // Rotation button
        {
            rotate[Sq_TYPE]++;

            if (rotate[Sq_TYPE] == 5)
            {
                rotate[Sq_TYPE] = 1;
            }
        }

        if (keyPressed[K_LEFT] && blocks.Sq_shape.X > screen.TmLocation.X)
        {
            blocks.Sq_shape.X--;
        }
        
        if (keyPressed[K_DOWN] && blocks.Sq_shape.Y < consoleSize.Y - 1)
        {
            blocks.Sq_shape.Y++; 
        }

        if (keyPressed[K_RIGHT] && blocks.Sq_shape.X < screen.TmLocation.X + 12)
        {
            blocks.Sq_shape.X++;
        }

        // for T-shape
        if (keyPressed[K_UP] && blocks.T_shape.Y > 0) // Rotation button
        {
            rotate[4]++;

            if (rotate[T_TYPE] == 5)
            {
                rotate[T_TYPE] = 1;
            }
        }

        if (keyPressed[K_LEFT] && blocks.T_shape.X > screen.TmLocation.X)
        {
            blocks.T_shape.X--;
        }
        
        if (keyPressed[K_DOWN] && blocks.T_shape.Y < consoleSize.Y - 1)
        {
            blocks.T_shape.Y++; 
        }

        if (keyPressed[K_RIGHT] && blocks.T_shape.X < screen.TmLocation.X + 12)
        {
            blocks.T_shape.X++;
        }

        // quits the game if player hits the escape key

        if (keyPressed[K_ESCAPE])
        {
            g_quitGame = true;
        }

        if(keyPressed[K_SPACE])
		{
			stage = PAUSE_SCREEN;
		}

		break;

	case PAUSE_SCREEN:

		if (keyPressed[K_UP] && screen.PsLocation.Y > 10)
        {
            Beep(1440, 30);
            screen.PsLocation.Y -= 5; 
        }

        if (keyPressed[K_DOWN] && screen.PsLocation.Y < 15)
        {
            Beep(1440, 30);
            screen.PsLocation.Y += 5; 
        }

        if (keyPressed[K_ENTER] && screen.PsLocation.Y == 10)
        {
            stage = GAMEPLAY_SCREEN;
        }

        if (keyPressed[K_ENTER] && screen.PsLocation.Y == 15)
        {
            g_quitGame = true;
        }

        break;

	// for options
    case OPTION_SCREEN:
        elapsedTime += dt;
        deltaTime = dt;
        if (keyPressed[K_UP] && screen.OptLocation.Y > 10)
	    {
	        Beep(1440, 30);
		    screen.OptLocation.Y -= 5; 
        }

        if (keyPressed[K_DOWN] && screen.OptLocation.Y < 15)
	    {
		    Beep(1440, 30);
		    screen.OptLocation.Y += 5; 
	    }

	    if (keyPressed[K_ENTER] && screen.OptLocation.Y == 10)
        {
			stage = GAMEPLAY_SCREEN;
		}

		if (keyPressed[K_ENTER] && screen.OptLocation.Y == 15)
        {
			stage = MENU_SCREEN;
		}*/
    }
}

void render()
{
    // clear previous screen
    cls();

    // render game
    switch (stage)
    {
    case START_SCREEN: 
        // render Start screen
        renderStartScreen(screen.MmLocation); 
        break;

    case MENU_SCREEN:
        // render main menu
        renderMenu(screen.MmLocation);
        break;

    case GAMEPLAY_SCREEN: 
        //DrawBorder(screen.BdLocation);
        DrawMap(screen.TmLocation);

        initiate(blocks.l_shape, blocks.Z_shape, blocks.L_shape, blocks.Sq_shape, blocks.T_shape);
        printBlocks(LONG_TYPE, rotate[LONG_TYPE]);
        break;

	case OPTION_SCREEN:
		renderOption(screen.OptLocation);
		break;

	case PAUSE_SCREEN:
		renderPause(screen.PsLocation);
		break;
    }

    //render the game
    
    //render test screen code (not efficient at all)
    /*const WORD colors[] =   {
	                        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	                        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	                        };*/
    // render time taken to calculate this frame

    FPSInfo();
    TIMINGInfo();
}

void FPSInfo()
{
	colour(0xF);
    gotoXY(71, 0);
    //colour(0xC);
    std::cout << 1.0 / deltaTime << "fps" << std::endl;
}

void TIMINGInfo()
{
	//colour(0xC);
    gotoXY(0, 0);
    //colour(0x2);
    std::cout << elapsedTime << "secs" << std::endl;
}