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
	gotoXY(13, 2);
	colour(Yellow);
	cout << "*******   *******  *******   ******    *******    ***** " << endl;
	gotoXY(13, 3);
	cout << "   *      *           *     *      *      *      *     *" << endl;
	gotoXY(13, 4);
	cout << "   *      *           *     *     *       *       *      " << endl;
	gotoXY(13, 5);
	cout << "   *      *******     *     ******        *        *     " << endl;
	gotoXY(13, 6);
	cout << "   *      *           *     *     *       *         *    "<< endl;
	gotoXY(13, 7);
	cout << "   *      *           *     *      *      *    *     * "<< endl;
	gotoXY(13, 8);
	cout << "   *      *******     *     *       *  *******  ***** "<< endl;

	/*ifstream inlukris;
	string hi;

	inlukris.open ("Bg.txt");

	while (!inlukris.eof())
	{
		colour(Green);
		getline (inlukris,hi);
		cout << hi << endl;
	}

	inlukris.close();*/

	colour(Magenta);
	gotoXY(32, 15);
	cout << "Please press ENTER";
}
>>>>>>> 9e9db701eb7626b55aa40b0c2ba974df1dfb451c
