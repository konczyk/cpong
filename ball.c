#include "ball.h"

bool init_ball(struct State *s) {
    s->ball = calloc(1, sizeof(struct Ball));
    if (!s->ball) {
        fprintf(stderr, "Error allocating memory");
        return false;
    }

    s->ball->rect = (SDL_FRect) {
        .x = (int) ((WINDOW_WIDTH-BALL_SIZE/2)/2),
        .y = (int) ((WINDOW_HEIGHT-BALL_SIZE/2)/2),
        .w = BALL_SIZE,
        .h = BALL_SIZE
    };
    s->ball->vel_x = s->ball->vel_y = 0;

    return true;
}

void update_ball(struct State *s) {
}

void draw_ball(struct State *s) {
    SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(s->renderer, &s->ball->rect);
}
