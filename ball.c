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
    center_ball(s->ball);

    return true;
}

void center_ball(struct Ball *b) {
    b->rect.x = (int) ((WINDOW_WIDTH-BALL_SIZE/2)/2);
    b->rect.y = (int) ((WINDOW_HEIGHT-BALL_SIZE/2)/2);
    b->vel_x = b->vel_y = 0;
}

void start_ball(struct Ball *b) {
    if (b->vel_x == 0 && b->vel_y == 0) {
        b->vel_x = SPEED * (rand() % 2 == 0 ? 1 : -1);
    }
}

void update_ball(struct State *s) {
    // player 2 score
    if (s->ball->rect.x + BALL_SIZE <= 0) {
        center_ball(s->ball);

    // player 1 score
    } else if (s->ball->rect.x >= WINDOW_WIDTH) {
        center_ball(s->ball);

    // ball bounce from player 1
    } else if (s->ball->rect.x <= s->player1->rect.x + PLAYER_WIDTH &&
                s->ball->rect.y <= s->player1->rect.y + PLAYER_HEIGHT &&
                s->ball->rect.y -BALL_SIZE >= s->player1->rect.y
    ) {
        s->ball->vel_x *= -1;

    // ball bounce from player 2
    } else if (s->ball->rect.x >= s->player2->rect.x - BALL_SIZE &&
                s->ball->rect.y <= s->player2->rect.y + PLAYER_HEIGHT &&
                s->ball->rect.y -BALL_SIZE >= s->player2->rect.y
    ) {
        s->ball->vel_x *= -1;
    }
    s->ball->rect.x += s->ball->vel_x;
    s->ball->rect.y += s->ball->vel_y;
}

void draw_ball(struct State *s) {
    SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(s->renderer, &s->ball->rect);
}
