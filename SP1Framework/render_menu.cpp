#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

void renderMenu (COORD c)
{
    gotoXY(c);
    cout << ">>";

<<<<<<< 87aa194b1bd5ed24b346043231c8a90fe4dec7a9
    gotoXY(30, 10);
=======
    gotoXY(32, 5);
    colour(Green);
>>>>>>> 88020fb2bd62eb19a3dbe39bd3d47221ba78f6cc
    cout << "Start Game";

    gotoXY(30, 15);
    cout << "Option";

<<<<<<< 87aa194b1bd5ed24b346043231c8a90fe4dec7a9
=======
	gotoXY(32, 15);
	colour(Cyan);
	cout << "Return to start screen";

	gotoXY(32, 20);
	colour(Magenta);
	cout << "EXIT GAME";
	
>>>>>>> 88020fb2bd62eb19a3dbe39bd3d47221ba78f6cc
    gotoXY(58, 25);
    cout << "*Up/Down to select";

    gotoXY(58, 27);
    cout << "*Enter key to confirm";
}