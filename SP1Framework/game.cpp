// This is the main file for the game logic and function
//
//
#include "game.h"
#include "tetris.h"
#include "Gameplay.h"
#include "Framework\console.h"

// Console size, width by height
COORD ConsoleSize = {60, 26};

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];

stages gameState = HIGHSCORE_MODE;

COORD consoleSize;

// Game specific variables here
COORD charLocation;

Location screen;        //coordinates for start, main menu, gameplay, and pause screen 
Blocks blocks;          //coordinates for different blocks
Block block;            //use for individual block
BlocksType store;       //use for store different kind of blocks
BlocksType *temporaryStore = new BlocksType;      
storeNswitch count;     //check and store the block
blockcolor color;       //blocks colors
collisionCheck check;   //use to check for collision (left and right of the blocks)

int speed;

int downward = 0;

int randomisation;

int checkscore[height];

int randomblock[65535];
int next = 0;

bool dunturnup = true;

void init()
{
    // Set precision for floating point output
    elapsedTime = 0.0;

    initConsole(ConsoleSize, "SP1 Framework");

    charLocation.X = ConsoleSize.X / 2;
    charLocation.Y = ConsoleSize.Y / 2;

    screen.ScLocation.X = ConsoleSize.X / 2;
    screen.ScLocation.Y = ConsoleSize.Y / 2;

    screen.MmLocation.X = ConsoleSize.X / 2;
    screen.MmLocation.Y = ConsoleSize.Y / 2;

    screen.BdLocation.X = 30;
    screen.BdLocation.Y = 3;

    screen.ShowScore.X = 25;
    screen.ShowScore.Y = 22;

    screen.FinalResult.X = ConsoleSize.X / 2 - 10;
    screen.FinalResult.Y = ConsoleSize.Y / 2;

    // initiate block thingy here
    // will do randomisation here
    screen.NLineLocation.X = ConsoleSize.X / 2;
    screen.NLineLocation.Y = ConsoleSize.Y / 2;

    screen.StoreLineLocation.X = ConsoleSize.X / 2;
    screen.StoreLineLocation.Y = ConsoleSize.Y / 2 - 10;

    count.storeornot = false;
    count.storeOredi = false;

    count.switchcount = 0;

    blockcolorinit();
    temporaryStore = &store;

    srand (time(NULL));
    for (int i = 0; i < 65535; i++)
    { 
        randomblock[i] = rand()%5;
    }

    initBlockLocation();
    initCheck();
    random();
    /*
    switch(gameState)
    {
    case START_SCREEN:
        
        screen.ScLocation.X = ConsoleSize.X / 2;
        screen.ScLocation.Y = ConsoleSize.Y / 2;
        break;

    case MAIN_MENU:

        screen.MmLocation.X = ConsoleSize.X / 2;
        screen.MmLocation.Y = ConsoleSize.Y / 2;
        break;

    case HIGHSCORE_MODE:

        screen.NLineLocation.X = ConsoleSize.X / 2;
        screen.NLineLocation.Y = ConsoleSize.Y / 2;

        screen.StoreLineLocation.X = ConsoleSize.X / 2;
        screen.StoreLineLocation.Y = ConsoleSize.Y / 2 - 10;

        count.storeornot = false;
        count.storeOredi = false;

        count.switchcount = 0;

        blockcolorinit();

        // initiate block thingy here
        // will do randomisation here

        srand (time(NULL));
        for (int i = 0; i < 65535; i++)
        { 
            randomblock[i] = rand()%5;
        }

        initBlockLocation();
        initCheck();
        random();

        break;

    case PAUSE_SCREEN:

        screen.PsLocation.X = ConsoleSize.X / 2;
        screen.PsLocation.Y = ConsoleSize.Y / 2;
        break;
    }*/
}

void shutdown()
{
    // Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    shutDownConsole();
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
    keyPressed[K_SHIFT] = isKeyPressed(VK_SHIFT);
}

