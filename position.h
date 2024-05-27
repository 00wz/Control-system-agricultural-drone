#ifndef POSITION_H
#define POSITION_H

#include <stdbool.h>

typedef struct position
{
	int x;
	int y;
}position;

bool equalPositions(struct position a, struct position b);

#endif
