#ifndef PONG_PLAYER_H
#define PONG_PLAYER_H

#include "main.h"

struct Player {
    SDL_FRect rect;
    int score;
};

bool init_players(struct State *s);
void draw_players(struct State *s);
void update_players(struct State *s);

#endif //PONG_PLAYER_H
