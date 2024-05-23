#ifndef CARTS_H
#define CARTS_H

typedef struct cart
{
	int pos_x;
	int pos_y;
	struct cart *next;
}cart;

extern cart *head;

void init_head(int pos_x, int pos_y);

void add_cart();

void clean_carts();

#endif
