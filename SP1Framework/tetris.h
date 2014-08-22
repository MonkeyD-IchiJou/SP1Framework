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

//In help_screen.cpp file
void HelpScreen();

//In print_shapes.cpp file
char BLocksShape();

//In music_screen.cpp file
void MusicScreen();

//In 8bit_music.cpp
void menu_music();
void Playmusic();

#endif // _TETRIS_H



<<<<<<< 9c93694bdeeb5340ac49fa7edd003eef7e69dd48
<<<<<<< 799e80efabbe725e5f8ebfbfc6cd87cab6305b66
void testingOnly(int x, int y);

=======
>>>>>>> 21188ee6b63b1d789dfc0cedc831b39a4f8f434b
#endif // _TETRIS_H
=======
>>>>>>> 3dc107a1e9f154c764238b05d4954d12ffbf1fb3
