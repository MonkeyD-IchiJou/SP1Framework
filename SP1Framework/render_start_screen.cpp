#include "game.h"
#include "Framework\console.h"
#include "tetris.h"
#include "Gameplay.h"

void renderStartScreen (COORD c)
{
<<<<<<< 3c933a5cf0c2485b2858fb536fbeb3e07674b60d
	colour(Yellow);
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
=======
	colour(0xE);
	cout << " *******  *******  *******   ******     *******    *****   " << endl;
	colour(0xD);
	cout << "    *     *           *      *     *       *       *    *  " << endl;
	colour(0xC);
	cout << "    *     *           *      *     *       *        *      " << endl;
	colour(0xB);
	cout << "    *     *******     *      ******        *          *    " << endl; 
	colour(0xA);
	cout << "    *     *           *      *     *       *            *  " << endl;
	colour(0xF);
	cout << "    *     *           *      *      *      *       *    *  " << endl;
	colour(0x2);
	cout << "    *     *******     *      *       *  *******    *****   " << endl;
>>>>>>> d7d7cad63f56c04b595d110c2bf4b8f3ab4c53b5

    gotoXY(30, 15);
	colour(Cyan);
    cout << "Please press ENTER";
}