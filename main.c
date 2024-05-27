#include <stdbool.h>
#include "carts.h"
#include "draw_functions.h"
#include "curses/curses.h"
#include "pumpkins.h"

bool closeProgrammFlag = false;

void start()
{
	init_head(10, 10);
	enable_draw();
	//enable arrow control
	keypad(stdscr, true);
	halfdelay(1);
	
	//init pumpkins system
	int row, col;
	get_shape(&row, &col);
	init_pumpkins(1, col - 2, 1, row - 2);
	
}

void process_input(int input_char)
{
	switch(input_char)
	{
		case '\n'://press enter to close program
			closeProgrammFlag = true;
			break;
		case KEY_LEFT:
			move_carts(direction_left);
			break;
		case KEY_RIGHT:
			move_carts(direction_right);
			break;
		case KEY_UP:
			move_carts(direction_forward);
			break;
		case KEY_DOWN:
			move_carts(direction_back);
			break;
	}
}

bool check_cart(struct position pos)
{
	return contain_cart(head, pos);
}

//conio.h and curses.h conflict. so let's move kbhit to another file.
extern int usr_kbhit();

void update()
{
	draw_clear_field();
	drow_carts(head);
	draw_pumpkins(pumpkins, pumpkins_count);

	int inp = getch();
	process_input(inp);
	
	update_pumpkins(check_cart);
}

void end()
{
	disable_draw();
	clean_carts();
}

int main(int argc, char **argv)
{
	start();
	
	while(!closeProgrammFlag)
	{
		update();
	}
	
	end();
	
	return 0;
}
