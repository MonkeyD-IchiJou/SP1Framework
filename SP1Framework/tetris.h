#ifndef _TETRIS_H
#define _TETRIS_H

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

using std::string;

const size_t height = 23;
const size_t width = 14;

struct SetArt
{
    char tetris_map[height][width];
};

SetArt tetris_standard_map();

//In game.cpp file
void TIMINGInfo();
void FPSInfo();
void TetrisGameplay();
void Standard();

void render_longline(COORD c);
void render_longlineR(COORD c);
void spawn_new_block();


//In menu_screen.cpp file
void MenuScreen();
void Paused_Screen();

//In print_shapes.cpp file
char BLocksShape();

//In 8bit_music.cpp
void menu_music();

void testingOnly(int x, int y);

#endif // _TETRIS_H