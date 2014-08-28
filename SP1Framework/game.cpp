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

    screen.TmLocation.X = 30;       //for tetris map
    screen.TmLocation.Y = 3;

    blocks.l_shape.X = 35;
    blocks.l_shape.Y = 3;

    blocks.L_shape.X = 35;
    blocks.L_shape.Y = 3;

    blocks.Sq_shape.X = 35;
    blocks.Sq_shape.Y = 3;

    blocks.T_shape.X = 35;
    blocks.T_shape.Y = 3;

    blocks.Z_shape.X = 35;
    blocks.Z_shape.Y = 3;

    // initiate block thingy here
    // will do randomisation here
    block.orientation = FIRST;

    block.location.X = blocks.l_shape.X;
    block.location.Y = blocks.l_shape.Y;

    block.type = LONG_TYPE;

    initCheck();
    check.wallcollision = 0;
    downward = 0;
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

        initiate(block.type, block.orientation, block.location);

        switch(block.type)
        {
        case LONG_TYPE:
            updateLONG();
            break;

        case Z_TYPE:
            updateZ();
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

        printBlock(block.type, block.orientation, check.wallcollision);
        cout << check.l;
        
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
    const WORD colors[] =   {
        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
    };
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
    case FIRST:

        if (keyPressed[K_LEFT] && check.l > 0)
        {
            Beep(1440, 30);
            block.location.X--;
            
            check.l--;
        }

        if (keyPressed[K_RIGHT] && check.l < 6)
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
            block.orientation = SECOND;

            downward++;

            check.l+=2;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 21)
        {
            UpdateMap(block.orientation, downward - 1, check.l);             // bu jie zhi mi

            init();
        }

        if (map[downward][check.l] == '1')
        {
            UpdateMap(block.orientation, downward - 1, check.l);

            init();
        }

        break;

    case SECOND:

        if (keyPressed[K_LEFT] && check.l > 0)
        {
            Beep(1440, 30);
            block.location.X--;
            
            check.l--;
        }

        if (keyPressed[K_RIGHT] && check.l < 9)
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
            block.orientation = THIRD;
            downward--;

            check.l-=2;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 21)
        {
            UpdateMap(block.orientation, downward - 1, check.l);             // bu jie zhi mi

            init();
        }

        if (map[downward][check.l] == '1')
        {
            UpdateMap(block.orientation, downward - 1, check.l);

            init();
        }

        break;

    case THIRD:

        if (keyPressed[K_LEFT] && check.l > 0)
        {
            Beep(1440, 30);
            block.location.X--;
            
            check.l--;
        }

        if (keyPressed[K_RIGHT] && check.l < 6)
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

            downward+=2;

            check.l+=2;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 21)
        {
            UpdateMap(block.orientation, downward - 1, check.l);             // bu jie zhi mi

            init();
        }

        if (map[downward][check.l] == '1')
        {
            UpdateMap(block.orientation, downward - 1, check.l);

            init();
        }

        break;

    case FOURTH:

        if (keyPressed[K_LEFT] && check.l > 1)
        {
            Beep(1440, 30);
            block.location.X--;
            
            check.l--;
        }

        if (keyPressed[K_RIGHT] && check.l < 10)
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
            block.orientation = FIRST;

            downward-=2;

            check.l-=2;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 21)
        {
            UpdateMap(block.orientation, downward - 1, check.l);             // bu jie zhi mi

            init();
        }

        if (map[downward][check.l] == '1')
        {
            UpdateMap(block.orientation, downward - 1, check.l);

            init();
        }

        break;
    }
}

void updateZ()
{
    switch(block.orientation)
    {
    case FIRST:
        // enter key here
        break;

    case SECOND:
        // enter e=key here
        break;

    case THIRD:
        // enter key here
        break;

    case FOURTH:
        // enter key here
        break;
    }
}