void update(double dt)
{
    if (gameState != PAUSE_SCREEN)
    {
        elapsedTime += dt;
        deltaTime = dt;
    }

    initiate(block.type, block.location);
    speed = static_cast<int>(elapsedTime*500);     //500 -> 10; 1000 -> 4; 1000 -> 2; 1000 -> 1

    switch(gameState)
    {
    case START_SCREEN:

        if (keyPressed[K_ENTER])
        {
            Sleep(100);
            gameState = MAIN_MENU;
        }
        break;

    case MAIN_MENU:

        if (keyPressed[K_ENTER])
        {
            gameState = HIGHSCORE_MODE;
        }
        break;

    case HIGHSCORE_MODE:

        //if blocks reach the top of the map, game end
        for (int i = 0; i < width; i++)
        {
            if (map[0][i] == '1')
            {
                gameState = END_GAME;
            }
        }

        if (!keyPressed[K_UP])
        {
            dunturnup = true;
        }

        int changeSpeed;
        int divide;
        /*
        if (score >= 0 && score < 999)      // beginer speed
        {
            changeSpeed = 500;
            divide = 10;
        }

        else if (score >= 1000 && score < 4999)
        {
            changeSpeed = 1000;
            divide = 4;
        }

        else if (score >= 5000 && score < 14999)
        {
            changeSpeed = 1000;
            divide = 2;
        }

        else if (score >= 15000)
        {
            changeSpeed = 1000;
            divide = 1;
        }*/

        speed = static_cast<int>(elapsedTime*changeSpeed);

        if (speed % divide == 0 && !keyPressed[K_DOWN])
        {
            block.location.Y++;
            downward++;
        }

        if (keyPressed[K_DOWN])
        {
            block.location.Y++;
            downward++;
        }

        if (keyPressed[K_SHIFT] && count.storeornot == false && count.switchcount % 2 == 0)
        {
            Sleep(150);

            count.switchcount++;

            *temporaryStore = block.type;

            next++;
            initCheck();
            random();

            count.storeornot = true;
            count.storeOredi = true;

        }

        else if (keyPressed[K_SHIFT] && count.storeOredi == true && count.switchcount % 2 == 0)
        {
            Sleep(150);

            count.switchcount--; // unlimited switchcount if i put minus sign here

            random();
            initCheck();
            initBlockLocation();

            BlocksType currentblock = block.type;
            block.type = *temporaryStore;
            *temporaryStore = currentblock;

            switch(block.type)
            {
            case LONG_TYPE:
                block.color = color.l;
                break;

            case Z_TYPE:
                block.color = color.Z;
                break;

            case L_TYPE:
                block.color = color.L;
                break;

            case Sq_TYPE:
                block.color = color.Sq;
                break;

            case T_TYPE:
                block.color = color.T;
                break;
            }
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

        case Z_REV_TYPE:
            updateREVZ();
            break;

        case L_REV_TYPE:
            updateREVL();
            break;
        }   

        if (keyPressed[K_ESCAPE])
        {
            Sleep(100);
            gameState = PAUSE_SCREEN;
        }
        break;  

    case PAUSE_SCREEN:
        if (keyPressed[K_ENTER])
        {
            init();
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < width-1; j++)
                {
                    map[i][j] = '0';
                    checkscore[i] = 0;
                }
            }

            score = 0;
            gameState = HIGHSCORE_MODE;
        }

        if (keyPressed[K_SHIFT])
        {
            Sleep(100);
            gameState = HIGHSCORE_MODE;
        }
        break;

    case END_GAME:
        if (keyPressed[K_ENTER])
        {
            init();
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < width-1; j++)
                {
                    map[i][j] = '0';
                    checkscore[i] = 0;
                }
            }

            score = 0;
            gameState = HIGHSCORE_MODE;
        }
    }
}

void render()
{    
    // Clears the buffer with this colour attribute
    clearBuffer(0x1A);

    //TIMINGInfo(charLocation); //show timing

    // Set up sample colours, and output shadings
    const WORD colors[] =   {
	                        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	                        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	                        };
    
    switch(gameState)
    {
    case START_SCREEN:

        renderStartScreen(screen.ScLocation);
        break;

    case MAIN_MENU:

        renderMenu(screen.MmLocation);
        break;

    case HIGHSCORE_MODE:

        //DrawBorder(screen.BdLocation);
        DrawMap(screen.TmLocation, block.type);
        printBlock(block.type, block.orientation, block.color);
        showNextBlock(screen.NLineLocation, block.type);
        storeBlock(screen.StoreLineLocation, count.storeornot, *temporaryStore);
        showScore(screen.ShowScore, score);
        writeToBuffer(block.location, (char)check.RZ);
        break;

    case PAUSE_SCREEN:

        RenderPauseScreen(screen.PsLocation);
        break;

    case END_GAME:

        renderResult(screen.FinalResult);
        break;
    }

    flushBufferToConsole();
}

void FPSinfo(COORD c)
{
    // displays the framerate
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << 1.0 / deltaTime << "fps";
    c.X = ConsoleSize.X-9;
    c.Y = 0;
    writeToBuffer(c, ss.str());
}

void TIMINGInfo(COORD c)
{
    // displays the elapsed time
    std::ostringstream ss;
    ss.str("");
    ss << elapsedTime << "secs";
    c.X = 0;
    c.Y = 0;
    writeToBuffer(c, ss.str(), 0x59);
}

