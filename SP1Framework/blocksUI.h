#ifndef _TETRIS_UI_H
#define _TETRIS_UI_H

struct blocks
{
    char tetris_map[23][14];
    char SqBlock[2][2];
};

void TetrisMap(short x = 0, short y = 0);
char BLocksShape();

#endif // _TETRIS_UI_H