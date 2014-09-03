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
    COORD ScLocation;   // Start Screen 
    COORD MmLocation;   // main menu screen
    COORD ILocation;    // Instruction screen
    COORD CrLocation;   // Credit screen
	COORD CLocation;	// Change shape
	COORD PsLocation;   // pause screen
    COORD TmLocation;   // tetris map 
    COORD BdLocation;   // border location
    COORD NLineLocation; // show next line block
    COORD StoreLineLocation; // show the storing block
    COORD ShowScore; // show score
    COORD FinalResult; // show final score
	COORD Background;
};

enum colour
{
    GreyBlue = 0x3,
    Black = 0x0,
    Blue = 0x1,
    DarkGreen = 0x2,
    Brown = 0x6,
    Green = 0xA,
    Cyan = 0xB,
    Red = 0xC,
    Magenta = 0xD,
    Yellow = 0xE,
    Grey = 0x7,
    White = 0xF

};

struct storeNswitch
{
    bool storeornot;  
    bool storeOredi;
    int switchcount;
};

void showNextBlock(COORD c, int type);                          //show the next blocks on the screen & aesthetic
void storeBlock(COORD c, bool switchOrstore, int type);         
void blockcolorinit();                                          //initiate for all the blocks color

// in render_menu.cpp
void renderMenu(COORD c);

// in render_start_screen.cpp
void renderStartScreen(COORD c);

// in render_instruction.cpp
void renderInstruction(COORD c);

// in render_credit.cpp
void renderCredit(COORD c);

// in render_change.cpp
void renderChange(COORD c);

// in render_pause.cpp
void renderPause(COORD c);

// in render_pause_screen.cpp
void RenderPauseScreen(COORD c);

// in render_end_game.cpp
void renderResult(COORD c);


#endif // _TETRIS_H