void updateLONG()
{
    switch(block.orientation)
    {
    case FIRST:     // First orientation

        if (keyPressed[K_LEFT] && check.l > 0 && map[downward][check.l-1] == '0')
        {
            block.location.X--;
            
            check.l--;
        }

        else if (keyPressed[K_RIGHT] && check.l < 6 && map[downward][check.l + 4] == '0')
        {
            block.location.X++;

            check.l++;
        }

        if (keyPressed[K_UP] && dunturnup == true && (downward == 21 || map[downward+1][check.l] != '0' || map[downward+1][check.l + 1] != '0' || map[downward+1][check.l + 2] != '0' || map[downward+1][check.l + 3] != '0'))
        {
            Sleep(100);
            check.l+=2;

            block.location.Y--;
            downward--;
            
            block.orientation = SECOND;

            dunturnup = false;
        }

        else if (keyPressed[K_UP] && dunturnup == true)
        {
            Sleep(100);
            check.l+=2;

            block.orientation = SECOND;

            dunturnup = false;
        }


        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        // or when the user press space

        else if (downward-1 >= 22 || map[downward][check.l] != '0' || map[downward][check.l + 1] != '0' || map[downward][check.l + 2] != '0' || map[downward][check.l + 3] != '0')
        {
            UpdateMap(block.type, block.orientation, downward-1, check.l);              // bu jie zhi mi

            receive (block.type, block.orientation, downward-1);
            calculate (downward-1);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}
        }

        break;

    case SECOND:    // Second orientation

        if (keyPressed[K_LEFT] && check.l > 0 && map[downward][check.l - 1] == '0' && map[downward -1][check.l - 1] == '0' && map[downward - 2][check.l - 1] == '0' && map[downward + 1][check.l - 1] == '0')
        {
            block.location.X--;
            
            check.l--;
        }

        else if (keyPressed[K_RIGHT] && check.l < 9 && map[downward][check.l + 1] == '0' && map[downward -1][check.l + 1] == '0' && map[downward - 2][check.l + 1] == '0' && map[downward + 1][check.l + 1] == '0')
        {
            block.location.X++;

            check.l++;
        }

        // if user want to rotate, check the surrounding of the blocks
        
        if(keyPressed[K_UP] && dunturnup == true && check.l < 2 && (map[downward - 1][check.l + 1] != '0'|| map[downward - 2][check.l + 1] != '0' || map[downward + 1][check.l + 1] != '0' ||
                                                                    map[downward - 1][check.l + 2] != '0' || map[downward -2][check.l + 2] != '0' || map[downward + 1][check.l + 2] != '0' ||
                                                                    map[downward - 1][check.l + 3] != '0' || map[downward -2][check.l + 3] != '0' || map[downward + 1][check.l + 3] != '0'))
        {
            dunturnup = true;
        }
        
        else if (keyPressed[K_UP] && dunturnup == true && check.l > 6 && (map[downward + 1][check.l - 1] != '0' || map[downward -1][check.l - 1] != '0' || map[downward - 2][check.l - 1] != '0' ||
                                                                          map[downward + 1][check.l - 2] != '0' || map[downward -1][check.l - 2] != '0' || map[downward - 2][check.l - 2] != '0' || 
                                                                          map[downward + 1][check.l - 3] != '0' || map[downward -1][check.l - 3] != '0' || map[downward - 2][check.l - 3] != '0'))
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && dunturnup == true  && (map[downward + 1][check.l - 1] != '0' || map[downward -1][check.l - 1] != '0' || map[downward - 2][check.l - 1] != '0' ||
                                                            map[downward + 1][check.l - 2] != '0' || map[downward -1][check.l - 2] != '0' || map[downward - 2][check.l - 2] != '0' ||
                                                            map[downward + 1][check.l - 3] != '0' || map[downward -1][check.l - 3] != '0' || map[downward - 2][check.l - 3] != '0')&&
                                                           (map[downward - 1][check.l + 1] != '0'|| map[downward - 2][check.l + 1] != '0' || map[downward + 1][check.l + 1] != '0' ||
                                                            map[downward - 1][check.l + 2] != '0' || map[downward -2][check.l + 2] != '0' || map[downward + 1][check.l + 2] != '0' ||
                                                            map[downward - 1][check.l + 3] != '0' || map[downward -2][check.l + 3] != '0' || map[downward + 1][check.l + 3] != '0'))
        {
            dunturnup = true;
        }

        else if(keyPressed[K_UP] && dunturnup == true && check.l < 2)
        {
            Sleep(100);
            block.location.X+=2;

            block.orientation = FIRST;

            dunturnup = false;
        }
        
        else if(keyPressed[K_UP] && dunturnup == true &&(map[downward + 1][check.l - 1] != '0' || map[downward -1][check.l - 1] != '0' || map[downward - 2][check.l - 1] != '0'))
        {
            Sleep(100);
            block.location.X+=2;

            block.orientation = FIRST;

            dunturnup = false;
        }
        
        else if (keyPressed[K_UP] && dunturnup == true && (map[downward + 1][check.l - 2] != '0' || map[downward -1][check.l - 2] != '0' || map[downward - 2][check.l - 2] != '0'))
        {
            Sleep(100);
            block.location.X++;
            check.l --;

            block.orientation = FIRST;

            dunturnup = false;
        }

        else if(keyPressed[K_UP] && dunturnup == true && check.l > 8)
        {
            Sleep(100);
            block.location.X--;
            check.l-=3;

            block.orientation = FIRST;

            dunturnup = false;
        }
        
        else if (keyPressed[K_UP] && dunturnup == true && check.l > 2 && (map[downward -1][check.l + 1] != '0' || map[downward - 2][check.l + 1] != '0' || map[downward + 1][check.l + 1] != '0'))  // check for right side obstacle
        {
            Sleep(100);
            block.location.X--;
            check.l-=3;

            block.orientation = FIRST;

            dunturnup = false;
        }
        
        else if(keyPressed[K_UP] && dunturnup == true)
        {
            Sleep(100); 
            check.l-=2;

            block.orientation = FIRST;

            dunturnup = false;
        }
        
        

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        else if (downward >= 22 || map[downward+1][check.l] != '0')
        {
            UpdateMap(block.type, block.orientation, downward, check.l);              // bu jie zhi mi
            receive (block.type, block.orientation, downward);
            calculate (downward);

            next++; 

            initCheck();
            random(); 

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}
        }

        break;
    }
}

