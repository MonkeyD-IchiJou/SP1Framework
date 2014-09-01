#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"

void renderStartScreen(COORD c)
{
<<<<<<< af641be0ae46d1e3f03e21a3fabb966d0139b5df
    writeToBuffer(c, (char)4);
}
=======
	gotoXY(14, 2);
	colour(Yellow);
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
        
    colour(Magenta);
    gotoXY(30, 10);
    cout << "Press press ENTER";
}
>>>>>>> 41ca18c300f2574f98c3a154eeeb40c4994661cf
