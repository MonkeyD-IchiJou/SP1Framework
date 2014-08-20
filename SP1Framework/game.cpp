// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
<<<<<<< d424e59c80c4a5e5ee3591644886a4ce5d49be02

//#include <iostream>
//#include <iomanip>
=======
#include "tetris.h"

#include <iostream>
#include <iomanip>
>>>>>>> 1cde7b25c2b20c2d421e9d2235298c997a49c4f4

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD charLocation;
COORD consoleSize;

void init()
{
    // Set precision for floating point output
    std::cout << std::fixed << std::setprecision(3);

    SetConsoleTitle(L"SP1 Framework");

    // Sets the console size, this is the biggest so far.
    setConsoleSize(50, 28);

    // Get console width and height
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */     

    /* get the number of character cells in the current buffer */ 
    GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
    consoleSize.X = csbi.srWindow.Right + 1;
    consoleSize.Y = csbi.srWindow.Bottom + 1;

    // set the character to be in the center of the screen.
    charLocation.X = consoleSize.X / 2;
    charLocation.Y = 0;

    elapsedTime = 0.0;
}

void shutdown()
{
    // Reset to white text on black background
    colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void getInput()
{    
    keyPressed[K_UP] = isKeyPressed(VkKeyScan('w'));
    keyPressed[K_DOWN] = isKeyPressed(VkKeyScan('s'));
    keyPressed[K_LEFT] = isKeyPressed(VkKeyScan('a'));
    keyPressed[K_RIGHT] = isKeyPressed(VkKeyScan('d'));
    keyPressed[K_ONE] = isKeyPressed(VkKeyScan('x'));

    keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
}

void update(double dt)
{
    
    // get the delta time
    elapsedTime += dt;
    deltaTime = dt;

    // Updating the location of the character based on the key press
    if (keyPressed[K_UP] && charLocation.Y > 0)
    {
<<<<<<< d424e59c80c4a5e5ee3591644886a4ce5d49be02
    Beep(1000, 100);
    charLocation.Y--;
    } 
=======
        Beep(1440, 30);
        charLocation.Y--; 
    }
>>>>>>> 1cde7b25c2b20c2d421e9d2235298c997a49c4f4

    if (keyPressed[K_LEFT] && charLocation.X > 0)
    {
    Beep(1000, 100);
    charLocation.X--; 
    }

    if (keyPressed[K_DOWN] && charLocation.Y < consoleSize.Y - 1)
    {
    Beep(1000, 100);
    charLocation.Y++; 
    }

    if (keyPressed[K_RIGHT] && charLocation.X < consoleSize.X - 1)
    {
    Beep(1000, 100);
    charLocation.X++; 
    }

    // Pauses the game if player hits the escape key
    if (keyPressed[K_ESCAPE])
<<<<<<< d424e59c80c4a5e5ee3591644886a4ce5d49be02
    {
        system("pause.exe");
    }

=======
        g_quitGame = true;    
    
>>>>>>> 1cde7b25c2b20c2d421e9d2235298c997a49c4f4
}

void render()
{
    // clear previous screen
    cls();

    
    //render time taken to calculate this frame
    gotoXY(40, 0);

    //render the game

    //render test screen code (not efficient at all)
    const WORD colors[] =   {
<<<<<<< d424e59c80c4a5e5ee3591644886a4ce5d49be02
    0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
    0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6,
    };
=======
	                        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	                        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	                        };
    int y = 0;
	for (int i = 0; i < 12; ++i)
	{
		gotoXY(3*i,i+1);
		colour(colors[i]);
		std::cout << "WOW";
        y = i;
	}
>>>>>>> 1cde7b25c2b20c2d421e9d2235298c997a49c4f4

    for (int i = 0; i < 12; ++i)
    {
        gotoXY(3*i,i+1);
        colour(colors[i]);
        std::cout << "WOW";
    }
    
    // render time taken to calculate this frame
    gotoXY(70, 0);

    colour(0x1A);
    std::cout << 1.0 / deltaTime << "fps" << std::endl;

    gotoXY(0, 0);
    colour(0x59);
    std::cout << elapsedTime << "secs" << std::endl;

    //_getch();// render character
    gotoXY(charLocation);
<<<<<<< d424e59c80c4a5e5ee3591644886a4ce5d49be02
    colour(0x0C);
    std::cout << (char)1;
}



=======
    charLocation.Y++;
    cout << (char)1;
    Sleep(200);

    int x = charLocation.Y ;
    if (x == y)
    {
        charLocation.Y--;
        gotoXY(0, 0);
    }

    gotoXY(charLocation);
    
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
    WaitKey();  // Wait for a keypress
}

void WaitKey()
{
   while (_kbhit()) _getch(); // Empty the input buffer
   _getch(); // Wait for a key
   while (_kbhit()) _getch(); // Empty the input buffer (some keys sends two messages)
}
>>>>>>> 1cde7b25c2b20c2d421e9d2235298c997a49c4f4
