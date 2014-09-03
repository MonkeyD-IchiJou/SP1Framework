// This is the main file for the game logic and function
//
//
#include "game.h"
#include "tetris.h"
#include "Gameplay.h"
#include "Framework\console.h"
#include "Framework\sound.h"

// Console size, width by height
COORD ConsoleSize = {60, 36};

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];

stages gameState = START_SCREEN;

COORD consoleSize;

Sound snd;

// Game specific variables here
COORD charLocation;

Location screen;        //coordinates for start, main menu, gameplay, and pause screen 
Blocks blocks;          //coordinates for different blocks
Block block;            //use for individual block
BlocksType store;       //use for store different kind of blocks
BlocksType *temporaryStore;     
storeNswitch count;     //check and store the block
blockcolor color;       //blocks colors
collisionCheck check;   //use to check for collision (left and right of the blocks)

int speed;

int downward = 0;

int randomisation;

int checkscore[height];

unsigned long int randomblock[10000000];

int next = 0;

bool dunturnup = true;
bool dungoright = true;
bool dungoleft = true;
bool buggoaway = true;
unsigned int constantmoveright;
unsigned int constantmoveleft;

int music;

char indicate = (char) 4;

void init()
{
    // Set precision for floating point output
    elapsedTime = 0.0;
    std::cout << std::fixed << std::setprecision(3);

    SetConsoleTitle(L"Tetris");

    // Sets the console size, this is the biggest so far.
    setConsoleSize(60, 36);

    initConsole(ConsoleSize, "SP1 Framework");

    charLocation.X = ConsoleSize.X / 2;
    charLocation.Y = ConsoleSize.Y / 2;

    snd.loadWave("move", "Tetris.wav");
	snd.loadWave("rotate", "rotate.wav");
    snd.loadWave("land", "BlocksLanding.wav");
    snd.loadWave("clear", "ClearLine.wav");
    snd.loadWave("over", "Gameover.wav");
    
    screen.ScLocation.X = 22;
    screen.ScLocation.Y = 14;

    screen.MmLocation.X = 7;
    screen.MmLocation.Y = 14;

	screen.PsLocation.X = 3;
	screen.PsLocation.Y = 12;

	screen.CLocation.X = 18;
	screen.CLocation.Y = 5;

    screen.BdLocation.X = 30;
    screen.BdLocation.Y = 3;

    screen.ShowScore.X = 30;
    screen.ShowScore.Y = 22;

	screen.Background.X = 35;
	screen.Background.Y = 0;

    screen.FinalResult.X = 21;
    screen.FinalResult.Y = 20;

	/*screen.BorderShowLocation.X = 2;
	screen.BorderShowLocation.Y = 18;*/
    // initiate block thingy here
    // will do randomisation here
    screen.NLineLocation.X = ConsoleSize.X / 4 - 9;
    screen.NLineLocation.Y = 21;

    screen.StoreLineLocation.X = ConsoleSize.X / 4 - 9;
    screen.StoreLineLocation.Y = 8;

    count.storeornot = false;
    count.storeOredi = false;

    count.switchcount = 0;

    blockcolorinit();
    temporaryStore = &store;

    srand (time(NULL));
    for (int i = 0; i < 65535; i++)
    { 
        randomblock[i] = rand()%7;
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
        
        //playGameSound(S_JJ);

        if (keyPressed[K_ENTER])
        {
            Sleep(100);
            gameState = MAIN_MENU;
        }
        break;

    case MAIN_MENU:

		if (keyPressed[K_ENTER] && screen.MmLocation.Y == 14)
        {
			Sleep(100);
            Beep(1440, 30);
            gameState = HIGHSCORE_MODE;
		}

        if (keyPressed[K_ENTER] && screen.MmLocation.Y == 20)
        {
			Sleep(100);
            Beep(1440, 30);
            gameState = INSTRUCTION;
		}
        /*
<<<<<<< fb5b0cddf82a2d8ad7bc8a5b2715c6c77c4daa08
		
		if (keyPressed[K_ENTER] && screen.MmLocation.Y == 26)
        {
			Sleep(100);
            Beep(1440, 30);
		}
=======
>>>>>>> a476f34d3e1a3d52c35efb877523209e1ea6d6e4*/

        if (keyPressed[K_ENTER] && screen.MmLocation.Y == 32)
        {
            Sleep(100);
            Beep(1440, 30);
            g_quitGame = true;
        }

		if (keyPressed[K_UP] && screen.MmLocation.Y > 14)
        {
            Beep(1440, 30);
			Sleep(100);
            screen.MmLocation.Y -= 6;
        }

		if (keyPressed[K_DOWN] && screen.MmLocation.Y < 31)
        {
            Beep(1440, 30);
			Sleep(100);
            screen.MmLocation.Y += 6; 
        }
		break;

    case INSTRUCTION:
        if (keyPressed[K_ENTER])
        {
            Sleep(100);
            Beep(1440, 30);
            gameState = MAIN_MENU;
        }
		break;

    case HIGHSCORE_MODE:

        //if blocks reach the top of the map, game end
        for (int i = 0; i < width-1; i++)
        {
            if (map[0][i] != '0')
            {
                gameState = END_GAME;
                break;
            }
        }

        if (!keyPressed[K_UP])
        {
            dunturnup = true;
        }

        if (!keyPressed[K_SPACE])
        {
            buggoaway = true;
        }

        if (!keyPressed[K_RIGHT])
        {
            dungoright = true;
            constantmoveright = 0;
        }

        if (keyPressed[K_UP] && dunturnup == true)
        {
            playGameSound(S_ROTATE);
        }
        
        if (keyPressed[K_RIGHT])
        {
            constantmoveright++;
        }

        if (constantmoveright >= 6)
        {
            dungoright = true;
        }

        if (!keyPressed[K_LEFT])
        {
            dungoleft = true;
            constantmoveleft = 0;
        }

        if (keyPressed[K_LEFT])
        {
            constantmoveleft++;
        }

        if (constantmoveleft >= 6)
        {
            dungoleft = true;
        }

        int changeSpeed;
        int divide;
        
        if (score >= 0 && score < 499)      // beginer speed
        {
            changeSpeed = 500;
            divide = 10;
        }

        else if (score >= 500 && score < 1499)
        {
            changeSpeed = 1000;
            divide = 4;
        }

        else if (score >= 1500)
        {
            changeSpeed = 1000;
            divide = 2;
        }

        speed = static_cast<int>(elapsedTime*changeSpeed);
        
        if (speed % divide == 0 && !keyPressed[K_DOWN] && !keyPressed[K_SPACE])
        {
            block.location.Y++;
            downward++;
        }
        
        if (keyPressed[K_DOWN])
        {
            block.location.Y++;
            downward++;
        }

        if (keyPressed[K_SHIFT] && count.storeornot == false && count.switchcount % 2 == 0)     // store system here
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

            case L_REV_TYPE:
                block.color = color.RL;
                break;

            case Z_REV_TYPE:
                block.color = color.RZ;
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

		if (keyPressed[K_UP] && screen.PsLocation.Y > 13)
        {
            Beep(1440, 30);
			Sleep(100);
            screen.PsLocation.Y -= 7;
        }

		if (keyPressed[K_DOWN] && screen.PsLocation.Y < 21)
        {
            Beep(1440, 30);
			Sleep(100);
            screen.PsLocation.Y += 7; 
        }

		if(keyPressed[K_ENTER] && screen.PsLocation.Y == 12)
		{
			Sleep(100);
			gameState = HIGHSCORE_MODE;
		}

		if (keyPressed[K_ENTER] && screen.PsLocation.Y == 19)
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

		if(keyPressed[K_ENTER] && screen.PsLocation.Y == 26)
		{
			gameState = MAIN_MENU; 
		}

        if (keyPressed[K_SHIFT])
        {
            Sleep(100);
            gameState = HIGHSCORE_MODE;
        }
        break;

    case END_GAME:
        speed = static_cast<int>(elapsedTime*500);
        if(speed % 50 == 0)
        {
            playGameSound(S_OVER);
        }

		if (keyPressed[K_ENTER] && screen.FinalResult.Y == 20)
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

		if(keyPressed[K_ENTER] && screen.FinalResult.Y == 24)
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
			Sleep(100);
			gameState = MAIN_MENU; playGameSound(S_STOP);
		}

		if (keyPressed[K_UP] && screen.FinalResult.Y > 20)
        {
            Beep(1440, 30);
			Sleep(100);
            screen.FinalResult.Y -= 4;
        }

		if (keyPressed[K_DOWN] && screen.FinalResult.Y < 24)
        {
            Beep(1440, 30);
			Sleep(100);
            screen.FinalResult.Y += 4; 
        }
    }
}

