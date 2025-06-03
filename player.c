#include "player.h"

bool init_players(struct State *s) {
    s->playerLeft = calloc(1, sizeof(struct Player));
    if (!s->playerLeft) {
        fprintf(stderr, "Error allocating memory");
        return false;
    }
    s->playerLeft->rect = (SDL_FRect) {
        .x = PLAYER_INDENT,
        .y = (int) (WINDOW_HEIGHT/2 - PLAYER_HEIGHT/2),
        .w = PLAYER_WIDTH,
        .h = PLAYER_HEIGHT
    };
    s->playerLeft->score = 0;

    s->playerRight = calloc(1, sizeof(struct Player));
    if (!s->playerRight) {
        fprintf(stderr, "Error allocating memory");
        return false;
    }
    s->playerRight->rect = (SDL_FRect) {
        .x = WINDOW_WIDTH - PLAYER_INDENT - PLAYER_WIDTH,
        .y = (int) (WINDOW_HEIGHT/2 - PLAYER_HEIGHT/2),
        .w = PLAYER_WIDTH,
        .h = PLAYER_HEIGHT
    };
    s->playerRight->score = 0;

    return true;
}

void update_players(struct State *s) {
    if (s->key_state[SDL_SCANCODE_W] && s->playerLeft->rect.y > 0) {
        s->playerLeft->rect.y -= SPEED;
    }

    if (s->key_state[SDL_SCANCODE_S] && s->playerLeft->rect.y < WINDOW_HEIGHT - s->playerLeft->rect.h) {
        s->playerLeft->rect.y += SPEED;
    }

    if (s->key_state[SDL_SCANCODE_UP] && s->playerRight->rect.y > 0) {
        s->playerRight->rect.y -= SPEED;
    }

    if (s->key_state[SDL_SCANCODE_DOWN] && s->playerRight->rect.y < WINDOW_HEIGHT - s->playerRight->rect.h) {
        s->playerRight->rect.y += SPEED;
    }

}

void draw_players(struct State *s) {
    SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(s->renderer, &s->playerLeft->rect);
    SDL_RenderFillRect(s->renderer, &s->playerRight->rect);
}