void updateZ()
{
    switch(block.orientation)
    {
    case FIRST:
        if (keyPressed[K_LEFT] && check.Z > 0 && map[downward][check.Z - 1] == '0' && map[downward+1][check.Z] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.Z--;
        }

        else if (keyPressed[K_RIGHT] && check.Z < 7 && map[downward+1][check.Z + 3] == '0' && map[downward][check.Z + 2] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.Z++;
        }

        else if (keyPressed[K_UP] && dunturnup == true)
        {
            Sleep(100);

            block.orientation = SECOND;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        else if (downward >= 22 || map[downward][check.Z] != '0' || map[downward+1][check.Z + 1] != '0' || map[downward+1][check.Z + 2] != '0')
        {
            UpdateMap(block.type, block.orientation, downward, check.Z - 1);             // bu jie zhi mi
            receive (block.type, block.orientation, downward);
            calculate (downward);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}
        }
        break;

    case SECOND:
        if (keyPressed[K_LEFT] && check.Z > 0 && map[downward+1][check.Z-1] == '0' && map[downward][check.Z-1] == '0' && map[downward-1][check.Z] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.Z--;
        }

        else if (keyPressed[K_RIGHT] && check.Z < 8 && map[downward][check.Z+2] == '0' && map[downward+1][check.Z+1] == '0' && map[downward-1][check.Z + 2] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.Z++;
        }

        // if user want to rotate the block, check the surrounding whether possible for him to rotate or not
        else if (keyPressed[K_UP] && dunturnup == true  && check.Z > 7 && (map[downward+1][check.Z-1] != '0' || map[downward][check.Z-1] != '0' || map[downward-1][check.Z] != '0'))
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && dunturnup == true  && check.Z < 2 && (map[downward][check.Z+2] != '0' || map[downward+1][check.Z+1] != '0' || map[downward-1][check.Z + 3] != '0'))
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && dunturnup == true  &&  (map[downward][check.Z+2] != '0' || map[downward+1][check.Z+1] != '0' || map[downward-1][check.Z + 3] != '0') &&
                                                            (map[downward+1][check.Z-1] != '0' || map[downward][check.Z-1] != '0' || map[downward-1][check.Z] != '0'))
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && dunturnup == true  && (map[downward][check.Z+2] != '0' || map[downward+1][check.Z+1] != '0' || map[downward-1][check.Z + 3] != '0'))
        {
            Sleep(100);
            block.location.X--;
            check.Z--;

            block.orientation = FIRST;

            dunturnup = false;
        }

        else if (keyPressed[K_UP] && dunturnup == true && check.Z == 8)
        {
            Sleep(100);
            block.location.X--;
            check.Z--;

            block.orientation = FIRST;

            dunturnup = false;
        }

        else if (keyPressed[K_UP] && dunturnup == true)
        {
            Sleep(100);

            block.orientation = FIRST;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        else if (downward >= 22 || map[downward+1][check.Z] != '0' || map[downward][check.Z+1] != '0')
        {
            UpdateMap(block.type, block.orientation, downward, check.Z - 1);             // bu jie zhi mi
            receive (block.type, block.orientation, downward);
            calculate (downward);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}
        }
        break;
    }
}