/*void longshapeUpdate()
{
    /*
    // for long shape

    if (speed % 5  == 0 )
    {
        blocks.l_shape.Y++;
        l_downward++;
    }

    // Rotation button
    if (keyPressed[K_UP]) 
    {
        Beep(1440, 30);

        rotate[LONG_TYPE]++;

        if (rotate[LONG_TYPE] == 1)
        {
            check_l++;
            l_downward+=2;
            check_Right = 1;
        }

        else if (rotate[LONG_TYPE] == 2)
        {
            check_l-=2;
            l_downward-=2;
            check_Right = 4;
        }

        else if (rotate[LONG_TYPE] == 3)
        {
            check_l+=2;
            l_downward++;
            check_Right = 1;
        }

        else if (rotate[LONG_TYPE] == 4)
        {
            rotate[LONG_TYPE] = 0;
            check_l--;
            l_downward--;
            check_Right = 4;
        }
    }

    //  for different orientation, different coordinate to detect collision
    if (keyPressed[K_LEFT] && map[l_downward][check_l + check_Left] != '2' && map[l_downward][check_l + check_Left] != '1')
    {
        Beep(1440, 30);
        blocks.l_shape.X--;
        check_l--;
    }

    if (keyPressed[K_DOWN])
    {
        Beep(1440, 30);
        blocks.l_shape.Y++;
        l_downward++;
    }

    if (keyPressed[K_RIGHT] && map[l_downward][check_l + check_Right] != '2' && map[l_downward][check_l + check_Right] != '1')
    {
        Beep(1440, 30);
        blocks.l_shape.X++;
        check_l++;
    }
    
    // if blocks touches 1 in the map, update the map
    if (map[l_downward][check_l] == '1' || map[l_downward][check_l+1] == '1' || map[l_downward][check_l+2] == '1' || map[l_downward][check_l+3] == '1')                            

    // if blocks touches reach 1 in the map, update the map
    if (map[l_downward][check_l] == '1')                            
    {
        blocks.l_shape.X = defaultX + Long_shapedefaultX;          //for l-shape
        blocks.l_shape.Y = defaultY + Long_shapedefaultY;

        drawShape(rotate[LONG_TYPE], l_downward-1, check_l);

        if (rotate[LONG_TYPE] == 0)
        {
            l_downward = 0;
            check_l = 3;
        }

        else if (rotate[LONG_TYPE] == 1)
        {
            l_downward = 2;
            check_l = 4;
        }

        else if (rotate[LONG_TYPE] == 2)
        {
            l_downward = 0;
            check_l = 2;
        }

        else if (rotate[LONG_TYPE] == 3)
        {
            l_downward = 1;
            check_l = 4;
        }
    }

    // if the blocks reach the floor, update the map
    else if (l_downward >= 21)
    {
        blocks.l_shape.X = defaultX + Long_shapedefaultX;          //for l-shape
        blocks.l_shape.Y = defaultY + Long_shapedefaultY;

        drawShape(rotate[LONG_TYPE], l_downward, check_l);

        if (rotate[LONG_TYPE] == 0)
        {
            l_downward = 0;
            check_l = 3;
        }

        else if (rotate[LONG_TYPE] == 1)
        {
            l_downward = 2;
            check_l = 4;
        }

        else if (rotate[LONG_TYPE] == 2)
        {
            l_downward = 0;
            check_l = 2;
        }

        else if (rotate[LONG_TYPE] == 3)
        {
            l_downward = 1;
            check_l = 4;
        }
    }

    switch (rotate[LONG_TYPE])
    {
    case FIRST:

        check_Right = 5;
        check_Left = 0;

        if (speed % 5  == 0 )
        {
            blocks.l_shape.Y++;

            l_downward++;
        }

        if (keyPressed[K_LEFT] && map[l_downward][check_l + check_Left] != '3' && map[l_downward][check_l + check_Left] != '1')
        {
            Beep(1440, 30);

            blocks.l_shape.X--;

            check_l--;
        }

        if (keyPressed[K_RIGHT] && map[l_downward][check_l + check_Right] != '3' && map[l_downward][check_l + check_Right] != '1')
        {
            Beep(1440, 30);

            blocks.l_shape.X++;

            check_l++;
        }

        if (keyPressed[K_DOWN] && map[l_downward][check_l] != '2' && map[l_downward][check_l+1] != '1' && map[l_downward][check_l+2] != '1' && map[l_downward][check_l+3] != '1' && map[l_downward][check_l+4] != '1')
        {
            Beep(1440, 30);
            blocks.l_shape.Y++;

            l_downward++;
        }

        //check for collision
        if (map[l_downward][check_l] == '2' || map[l_downward][check_l+1] == '1' || map[l_downward][check_l+2] == '1' || map[l_downward][check_l+3] == '1' || map[l_downward][check_l+4] == '1')                            
        {
            blocks.l_shape.X = defaultX + Long_shapedefaultX;          //for l-shape
            blocks.l_shape.Y = defaultY + Long_shapedefaultY;
        
            drawShape(rotate[LONG_TYPE], l_downward-1, check_l+1);

            l_downward = 0;
            check_l = 3;
        }

        // if press up, go to next orientation
        if (keyPressed[K_UP]) 
        {
            Beep(1440, 30);

            rotate[LONG_TYPE] = 1;

            l_downward+=2;
            check_l++;
        }
        break;

    case SECOND:

        check_Right = 2;
        check_Left = 0;

        if (speed % 5  == 0)
        {
            blocks.l_shape.Y++;
            l_downward++;
        }

        if (keyPressed[K_LEFT] && map[l_downward][check_l + check_Left] != '3' && map[l_downward][check_l + check_Left] != '1' && map[l_downward-1][check_l + check_Left] != '1' && map[l_downward-2][check_l + check_Left] != '1' && map[l_downward-3][check_l + check_Left] != '1')
        {
            Beep(1440, 30);

            blocks.l_shape.X--;
            check_l--;
        }

        if (keyPressed[K_RIGHT] && map[l_downward][check_l + check_Right] != '3' && map[l_downward][check_l + check_Right] != '1' && map[l_downward-1][check_l + check_Right] != '1' && map[l_downward-2][check_l + check_Right] != '1' && map[l_downward-3][check_l + check_Right] != '1')
        {
            Beep(1440, 30);

            blocks.l_shape.X++;
            check_l++;
        }

        if (keyPressed[K_DOWN] && map[l_downward][check_l] != '2' && map[l_downward][check_l+1] != '1' )
        {
            Beep(1440, 30);

            blocks.l_shape.Y++;
            l_downward++;
        }

        // check for collision
        if (map[l_downward][check_l] == '2' || map[l_downward][check_l+1] == '1' )                            
        {
            blocks.l_shape.X = defaultX + Long_shapedefaultX;          //for l-shape
            blocks.l_shape.Y = defaultY + Long_shapedefaultY;
        
            drawShape(rotate[LONG_TYPE], l_downward-1, check_l+1);

            l_downward = 2;
            check_l = 4;
        }

        // rotate when pressed UP
        if (keyPressed[K_UP] && map[l_downward][check_l-1] != '3' && map[l_downward][check_l] != '3' && map[l_downward][check_l+2] != '3' && map[l_downward][check_l-1] != '1' && map[l_downward][check_l] != '1' && map[l_downward][check_l+2] != '1') 
        {
            Beep(1440, 30);

            rotate[LONG_TYPE] = THIRD;

            l_downward-=2;
            check_l-=2;
        }
        break;

    case THIRD:

        check_Right = 5;
        check_Left = 0;

        if (speed % 5  == 0 )
        {
            blocks.l_shape.Y++;
            l_downward++;
        }

        if (keyPressed[K_LEFT] && map[l_downward][check_l + check_Left] != '3' && map[l_downward][check_l + check_Left] != '1')
        {
            Beep(1440, 30);

            blocks.l_shape.X--;
            check_l--;
        }

        if (keyPressed[K_RIGHT] && map[l_downward][check_l + check_Right] != '3' && map[l_downward][check_l + check_Right] != '1')
        {
            Beep(1440, 30);

            blocks.l_shape.X++;
            check_l++;
        }

        if (keyPressed[K_DOWN] && map[l_downward][check_l] != '2' && map[l_downward][check_l+1] != '1' && map[l_downward][check_l+2] != '1' && map[l_downward][check_l+3] != '1' && map[l_downward][check_l+4] != '1')
        {
            Beep(1440, 30);

            blocks.l_shape.Y++;
            l_downward++;
        }

        //check for collision
        if (map[l_downward][check_l] == '2' || map[l_downward][check_l+1] == '1' || map[l_downward][check_l+2] == '1' || map[l_downward][check_l+3] == '1' || map[l_downward][check_l+4] == '1')                            
        {
            blocks.l_shape.X = defaultX + Long_shapedefaultX;          //for l-shape
            blocks.l_shape.Y = defaultY + Long_shapedefaultY;
        
            drawShape(rotate[LONG_TYPE], l_downward-1, check_l+1);

            l_downward = 0;
            check_l = 2;
        }

        // Press UP to rotate
        if (keyPressed[K_UP]) 
        {
            Beep(1440, 30);

            rotate[LONG_TYPE] = FOURTH;

            l_downward+=2;
            check_l+=2;
        }

        break;

    case FOURTH:

        check_Right = 2;
        check_Left = 0;

        if (speed % 5  == 0 )
        {
            blocks.l_shape.Y++;
            l_downward++;
        }

        if (keyPressed[K_LEFT] && map[l_downward][check_l + check_Left] != '3' && map[l_downward][check_l + check_Left] != '1')
        {
            Beep(1440, 30);

            blocks.l_shape.X--;
            check_l--;
        }

        if (keyPressed[K_RIGHT] && map[l_downward][check_l + check_Right] != '3' && map[l_downward][check_l + check_Right] != '1')
        {
            Beep(1440, 30);

            blocks.l_shape.X++;
            check_l++;
        }

        if (keyPressed[K_DOWN] && map[l_downward][check_l] != '2' && map[l_downward][check_l+1] != '1' )
        {
            Beep(1440, 30);

            blocks.l_shape.Y++;
            l_downward++;
        }

        //check for collision
        if (map[l_downward][check_l] == '2' || map[l_downward][check_l+1] == '1' )                           
        {
            blocks.l_shape.X = defaultX + Long_shapedefaultX;          //for l-shape
            blocks.l_shape.Y = defaultY + Long_shapedefaultY;
        
            drawShape(rotate[LONG_TYPE], l_downward-1, check_l+1);

            l_downward = 1;
            check_l = 4;
        }

        //Press UP to rotate
        if (keyPressed[K_UP] && map[l_downward][check_l-1] != '3' && map[l_downward][check_l] != '3' && map[l_downward][check_l+3] != '3' && map[l_downward][check_l+2] != '3' && map[l_downward][check_l-1] != '1' && map[l_downward][check_l] != '1' && map[l_downward][check_l+2] != '1')  
        {
            Beep(1440, 30);
            
            rotate[LONG_TYPE] = FIRST;
            l_downward-=2;
            check_l--;
        }

        break;
    }
}

/*
void zshapeUpdate()
{
    // for z-shape

    if (speed % 5  == 0 )
    {
        blocks.Z_shape.Y++;
        Z_downward++;
    }

    if (keyPressed[K_UP] && DataBlocks[Z_TYPE][rotate[Z_TYPE]][0].Y > 0) // Rotation button
    {
        rotate[Z_TYPE]++;

        if (rotate[Z_TYPE]== 4)
        {
            rotate[Z_TYPE] = 0;
        }
    }

    if (keyPressed[K_LEFT] && DataBlocks[Z_TYPE][rotate[Z_TYPE]][0].X != DataMap[0][0].X - Z_left)
    {
        blocks.Z_shape.X--;
    }

    if (keyPressed[K_DOWN] && DataBlocks[Z_TYPE][rotate[Z_TYPE]][3].Y != defaultY + down)
    {
        Beep(1440, 30);
        blocks.Z_shape.Y++; 
        Z_downward++;
    }

    if (keyPressed[K_RIGHT] && DataBlocks[Z_TYPE][rotate[Z_TYPE]][3].X != DataMap[0][0].X + Z_right)
    {
        blocks.Z_shape.X++;
    }

    if (Z_downward >= 21)
    {
        blocks.Z_shape.X = defaultX + Z_shapedefaultX;          //for Z-shape
        blocks.Z_shape.Y = defaultY + Z_shapedefaultY;
        Z_downward = 1;

        randomisation = 4;
    }
}

void LshapeUpdate()
{
    // for L-shape

    if (speed % 5  == 0 )
    {
        blocks.L_shape.Y++;
        L_downward++;
    }

    if (keyPressed[K_UP] && DataBlocks[L_TYPE][rotate[L_TYPE]][0].Y > 0) // Rotation button
    {
        rotate[L_TYPE]++;

        if (rotate[L_TYPE] == 4)
        {
            rotate[L_TYPE] = 0;
        }
    }

    if (keyPressed[K_LEFT] && DataBlocks[L_TYPE][rotate[L_TYPE]][1].X != DataMap[0][0].X - L_left)
    {
        blocks.L_shape.X--;
    }

    if (keyPressed[K_DOWN] && DataBlocks[L_TYPE][rotate[L_TYPE]][3].Y != defaultY + down)
    {
        blocks.L_shape.Y++; 
        L_downward++;
    }

    if (keyPressed[K_RIGHT] && DataBlocks[L_TYPE][rotate[L_TYPE]][3].X != DataMap[0][0].X + L_right)
    {
        blocks.L_shape.X++;
    }

    if(rotate[L_TYPE] == 2)
    {
        L_right = 8;
        L_left = -1;
    }

    else
    {
        L_right = 9;
        L_left = 0;
    }

    if (L_downward >= 21)
    {
        blocks.L_shape.X = defaultX + L_shapedefaultX;          //for L-shape
        blocks.L_shape.Y = defaultY + L_shapedefaultY;
        L_downward = 0;

        randomisation = 1;
    }
}

void sqshapeUpdate()
{
    // For square-shape

    if (speed % 5  == 0 )
    {
        blocks.Sq_shape.Y++;
        Sq_downward++;
    }

    if (keyPressed[K_UP] && DataBlocks[Sq_TYPE][rotate[Sq_TYPE]][0].Y > 0) // Rotation button
    {
        rotate[Sq_TYPE]++;

        if (rotate[Sq_TYPE] == 4)
        {
            rotate[Sq_TYPE] = 0;
        }
    }

    if (keyPressed[K_LEFT] && DataBlocks[Sq_TYPE][rotate[Sq_TYPE]][1].X != DataMap[0][0].X - Sq_left)
    {
        blocks.Sq_shape.X--;
    }

    if (keyPressed[K_DOWN] && DataBlocks[Sq_TYPE][rotate[Sq_TYPE]][3].Y != defaultY + down)
    {
        blocks.Sq_shape.Y++; 
        Sq_downward++;
    }

    if (keyPressed[K_RIGHT] && DataBlocks[Sq_TYPE][rotate[Sq_TYPE]][3].X != DataMap[0][0].X + Sq_right)
    {
        blocks.Sq_shape.X++;
    }

    if (Sq_downward >= 21)
    {
        blocks.Sq_shape.X = defaultX + Sq_shapedefaultX;          //for sq-shape
        blocks.Sq_shape.Y = defaultY + Sq_shapedefaultY;
        Sq_downward = 0;

        randomisation = 2;
    }
}

void tshapeUpdate()
{
    // for T-shape

    if (speed % 5  == 0 )
    {
        blocks.T_shape.Y++;
        T_downward++;
    }
    if (keyPressed[K_UP] && DataBlocks[T_TYPE][rotate[T_TYPE]][0].Y > 0) // Rotation button
    {
        rotate[4]++;

        if (rotate[T_TYPE] == 4)
        {
            rotate[T_TYPE] = 0;
        }
    }

    if (keyPressed[K_LEFT] && DataBlocks[T_TYPE][rotate[T_TYPE]][1].X != DataMap[0][0].X - T_left)
    {
        blocks.T_shape.X--;
    }

    if (keyPressed[K_DOWN] && DataBlocks[T_TYPE][rotate[T_TYPE]][3].Y != defaultY + down)
    {
        blocks.T_shape.Y++; 
        T_downward++;
    }

    if (keyPressed[K_RIGHT] && DataBlocks[T_TYPE][rotate[T_TYPE]][3].X != DataMap[0][0].X + T_right)
    {
        blocks.T_shape.X++;
    }

    if(rotate[T_TYPE] == 1)
    {
        T_right = 8;
        T_left = 0;
    }

    else if(rotate[T_TYPE] == 3)
    {
        T_right = 9;
        T_left = -1;
    }

    else
    {
        T_right = 9;
        T_left = 0;
    }

    if (T_downward >= 21)
    {
        blocks.T_shape.X = defaultX + T_shapedefaultX;          //for T-shape
        blocks.T_shape.Y = defaultY + T_shapedefaultY;
        T_downward = 0;

        randomisation = 3;
    }
}
*/


void initCheck()
{
    check.l = 3;
}