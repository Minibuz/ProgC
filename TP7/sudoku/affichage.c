#include "affichage.h"

/** Draw a rectangle of the size
 */
void draw_rectangle(int x, int y, MLV_Color line_color, MLV_Color fill_color) {
	MLV_draw_filled_rectangle(
			GRID_SCALE*x,
			GRID_SCALE*y,
			GRID_SCALE,
			GRID_SCALE,
			fill_color
		);
	MLV_draw_rectangle(
			GRID_SCALE*x,
			GRID_SCALE*y,
			GRID_SCALE,
			GRID_SCALE,
			line_color
		);
}

/**
 */
void draw_cell(Board g,int column, int row) {
    draw_rectangle(column, row, MLV_COLOR_GRAY50, MLV_COLOR_BLACK);
    char str[10];
    sprintf(str,"%d",g[column][row]);
    MLV_draw_text(
                GRID_SCALE*column+(GRID_SCALE-10)/2,
				GRID_SCALE*row+(GRID_SCALE-10)/2,
				str,
                MLV_COLOR_WHITE
				);
}

/**
 */
void draw_board(Board g) {
	int i, j;
	for (i = 0; i < GRID_HEIGHT; i++)
		for (j = 0; j < GRID_WIDTH; j++)
			draw_cell(g, i, j);
	MLV_actualise_window();
}

void draw_numbers(int width, int row) {
	int i, j;

	for(i = 0; i<3; i++) { 
		for(j = 0; j<3; j++) {
			MLV_draw_filled_rectangle(
				GRID_SCALE*(12+i+j),
				0,
				1,
				1,
				MLV_COLOR_WHITE
			);
			MLV_draw_rectangle(
				GRID_SCALE*GRID_SCALE*(width+i+j),
				0,
				1,
				1,
				MLV_COLOR_GRAY50
			);

    		char str[10];
    		sprintf(str,"%d",1+i+j);
   			MLV_draw_text(
                GRID_SCALE*i+(GRID_SCALE-10)/2,
				GRID_SCALE*j+(GRID_SCALE-10)/2,
				str,
                MLV_COLOR_WHITE
				);
		}
	}
}