void render()
{    
    // Clears the buffer with this colour attribute
    clearBuffer(Black);

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

    case INSTRUCTION:
        renderInstruction(screen.ILocation);
        break;


    case HIGHSCORE_MODE:

        DrawBorder(screen.BdLocation);
        DrawMap(screen.TmLocation, block.type);
        printBlock(block.type, block.orientation, block.color);
        showNextBlock(screen.NLineLocation, block.type);
        storeBlock(screen.StoreLineLocation, count.storeornot, *temporaryStore);
        showScore(screen.ShowScore, score);
        //writeToBuffer(block.location, (char)constantmove);

        //writeToBuffer(block.location, (char)check.RZ);

        // indicator for every block 
		Background(screen.Background);
        COORD c;
        c.X = block.location.X;
        c.Y = 30;

        switch (block.type)
        {
        case LONG_TYPE:
            switch (block.orientation)
            {
            case FIRST:
                c.X--;
                c.X--;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                break;

            case SECOND:
                writeToBuffer(c, indicate, block.color);
                break;
            }
            break;
            
        case Z_TYPE:
            switch (block.orientation)
            {
            case FIRST:
                c.X--;
                writeToBuffer(c, indicate);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                break;

            case SECOND:
                c.X--;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate);
                break;
            }
            break;

        case L_TYPE:
            switch (block.orientation)
            {
            case FIRST:
                c.X--;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                break;

            case SECOND:
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate);
                break;

            case THIRD:
                c.X--;
                writeToBuffer(c, indicate);
                c.X++;
                writeToBuffer(c, indicate);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                break;

            case FOURTH:
                c.X--;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                break;
            }
            break;
            
        case Sq_TYPE:
            switch (block.orientation)
            {
            case FIRST:
                c.X--;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                break;
            }
            break;
            
        case T_TYPE:
            switch (block.orientation)
            {
            case FIRST:
                c.X--;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                break;

            case SECOND:
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate);
                break;

            case THIRD:
                c.X--;
                writeToBuffer(c, indicate);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate);
                break;

            case FOURTH:
                c.X--;
                writeToBuffer(c, indicate);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                break;
            }
            break;
            
        case L_REV_TYPE:
            switch (block.orientation)
            {
            case FIRST:
                c.X--;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                break;

            case SECOND:
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                break;

            case THIRD:
                c.X--;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate);
                c.X++;
                writeToBuffer(c, indicate);
                break;

            case FOURTH:
                c.X--;
                writeToBuffer(c, indicate);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                break;
            }
            break;
            
        case Z_REV_TYPE:
            switch (block.orientation)
            {
            case FIRST:
                c.X--;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                c.X++;
                writeToBuffer(c, indicate);
                break;

            case SECOND:
                c.X--;
                writeToBuffer(c, indicate);
                c.X++;
                writeToBuffer(c, indicate, block.color);
                break;
            }
            break;
        }
        
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

