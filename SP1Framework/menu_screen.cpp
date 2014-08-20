#include "game.h"
#include "Framework\console.h"
#include "tetris.h"

void MenuScreen()
{
        //Title of the game
		/*cout << endl;
		cout << "*******" << " *******" << " *******" << " ******   "  << " ******* " << "   ***** " << endl;
		cout << "   *   " << " *      " << "    *   " << " *     *  "  << "    *    " << "  *    *" << endl;
		cout << "   *   " << " *      " << "    *   " << " *     *  "  << "    *    " << "   *      " << endl;
		cout << "   *   " << " *******" << "    *   " << " ******   "  << "    *    " << "    *     " << endl;
		cout << "   *   " << " *      " << "    *   " << " *     *  "  << "    *    " << "     *    "<< endl;
		cout << "   *   " << " *      " << "    *   " << " *      * "  << "    *    " << " *    * "<< endl;
		cout << "   *   " << " *******" << "    *   " << " *       *"  << " ******* " << " ***** "<< endl;*/

        gotoXY(20, 10);
        cout << "Press Enter to play game" << endl;
}