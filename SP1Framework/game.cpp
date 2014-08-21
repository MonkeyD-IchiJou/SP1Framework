// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD charLocation;
COORD consoleSize;

bool press = false;

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

    // set the character to be in the center of the screen.
    charLocation.X = 22;
    charLocation.Y = 4;

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

    FindCoordinates (2, 3);

    // Updating the location of the character based on the key press
    if (keyPressed[K_UP] && charLocation.Y > 20)
    {
        Beep(1440, 30);
        charLocation.Y--; 
    }

    if (keyPressed[K_LEFT] && charLocation.X > 17)
    {
        Beep(1440, 30);
        charLocation.X--; 
    }

    if (keyPressed[K_DOWN] && charLocation.Y < consoleSize.Y - 1)
    {
        Beep(1440, 30);
        charLocation.Y++; 
    }

    if (keyPressed[K_RIGHT] && charLocation.X < 26)//consoleSize.X - 1)
    {
        Beep(1440, 30);
        charLocation.X++;
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
}

void render()
{
    // clear previous screen
    
    Standard();
    
    //render the game
    MenuScreen();
    //render test screen code (not efficient at all)
    const WORD colors[] =   {
	                            0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	                            0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	                        };
    
    // render time taken to calculate this frame

    FPSInfo();
    TIMINGInfo();


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*Put function here*/
    
    if (press == true)
    {
        Standard();

        TIMINGInfo();
        FPSInfo();

        TetrisGameplay();
    }
}

COORD FindCoordinates (short n1, short n2)
{
    COORD location;

    location.X = n1; 
    location.Y = n2;

    return location;
}

void testing ()
{
    int x = 1;// Column 1
    int y = 5;// Row 5
    // Start position of the text 

    gotoXY(24,2); // Placing title

    cout <<   "gotoXY(x,y) Demonstration..";

    for (x=1;x<27;x++)  // Moves the text to the right
    {
        gotoXY(x,y);
        cout << "* column " << x <<  ", row " << y << "!";

        Sleep(200);
        gotoXY(x,y); // Locate the asterisk
	    cout << " "; // Remove it from screen, so we don't have a trail of asterisks
    }
    x--; // Remove 1 from x, so we start where the text is now located

    for (y=5;y<23;y++) // Moves the text down the screen
    {
        Sleep(200);
        gotoXY(x,y);
	    cout << "                                   "; // Remove the line of text

        Sleep(200);

        gotoXY(x,y+1);
        cout << "* column " << x << ", row " << y+1 << "!"; // Print new text line
    }
    Sleep(800);

    for (y=23;y>8;y--) // Moves text up the screen to row 8
    {
        Sleep(200);

        gotoXY(x,y);
	    cout << "                                   ";
        Sleep(200);

        gotoXY(x,y-1);
        cout << "* column " << x << ", row " << y-1 << "!";
    }

    Sleep(1000); // Program finished, wait 1 second
    gotoXY(23,24);
    cout << "Press any key to continue . . ."; // Let user know we're done
    gotoXY(23,24); // Cursor to blink on the letter 'P' of 'Press.. ', above
}

void TetrisGameplay()
{
    TetrisUI();
    gotoXY(charLocation);
    charLocation.Y++;
    cout << (char)1;

    if (charLocation.Y > 24)
    {
        charLocation.Y--;
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
    colour(0x59);
    std::cout << elapsedTime << "secs" << std::endl;
}

void Standard()
{
    colour(0x0F);
    cls();
}
