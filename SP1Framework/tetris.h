#ifndef _TETRIS_H
#define _TETRIS_H

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

//In game.cpp file
COORD FindCoordinates(short n1, short n2);
void TIMINGInfo();
void FPSInfo();
void TetrisGameplay();
void Standard();
void SQUARE();


//In menu_screen.cpp file
void MenuScreen();
void Paused_Screen();


//In 8bit_music.cpp
void MenuMusic ();


#endif // _TETRIS_H