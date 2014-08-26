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
    COORD OptLocation;  // option screen
	COORD PsLocation;   // pause screen
    COORD TmLocation;   // tetris map 
    COORD BdLocation;   // border location
};

enum gameState
{
    START_SCREEN,
    MENU_SCREEN,
    GAMEPLAY_SCREEN,
    OPTION_SCREEN,
	PAUSE_SCREEN
};

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

void lukris();
#endif // _TETRIS_H