#ifndef __SUDOKU__
#define __SUDOKU__

typedef int Board[9][9];

void initialize_empty_board(Board grid);
void print_board(Board grid);
void solve_grid(Board grid, int max);
void solving_grid_count(Board grid, int max,int* count);

#endif
