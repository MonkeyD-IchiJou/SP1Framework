#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

void renderOption (COORD c)
{
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
	cout << ">>";

	gotoXY(35, 9);
	cout << "Change colour";

	gotoXY(35, 14);
	cout << "Return to Main Menu";
}