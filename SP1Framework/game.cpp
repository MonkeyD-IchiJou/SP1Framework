
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

Location screen;        //coordinates for start, main menu, gameplay, and pause screen 
Blocks blocks;          //coordinates for different blocks
Block block;            //use for individual block

collisionCheck check;

gameState stage;        //check for the gamestate

COORD consoleSize;

int speed;

int extraX = 21;
int extraY = 4;
int downward = 0;

int randomisation;

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

    screen.OptLocation.X = 28;      //for options
    screen.OptLocation.Y = 10;

    screen.PsLocation.X = 28;       // for pause
    screen.PsLocation.Y = 10;  

    screen.TmLocation.X = 30;       //for tetris map
    screen.TmLocation.Y = 3;

    // initiate block thingy here
    // will do randomisation here
    initBlockLocation();
    initCheck();
    random();

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
    switch (stage)
    {
    case START_SCREEN: // For start screen
        elapsedTime += dt;
        deltaTime = dt;
        updateStartScreen();

        break;

    case MENU_SCREEN: // For main menu screen
        elapsedTime += dt;
        deltaTime = dt;

        updateMenu();

        break;

    case GAMEPLAY_SCREEN: // For gameplay screen
        elapsedTime += dt;
        deltaTime = dt;
        speed = static_cast<int>(elapsedTime*10);
        initiate(block.type, block.location);

        if (speed % 5 == 0)
        {
            block.location.Y++;
            downward++;
        }

        switch(block.type)
        {
        case LONG_TYPE:
            updateLONG();
            break;

        case Z_TYPE:
            updateZ();
            break;

        case L_TYPE:
            updateL();
            break;

        case Sq_TYPE:
            updateSq();
            break;

        case T_TYPE:
            updateT();
            break;
        }

    case PAUSE_SCREEN:
        elapsedTime += dt;
        deltaTime = dt;

        pauseScreenUpdate();

        break;

    case OPTION_SCREEN:

        elapsedTime += dt;
        deltaTime = dt;

        optionScreenUpdate();

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
        // render gameplay
        DrawMap(screen.TmLocation);

        printBlock(block.type, block.orientation);
        
        cout << downward;
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
    // render time taken to calculate this frame

    FPSInfo();
    TIMINGInfo();
}

// All the info and updates function below
void FPSInfo()
{
    gotoXY(71, 0);
    colour(Red);
    std::cout << 1.0 / deltaTime << "fps" << std::endl;
}

void TIMINGInfo()
{
    gotoXY(0, 0);
    colour(DarkGreen);
    std::cout << elapsedTime << "secs" << std::endl;
}

void updateMenu()
{
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
}

void updateStartScreen()

{
    if (keyPressed[K_ENTER])
    {
        stage = MENU_SCREEN;
    }
}

void pauseScreenUpdate()
{
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
}

void optionScreenUpdate()
{
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
    }
}

