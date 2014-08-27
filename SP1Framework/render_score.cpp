#include "game.h"
#include "Framework\console.h"
#include "tetris.h"
#include "Gameplay.h"
#include <string>
#include <fstream>

void renderScore()
{
	/*int score;
	scorefile();
	std::ofstream outData;
	std::string name;
	cout << "Your score is " << score;
	cin >> name;
	cout << endl;*/

	int tscore = 0;
    int fline = 0;
    for (int i = 0 ; i < 5; i++ ) 
    { 
        cin >> fline ;
        if (fline >= 1 && fline <= 4)
        {
            if(fline == 1)
            {
                tscore += 10;
            }
            else if( fline == 2)
            {
                tscore += 25;
            }
            else if ( fline == 3)
            {
                tscore += 50;
            }
            else if ( fline == 4)
            {
                tscore += 100;
            }
        }
        else if (fline >= 5)
        {
            cout << " you must be a hacker to attain this score!" << endl;
        }
    }
    cout << "Your Score -> " << tscore << endl;
}

void scorefile()
{
	int score;
	std::ifstream scorefile;
	cout << "Score is: " << endl;

	scorefile.open("highscore.txt"); 
	scorefile >> score;

	while (scorefile !=0)
	{
		cout << "\n" << score << "\t";
	}
}