void updateL()
{
    switch(block.orientation)
    {
    case FIRST:
        if (keyPressed[K_LEFT] && check.L > 0 && map[downward][check.L-1] == '0' && map[downward-1][check.L-1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.L--;
        }

        else if (keyPressed[K_RIGHT] && check.L < 7 && map[downward][check.L + 3] == '0' && map[downward + 1][check.L + 1] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.L++;
        }

        // check surrounding before rotate
        else if (keyPressed[K_UP] && dunturnup == true)
        {
            Sleep(100);
            check.L++;

            block.orientation = SECOND;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        else if (downward >= 22 || map[downward+1][check.L] != '0' || map[downward+1][check.L+1] != '0' || map[downward+1][check.L+2] != '0')
        {
            UpdateMap(block.type, block.orientation, downward, check.L);             
            receive (block.type, block.orientation, downward);
            calculate (downward);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}
        }
        break;

    case SECOND:
        if (keyPressed[K_LEFT] && check.L > 0 && map[downward][check.L - 1] == '0' && map[downward - 1][check.L - 1] == '0' && map[downward + 1][check.L - 1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.L--;
        }

        else if (keyPressed[K_RIGHT] && check.L < 8 && map[downward][check.L + 1] == '0' && map[downward - 1][check.L + 2] == '0' && map[downward + 1][check.L+1] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.L++;
        }

        // check surrounding before rotate
        else if (keyPressed[K_UP] && dunturnup == true && map[downward + 1][check.L + 2] != '0' &&  ((map[downward][check.L - 1] != '0' || map[downward - 1][check.L - 1] != '0' || map[downward + 1][check.L - 1] != '0') || 
                                                                                                    (map[downward][check.L - 2] != '0' || map[downward - 1][check.L - 2] != '0' || map[downward + 1][check.L - 2] != '0' )))
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && map[downward][check.L+1] != '0')
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && dunturnup == true && ( map[downward][check.L - 1] != '0' && map[downward - 1][check.L - 1] != '0' && map[downward + 1][check.L - 1] != '0'))
        {
            Sleep(100);
            block.location.X++;

            block.orientation = THIRD;

            dunturnup = false;
        }

        
        
        else if (keyPressed[K_UP] && dunturnup == true && check.L <1 )
        {
            Sleep(100);
            block.location.X++;

            block.orientation = THIRD;

            dunturnup = false;
        }

        else if (keyPressed[K_UP] && dunturnup == true)
        {
            Sleep(100);
            check.L--;

            block.orientation = THIRD;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom

        else if (downward >= 22 || map[downward+1][check.L] != '0' || map[downward-1][check.L+1] != '0')
        {
            UpdateMap(block.type, block.orientation, downward-1, check.L);             // bu jie zhi mi
            receive (block.type, block.orientation, downward);
            calculate (downward);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}
        }
        break;

    case THIRD:
        if (keyPressed[K_LEFT] && check.L > 0 && map[downward][check.L-1] == '0' && map[downward+1][check.L+1] == '0' )
        {
            Beep(1440, 30);
            block.location.X--;

            check.L--;
        }

        else if (keyPressed[K_RIGHT] && check.L < 7 && map[downward+1][check.L + 3] == '0' && map[downward][check.L + 3] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.L++;
        }

        else if (keyPressed[K_UP] && dunturnup == true)
        {
            Sleep(100);

            block.orientation = FOURTH;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        else if (downward >= 22 || map[downward][check.L] != '0' || map[downward][check.L+1] != '0' || map[downward+1][check.L + 2] != '0')
        {
            UpdateMap(block.type, block.orientation, downward, check.L);             // bu jie zhi mi
            receive (block.type, block.orientation, downward);
            calculate (downward);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}
        }
        break;

    case FOURTH:
        if (keyPressed[K_LEFT] && check.L > 0 && map[downward + 1][check.L - 1] == '0' && map[downward-1][check.L ] == '0' && map[downward][check.L ] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.L--;
        }

        else if (keyPressed[K_RIGHT] && check.L < 8 && map[downward+1][check.L + 2] == '0' && map[downward][check.L + 2] == '0' && map[downward-1][check.L + 2] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.L++;
        }
        
        // check for surrounding when rotate
        else if (keyPressed[K_UP] && dunturnup == true && check.L < 1 && map[downward][check.L + 2] != '0')
        {
            dunturnup = true;
        }
        
        else if (keyPressed[K_UP] && dunturnup == true && (map[downward][check.L + 2] != '0'|| map[downward-1][check.L + 2] != '0' || map[downward+1][check.L + 2] != '0') && 
                                                          (map[downward + 1][check.L - 1] != '0' || map[downward-1][check.L] != '0' || map[downward][check.L] != '0'))
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && dunturnup == true && (check.L > 7 || map[downward][check.L + 2] != '0'))
        {
            Sleep(100);
            block.location.X--;

            check.L--;

            block.orientation = FIRST;

            dunturnup = false;
        }

        else if (keyPressed[K_UP] && dunturnup == true)
        {
            Sleep(100);

            block.orientation = FIRST;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        else if (downward >= 22 || map[downward+1][check.L] != '0' || map[downward+1][check.L+1] != '0')
        {
            UpdateMap(block.type, block.orientation, downward, check.L);             // bu jie zhi mi
            receive (block.type, block.orientation, downward);
            calculate (downward);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}
        }
        break;
    }
}

void updateSq()
{
    switch(block.orientation)
    {
    case FIRST:
        if (keyPressed[K_LEFT] && check.Sq > 0 && map[downward + 1][check.Sq - 1] == '0' && map[downward][check.Sq - 1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.Sq--;
        }

        if (keyPressed[K_RIGHT] && check.Sq < 8 && map[downward + 1][check.Sq + 2] == '0' && map[downward][check.Sq + 2] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.Sq++;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward >= 22 || map[downward + 1][check.Sq] != '0' || map[downward + 1][check.Sq + 1] != '0')
        {
            UpdateMap(block.type, block.orientation, downward, check.Sq - 1);             
            receive (block.type, block.orientation, downward);
            calculate (downward);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}
        }
        break;
    }
}

