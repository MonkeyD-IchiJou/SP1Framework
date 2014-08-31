#ifndef _TETRIS_H
#define _TETRIS_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

using std::ifstream;
using std::string;
using std::ofstream;

struct Location
{
    COORD ScLocation;   //Start Screen 
    COORD MmLocation;   // main menu screen
    COORD OptLocation;  // option screen
	COORD PsLocation;   // pause screen
    COORD TmLocation;   // tetris map 
    COORD BdLocation;   // border location
    COORD NLineLocation; // show next line block
    COORD StoreLineLocation; // show the storing block
};

enum colour
{
    White = 0xF,
    Green = 0xA,
    Red = 0xC,
    Yellow = 0xE,
    Cyan = 0xB,
    Magenta = 0xD,
    DarkGreen = 0x2
};

struct storeNswitch
{
    bool storeornot;  
    bool storeOredi;
    int switchcount;
};

void showNextBlock(COORD c, int type);
void storeBlock(COORD c, bool switchOrstore, int type);
void blockcolorinit();

// in render_menu.cpp
void renderMenu(COORD c);

// in render_start_screen.cpp
void renderStartScreen(COORD c);

// in render_option.cpp
void renderOption(COORD c);

// in render_pause.cpp
void renderPause(COORD c);

// in render_pause_screen.cpp
void RenderPauseScreen(COORD c);


#endif // _TETRIS_H