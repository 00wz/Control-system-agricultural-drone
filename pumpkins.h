#define PUMPKINS_BUFFER 20
#define SPAWN_ATTEMPTS 5

#include "position.h"
#include <stdbool.h>

extern struct position pumpkins[PUMPKINS_BUFFER];

extern int pumpkins_count;

bool contain_pumpkin(struct position pos);

void add_rand_pumpkins(bool contain_cart(struct position pos));

void init_pumpkins(int min_x, int max_x, int min_y, int max_y);

void update_pumpkins(bool contain_cart(struct position pos));

void remove_pumpkin(position pos);