void updateT()
{
    switch(block.orientation)
    {
    case FIRST:
        if (keyPressed[K_LEFT] && check.T > 0 && map[downward-1][check.T] == '0' && map[downward][check.T-1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.T--;
        }

        else if (keyPressed[K_RIGHT] && check.T < 7 && map[downward-1][check.T + 2] == '0' && map[downward][check.T + 3] == '0' )
        {
            Beep(1440, 30);
            block.location.X++;

            check.T++;
        }

        else if (keyPressed[K_UP] && dunturnup == true)
        {
            Sleep(100);
            check.T++;

            block.orientation = SECOND;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        else if (downward >= 22 || map[downward+1][check.T] != '0' || map[downward+1][check.T+2] != '0' || map[downward+1][check.T+1] != '0')
        {
            UpdateMap(block.type, block.orientation, downward - 1, check.T);             // bu jie zhi mi
            receive (block.type, block.orientation, downward);
            calculate (downward);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}
        }
        break;

    case SECOND:
        if (keyPressed[K_LEFT] && check.T > 0 && map[downward][check.T-1] == '0' && map[downward - 1][check.T-1] == '0' && map[downward + 1][check.T-1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.T--;
        }

        else if (keyPressed[K_RIGHT] && check.T < 8 && map[downward][check.T+2] == '0' && map[downward-1][check.T+2] == '0' && map[downward+1][check.T+1] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.T++;
        }

        //check for surrounding if press rotate button
        else if (keyPressed[K_UP] && dunturnup == true && (map[downward][check.T-1] != '0' || map[downward - 1][check.T-1] != '0' || map[downward + 1][check.T-1] != '0')&&
                                                          (map[downward][check.T+2] != '0' || map[downward-1][check.T+2] != '0' || map[downward+1][check.T+1] != '0'))
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && dunturnup == true && (map[downward][check.T-1] != '0' || map[downward - 1][check.T-1] != '0' || map[downward + 1][check.T-1] != '0'))
        {
            Sleep(100);
            block.location.X++;

            block.orientation = THIRD;

            dunturnup = false;
        }

        else if (keyPressed[K_UP] && dunturnup == true && check.T < 1)
        {
            Sleep(100);
            block.location.X++;

            block.orientation = THIRD;

            dunturnup = false;
        }
        
        else if (keyPressed[K_UP] && dunturnup == true)
        {
            Sleep(100);
            check.T--;

            block.orientation = THIRD;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward >= 22 || map[downward+1][check.T] != '0' || map[downward][check.T+1] != '0')
        {
            UpdateMap(block.type, block.orientation, downward - 1, check.T);             // bu jie zhi mi
            receive (block.type, block.orientation, downward);
            calculate (downward);

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}
        }
        break;

    case THIRD:
        if (keyPressed[K_LEFT] && check.T > 0 && map[downward+1][check.T] == '0' && map[downward][check.T-1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.T--;
        }

        if (keyPressed[K_RIGHT] && check.T < 7 && map[downward+1][check.T + 2] == '0' && map[downward][check.T + 3] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.T++;
        }

        else if (keyPressed[K_UP] && dunturnup == true)
        {
            Sleep(100);

            block.orientation = FOURTH;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward >= 22 || map[downward+1][check.T+1] != '0' || map[downward][check.T] != '0' || map[downward][check.T+2] != '0')
        {
            UpdateMap(block.type, block.orientation, downward - 1, check.T);             // bu jie zhi mi
            receive (block.type, block.orientation, downward);
            calculate (downward);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}
        }
        break;

    case FOURTH:
        if (keyPressed[K_LEFT] && check.T > 0 && map[downward][check.T-1] == '0' && map[downward - 1][check.T] == '0' && map[downward + 1][check.T] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.T--;
        }

        else if (keyPressed[K_RIGHT] && check.T < 8 && map[downward][check.T+2] == '0' && map[downward-1][check.T+2] == '0' && map[downward+1][check.T+2] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.T++;
        }

        // check surrounding when hit rotate button
        else if (keyPressed[K_UP] && dunturnup == true && (map[downward][check.T+2] != '0' || map[downward-1][check.T+2] != '0' || map[downward+1][check.T+2] != '0') && 
                                                           (map[downward][check.T-1] != '0' && map[downward - 1][check.T] != '0' && map[downward + 1][check.T] != '0'))
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && dunturnup == true && check.T > 7 && (map[downward][check.T-1] != '0' && map[downward - 1][check.T] != '0' && map[downward + 1][check.T] != '0'))
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && dunturnup == true && (map[downward][check.T+2] != '0' || map[downward-1][check.T+2] != '0' || map[downward+1][check.T+2] != '0'))
        {
            Sleep(100);
            block.location.X--;
            check.T--;

            block.orientation = FIRST;

            dunturnup = false;
        }

        else if (keyPressed[K_UP] && dunturnup == true && check.T > 7)
        {
            Sleep(100);
            block.location.X--;
            check.T--;

            block.orientation = FIRST;

            dunturnup = false;
        }
        
        else if (keyPressed[K_UP] && dunturnup == true)
        {
            Sleep(100);

            block.orientation = FIRST;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward >= 22 || map[downward+1][check.T+1] != '0' || map[downward][check.T] != '0')
        {
            UpdateMap(block.type, block.orientation, downward-1, check.T);             // bu jie zhi mi
            receive (block.type, block.orientation, downward);
            calculate (downward);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}
        }
        break;
    }
}

