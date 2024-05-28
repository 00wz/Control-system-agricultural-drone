#define PUMPKINS_BUFFER 20

#include "position.h"
#include <stdbool.h>

extern struct position pumpkins[PUMPKINS_BUFFER];

extern int pumpkins_count;

bool contain_pumpkin(struct position pos);

void add_rand_pumpkins(bool try_get_free_pos(position *pos));

void update_pumpkins(bool try_get_free_pos(position *pos));

void remove_pumpkin(position pos);

bool try_get_closest_pumpkin(position pos, position *result);
