#include <stdio.h>
#include "carts.h"
#include "draw_functions.h"

int main(int argc, char **argv)
{
	init_head(10, 10);
	enable_draw();
	
	draw_field();
	drow_carts(head);
	
	disable_draw();
	clean_carts();
	
	return 0;
}

