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

const int Long_shapedefaultX = 5;
const int Long_shapedefaultY = 0;

const int Z_shapedefaultX = 5;
const int Z_shapedefaultY = 0;

const int L_shapedefaultX = 4;
const int L_shapedefaultY = 0;

const int Sq_shapedefaultX = 4;
const int Sq_shapedefaultY = 0;

const int T_shapedefaultX = 4;
const int T_shapedefaultY = 0;

/*
int Z_right = 8;
int Z_left = 0;

int L_right = 9;
int L_left = 0;

int Sq_right = 9;
int Sq_left = -1;

int T_right = 9;
int T_left = 0;
*/

int check_l = 3;
int check_Right;
int check_Left;

int check = 0;

const int down = 21;

int rotate[7] = {0, 0, 0, 0, 0, 0, 0};

int l_downward = 0;
int Z_downward = 0;
int L_downward = 0;
int Sq_downward = 0;
int T_downward = 0;

unsigned int randomisation = 0;

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
    /*
    screen.BdLocation.X = 25;       //for border
    screen.BdLocation.Y = 2;*/
    
    blocks.Sq_shape.X = defaultX + Sq_shapedefaultX;         //for square blocks
    blocks.Sq_shape.Y = defaultY + Sq_shapedefaultY;          
    
    blocks.L_shape.X = defaultX + L_shapedefaultX;          //for L-shape
    blocks.L_shape.Y = defaultY + L_shapedefaultY;

    blocks.Z_shape.X = defaultX + Z_shapedefaultX;          //for N-blocks
    blocks.Z_shape.Y = defaultY + Z_shapedefaultY;
    
    blocks.l_shape.X = defaultX + Long_shapedefaultX;          //for l-shape
    blocks.l_shape.Y = defaultY + Long_shapedefaultY;
    
    blocks.T_shape.X = defaultX + T_shapedefaultX;          //for T-shape
    blocks.T_shape.Y = defaultY + T_shapedefaultY;

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
    if(!keyPressed[K_ESCAPE])
    {
    // get the delta time
<<<<<<< f42c40c2adcab91354e2f34e613f9182af718cb4

=======
        elapsedTime += dt;
        deltaTime = dt;
    }
>>>>>>> dd88a835f519b64050d0c5393a72bb9806699e88
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

        // Updating Gameplay screen by pressing buttons
        switch(randomisation)
        {
        case 0:
            longshapeUpdate ();
            break;
/*
        case 1:
            zshapeUpdate();
            break;

        case 2:
            LshapeUpdate();
            break;

        case 3:
            sqshapeUpdate();
            break;

        case 4:
            tshapeUpdate();
            break;*/
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
		}
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
		//lukris();
        renderStartScreen(screen.MmLocation); 
        break;

    case MENU_SCREEN:
        // render main menu
        renderMenu(screen.MmLocation);
        break;

    case GAMEPLAY_SCREEN: 
        //DrawBorder(screen.BdLocation);
        DrawMap(screen.TmLocation);
        initiateMap(screen.TmLocation);

        initiate(blocks.l_shape, blocks.Z_shape, blocks.L_shape, blocks.Sq_shape, blocks.T_shape);
        printBlocks(LONG_TYPE, rotate[LONG_TYPE]);
        cout << l_downward;
        /*
        
        switch(randomisation)
        {
        case 0:
            printBlocks(LONG_TYPE, rotate[LONG_TYPE]);cout << check_l;
            break;

        case 1:
            printBlocks(Z_TYPE, rotate[Z_TYPE]);
            break;

        case 2:
            printBlocks(L_TYPE, rotate[L_TYPE]);
            break;

        case 3:
            printBlocks(Sq_TYPE, rotate[Sq_TYPE]);
            break;

        case 4:
            printBlocks(T_TYPE, rotate[T_TYPE]);
            break;
        }*/

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

void longshapeUpdate ()
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
    }*/

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

void lukris()
{
	ifstream inlukris;
	string hi;

	inlukris.open ("Bg.txt");

	while (!inlukris.eof())
	{
		getline (inlukris,hi);
		cout << hi << endl;
	}

	inlukris.close();
}*/