void playGameSound(SoundType sound)
{
    switch (sound)
    {
    case S_JJ : snd.playSound("move");
        break;
	case S_ROTATE: snd.playSound("rotate");
        break;
    case S_STOP: snd.playSound("stop");
        break;
    case S_LAND: snd.playSound("land");
        break;
    case S_CLEAR: snd.playSound("clear");
        break;
    case S_OVER: snd.playSound("over");
        break;
    }
}

void playNote(char note) // play this note
{
    // not gonna happen
    /*
    Octave 0    1    2    3    4    5    6    7
    Note
    C     16   33   65  131  262  523 1046 2093
    C#    17   35   69  139  277  554 1109 2217
    D     18   37   73  147  294  587 1175 2349
    D#    19   39   78  155  311  622 1244 2489
    E     21   41   82  165  330  659 1328 2637
    F     22   44   87  175  349  698 1397 2794
    F#    23   46   92  185  370  740 1480 2960
    G     24   49   98  196  392  784 1568 3136
    G#    26   52  104  208  415  831 1661 3322
    A     27   55  110  220  440  880 1760 3520
    A#    29   58  116  233  466  932 1865 3729
    B     31   62  123  245  494  988 1975 3951
    */
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

        if (keyPressed[K_LEFT] && dungoleft == true && check.l > 0 && map[downward][check.l-1] == '0')
        {
            block.location.X--;
            
            check.l--;

            dungoleft = false;
        }
        
        else if (keyPressed[K_RIGHT] && dungoright == true && check.l < 6 && map[downward][check.l + 4] == '0')
        {
            block.location.X++;

            check.l++;

            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward][check.l] != '0' || map[downward][check.l + 1] != '0' || map[downward][check.l + 2] != '0' || map[downward][check.l + 3] != '0')
                {
                    break;
                }
            }

            buggoaway = false;
        }

        if (keyPressed[K_UP] && dunturnup == true &&( downward > 18 || map[downward][check.l] != '0' || map[downward][check.l + 1] != '0' || map[downward][check.l + 2] != '0' || map[downward][check.l + 3] != '0' ||
                                                                          map[downward + 1][check.l] != '0' || map[downward + 1][check.l + 1] != '0' || map[downward + 1][check.l + 2] != '0' || map[downward + 1][check.l + 3] != '0' || 
                                                                          map[downward+2][check.l] != '0' || map[downward+2][check.l + 1] != '0' || map[downward+2][check.l + 2] != '0' || map[downward+2][check.l + 3] != '0'))
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && dunturnup == true && (downward == 21 || map[downward+1][check.l] != '0' || map[downward+1][check.l + 1] != '0' || map[downward+1][check.l + 2] != '0' || map[downward+1][check.l + 3] != '0'))
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
            Sleep(150);
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

            Sleep(150); if(count.switchcount % 2 != 0){count.switchcount++;}

            playGameSound(S_LAND);
        }

        break;

    case SECOND:    // Second orientation

        if (keyPressed[K_LEFT] && check.l > 0 && dungoleft == true && map[downward][check.l - 1] == '0' && map[downward -1][check.l - 1] == '0' && map[downward - 2][check.l - 1] == '0' && map[downward + 1][check.l - 1] == '0')
        {
            block.location.X--;
            
            check.l--;

            dungoleft = false;
        }

        else if (keyPressed[K_RIGHT] && dungoright == true && check.l < 9 && map[downward][check.l + 1] == '0' && map[downward -1][check.l + 1] == '0' && map[downward - 2][check.l + 1] == '0' && map[downward + 1][check.l + 1] == '0')
        {
            block.location.X++;

            check.l++;

            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward+1][check.l] != '0')
                {
                    break;
                }
            }

            buggoaway = false;
        }

        // if user want to rotate, check the surrounding of the blocks
        
        else if(keyPressed[K_UP] && dunturnup == true && check.l < 2 && (map[downward - 1][check.l + 1] != '0'|| map[downward - 2][check.l + 1] != '0' || map[downward + 1][check.l + 1] != '0' ||
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
        
        else if(keyPressed[K_UP] && dunturnup == true && check.l > 2 && (map[downward -1][check.l + 1] != '0' || map[downward - 2][check.l + 1] != '0' || map[downward + 1][check.l + 1] != '0'))  // check for right side obstacle
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

            Sleep(150); if(count.switchcount % 2 != 0){count.switchcount++;}
            
            playGameSound(S_LAND);
        }

        break;
    }
}

