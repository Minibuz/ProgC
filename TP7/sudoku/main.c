#include <stdio.h>

#include "sudoku.h"
#include "in_out.h"
#include "affichage.h"

int main(int argc, char* argv[]){
	Board B;
	int number_of_possible_grid;
	number_of_possible_grid = 0;

	fread_board(argv[1], B);

  /* Create the window */

	int width=GRID_WIDTH*GRID_SCALE;
	int height=GRID_HEIGHT*GRID_SCALE;
	MLV_create_window("Sudoku", "Sudoku", width*2, height);

  	draw_board(B);
	MLV_actualise_window();


  /* Main game loop */

	MLV_Event event = MLV_NONE;
	MLV_Keyboard_button key_button;
	MLV_Mouse_button mouse_button;
	MLV_Button_state mouse_state;
	int x_pixel, y_pixel, x_pos, y_pos;

  	while (!(event == MLV_KEY && key_button == MLV_KEYBOARD_ESCAPE)) {
    	event = MLV_wait_event(
				&key_button,
				NULL,
				NULL,
				NULL,
				NULL,
				&x_pixel,
				&y_pixel,
				&mouse_button,
				&mouse_state
			);

		if (event == MLV_MOUSE_BUTTON && mouse_state == MLV_RELEASED) {
			
			x_pos = x_pixel/GRID_SCALE;
			y_pos = y_pixel/GRID_SCALE;
			printf("Mouse click on (%d,%d)\n", x_pos, y_pos);

			if(mouse_button == MLV_BUTTON_LEFT && x_pos<GRID_WIDTH && y_pos<GRID_HEIGHT) {
				printf("Mouse click validated on (%d,%d)\n", x_pos, y_pos);
				draw_numbers(width,height);
				MLV_actualise_window();
			}
		}
 	}

  	MLV_free_window();

  	return 0;
}
