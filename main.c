#include <stdbool.h>
#include "carts.h"
#include "draw_functions.h"
#include "curses/curses.h"
#include "pumpkins.h"
#include "direction.h"

bool closeProgrammFlag = false;

cart *main_dron;

int x_min;
int x_max;
int y_min;
int y_max;

void start()
{
	main_dron = create_head(10, 10);
	enable_draw();
	//enable arrow control
	keypad(stdscr, true);
	halfdelay(1);
	
	//init pumpkins system
	int row, col;
	get_shape(&row, &col);
	x_min = 1;
	x_max = col -2;
	y_min = 1;
	y_max = row - 2;
	init_pumpkins(x_min, x_max, y_min, y_max);
	
}

bool check_cart(struct position pos)
{
	return contain_cart(main_dron, pos);
}

void move_dron(cart *head, Direction dir)
{
	position next_pos = get_next_position(head -> pos, dir);
	
	if(next_pos.x < x_min ||
		next_pos.x > x_max ||
		next_pos.y < y_min ||
		next_pos.y > y_max)
	{
		return;
	}
	if(check_cart(next_pos))
	{
		return;
	}
	if(contain_pumpkin(next_pos))
	{
		remove_pumpkin(next_pos);
		add_cart(head);
	}
	move_carts(head, dir);
}

void process_input(int input_char)
{
	switch(input_char)
	{
		case '\n'://press enter to close program
			closeProgrammFlag = true;
			break;
		case KEY_LEFT:
			move_dron(main_dron, direction_left);
			break;
		case KEY_RIGHT:
			move_dron(main_dron, direction_right);
			break;
		case KEY_UP:
			move_dron(main_dron, direction_forward);
			break;
		case KEY_DOWN:
			move_dron(main_dron, direction_back);
			break;
	}
}

void update()
{
	draw_clear_field();
	drow_carts(main_dron);
	draw_pumpkins(pumpkins, pumpkins_count);

	int inp = getch();
	process_input(inp);
	
	update_pumpkins(check_cart);
}

void end()
{
	disable_draw();
	clean_carts(main_dron);
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