void updateZ()
{
    switch(block.orientation)
    {
    case FIRST:
        if (keyPressed[K_LEFT] && check.Z > 0 && dungoleft == true && map[downward][check.Z - 1] == '0' && map[downward+1][check.Z] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.Z--;

            dungoleft = false;
        }

        else if (keyPressed[K_RIGHT] && dungoright == true && check.Z < 7 && map[downward+1][check.Z + 3] == '0' && map[downward][check.Z + 2] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.Z++;
            dungoright = false;
        }


        else if (keyPressed[K_UP] && dunturnup == true)
        {
            Sleep(100);

            block.orientation = SECOND;

            dunturnup = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward][check.Z] != '0' || map[downward+1][check.Z + 1] != '0' || map[downward+1][check.Z + 2] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
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

            playGameSound(S_LAND);
        }
        break;

    case SECOND:
        if (keyPressed[K_LEFT] && check.Z > 0 && dungoleft == true && map[downward+1][check.Z-1] == '0' && map[downward][check.Z-1] == '0' && map[downward-1][check.Z] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.Z--;
            dungoleft = false;
        }

        else if (keyPressed[K_RIGHT] && check.Z < 8 && dungoright == true && map[downward][check.Z+2] == '0' && map[downward+1][check.Z+1] == '0' && map[downward-1][check.Z + 2] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.Z++;
            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward+1][check.Z] != '0' || map[downward][check.Z+1] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
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

            playGameSound(S_LAND);
        }
        break;
    }
}

