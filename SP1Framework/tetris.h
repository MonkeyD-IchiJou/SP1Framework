#ifndef _TETRIS_H
#define _TETRIS_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

using std::ifstream;
using std::string;
using std::ofstream;

struct Location
{
    COORD MmLocation;   // main menu screen
<<<<<<< f42c40c2adcab91354e2f34e613f9182af718cb4
    COORD OptLocation;  // option screen
	COORD PsLocation;   // pause screen
    COORD TmLocation;   // tetris map 
    COORD BdLocation;   // border location
=======
    COORD OptLocation;  // option screen (havent done yet)
    COORD TmLocation;   //tetris map 
	COORD PsLocation;   // pause screen
    COORD BdLocation;   //border location
>>>>>>> dd88a835f519b64050d0c5393a72bb9806699e88
};

enum gameState
{
    START_SCREEN,
    MENU_SCREEN,
    GAMEPLAY_SCREEN,
    OPTION_SCREEN,
	PAUSE_SCREEN
};

<<<<<<< beae32c5d0bc41106470374b59bb9102ab67af32
=======
enum BlocksType
{
    LONG_TYPE,
    Z_TYPE,
    L_TYPE,
    Sq_TYPE,
    T_TYPE
};

enum colour
{
    White = 0xF,
    Green = 0xA,
    Red = 0xC,
    Yellow = 0xE,
    Cyan = 0xB,

};

>>>>>>> 4d78c908850b7c8d4ed128924b39bb047bb4e5c2
void FPSInfo();
void TIMINGInfo();

// in render_menu.cpp
void renderMenu(COORD c);

// in render_start_screen.cpp
void renderStartScreen(COORD c);

// in render_option.cpp
void renderOption(COORD c);

// in render_pause.cpp
void renderPause(COORD c);

// in render_gameplay.cpp
void printTetrisMap(COORD c);
void DrawMap(COORD c);
void DrawBorder(COORD c);

void initiate(COORD l, COORD Z, COORD L, COORD S, COORD T);

void print_l_blocks(int change);
void print_Z_blocks(int change);
void print_L_blocks(int change);
void print_Sq_blocks(int change);
void print_T_blocks(int change);

void printBlocks(int type, int change);
<<<<<<< beae32c5d0bc41106470374b59bb9102ab67af32

void lukris();
=======
// in render_pause_screen.cpp
void RenderPauseScreen(COORD c);

>>>>>>> 4d78c908850b7c8d4ed128924b39bb047bb4e5c2
#endif // _TETRIS_H