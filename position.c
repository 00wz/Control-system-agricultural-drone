#include "position.h"
#include <stdbool.h>

bool equalPositions(struct position a, struct position b)
{
	return (a.x == b.x) && (a.y == b.y);
}

