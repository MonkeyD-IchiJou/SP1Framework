#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

void renderOption (COORD c)
{
	gotoXY(c);
	colour(0xF);
	cout << ">>";

	colour(0xE);
	gotoXY(19, 2);  
	cout << " *****  " << "******" << " *******" << " *******" << "  ***** " << " **    *" << endl;
	gotoXY(19, 3);
	cout << "*     * " << "*    *" << "    *   " << "    *   " << " *     *" << " * *   *" << endl;
	gotoXY(19, 4);
	cout << "*     * " << "******" << "    *   " << "    *   " << " *     *" << " *  *  *" << endl;
	gotoXY(19, 5);
	cout << "*     * " << "*     " << "    *   " << "    *   " << " *     *" << " *   * *" << endl;
	gotoXY(19, 6);
	cout << " *****  " << "*     " << "    *   " << " *******" << "  ***** " << " *    **" << endl;

	colour(0xB);
	gotoXY(35, 10);
	cout << "Change colour";

	gotoXY(35, 15);
	cout << "Return to Main Menu";

	colour(0xE);
	gotoXY(58, 25);
    cout << "*Up/Down to select";

    gotoXY(58, 27);
    cout << "*Enter key to confirm";
}