void updateREVZ()
{
	switch(block.orientation)
    {
    case FIRST:
        if (keyPressed[K_LEFT] && check.RZ > 0 && map[downward][check.RZ] == '0' && map[downward+1][check.RZ - 1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.RZ--;
        }

        if (keyPressed[K_RIGHT] && check.RZ < 7 && map[downward][check.RZ+3] == '0' && map[downward+1][check.RZ+2] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.RZ++;
        }

        else if (keyPressed[K_UP] && dunturnup == true)
        {
            Sleep(100);

            block.orientation = SECOND;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward >= 22 ||  map[downward+1][check.RZ] != '0' ||  map[downward+1][check.RZ + 1] != '0' ||  map[downward][check.RZ + 2] != '0')
        {
            UpdateMap(block.type, block.orientation, downward, check.RZ-1);             // bu jie zhi mi
            receive (block.type, block.orientation, downward);
            calculate (downward);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}
        }
        break;

    case SECOND:
        if (keyPressed[K_LEFT] && check.RZ > 0 && map[downward+1][check.RZ] == '0' && map[downward][check.RZ-1] == '0' && map[downward-1][check.RZ-1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.RZ--;
        }

        if (keyPressed[K_RIGHT] && check.RZ < 8 && map[downward][check.RZ+2] == '0' && map[downward+1][check.RZ+2] == '0'&& map[downward-1][check.RZ+1] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.RZ++;
        }

        // if user want to rotate the block, check the surrounding whether possible for him to rotate or not
        else if (keyPressed[K_UP] && dunturnup == true  && check.Z > 7 && (map[downward+1][check.RZ] != '0' || map[downward][check.RZ-1] != '0' || map[downward-1][check.RZ-1] != '0'))
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && dunturnup == true  && check.Z < 2 && (map[downward][check.RZ+2] != '0' || map[downward+1][check.RZ+2] != '0'|| map[downward-1][check.RZ+1] != '0'))
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && dunturnup == true  &&  (map[downward][check.RZ+2] != '0' || map[downward+1][check.RZ+2] != '0'|| map[downward-1][check.RZ+1] != '0') &&
                                                            (map[downward+1][check.RZ] != '0' || map[downward][check.RZ-1] != '0' || map[downward-1][check.RZ-1] != '0'))
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && dunturnup == true  && (map[downward][check.RZ+2] == '0' || map[downward+1][check.RZ+2] == '0'|| map[downward-1][check.RZ+1] == '0'))
        {
            Sleep(100);
            block.location.X--;
            check.RZ--;

            block.orientation = FIRST;

            dunturnup = false;
        }

        else if (keyPressed[K_UP] && dunturnup == true && check.RZ > 7)
        {
            Sleep(100);
            block.location.X--;
            check.RZ--;

            block.orientation = FIRST;

            dunturnup = false;
        }

        else if (keyPressed[K_UP] && dunturnup == true)
        {
            Sleep(100);

            block.orientation = FIRST;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward >= 22 ||  map[downward+1][check.RZ+1] != '0' ||  map[downward][check.RZ] != '0')
        {
            UpdateMap(block.type, block.orientation, downward, check.RZ);             // bu jie zhi mi
            receive (block.type, block.orientation, downward);
            calculate (downward);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}
        }
        break;
	}
}