void updateL()
{
    switch(block.orientation)
    {
    case FIRST:
        if (keyPressed[K_LEFT] && check.L > 0 && dungoleft == true && map[downward][check.L-1] == '0' && map[downward-1][check.L-1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.L--;
            dungoleft = false;
        }

        else if (keyPressed[K_RIGHT] && check.L < 7 && dungoright == true && map[downward][check.L + 3] == '0' && map[downward - 1][check.L + 1] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.L++;
            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward][check.L] != '0' || map[downward][check.L+1] != '0' || map[downward][check.L+2] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
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
        else if (downward > 22 || map[downward][check.L] != '0' || map[downward][check.L+1] != '0' || map[downward][check.L+2] != '0')
        {
            UpdateMap(block.type, block.orientation, downward-1, check.L);             
            receive (block.type, block.orientation, downward-1);
            calculate (downward-1);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}

            playGameSound(S_LAND);
        }
        break;

    case SECOND:
        if (keyPressed[K_LEFT] && check.L > 0 && dungoleft == true && map[downward][check.L - 1] == '0' && map[downward - 1][check.L - 1] == '0' && map[downward + 1][check.L - 1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.L--;
            dungoleft = false;
        }

        else if (keyPressed[K_RIGHT] && check.L < 8 && dungoright == true && map[downward][check.L + 1] == '0' && map[downward - 1][check.L + 2] == '0' && map[downward + 1][check.L+1] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.L++;
            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward+1][check.L] != '0' || map[downward-1][check.L+1] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
        }

        // check surrounding before rotate
        else if (keyPressed[K_UP] && dunturnup == true && map[downward + 1][check.L + 2] != '0' &&  (map[downward][check.L - 1] != '0' || map[downward - 1][check.L - 1] != '0' || map[downward + 1][check.L - 1] != '0'))
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && map[downward][check.L+1] != '0')
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && dunturnup == true && ( map[downward][check.L - 1] != '0' || map[downward - 1][check.L - 1] != '0' || map[downward + 1][check.L - 1] != '0'))
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

            playGameSound(S_LAND);
        }
        break;

    case THIRD:
        if (keyPressed[K_LEFT] && check.L > 0 && dungoleft == true && map[downward][check.L-1] == '0' && map[downward+1][check.L+1] == '0' )
        {
            Beep(1440, 30);
            block.location.X--;

            check.L--;
            dungoleft = false;
        }

        else if (keyPressed[K_RIGHT] && check.L < 7 && dungoright == true && map[downward+1][check.L + 3] == '0' && map[downward][check.L + 3] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.L++;
            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward][check.L] != '0' || map[downward][check.L+1] != '0' || map[downward+1][check.L + 2] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
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

            playGameSound(S_LAND);
        }
        break;

    case FOURTH:
        if (keyPressed[K_LEFT] && check.L > 0 && dungoleft == true && map[downward + 1][check.L - 1] == '0' && map[downward-1][check.L ] == '0' && map[downward][check.L ] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.L--;
            dungoleft = false;
        }

        else if (keyPressed[K_RIGHT] && check.L < 8 && dungoright == true && map[downward+1][check.L + 2] == '0' && map[downward][check.L + 2] == '0' && map[downward-1][check.L + 2] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.L++;
            dungoright = false;
        }
        
        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward+1][check.L] != '0' || map[downward+1][check.L+1] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
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

            playGameSound(S_LAND);
        }
        break;
    }
}

void updateSq()
{
    switch(block.orientation)
    {
    case FIRST:
        if (keyPressed[K_LEFT] && check.Sq > 0 && dungoleft == true && map[downward + 1][check.Sq - 1] == '0' && map[downward][check.Sq - 1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.Sq--;
            dungoleft = false;
        }

        else if (keyPressed[K_RIGHT] && check.Sq < 8 && dungoright == true && map[downward + 1][check.Sq + 2] == '0' && map[downward][check.Sq + 2] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.Sq++;
            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if ( map[downward + 1][check.Sq] != '0' || map[downward + 1][check.Sq + 1] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
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

            playGameSound(S_LAND);
        }
        break;
    }
}

void updateT()
{
    switch(block.orientation)
    {
    case FIRST:
        if (keyPressed[K_LEFT] && check.T > 0 && dungoleft == true && map[downward-1][check.T] == '0' && map[downward][check.T-1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.T--;
            dungoleft = false;
        }

        else if (keyPressed[K_RIGHT] && check.T < 7 && dungoright == true && map[downward-1][check.T + 2] == '0' && map[downward][check.T + 3] == '0' )
        {
            Beep(1440, 30);
            block.location.X++;

            check.T++;
            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward][check.T] != '0' || map[downward][check.T+2] != '0' || map[downward][check.T+1] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
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
        else if (map[downward][check.T] != '0' || map[downward][check.T+2] != '0' || map[downward][check.T+1] != '0')
        {
            UpdateMap(block.type, block.orientation, downward-2, check.T);             // bu jie zhi mi
            receive (block.type, block.orientation, downward - 1);
            calculate (downward - 1);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}

            playGameSound(S_LAND);
        }
        break;

    case SECOND:
        if (keyPressed[K_LEFT] && check.T > 0 && dungoleft == true && map[downward][check.T-1] == '0' && map[downward - 1][check.T-1] == '0' && map[downward + 1][check.T-1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.T--;
            dungoleft = false;
        }

        else if (keyPressed[K_RIGHT] && check.T < 8 && dungoright == true && map[downward][check.T+2] == '0' && map[downward-1][check.T+1] == '0' && map[downward+1][check.T+1] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.T++;
            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward+1][check.T] != '0' || map[downward][check.T+1] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
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

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}

            playGameSound(S_LAND);
        }
        break;

    case THIRD:
        if (keyPressed[K_LEFT] && check.T > 0 && dungoleft == true && map[downward+1][check.T] == '0' && map[downward][check.T-1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.T--;
            dungoleft = false;
        }

        if (keyPressed[K_RIGHT] && check.T < 7 && dungoright == true && map[downward+1][check.T + 2] == '0' && map[downward][check.T + 3] == '0')
        { 
            Beep(1440, 30);
            block.location.X++;

            check.T++;
            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward+1][check.T+1] != '0' || map[downward][check.T] != '0' || map[downward][check.T+2] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
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

            playGameSound(S_LAND);
        }
        break;

    case FOURTH:
        if (keyPressed[K_LEFT] && check.T > 0 && dungoleft == true && map[downward][check.T-1] == '0' && map[downward - 1][check.T] == '0' && map[downward + 1][check.T] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.T--;
            dungoleft = false;
        }

        else if (keyPressed[K_RIGHT] && check.T < 8 && dungoright == true && map[downward][check.T+2] == '0' && map[downward-1][check.T+2] == '0' && map[downward+1][check.T+2] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.T++;
            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward+1][check.T+1] != '0' || map[downward][check.T] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
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

            playGameSound(S_LAND);
        }
        break;
    }
}

