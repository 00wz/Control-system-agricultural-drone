#include "position.h"
#include <stdbool.h>
#include <stdlib.h>
#include "pumpkins.h"
#include <time.h>

struct position pumpkins[PUMPKINS_BUFFER];

int pumpkins_count = 0;

int x_min;
int x_max;
int y_min;
int y_max;

time_t last_spawn_time = 0;
time_t spawn_interval = 1; 


void update_pumpkins(bool contain_cart(struct position pos))
{
	if((time(NULL) - last_spawn_time) >= spawn_interval)
	{
		last_spawn_time = time(NULL);
		add_rand_pumpkins(contain_cart);
	}
}

void init_pumpkins(int min_x, int max_x, int min_y, int max_y)
{
	x_min = min_x;
	x_max = max_x;
	y_min = min_y;
	y_max = max_y;
	//last_spawn_time = time(NULL);
}

bool contain_pumpkin(struct position pos)
{
	for(int i = 0; i < pumpkins_count; i++)
	{
		if(equalPositions(pumpkins[i], pos))
		{
			return true;
		}
	}
	return false;
}

static void add_pumpkins(struct position pos)
{
	pumpkins[pumpkins_count] = pos;
	pumpkins_count++;
}

void add_rand_pumpkins(bool contain_cart(struct position pos))
{
	if(pumpkins_count >= PUMPKINS_BUFFER)
	{
		return;
	}
	
	//limits the number of pumpkin respawn attempts to prevent freezes
	for(int i = 0; i < SPAWN_ATTEMPTS; i++)
	{
		struct position new_pumpkins;
		new_pumpkins.y = rand() % (y_max - y_min + 1) + y_min;
		new_pumpkins.x = rand() % (x_max - x_min + 1) + x_min;
		
		if(!contain_cart(new_pumpkins) && !contain_pumpkin(new_pumpkins))
		{
			add_pumpkins(new_pumpkins);
			break;
		}
	}
}

