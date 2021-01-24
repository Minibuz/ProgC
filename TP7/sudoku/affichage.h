#include <stdio.h>
#include <MLV/MLV_all.h>

#include "sudoku.h"

#define GRID_WIDTH  9
#define GRID_HEIGHT 9
#define GRID_SCALE 30

void draw_board(Board g);
void draw_numbers(int width, int row);