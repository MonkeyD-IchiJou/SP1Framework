#include "game.h"
#include "Framework\console.h"
#include "tetris.h"
#include "Gameplay.h"

void renderMenu (COORD c)
{
    
    gotoXY(c);
	colour(White);
    cout << ">>";
<<<<<<< f42c40c2adcab91354e2f34e613f9182af718cb4

    gotoXY(32, 5);
	colour(0xA);
=======
    
    gotoXY(35, 10);
    colour(0xA);
>>>>>>> dd88a835f519b64050d0c5393a72bb9806699e88
    cout << "Start Game";

    gotoXY(32, 10);
    cout << "Option";

	gotoXY(32, 15);
	colour(0xB);
	cout << "Return to start screen";

	gotoXY(32, 20);
	colour(0xD);
	cout << "EXIT GAME";
	
	colour(0xE);
    gotoXY(58, 25);
    colour(0xE);
    cout << "*Up/Down to select";

    gotoXY(58, 27);
    cout << "*Enter key to confirm";
}