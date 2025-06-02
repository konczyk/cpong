#ifndef PONG_BALL_H
#define PONG_BALL_H

#include "main.h"

struct Velocity {
    float x;
    float y;
};

bool init_ball(struct State *s);
void draw_ball(struct State *s);
void update_ball(struct State *s);

#endif //PONG_BALL_H
