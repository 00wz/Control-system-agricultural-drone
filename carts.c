#include <stdio.h>
#include <stdlib.h>
#include "carts.h"

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
	head -> pos_x = pos_x;
	head -> pos_y = pos_y;
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
	new_cart -> pos_x = last_cart -> pos_x;
	new_cart -> pos_y = last_cart -> pos_y;
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

