#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

void renderOption (COORD c)
{
	colour(Yellow);
	gotoXY(18, 2);  
	cout << " *****  " << "******" << " *******" << " *******" << "  ***** " << " **    *" << endl;
	gotoXY(18, 3);
	cout << "*     * " << "*    *" << "    *   " << "    *   " << " *     *" << " * *   *" << endl;
	gotoXY(18, 4);
	cout << "*     * " << "******" << "    *   " << "    *   " << " *     *" << " *  *  *" << endl;
	gotoXY(18, 5);
	cout << "*     * " << "*     " << "    *   " << "    *   " << " *     *" << " *   * *" << endl;
	gotoXY(18, 6);
	cout << " *****  " << "*     " << "    *   " << " *******" << "  ***** " << " *    **" << endl;

    gotoXY(c);
	colour(White);
    cout << ">>";

    gotoXY(34, 10);
	colour(Green);
    cout << "Change Colour";

    gotoXY(34, 15);
	colour(Magenta);
    cout << "Return to Main Menu";

    gotoXY(58, 25);
    cout << "*Up/Down to select";

    gotoXY(58, 27);
    cout << "*Enter key to confirm";
}