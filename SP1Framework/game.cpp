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
    screen.TmLocation.Y = 5;

    blocks.Sq_shape.X = 36;         //for square blocks
    blocks.Sq_shape.Y = 5;          

    blocks.L_shape.X = 36;          //for L-shape
    blocks.L_shape.Y = 5;

    blocks.Z_shape.X = 36;          //for N-blocks
    blocks.Z_shape.Y = 5;

    

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

        if (speed % 5  == 0)
        {
            blocks.Sq_shape.Y++;
        }

        // Updating Gameplay screen by pressing buttons
        if (keyPressed[K_UP] && blocks.Sq_shape.Y > 0) // Rotation button
        {
            Beep(1440, 30);
        }

        if (keyPressed[K_LEFT] && blocks.Sq_shape.X > 0)
        {
            Beep(1440, 30);
            blocks.Sq_shape.X-=2;
        }
        
        if (keyPressed[K_DOWN] && blocks.Sq_shape.Y < consoleSize.Y - 1)
        {
            Beep(1440, 30);
            blocks.Sq_shape.Y+=2; 
        }

        if (keyPressed[K_RIGHT] && blocks.Sq_shape.X < consoleSize.X - 1)
        {
            Beep(1440, 30);
            blocks.Sq_shape.X+=2;
        }

        // quits the game if player hits the escape key
        if (keyPressed[K_ESCAPE])
        {
            g_quitGame = true;
        }
        
        if (blocks.Sq_shape.Y > 22)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    map[8+i][8+j] = Sq[i][j];
                }
            }
            
            blocks.Sq_shape.X = 36;
            blocks.Sq_shape.Y = 5;
        }
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
        DrawMap(screen.TmLocation);
        //DrawArray(screen.TmLocation);
        sqBlocks(blocks.Sq_shape);
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

void Map()
{

}