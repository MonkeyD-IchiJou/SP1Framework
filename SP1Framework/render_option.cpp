#include "game.h"
#include "Framework\console.h"
#include "tetris.h"
#include "Gameplay.h"

void renderOption (COORD c)
{
	gotoXY(c);
	colour(White);
	cout << ">>";

	colour(Yellow);
	gotoXY(17, 2);  
	cout << " *****  " << "******" << " *******" << " *******" << "  ***** " << " **    *" << endl;
	gotoXY(17, 3);
	cout << "*     * " << "*    *" << "    *   " << "    *   " << " *     *" << " * *   *" << endl;
	gotoXY(17, 4);
	cout << "*     * " << "******" << "    *   " << "    *   " << " *     *" << " *  *  *" << endl;
	gotoXY(17, 5);
	cout << "*     * " << "*     " << "    *   " << "    *   " << " *     *" << " *   * *" << endl;
	gotoXY(17, 6);
	cout << " *****  " << "*     " << "    *   " << " *******" << "  ***** " << " *    **" << endl;

	colour(Cyan);
	gotoXY(32, 10);
	cout << "Change colour";

	gotoXY(32, 15);
	cout << "Return to Main Menu";

	colour(Yellow);
	gotoXY(58, 25);
    cout << "*Up/Down to select";

    gotoXY(58, 27);
    cout << "*Enter key to confirm";
}