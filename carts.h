#ifndef CARTS_H
#define CARTS_H

#include "position.h"
#include "direction.h"

typedef struct cart
{
	position pos;
	struct cart *next;
}cart;

extern cart *head;

void init_head(int pos_x, int pos_y);

void add_cart();

void clean_carts();

void move_carts(Direction dir);

#endif
