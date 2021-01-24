#include <stdio.h>

#include "sudoku.h"

void initialize_empty_board(Board grid){

}

/**
 * Print the grid
 * 
 * @param grid The sudoku grid
 */
void print_board(Board grid){
    int i; int j;
    printf("Sudoku:\n");
    for(i=0; i<9; i++) {
        printf("\n-------------------------------------\n");
        for(j=0; j<9; j++) {
            if(j==8) {
                printf("| %d |",grid[i][j]);
                break;
            }
            printf("| %d ",grid[i][j]);
        }
    }
    printf("\n-------------------------------------\n");
}

int is_row_valid(Board grid, int row, int number) {
    int i;
    for(i=0; i<9; i++) {
        if(grid[row][i]==number) {
            return 0;
        }
    }
    return 1;
}

int is_column_valid(Board grid, int column, int number) {
    int i;
    for(i=0; i<9; i++) {
        if(grid[i][column]==number) {
            return 0;
        }
    }
    return 1;
}

int is_area_valid(Board grid, int column, int row, int number) {
    int i,j;

    column = column - column % 3;
    row = row - row % 3;

    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(grid[row+i][column+1]==number) {
                return 0;
            }
        }
    }

    return 1;
}

int is_number_valid(Board grid, int column, int row, int number) {
    if(number<1 || number>9) {
        fprintf(stderr,"Number entered : %d is not between 1 - 9 !\n",number);
    }

    return is_area_valid(grid,column,row,number) && is_row_valid(grid,row,number) && is_column_valid(grid,column,number);
}

int is_grid_full(Board grid, int* row, int* column, int max) {
    int i; int j;

    for(i=0; i<max; i++) {
        for(j=0; j<max; j++) {
            if(grid[i][j] == 0) {
                *row=i; *column=j;
                return 0;
            }
        }
    }

    return 1;
}

void solve_grid(Board grid, int max) {
    int i; int row; int column;

    if(is_grid_full(grid,&row,&column,max)==1) {
        print_board(grid);
        return;
    }

    for(i=1; i<=max; i++) {
        if(is_number_valid(grid,column,row,i)) {
            grid[row][column]=i;
            solve_grid(grid,max);
            grid[row][column]=0;
        }
    }
}

void solving_grid_count(Board grid, int max, int* count) {
    int i; int row; int column;

    if(is_grid_full(grid,&row,&column,max)==1) {
        *count += 1;
        return;
    }

    for(i=1; i<=max; i++) {
        if(is_number_valid(grid,column,row,i)) {
            grid[row][column]=i;
            solving_grid_count(grid,max,count);
            grid[row][column]=0;
        }
    }
}