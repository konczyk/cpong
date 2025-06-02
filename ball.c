#include "ball.h"
#include "player.h"

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

void start_ball(struct Ball *b) {
    if (b->vel_x == 0 && b->vel_y == 0) {
        b->vel_x = SPEED * (rand() % 2 == 0 ? 1 : -1);
    }
}

void update_ball(struct State *s) {
    if (s->ball->rect.x <= 0) {
        // player 2 score
    } else if (s->ball->rect.x + BALL_SIZE >= WINDOW_WIDTH) {
        // player 1 score
    } else if (s->ball->rect.x <= s->player1->rect.x + PLAYER_WIDTH) {
        s->ball->vel_x *= -1;
    } else if (s->ball->rect.x >= s->player2->rect.x - BALL_SIZE) {
        s->ball->vel_x *= -1;
    }
    s->ball->rect.x += s->ball->vel_x;
    s->ball->rect.y += s->ball->vel_y;
}

void draw_ball(struct State *s) {
    SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(s->renderer, &s->ball->rect);
}
