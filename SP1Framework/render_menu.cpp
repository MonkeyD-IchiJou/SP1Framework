#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

void renderMenu (COORD c)
{
<<<<<<< 6b6f6918ec99e0cb9e4157bc837967d3701766ff
    
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
=======

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
>>>>>>> 2fef80e018b397603e49e6d5824c9bc2196695f3

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