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

<<<<<<< bd4cbfb6287179dbfd666aad9e8e624f0e06f995
=======
//In print_screen.cpp file
void TetrisUI ();


//In print_blocks.cpp file
void SquareBlocks ();

>>>>>>> 404fe67a56df774e032bd0fe4f2ec38fa4390284

//In 8bit_music.cpp
void menu_music();


#endif // _TETRIS_H