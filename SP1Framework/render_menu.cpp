#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

void renderMenu (COORD c)
{
    
    
    gotoXY(c);
	colour(White);
    cout << ">>";

<<<<<<< 577c1c6ee86514be23a66501e64c3ab889843ffb
    gotoXY(32, 5);
    colour(Green);

=======
    gotoXY(30, 10);
    gotoXY(32, 5);
    colour(Green);
>>>>>>> e72da49ac99736d9f7cb1877b60c4e7ba0748c99
    cout << "Start Game";

    gotoXY(32, 10);
    cout << "Option";

	gotoXY(32, 15);
	colour(Cyan);
	cout << "Return to start screen";

	gotoXY(32, 20);
	colour(Magenta);
	cout << "EXIT GAME";

    gotoXY(58, 25);
    cout << "*Up/Down to select";

    gotoXY(58, 27);
    cout << "*Enter key to confirm";
    colour(0x1A);
}