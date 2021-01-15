#include <stdio.h>

#include "sudoku.h"
#include "in_out.h"

#define max 9

int main(int argc, char* argv[]){
  Board B;
  int number_of_possible_grid;
  number_of_possible_grid = 0;

  fread_board(argv[1], B);

  print_board(B);

  solve_grid(B,max);

  solving_grid_count(B,max,&number_of_possible_grid);
  printf("For grid %s, there is %d solutions\n",argv[1],number_of_possible_grid);

  return 0;
}