void updateREVZ()
{
	switch(block.orientation)
    {
    case FIRST:
        if (keyPressed[K_LEFT] && check.RZ > 0 && dungoleft == true && map[downward][check.RZ] == '0' && map[downward+1][check.RZ - 1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.RZ--;
            dungoleft = false;
        }

        if (keyPressed[K_RIGHT] && check.RZ < 7 && dungoright == true && map[downward][check.RZ+3] == '0' && map[downward+1][check.RZ+2] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.RZ++;
            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward+1][check.RZ] != '0' ||  map[downward+1][check.RZ + 1] != '0' ||  map[downward][check.RZ + 2] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
        }

        else if (keyPressed[K_UP] && dunturnup == true)
        {
            block.orientation = SECOND;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        else if (downward >= 22 ||  map[downward+1][check.RZ] != '0' ||  map[downward+1][check.RZ + 1] != '0' ||  map[downward][check.RZ + 2] != '0')
        {
            UpdateMap(block.type, block.orientation, downward, check.RZ-1);             // bu jie zhi mi
            receive (block.type, block.orientation, downward);
            calculate (downward);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}

            playGameSound(S_LAND);
        }
        break;

    case SECOND:
        if (keyPressed[K_LEFT] && check.RZ > 0 && dungoleft == true && map[downward+1][check.RZ] == '0' && map[downward][check.RZ-1] == '0' && map[downward-1][check.RZ-1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.RZ--;
            dungoleft = false;
        }

        else if (keyPressed[K_RIGHT] && check.RZ < 8 && dungoright == true && map[downward][check.RZ+2] == '0' && map[downward+1][check.RZ+2] == '0'&& map[downward-1][check.RZ+1] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.RZ++;
            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward+1][check.RZ+1] != '0' ||  map[downward][check.RZ] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
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
        
        else if (keyPressed[K_UP] && dunturnup == true  && (map[downward][check.RZ+2] != '0' || map[downward+1][check.RZ+2] != '0'|| map[downward-1][check.RZ+1] != '0'))
        {
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
        else if (downward >= 22 ||  map[downward+1][check.RZ+1] != '0' ||  map[downward][check.RZ] != '0')
        {
            UpdateMap(block.type, block.orientation, downward, check.RZ);             // bu jie zhi mi
            receive (block.type, block.orientation, downward);
            calculate (downward);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}

            playGameSound(S_LAND);
        }
        break;
	}
}

void updateREVL()
{
	switch(block.orientation)
    {
    case FIRST:
        if (keyPressed[K_LEFT] && check.RL > 0 && dungoleft == true && map[downward][check.RL - 1] == '0' && map[downward-1][check.RL +1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.RL--;
            dungoleft = false;
        }

        if (keyPressed[K_RIGHT] && check.RL < 7 && dungoright == true && map[downward-1][check.RL+3] == '0' && map[downward][check.RL+3] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.RL++;
            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward][check.RL] != '0' ||  map[downward][check.RL + 1] != '0' ||  map[downward][check.RL + 2] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
        }

        else if (keyPressed[K_UP] && dunturnup == true)
        {
            check.RL++;
            downward++;
            block.orientation = SECOND;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        else if (map[downward][check.RL] != '0' ||  map[downward][check.RL + 1] != '0' ||  map[downward][check.RL + 2] != '0')
        {
            UpdateMap(block.type, block.orientation, downward-1, check.RL+2);             
            receive (block.type, block.orientation, downward-1);
            calculate (downward-1);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}

            playGameSound(S_LAND);
        }
        break;

    case SECOND:
        if (keyPressed[K_LEFT] && check.RL > 0 && dungoleft == true && map[downward][check.RL-1] == '0' && map[downward-1][check.RL-1] == '0' && map[downward-2][check.RL-1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.RL--;
            dungoleft = false;
        }

        if (keyPressed[K_RIGHT] && check.RL < 8 && dungoright == true && map[downward][check.RL+2] == '0' && map[downward - 1][check.RL+1] == '0'  && map[downward-2][check.RL+1] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.RL++;
            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward][check.RL] != '0' ||  map[downward][check.RL + 1] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
        }

        // rotate after ensure the surrounding is allowed it
        else if (keyPressed[K_UP] && dunturnup == true && (map[downward][check.RL+1] != '0' || map[downward-1][check.RL+2] != '0') &&
                                                          ( map[downward][check.RL-1] != '0' || map[downward-1][check.RL-1] != '0' || map[downward-2][check.RL-1] != '0'))
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && dunturnup == true && ( map[downward][check.RL-1] != '0' || map[downward-1][check.RL-1] != '0' || map[downward-2][check.RL-1] != '0'))
        {
            block.location.X++;

            block.orientation = THIRD;

            dunturnup = false;
        }
        
        else if (keyPressed[K_UP] && dunturnup == true && check.RL <1 )
        {
            block.location.X++;

            block.orientation = THIRD;

            dunturnup = false;
        }

        else if (keyPressed[K_UP] && dunturnup == true)
        {
            check.RL--;

            block.orientation = THIRD;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        else if (map[downward][check.RL] != '0' ||  map[downward][check.RL + 1] != '0')
        {
            UpdateMap(block.type, block.orientation, downward-3, check.RL);             
            receive (block.type, block.orientation, downward-1);
            calculate (downward-1);

            next++;

            initCheck();
            random();

            Sleep(150); if(count.switchcount % 2 != 0){count.switchcount++;}

            playGameSound(S_LAND);
        }
        break;

	case THIRD:
		if (keyPressed[K_LEFT] && check.RL > 0 && dungoleft == true && map[downward][check.RL-1] == '0' && map[downward-1][check.RL-1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.RL--;
            dungoleft = false;
        }

        if (keyPressed[K_RIGHT] && check.RL < 7 && dungoright == true && map[downward][check.RL+1] == '0' && map[downward-1][check.RL+3] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.RL++;
            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward][check.RL] != '0' ||  map[downward-1][check.RL + 1] != '0' || map[downward-1][check.RL + 2] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
        }

        else if (keyPressed[K_UP] && dunturnup == true)
        {
            block.orientation = FOURTH;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        else if (map[downward][check.RL] != '0' ||  map[downward-1][check.RL + 1] != '0' || map[downward-1][check.RL + 2] != '0')
        {
            UpdateMap(block.type, block.orientation, downward-1, check.RL - 2);             
            receive (block.type, block.orientation, downward-1);
            calculate (downward-1);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}

            playGameSound(S_LAND);
        }
        break;

	case FOURTH:
		if (keyPressed[K_LEFT] && check.RL > 0 && dungoleft == true && map[downward][check.RL] == '0' && map[downward-1][check.RL] == '0' && map[downward-2][check.RL-1] == '0')
        {
            Beep(1440, 30);
            block.location.X--;

            check.RL--;
            dungoleft = false;
        }

        else if (keyPressed[K_RIGHT] && check.RL < 8 && dungoright == true && map[downward][check.RL+2] == '0' && map[downward-1][check.RL+2] == '0' &&  map[downward-2][check.RL+2] == '0')
        {
            Beep(1440, 30);
            block.location.X++;

            check.RL++;
            dungoright = false;
        }

        if (keyPressed[K_SPACE] && buggoaway == true)
        {
            for(int i = 0; i < 23; i++)
            {
                block.location.Y++;
                downward++;

                if (map[downward][check.RL+1] != '0' ||  map[downward-2][check.RL] != '0')
                {
                    break;
                }
            }
            
            buggoaway = false;
        }

        // check surrounding before rotate
        else if (keyPressed[K_UP] && dunturnup == true && ((map[downward][check.RL+2] != '0' || map[downward-1][check.RL+2] != '0' ||  map[downward-2][check.RL+2] != '0') && 
                                                          ((map[downward][check.RL] != '0' || map[downward-1][check.RL] != '0' || map[downward-2][check.RL-1] != '0')||
                                                          (map[downward][check.RL-1] != '0' || map[downward-1][check.RL-1] != '0' || map[downward-2][check.RL-2] != '0'))))
        {
            dunturnup = true;
        }

        else if (keyPressed[K_UP] && dunturnup == true && (check.RL > 7 || map[downward][check.RL+2] != '0' && map[downward-1][check.RL+2] != '0' &&  map[downward-2][check.RL+2] != '0'))
        {
            block.location.X--;

            check.RL--;

            block.orientation = FIRST;

            dunturnup = false;
        }
        
        else if (keyPressed[K_UP] && dunturnup == true)
        {
            downward--;

            block.orientation = FIRST;

            dunturnup = false;
        }

        // Update map when reach bottom or other block
        // Come down next block when reach bottom
        if (map[downward][check.RL+1] != '0' ||  map[downward-2][check.RL] != '0')
        {
            UpdateMap(block.type, block.orientation, downward-3, check.RL+1);             
            receive (block.type, block.orientation, downward-1);
            calculate (downward-1);

            next++;

            initCheck();
            random();

            Sleep(100); if(count.switchcount % 2 != 0){count.switchcount++;}

            playGameSound(S_LAND);
        }
        break;

	}
}

void initCheck()
{
    random();
    check.l = 3;
    check.Z = 4;
    check.L = 4;
    check.Sq = 4;
    check.T = 4;
	check.RZ = 4;
	check.RL = 4;

    if(block.type != L_TYPE && block.type != T_TYPE && block.type != L_REV_TYPE)
    {
        downward = 0;
    }

    else
    {
        downward = 1;
    }
}

void initBlockLocation()
{
    int initialX = 30;
    int initialY = 6;

    blocks.l_shape.X = initialX;
    blocks.l_shape.Y = initialY;
    
    blocks.L_shape.X = initialX;
    blocks.L_shape.Y = initialY + 1;

    blocks.Sq_shape.X = initialX;
    blocks.Sq_shape.Y = initialY;

    blocks.T_shape.X = initialX;
    blocks.T_shape.Y = initialY + 1;

    blocks.Z_shape.X = initialX;
    blocks.Z_shape.Y = initialY;

	blocks.RZ_shape.X = initialX;
    blocks.RZ_shape.Y = initialY;

	blocks.RL_shape.X = initialX;
	blocks.RL_shape.Y = initialY+1;

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

    case 5:
        c.X+=3;
        c.Y--;
        writeToBuffer(c, shape, color.RL);

        c.Y++;
        c.X-=3;
        for(int i = 0; i < 3; i++)
        {
            c.X++;
            writeToBuffer(c, shape, color.RL);
        }

        break;

    case 6:
        c.X;
        c.Y;
        writeToBuffer(c, shape, color.RZ);

        c.X++;
        c.Y;
        writeToBuffer(c, shape, color.RZ);

        c.X;
        c.Y--;
        writeToBuffer(c, shape, color.RZ);

        c.X++;
        c.Y;
        writeToBuffer(c, shape, color.RZ);

        break;
    }

    std::ostringstream ss;
    ss.str("");
    ss << "Next Block";
    c.X = 4;
    c.Y = 16;
    writeToBuffer(c, ss.str(), 0x0A);
	c.X = 2;
	c.Y = 17;
	writeToBuffer(c, " =========== ", 0x0A);
	c.X = 2;
	c.Y = 25;
	writeToBuffer(c, " =========== ", 0x0A);
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

        case 5:
            c.X;
            c.Y++;
            writeToBuffer(c, shape, color.RL);

            c.Y--;
            c.X--;
            for(int i = 0; i < 3; i++)
            {
                c.X++;
                writeToBuffer(c, shape, color.RL);
            }
            break;

        case 6:
            c.X;
            c.Y;
            writeToBuffer(c, shape, color.RZ);

            c.X++;
            c.Y;
            writeToBuffer(c, shape, color.RZ);

            c.X;
            c.Y--;
            writeToBuffer(c, shape, color.RZ);

            c.X++;
            c.Y;
            writeToBuffer(c, shape, color.RZ);
        break;
        }
    }
    std::ostringstream ss;
    ss.str("");
    ss << "Store Block";
    c.X = 3;
    c.Y = 2;
    writeToBuffer(c, ss.str(), 0x0B);
	c.X = 2;
	c.Y = 3;
	writeToBuffer(c, " =========== ", 0x0B);
	c.X = 2;
	c.Y = 12;
	writeToBuffer(c, " =========== ", 0x0B);
}

void blockcolorinit()
{
    color.l = Cyan;
    color.Z = Red;
    color.L = Magenta; 
    color.Sq = Yellow;
    color.T = GreyBlue;
    color.RL = Grey;
    color.RZ = Green;

    color.map = Black; 
	color.border = Cyan;
}
