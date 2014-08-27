#include "game.h"
#include "Framework\console.h"
#include "tetris.h"
#include "Gameplay.h"

void renderStartScreen (COORD c)
{
<<<<<<< 95fd45bd0ce3d587b31acfe66e2d0789979e4f93
<<<<<<< c13c1255e165b872f5838b70dc44b4f9e873fe1f
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
=======
	gotoXY(13, 2);
>>>>>>> f8213adeafda100c0830681ed428d0b50541cf19
	colour(0xE);
=======
	gotoXY(11, 2);
>>>>>>> c9ef37fe465ca758d5453bae3a28c87137c42636
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
>>>>>>> d7d7cad63f56c04b595d110c2bf4b8f3ab4c53b5

    gotoXY(30, 15);
	colour(Cyan);
    cout << "Please press ENTER";
}