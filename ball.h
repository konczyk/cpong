#ifndef PONG_BALL_H
#define PONG_BALL_H

#include "main.h"

struct Ball {
    SDL_FRect rect;
    float vel_x;
    float vel_y;
};

bool init_ball(struct State *s);
void draw_ball(struct State *s);
void update_ball(struct State *s);

#endif //PONG_BALL_H