void updateLONG()
{
    switch(block.orientation)
    {
    case FIRST: // I Block

        if (keyPressed[K_LEFT] && check.l > 0 && map[downward][check.l-1] != '1')
        {
            Beep(1440, 30);
            block.location.X--;
            
            check.l--;
        }

        if (keyPressed[K_RIGHT] && check.l < 6 && map[downward][check.l + 4] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.l++;
        }

        if (keyPressed[K_DOWN] && downward < 21 && map[downward][check.l] != '1')
        {
            Beep(1440, 30);
            block.location.Y++;

            downward++;
        }

        if (keyPressed[K_UP])
        {
            block.orientation = SECOND;

            downward++;

            check.l+=2;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 21 || map[downward][check.l] == '1' || map[downward][check.l + 1] == '1' || map[downward][check.l + 2] == '1' || map[downward][check.l + 3] == '1')
        {
            UpdateMap(block.type, block.orientation, downward - 1, check.l);              // bu jie zhi mi
            score(block.type, block.orientation, downward);
            initCheck();
            random();
        }

        break;

    case SECOND:

        if (keyPressed[K_LEFT] && check.l > 0 && map[downward][check.l - 1] != '1' && map[downward -1][check.l - 1] != '1' && map[downward - 2][check.l - 1] != '1' && map[downward -3][check.l - 1] != '1')
        {
            Beep(1440, 30);
            block.location.X--;
            
            check.l--;
        }

        if (keyPressed[K_RIGHT] && check.l < 9 && map[downward][check.l + 1] != '1' && map[downward -1][check.l + 1] != '1' && map[downward - 2][check.l + 1] != '1' && map[downward -3][check.l + 1] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.l++;
        }

        if (keyPressed[K_DOWN])
        {
            Beep(1440, 30);
            block.location.Y++;

            downward++;
        }

        // if user want to rotate, check the surrounding of the blocks

        if(keyPressed[K_UP])
        {
            block.orientation = THIRD;

            downward--;

            check.l-=2;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 21 || map[downward][check.l] == '1')
        {
            UpdateMap(block.type, block.orientation, downward - 1, check.l);              // bu jie zhi mi

            initCheck();
            random();
        }

        break;

    case THIRD:   
        if (keyPressed[K_LEFT] && check.l > 0 && map[downward][check.l-1] != '1')
        {
            Beep(1440, 30);
            block.location.X--;
            
            check.l--;
        }

        if (keyPressed[K_RIGHT] && check.l < 6 && map[downward][check.l + 4] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.l++;
        }

        if (keyPressed[K_DOWN])
        {
            Beep(1440, 30);
            block.location.Y++;
            downward++;
        }

        if (keyPressed[K_UP])
        {
            block.orientation = FOURTH;

            downward += 2;

            check.l++;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 21 || map[downward][check.l] == '1' || map[downward][check.l + 1] == '1' || map[downward][check.l + 2] == '1' || map[downward][check.l + 3] == '1')
        {
            UpdateMap(block.type, block.orientation, downward - 1, check.l);              // bu jie zhi mi

            initCheck();
            random();
        }

        break;

    case FOURTH: // T Block

        if (keyPressed[K_LEFT] && check.l > 0 && map[downward][check.l - 1] != '1' && map[downward -1][check.l - 1] != '1' && map[downward - 2][check.l - 1] != '1' && map[downward -3][check.l - 1] != '1')
        {
            Beep(1440, 30);
            block.location.X--;
            
            check.l--;
        }

        if (keyPressed[K_RIGHT] && check.l < 9 && map[downward][check.l + 1] != '1' && map[downward -1][check.l + 1] != '1' && map[downward - 2][check.l + 1] != '1' && map[downward -3][check.l + 1] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.l++;
        }

        if (keyPressed[K_DOWN])
        {
            Beep(1440, 30);
            block.location.Y++;

            downward++;
        }

        // if user want to rotate, check the surrounding of the blocks
        
        if(keyPressed[K_UP] )
        {
            block.orientation = FIRST;

            downward-=2;

            check.l--;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 21 || map[downward][check.l] == '1')
        {
            UpdateMap(block.type, block.orientation, downward - 1, check.l);              // bu jie zhi mi

            initCheck();
            random();
        }

        break;
    }
}

