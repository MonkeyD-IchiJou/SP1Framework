#include "game.h"
#include "Framework\console.h"
#include "tetris.h"
#include "Gameplay.h"

void renderStartScreen (COORD c)
{
	colour(Yellow);
	/*
	gotoXY(14, 2);
	cout << "*******" << " *******" << " *******" << " ******   "  << " ******* " << "   ***** " << endl;
	gotoXY(14, 3);
	cout << "   *   " << " *      " << "    *   " << " *     *  "  << "    *    " << "  *    *" << endl;
	gotoXY(14, 4);
	cout << "   *   " << " *      " << "    *   " << " *     *  "  << "    *    " << "   *      " << endl;
	gotoXY(14, 5);
	cout << "   *   " << " *******" << "    *   " << " ******   "  << "    *    " << "    *     " << endl;
	gotoXY(14, 6);
	cout << "   *   " << " *      " << "    *   " << " *     *  "  << "    *    " << "     *    "<< endl;
	gotoXY(14, 7);
	cout << "   *   " << " *      " << "    *   " << " *      * "  << "    *    " << " *    * "<< endl;
	gotoXY(14, 8);
	cout << "   *   " << " *******" << "    *   " << " *       *"  << " ******* " << " ***** "<< endl;
	gotoXY(13, 2);*/
	
	gotoXY(11, 2);
	cout << " *******  *******  *******   ******     *******    *****   " << endl;
	gotoXY(11, 3);
	cout << "    *     *           *      *     *       *       *    *  " << endl;
	gotoXY(11, 4);
	cout << "    *     *           *      *     *       *        *      " << endl;
	gotoXY(11, 5);
	cout << "    *     *******     *      ******        *          *    " << endl; 
	gotoXY(11, 6);
	cout << "    *     *           *      *     *       *            *  " << endl;
	gotoXY(11, 7);
	cout << "    *     *           *      *      *      *       *    *  " << endl;
	gotoXY(11, 8);
	cout << "    *     *******     *      *       *  *******    *****   " << endl;

    gotoXY(30, 15);
	colour(Cyan);
    cout << "Please press ENTER";
}