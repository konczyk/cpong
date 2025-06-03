#include "ball.h"
#include "player.h"

bool init_ball(struct State *s) {
    s->ball = calloc(1, sizeof(struct Ball));
    if (!s->ball) {
        fprintf(stderr, "Error allocating memory");
        return false;
    }

    s->ball->rect = (SDL_FRect) {
        .x = 0,
        .y = 0,
        .w = BALL_SIZE,
        .h = BALL_SIZE
    };
    reset_ball(s->ball);

    return true;
}

void start_ball(struct Ball *b) {
    if (b->vel_x == 0 && b->vel_y == 0) {
        b->vel_x = BALL_SPEED * (rand() % 2 == 0 ? 1 : -1);
    }
}

void reset_ball(struct Ball *b) {
    b->rect.x = (WINDOW_WIDTH - b->rect.w/2)/2;
    b->rect.y = (WINDOW_HEIGHT - b->rect.h/2)/2;
    b->vel_x = b->vel_y = 0;
}

void update_ball(struct State *s) {
    // left player scores
    if (s->ball->rect.x >= WINDOW_WIDTH) {
        reset_ball(s->ball);

    // right player scores
    } else if (s->ball->rect.x + s->ball->rect.w <= 0) {
        reset_ball(s->ball);

    } else if (s->ball->rect.y <= 0 || s->ball->rect.y + s->ball->rect.h >= WINDOW_HEIGHT) {
        s->ball->vel_y *= -1;

    // ball bounces from left player
    } else if (s->ball->rect.x <= s->playerLeft->rect.x + s->playerLeft->rect.w &&
                s->ball->rect.x > s->playerLeft->rect.x &&
                check_ball_hits_player_y(s->ball, s->playerLeft)
    ) {
        bounce_ball_from_player(s->ball, s->playerLeft);

    // ball bounces from right player
    } else if (s->ball->rect.x + s->ball->rect.w >= s->playerRight->rect.x &&
                s->ball->rect.x + s->ball->rect.w < s->playerRight->rect.x + s->playerRight->rect.w &&
                check_ball_hits_player_y(s->ball, s->playerRight)
    ) {
        bounce_ball_from_player(s->ball, s->playerRight);
    }
    s->ball->rect.x += s->ball->vel_x;
    s->ball->rect.y += s->ball->vel_y;
}

bool check_ball_hits_player_y(struct Ball *b, struct Player *p) {
    return b->rect.y + b->rect.h >= p->rect.y && b->rect.y <= p->rect.y + p->rect.h;
}

void bounce_ball_from_player(struct Ball *b, struct Player *p) {
    double pcy = p->rect.y + PLAYER_HEIGHT/2.0;
    double bcy = b->rect.y + BALL_SIZE/2.0;
    bool is_left_player = p->rect.x < WINDOW_WIDTH/2.0;
    double rad = 0.0;

    double deg_per_px = 45.0 / (PLAYER_HEIGHT / 2.0);

    if (is_left_player) {
        if (pcy > bcy) {
            rad = (-(pcy-bcy) * deg_per_px * (M_PI / 180));
        } else if (pcy < bcy) {
            rad = ((bcy-pcy) * deg_per_px * (M_PI / 180));
        }
    } else {
        if (pcy > bcy) {
            rad = (135 + (pcy-bcy) * deg_per_px * (M_PI / 180));
        } else if (pcy < bcy) {
            rad = (-135 - (bcy-pcy) * deg_per_px * (M_PI / 180));
        }
    }

    b->vel_x = BALL_SPEED * cos(rad);
    b->vel_y = BALL_SPEED * sin(rad);
}

void draw_ball(struct State *s) {
    SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(s->renderer, &s->ball->rect);
}