void updateZ()
{
    switch(block.orientation)
    {
    case FIRST:
        if (keyPressed[K_LEFT] && check.Z > 0 && map[downward][check.Z - 1] != '1')
        {
            Beep(1440, 30);
            block.location.X--;

            check.Z--;
        }

        if (keyPressed[K_RIGHT] && check.Z < 7 && map[downward+1][check.Z + 3] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.Z++;
        }

        if (keyPressed[K_DOWN]  && downward < 21 && map[downward][check.Z] != '1')
        {
            Beep(1440, 30);
            block.location.Y++;

            downward++;
        }

        if (keyPressed[K_UP])
        {
            block.orientation = SECOND;
            //check.Z++;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 20 || map[downward][check.Z] == '1' || map[downward+1][check.Z + 1] == '1' || map[downward+1][check.Z + 2] == '1')
        {
            UpdateMap(block.type, block.orientation, downward, check.Z - 1);             // bu jie zhi mi

            initCheck();
            random();
        }
        break;

    case SECOND:
        if (keyPressed[K_LEFT] && check.Z > 0 && map[downward+1][check.Z-1] != '1' && map[downward][check.Z-1] != '1')
        {
            Beep(1440, 30);
            block.location.X--;

            check.Z--;
        }

        if (keyPressed[K_RIGHT] && check.Z < 8 && map[downward][check.Z+2] != '1' && map[downward-1][check.Z+2] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.Z++;
        }

        if (keyPressed[K_DOWN])
        {
            Beep(1440, 30);
            block.location.Y++;

            downward++;
        }

        if (keyPressed[K_UP])
        {
            block.orientation = FIRST;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 20 || map[downward+1][check.Z] == '1' || map[downward][check.Z+1] == '1')
        {
            UpdateMap(block.type, block.orientation, downward, check.Z - 1);             // bu jie zhi mi

            initCheck();
            random();
        }
        break;
    }
}

void updateL()
{
    switch(block.orientation)
    {
    case FIRST:
        if (keyPressed[K_LEFT] && check.L > 1 && map[downward][check.L-2] != '1' && map[downward+1][check.L-2] != '1')
        {
            Beep(1440, 30);
            block.location.X--;

            check.L--;
        }

        if (keyPressed[K_RIGHT] && check.L < 8 && map[downward+1][check.L + 2] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.L++;
        }

        if (keyPressed[K_DOWN])
        {
            Beep(1440, 30);
            block.location.Y++;

            downward++;
        }

        if (keyPressed[K_UP])
        {
            block.orientation = SECOND;

            downward++;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 20 || map[downward+1][check.L] == '1' || map[downward+1][check.L+1] == '1' || map[downward+1][check.L-1] == '1')
        {
            UpdateMap(block.type, block.orientation, downward, check.L - 1);             // bu jie zhi mi

            initCheck();
            random();
        }
        break;

    case SECOND:
        if (keyPressed[K_LEFT] && check.L > 0 && map[downward][check.L - 2] != '1' && map[downward + 1][check.L - 2] != '1' && map[downward + 2][check.L - 2] != '1')
        {
            Beep(1440, 30);
            block.location.X--;

            check.L--;
        }

        if (keyPressed[K_RIGHT] && check.L < 8 && map[downward][check.L + 2] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.L++;
        }

        if (keyPressed[K_DOWN])
        {
            Beep(1440, 30);
            block.location.Y++;

            downward++;
        }

        if (keyPressed[K_UP])
        {
            block.orientation = THIRD;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 20 || map[downward+1][check.L] == '1')
        {
            UpdateMap(block.type, block.orientation, downward - 1, check.L);             // bu jie zhi mi

            initCheck();
            random();
        }
        break;

    case THIRD:
        if (keyPressed[K_LEFT] && check.L > 1 && map[downward][check.L-2] != '1')
        {
            Beep(1440, 30);
            block.location.X--;

            check.L--;
        }

        if (keyPressed[K_RIGHT] && check.L < 8 && map[downward+1][check.L + 2] != '1' && map[downward][check.L + 2] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.L++;
        }

        if (keyPressed[K_DOWN])
        {
            Beep(1440, 30);
            block.location.Y++;

            downward++;
        }

        if (keyPressed[K_UP])
        {
            block.orientation = FOURTH;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 20 || map[downward][check.L] == '1' || map[downward+1][check.L+1] == '1' || map[downward][check.L-1] == '1')
        {
            UpdateMap(block.type, block.orientation, downward, check.L - 1);             // bu jie zhi mi

            initCheck();
            random();
        }
        break;

    case FOURTH:
        if (keyPressed[K_LEFT] && check.L > 1 && map[downward + 1][check.L - 2] != '1' && map[downward-1][check.L - 2] != '1' && map[downward][check.L - 2] != '1')
        {
            Beep(1440, 30);
            block.location.X--;

            check.L--;
        }

        if (keyPressed[K_RIGHT] && check.L < 9 && map[downward+1][check.L + 2] != '1' && map[downward][check.L + 2] != '1' && map[downward-1][check.L + 2] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.L++;
        }

        if (keyPressed[K_DOWN])
        {
            Beep(1440, 30);
            block.location.Y++;

            downward++;
        }

        if (keyPressed[K_UP])
        {
            block.orientation = FIRST;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 20 || map[downward+1][check.L] == '1' || map[downward+1][check.L-1] == '1')
        {
            UpdateMap(block.type, block.orientation, downward, check.L - 1);             // bu jie zhi mi

            initCheck();
            random();
        }
        break;
    }
}

void updateSq()
{
    switch(block.orientation)
    {
    case FIRST:
        if (keyPressed[K_LEFT] && check.Sq > 0 && map[downward + 1][check.Sq - 1] != '1' && map[downward][check.Sq - 1] != '1')
        {
            Beep(1440, 30);
            block.location.X--;

            check.Sq--;
        }

        if (keyPressed[K_RIGHT] && check.Sq < 8 && map[downward + 1][check.Sq + 2] != '1' && map[downward][check.Sq + 2] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.Sq++;
        }

        if (keyPressed[K_DOWN] && downward < 21 && map[downward][check.Sq] != '1')
        {
            Beep(1440, 30);
            block.location.Y++;

            downward++;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 20 || map[downward + 1][check.Sq] == '1' || map[downward + 1][check.Sq + 1] == '1')
        {
            UpdateMap(block.type, block.orientation, downward, check.Sq - 1);             // bu jie zhi mi

            initCheck();
            random();
        }
        break;
    }
}

void updateT()
{
    switch(block.orientation)
    {
    case FIRST:
        if (keyPressed[K_LEFT] && check.T > 0 && map[downward][check.T-1] != '1' && map[downward+1][check.T-1] != '1')
        {
            Beep(1440, 30);
            block.location.X--;

            check.T--;
        }

        if (keyPressed[K_RIGHT] && check.T < 7 && map[downward+1][check.T + 3] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.T++;
        }

        if (keyPressed[K_DOWN]  && downward < 21 && map[downward][check.T] != '1')
        {
            Beep(1440, 30);
            block.location.Y++;

            downward++;
        }

        if (keyPressed[K_UP])
        {
            block.orientation = SECOND;

            check.T++;

            downward++;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 20 || map[downward+1][check.T] == '1' || map[downward+1][check.T+2] == '1' || map[downward+1][check.T+1] == '1')
        {
            UpdateMap(block.type, block.orientation, downward - 1, check.T);             // bu jie zhi mi

            initCheck();
            random();
        }
        break;

    case SECOND:
        if (keyPressed[K_LEFT] && check.T > 0 && map[downward][check.T-1] != '1' && map[downward][check.T] != '1' && map[downward][check.T-1] != '1')
        {
            Beep(1440, 30);
            block.location.X--;

            check.T--;
        }

        if (keyPressed[K_RIGHT] && check.T < 8 && map[downward][check.T+2] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.T++;
        }

        if (keyPressed[K_DOWN])
        {
            Beep(1440, 30);
            block.location.Y++;

            downward++;
        }

        if (keyPressed[K_UP])
        {
            block.orientation = THIRD;

            check.T--;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 20 || map[downward+1][check.T] == '1' || map[downward][check.T+1] == '1')
        {
            UpdateMap(block.type, block.orientation, downward - 1, check.T);             // bu jie zhi mi

            initCheck();
            random();
        }
        break;

    case THIRD:
        if (keyPressed[K_LEFT] && check.T > 0 && map[downward][check.T-1] != '1')
        {
            Beep(1440, 30);
            block.location.X--;

            check.T--;
        }

        if (keyPressed[K_RIGHT] && check.T < 7 && map[downward][check.T+3] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.T++;
        }

        if (keyPressed[K_DOWN])
        {
            Beep(1440, 30);
            block.location.Y++;

            downward++;
        }

        if (keyPressed[K_UP])
        {
            block.orientation = FOURTH;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 20 || map[downward+1][check.T+1] == '1' || map[downward][check.T] == '1' || map[downward][check.T+2] == '1')
        {
            UpdateMap(block.type, block.orientation, downward - 1, check.T);             // bu jie zhi mi

            initCheck();
            random();
        }
        break;

    case FOURTH:
        if (keyPressed[K_LEFT] && check.T > 0 && check.T < 8 && map[downward-1][check.T-1] != '1')
        {
            Beep(1440, 30);
            block.location.X--;

            check.T--;
        }

        if (keyPressed[K_RIGHT] && check.T < 8 && map[downward+1][check.T+2] != '1' && map[downward][check.T+2] != '1' && map[downward-1][check.T+2] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.T++;
        }

        if (keyPressed[K_DOWN])
        {
            Beep(1440, 30);
            block.location.Y++;

            downward++;
        }

        if (keyPressed[K_UP])
        {
            block.orientation = FIRST;

            downward--;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 20 || map[downward][check.T] == '1' || map[downward + 1][check.T + 1] == '1')
        {
            UpdateMap(block.type, block.orientation, downward-1, check.T);             // bu jie zhi mi

            initCheck();
            random();
        }
        break;
    }
}

void updateREVZ()
{

}

void initCheck()
{
    check.l = 3;
    check.Z = 4;
    check.L = 5;
    check.Sq = 4;
    check.T = 4;

    check.wallcollision = 0;

    downward = 0;
}

void initBlockLocation()
{
    blocks.l_shape.X = 35;
    blocks.l_shape.Y = 3;
    
    blocks.L_shape.X = 35;
    blocks.L_shape.Y = 4;

    blocks.Sq_shape.X = 34;
    blocks.Sq_shape.Y = 3;

    blocks.T_shape.X = 35;
    blocks.T_shape.Y = 4;

    blocks.Z_shape.X = 35;
    blocks.Z_shape.Y = 3;

	//blocks.RZ_shape.X = 35;
    //blocks.RZ_shape.Y = 3;
}

void random()
{
    block.orientation = FIRST;

    srand (time(NULL));
<<<<<<< Updated upstream
    randomisation =rand()%5;
=======
    randomisation = 4;//rand()%5;
>>>>>>> Stashed changes

    switch(randomisation)
    {
    case 0:
        block.type = LONG_TYPE;
        block.location.X = blocks.l_shape.X;
        block.location.Y = blocks.l_shape.Y;
        break;

    case 1:
        block.type = Z_TYPE;
        block.location.X = blocks.Z_shape.X;
        block.location.Y = blocks.Z_shape.Y;
        break;

    case 2:
        block.type = L_TYPE;
        block.location.X = blocks.L_shape.X;
        block.location.Y = blocks.L_shape.Y;
        break;
        
    case 3:
        block.type = Sq_TYPE;
        block.location.X = blocks.Sq_shape.X;
        block.location.Y = blocks.Sq_shape.Y;
        break;

    case 4:
        block.type = T_TYPE;
        block.location.X = blocks.T_shape.X;
        block.location.Y = blocks.T_shape.Y;
        break;
        /*
	case 5:
		block.type = Z_REV_TYPE;
        block.location.X = blocks.RZ_shape.X;
        block.location.Y = blocks.RZ_shape.Y;
        break;*/
    }
}

