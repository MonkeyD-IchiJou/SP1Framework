// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];

Location screen;
Blocks blocks;

COORD consoleSize;

gameState stage;

int x, y;
int speed;

int defaultX = 32;
int defaultY = 3;

int switchornot = 1;
int switchornot1 = 1;
int switchornot2 = 1;

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
    screen.MmLocation.X = 27;       //for main menu
    screen.MmLocation.Y = 10;

    screen.TmLocation.X = 26;       //for tetris map
    screen.TmLocation.Y = 3;

    screen.BdLocation.X = 25;       //for border
    screen.BdLocation.Y = 2;

    blocks.Sq_shape.X = defaultX;         //for square blocks
    blocks.Sq_shape.Y = defaultY;          

    blocks.L_shape.X = defaultX;          //for L-shape
    blocks.L_shape.Y = defaultY+10;

    blocks.Z_shape.X = defaultX;          //for N-blocks
    blocks.Z_shape.Y = defaultY+5;

    blocks.l_shape.X = defaultX;          //for l-shape
    blocks.l_shape.Y = defaultY;

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
}

void update(double dt)
{
    // get the delta time
    elapsedTime += dt;
    deltaTime = dt;

    switch (stage)
    {
    case START_SCREEN: // For start screen

        if (keyPressed[K_ENTER])
        {
            stage = MENU_SCREEN;
        }

        break;

    case MENU_SCREEN: // For main menu screen

        if (keyPressed[K_UP] && screen.MmLocation.Y > 10)
        {
            Beep(1440, 30);
            screen.MmLocation.Y -= 5; 
        }

        if (keyPressed[K_DOWN] && screen.MmLocation.Y < 15)
        {
            Beep(1440, 30);
            screen.MmLocation.Y += 5; 
        }

        if (keyPressed[K_ENTER] && screen.MmLocation.Y == 10)
        {
            stage = GAMEPLAY_SCREEN;
        }

        if (keyPressed[K_ENTER] && screen.MmLocation.Y == 15)
        {
            stage = START_SCREEN;
        }

        break;

    case GAMEPLAY_SCREEN: // For gameplay screen
        
        speed = static_cast<int>(elapsedTime*10);
        /*
        if (speed % 5  == 0)
        {
            blocks.l_shape.Y++;
        }*/

        // Updating Gameplay screen by pressing buttons

        // for long shape
        if (keyPressed[K_UP] && blocks.l_shape.Y > 0) // Rotation button
        {
            Beep(1440, 30);
            switchornot++;

            if (switchornot == 5)
            {
                switchornot = 1;
            }
        }

        if (keyPressed[K_LEFT] && blocks.l_shape.X > screen.TmLocation.X)
        {
            Beep(1440, 30);
            blocks.l_shape.X--;
        }
        
        if (keyPressed[K_DOWN] && blocks.l_shape.Y < consoleSize.Y - 1)
        {
            Beep(1440, 30);
            blocks.l_shape.Y++; 
        }

        if (keyPressed[K_RIGHT] && blocks.l_shape.X < screen.TmLocation.X + 12)
        {
            Beep(1440, 30);
            blocks.l_shape.X++;
        }

        
        // for z-shape
        if (keyPressed[K_UP] && blocks.Z_shape.Y > 0) // Rotation button
        {
            Beep(1440, 30);
            switchornot1++;

            if (switchornot1 == 5)
            {
                switchornot1 = 1;
            }
        }

        if (keyPressed[K_LEFT] && blocks.Z_shape.X > screen.TmLocation.X)
        {
            Beep(1440, 30);
            blocks.Z_shape.X--;
        }
        
        if (keyPressed[K_DOWN] && blocks.Z_shape.Y < consoleSize.Y - 1)
        {
            Beep(1440, 30);
            blocks.Z_shape.Y++; 
        }

        if (keyPressed[K_RIGHT] && blocks.Z_shape.X < screen.TmLocation.X + 12)
        {
            Beep(1440, 30);
            blocks.Z_shape.X++;
        }

        // for L-shape
        if (keyPressed[K_UP] && blocks.L_shape.Y > 0) // Rotation button
        {
            Beep(1440, 30);
            switchornot2++;

            if (switchornot2 == 5)
            {
                switchornot2 = 1;
            }
        }

        if (keyPressed[K_LEFT] && blocks.L_shape.X > screen.TmLocation.X)
        {
            Beep(1440, 30);
            blocks.L_shape.X--;
        }
        
        if (keyPressed[K_DOWN] && blocks.L_shape.Y < consoleSize.Y - 1)
        {
            Beep(1440, 30);
            blocks.L_shape.Y++; 
        }

        if (keyPressed[K_RIGHT] && blocks.L_shape.X < screen.TmLocation.X + 12)
        {
            Beep(1440, 30);
            blocks.L_shape.X++;
        }

        // quits the game if player hits the escape key

        if (keyPressed[K_ESCAPE])
        {
            g_quitGame = true;
        }
        /*
        if (blocks.l_shape.Y > 22)
        {
            blocks.l_shape.X = 32;
            blocks.l_shape.Y = 5;
        }*/

		break;
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
        //DrawMap(screen.TmLocation);
        initiate(blocks.l_shape, blocks.Z_shape, blocks.L_shape);

        print_l_blocks(switchornot);
        print_Z_blocks(switchornot1);

        break;
    }

    //render the game
    /*
    //render test screen code (not efficient at all)
    const WORD colors[] =   {
	                        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	                        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	                        };*/

    // render time taken to calculate this frame

    FPSInfo();
    TIMINGInfo();
}

void FPSInfo()
{
    gotoXY(71, 0);
    std::cout << 1.0 / deltaTime << "fps" << std::endl;
}

void TIMINGInfo()
{
    gotoXY(0, 0);
    std::cout << elapsedTime << "secs" << std::endl;
}