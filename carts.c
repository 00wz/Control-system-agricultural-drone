#include <stdio.h>
#include <stdlib.h>
#include "carts.h"
#include "direction.h"
#include "position.h"

cart *head = NULL;

//add first cart
void init_head(int pos_x, int pos_y)
{
	if(head != NULL)
	{
		fprintf(stderr, "%s", "Head has already been initialized\n");
		return;
	}
	head = calloc(1,sizeof(cart));
	head -> pos.x = pos_x;
	head -> pos.y = pos_y;
}

void move_carts(Direction dir)
{
	position target_pos = head -> pos;
	switch(dir)
	{
		case direction_forward:
			target_pos.y -= 1;
			break;
		case direction_back:
			target_pos.y += 1;
			break;
		case direction_left:
			target_pos.x -= 1;
			break;
		case direction_right:
			target_pos.x += 1;
			break;
	}
	
	position tmp_pos;
	cart *current_cart = head;
	while(current_cart)
	{
		tmp_pos = current_cart -> pos;
		current_cart -> pos = target_pos;
		target_pos = tmp_pos;
		current_cart = current_cart -> next;
	}
}

//search tail cart
static cart* get_last_cart(cart *current_cart)
{
	while(current_cart -> next)
	{
		current_cart = current_cart -> next;
	}
	return current_cart;
}

//add new cart to tail
void add_cart()
{
	if(head == NULL)
	{
		fprintf(stderr, "%s", "Head is uninitialized\n");
		return;
	}
	cart *last_cart = get_last_cart(head);
	cart *new_cart = calloc(1,sizeof(cart));
	last_cart -> next = new_cart;
	new_cart -> pos = last_cart -> pos;
}

void clean_carts()
{
	cart *current = head;
	while(current)
	{
		cart *tmp = current -> next;
		free(current);
		current = tmp;
	}
	head = NULL;
}

bool contain_cart(cart *head, struct position pos)
{
	while(head)
	{
		if(equalPositions(head -> pos, pos))
		{
			return true;
		}
		head = head -> next;
	}
	return false;
}

