#ifndef PLAYER_H
#define PLAYER_H

#include "point.h"

struct game_state_s;
typedef struct game_state_s game_state_t;

typedef struct player_s {
	point_t (*get_action)(struct player_s *, game_state_t *);
	void (*setup_boats)(struct player_s *, game_state_t *);
	point_t owned_rect[2];
	int is_alive;
} player_t;

player_t *newLocalPlayer();

#endif /* PLAYER_H */
