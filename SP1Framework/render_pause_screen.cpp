#include "game.h"
#include "tetris.h"
#include "Framework\console.h"
#include "Gameplay.h"

void RenderPauseScreen(COORD c)
{
	writeToBuffer(c, ">>", 0x0E);
	
	c.X = 0;
	c.Y = 7;
	writeToBuffer(c, "*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=", 0x0C);

	c.X = 0;
	c.Y = 30;
	writeToBuffer(c, "*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=*/=", 0x0C);

	// pause title
	ifstream pause;
	string text;

	pause.open("pause.txt");
	c.X = 16;
	c.Y = 1;
	while( !pause.eof() )
	{
		getline(pause, text);
		writeToBuffer(c, text, 0x0D);
		c.Y++;
	}
	pause.close();

	// resume game
	ifstream resume;
	string resumetext;

	resume.open("resume.txt");
	c.X = 6;
	c.Y = 10;
	while( !resume.eof() )
	{
		getline(resume, resumetext);
		writeToBuffer(c, resumetext, 0x0A);
		c.Y++;
	}
	resume.close();

	// restart game
	ifstream restart;
	string retext;

	restart.open("restart.txt");
	c.X = 6;
	c.Y = 15;
	
	while( !restart.eof() )
	{
		getline(restart, retext);
		writeToBuffer(c, retext, 0x0B);
		c.Y++;
	}
	restart.close();

	//return to main
	ifstream main;
	string maintext;

	main.open("main.txt");
	c.X = 9;
	c.Y = 24;

	while( !main.eof() )
	{
		getline(main, maintext);
		writeToBuffer(c, maintext, 0x0F);
		c.Y++;
	}
	main.close();
}