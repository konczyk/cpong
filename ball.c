#include "ball.h"

bool init_ball(struct State *s) {

    s->ball = (SDL_FRect) {
        .x = (int) ((WINDOW_WIDTH-BALL_SIZE/2)/2),
        .y = (int) ((WINDOW_HEIGHT-BALL_SIZE/2)/2),
        .w = BALL_SIZE,
        .h = BALL_SIZE
    };

    return true;
}

void update_ball(struct State *s) {
}

void draw_ball(struct State *s) {
    SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(s->renderer, &s->ball);
}
