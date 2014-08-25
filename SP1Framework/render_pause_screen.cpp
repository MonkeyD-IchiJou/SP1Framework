#include "game.h"
#include "tetris.h"
#include "Framework\console.h"

void RenderPauseScreen(COORD c)
{
	/*clock_t begin=clock();
	clock_t pause, resume;
	
	int now, later;
	int num = 0;
	
	now = clock();
	later = now + num;
	
	while (clock() < later)
	{
	}

	pause= now;
	resume= later;

	clock_t totalPause = 0;
	totalPause += (later - now);
	
	cout << totalPause;

	void wait (int sec);
	{
	clock_t endwait;
	endwait = clock()+ sec * CLOCKS_PER_SEC;
	while ( clock() < endwait) {}
	}
	*/


	gotoXY(c);
	cout << "                    >>";

	gotoXY(30, 10);
	cout << "Continue Game";

	gotoXY(30, 15);
	cout << "Main Menu";

	gotoXY(58, 25);
	cout << "*Up/Down to select";

	gotoXY(58, 27);
	cout << "*Enter key to confirm";


}
