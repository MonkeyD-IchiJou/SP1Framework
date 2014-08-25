#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

void renderOption (COORD c)
{
	gotoXY(c);
	colour(0xF);
	cout << ">>";

	colour(0xE);
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

	colour(0xB);
	gotoXY(32, 10);
	cout << "Change colour";

	gotoXY(32, 15);
	cout << "Return to Main Menu";

	colour(0xE);
	gotoXY(58, 25);
    cout << "*Up/Down to select";

    gotoXY(58, 27);
    cout << "*Enter key to confirm";
}