void updateREVL()
{
	switch(block.orientation)
    {
    case FIRST:
        if (keyPressed[K_LEFT] && check.RL > 0 && map[downward][check.RL - 1] != '1' && map[downward+1][check.RL - 2] != '1')
        {
            Beep(1440, 30);
            block.location.X--;

            check.RL--;
        }

        if (keyPressed[K_RIGHT] && check.RL < 7 && map[downward+1][check.RL] != '1' && map[downward+1][check.RL-1] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.RL++;
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
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 20 ||  map[downward+1][check.RL] == '1' ||  map[downward+1][check.RL + 1] == '1' ||  map[downward][check.RL + 2] == '1')
        {
            UpdateMap(block.type, block.orientation, downward, check.RL - 1);             // bu jie zhi mi

            initCheck();
            random();
        }
        break;

    case SECOND:
        if (keyPressed[K_LEFT] && check.RL > 0 && map[downward+1][check.RL-1] != '1' && map[downward+1][check.RL-2] != '1')
        {
            Beep(1440, 30);
            block.location.X--;

            check.RL--;
        }

        if (keyPressed[K_RIGHT] && check.RL < 8 && map[downward][check.RL+2] != '1' && map[downward-1][check.RL+2] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.RL++;
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
        if (downward > 20 ||  map[downward+1][check.RL] == '1' ||  map[downward][check.RL - 1] == '1')
        {
            UpdateMap(block.type, block.orientation, downward, check.RL - 1);             // bu jie zhi mi

            initCheck();
            random();
        }
        break;
	case THIRD:
		if (keyPressed[K_LEFT] && check.RL > 0 && map[downward+1][check.RL-1] != '1' && map[downward+1][check.RL-2] != '1')
        {
            Beep(1440, 30);
            block.location.X--;

            check.RL--;
        }

        if (keyPressed[K_RIGHT] && check.RL < 7 && map[downward][check.RL+2] != '1' && map[downward-1][check.RL+2] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.RL++;
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
			check.RL++;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 20 ||  map[downward+1][check.RL] == '1' ||  map[downward][check.RL - 1] == '1')
        {
            UpdateMap(block.type, block.orientation, downward, check.RL - 1);             // bu jie zhi mi

            initCheck();
            random();
        }
        break;
	case FOURTH:
		if (keyPressed[K_LEFT] && check.RL > 0 && map[downward+1][check.RL-1] != '1' && map[downward+1][check.RL-2] != '1')
        {
            Beep(1440, 30);
            block.location.X--;

            check.RL--;
        }

        if (keyPressed[K_RIGHT] && check.RL < 8 && map[downward][check.RL+2] != '1' && map[downward-1][check.RL+2] != '1')
        {
            Beep(1440, 30);
            block.location.X++;

            check.RL++;
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

			check.RL--;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (downward > 20 ||  map[downward+1][check.RL] == '1' ||  map[downward][check.RL - 1] == '1')
        {
            UpdateMap(block.type, block.orientation, downward, check.RL - 1);             // bu jie zhi mi

            initCheck();
            random();
        }
        break;

	}
}

void initCheck()
{
    check.l = 3;
    check.Z = 4;
    check.L = 4;
    check.Sq = 4;
    check.T = 4;
	check.RZ = 4;
	check.RL = 4;

    downward = 0;
}

void initBlockLocation()
{
    int initialX = 8;
    int initialY = 1;

    blocks.l_shape.X = initialX;
    blocks.l_shape.Y = initialY;
    
    blocks.L_shape.X = initialX;
    blocks.L_shape.Y = initialY;

    blocks.Sq_shape.X = initialX;
    blocks.Sq_shape.Y = initialY;

    blocks.T_shape.X = initialX;
    blocks.T_shape.Y = initialY;

    blocks.Z_shape.X = initialX;
    blocks.Z_shape.Y = initialY;

	blocks.RZ_shape.X = initialX;
    blocks.RZ_shape.Y = initialY;

	blocks.RL_shape.X = initialX;
	blocks.RL_shape.Y = initialY;

}

void random()
{
    block.orientation = FIRST;
    
    randomisation = randomblock[0+next];

    switch(randomisation)
    {
    case 0:
        block.type = LONG_TYPE;
        block.location.X = blocks.l_shape.X;
        block.location.Y = blocks.l_shape.Y;
        block.color = color.l;
        break;

    case 1:
        block.type = Z_TYPE;
        block.location.X = blocks.Z_shape.X;
        block.location.Y = blocks.Z_shape.Y;
        block.color = color.Z;
        break;

    case 2:
        block.type = L_TYPE;
        block.location.X = blocks.L_shape.X;
        block.location.Y = blocks.L_shape.Y;
        block.color = color.L;
        break;
        
    case 3:
        block.type = Sq_TYPE;
        block.location.X = blocks.Sq_shape.X;
        block.location.Y = blocks.Sq_shape.Y;
        block.color = color.Sq;
        break;

    case 4:
        block.type = T_TYPE;
        block.location.X = blocks.T_shape.X;
        block.location.Y = blocks.T_shape.Y;
        block.color = color.T;
        break;
        
	case 5:
		block.type = L_REV_TYPE;
		block.location.X = blocks.RL_shape.X;
        block.location.Y = blocks.RL_shape.Y;
        block.color = color.RL;
        break;

	case 6:
        block.type = Z_REV_TYPE;
        block.location.X = blocks.RZ_shape.X;
        block.location.Y = blocks.RZ_shape.Y;
        block.color = color.RZ;
		break;
    }
}

void showNextBlock(COORD c, int type)
{
    type = randomblock[1+next];

    switch(type)
    {
    case 0:
        for(int i = 0; i < 4; i++)
        {
            c.X++;
            c.Y;
            writeToBuffer(c, shape, color.l);
        }

        break;

    case 1:
        c.X;
        c.Y;
        writeToBuffer(c, shape, color.Z);

        c.X++;
        c.Y;
        writeToBuffer(c, shape, color.Z);

        c.X;
        c.Y++;
        writeToBuffer(c, shape, color.Z);

        c.X++;
        c.Y;
        writeToBuffer(c, shape, color.Z);

        break;

    case 2:
        c.X;
        c.Y--;
        writeToBuffer(c, shape, color.L);

        c.Y++;
        c.X--;
        for(int i = 0; i < 3; i++)
        {
            c.X++;
            writeToBuffer(c, shape, color.L);
        }

        break;

    case 3:
        c.X;
        c.Y;
        writeToBuffer(c, shape, color.Sq);

        c.X++;
        c.Y;
        writeToBuffer(c, shape, color.Sq);

        c.X--;
        c.Y++;
        writeToBuffer(c, shape, color.Sq);

        c.X++;
        c.Y;
        writeToBuffer(c, shape, color.Sq);

        break;

    case 4:
        for (int i = 0; i < 3; i++)
        {
            c.X++;
            c.Y;
            writeToBuffer(c, shape, color.T);
        }

        c.X--;
        c.Y--;
        writeToBuffer(c, shape, color.T);
        break;
    }
    
}

void storeBlock(COORD c, bool switchOrstore, int type)
{
    if (switchOrstore == true)
    {
        switch(type)
        {
        case 0:
            for(int i = 0; i < 4; i++)
            {
                c.X++;
                c.Y;
                writeToBuffer(c, shape, color.l);
            }

            break;

        case 1:
            c.X;
            c.Y;
            writeToBuffer(c, shape, color.Z);

            c.X++;
            c.Y;
            writeToBuffer(c, shape, color.Z);

            c.X;
            c.Y++;
            writeToBuffer(c, shape, color.Z);

            c.X++;
            c.Y;
            writeToBuffer(c, shape, color.Z);

            break;

        case 2:
            c.X;
            c.Y--;
            writeToBuffer(c, shape, color.L);

            c.Y++;
            c.X--;
            for(int i = 0; i < 3; i++)
            {
                c.X++;
                writeToBuffer(c, shape, color.L);
            }

            break;

        case 3:
            c.X;
            c.Y;
            writeToBuffer(c, shape, color.Sq);

            c.X++;
            c.Y;
            writeToBuffer(c, shape, color.Sq);

            c.X--;
            c.Y++;
            writeToBuffer(c, shape, color.Sq);

            c.X++;
            c.Y;
            writeToBuffer(c, shape, color.Sq);

            break;

        case 4:
            for (int i = 0; i < 3; i++)
            {
                c.X++;
                c.Y;
                writeToBuffer(c, shape, color.T);
            }

            c.X--;
            c.Y--;
            writeToBuffer(c, shape, color.T);
            break;
        }
    }
}

void blockcolorinit()
{
    color.l = 0x09;
    color.Z = 0x0C;
    color.L = 0x0D;
    color.Sq = 0x0E;
    color.T = 0x0F;
    color.RL = 0x1A;
    color.RZ = 0x1A;

    color.map = 0x00;
}