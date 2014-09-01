#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

void renderMenu (COORD c)
{
    
        ifstream inlukris;
        string hi;

        inlukris.open ("Bg.txt");

        while (!inlukris.eof())
        {
            colour(Green);
            getline (inlukris,hi);
            cout << hi << endl;
        }

        inlukris.close();

    gotoXY(c);
	colour(White);
    cout << ">>";

    gotoXY(30, 10);
    gotoXY(32, 5);
    colour(Green);
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