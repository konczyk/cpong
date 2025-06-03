#ifndef PONG_BALL_H
#define PONG_BALL_H

#include "main.h"

struct Ball {
    SDL_FRect rect;
    float vel_x;
    float vel_y;
};

bool init_ball(struct State *s);
void start_ball(struct Ball *b);
void reset_ball(struct Ball *b);
bool check_ball_hits_player_y(struct Ball *b, struct Player *p);
void bounce_ball_from_player(struct Ball *b, struct Player *p);
void update_ball(struct State *s);
void draw_ball(struct State *s);

#endif //PONG_BALL_H
