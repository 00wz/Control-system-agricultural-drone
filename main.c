#include <stdbool.h>
#include "carts.h"
#include "draw_functions.h"
#include "curses/curses.h"
#include "pumpkins.h"
#include "direction.h"

bool closeProgrammFlag = false;

cart *main_dron;

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
	init_pumpkins(1, col - 2, 1, row - 2);
	
}

bool check_cart(struct position pos)
{
	return contain_cart(main_dron, pos);
}

void move_dron(cart *head, Direction dir)
{
	position next_pos = get_next_position(head -> pos, dir);
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
