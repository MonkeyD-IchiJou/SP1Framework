#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

void renderStartScreen (COORD c)
{
<<<<<<< 8d59e3cc1206155ee65fb0dd250b9834595be412
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

	gotoXY(30, 15);
	colour(Green);
    cout << "Press ENTER to start";
}
=======

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
>>>>>>> 0698cb49d5c3180f962311604c02fc4f2b324207
