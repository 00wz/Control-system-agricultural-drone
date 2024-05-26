#include <stdbool.h>
#include "carts.h"
#include "draw_functions.h"
#include "curses/curses.h"
#include <stdio.h>

bool closeProgrammFlag = false;

void start()
{
	init_head(10, 10);
	enable_draw();
	
	//enable arrow control
	keypad(stdscr, true);
	//when starting the program there are already characters 
	//in the input stream for some reason.
	//getch is not working properly. so let's clear the stdin
	fflush(stdin);
}

void process_input(int input_char)
{
	switch(input_char)
	{
		//press enter to close program
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

//conio.h and curses.h conflict. so let's move kbhit to another file.
extern int usr_kbhit();

void update()
{
	//waiting for and processing keyboard input
	//while(usr_kbhit())
	//{
		int inp = getch();
		process_input(inp);
	//}
	
	draw_clear_field();
	drow_carts(head);
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
