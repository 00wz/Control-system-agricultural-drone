#include <stdio.h>
#include <stdbool.h>
#include "carts.h"
#include "draw_functions.h"
#include "curses/curses.h"

bool closeProgrammFlag = false;

void start()
{
	init_head(10, 10);
	//enable_draw();
	
	//enable arrow control
	keypad(stdscr, true);
}

void process_input(int input_char)
{
	switch(input_char)
	{
		//enter to close program
		case '\n':
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

void update()
{
	//draw_clear_field();
	//drow_carts(head);
	
	//waiting for and processing keyboard input
	int inp = getch();
	process_input(inp);
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
