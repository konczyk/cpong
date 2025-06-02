#include "player.h"

bool init_players(struct State *s) {
    s->player1 = calloc(1, sizeof(struct Player));
    if (!s->player1) {
        fprintf(stderr, "Error allocating memory");
        return false;
    }
    s->player1->rect = (SDL_FRect) {
        .x = PLAYER_INDENT,
        .y = (int) (WINDOW_HEIGHT/2 - PLAYER_HEIGHT/2),
        .w = PLAYER_WIDTH,
        .h = PLAYER_HEIGHT
    };
    s->player1->score = 0;

    s->player2 = calloc(1, sizeof(struct Player));
    if (!s->player2) {
        fprintf(stderr, "Error allocating memory");
        return false;
    }
    s->player2->rect = (SDL_FRect) {
        .x = WINDOW_WIDTH - PLAYER_INDENT - PLAYER_WIDTH,
        .y = (int) (WINDOW_HEIGHT/2 - PLAYER_HEIGHT/2),
        .w = PLAYER_WIDTH,
        .h = PLAYER_HEIGHT
    };
    s->player2->score = 0;

    return true;
}

void update_players(struct State *s) {
    if (s->key_state[SDL_SCANCODE_W] && s->player1->rect.y > 0) {
        s->player1->rect.y -= SPEED;
    }

    if (s->key_state[SDL_SCANCODE_S] && s->player1->rect.y < WINDOW_HEIGHT - PLAYER_HEIGHT) {
        s->player1->rect.y += SPEED;
    }

    if (s->key_state[SDL_SCANCODE_UP] && s->player2->rect.y > 0) {
        s->player2->rect.y -= SPEED;
    }

    if (s->key_state[SDL_SCANCODE_DOWN] && s->player2->rect.y < WINDOW_HEIGHT - PLAYER_HEIGHT) {
        s->player2->rect.y += SPEED;
    }

}

void draw_players(struct State *s) {
    SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(s->renderer, &s->player1->rect);
    SDL_RenderFillRect(s->renderer, &s->player2->rect);
}
