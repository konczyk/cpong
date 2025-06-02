#include "player.h"

bool init_players(struct State *s) {

    s->player1 = (SDL_FRect) {
        .x = PLAYER_INDENT,
        .y = (int) (WINDOW_HEIGHT/2 - PLAYER_HEIGHT/2),
        .w = PLAYER_WIDTH,
        .h = PLAYER_HEIGHT
    };

    s->player2 = (SDL_FRect) {
        .x = WINDOW_WIDTH - PLAYER_INDENT - PLAYER_WIDTH,
        .y = (int) (WINDOW_HEIGHT/2 - PLAYER_HEIGHT/2),
        .w = PLAYER_WIDTH,
        .h = PLAYER_HEIGHT
    };

    return true;
}

void update_players(struct State *s) {
    if (s->key_state[SDL_SCANCODE_W] && s->player1.y > 0) {
        s->player1.y -= PLAYER_SPEED;
    }

    if (s->key_state[SDL_SCANCODE_S] && s->player1.y < WINDOW_HEIGHT - PLAYER_HEIGHT) {
        s->player1.y += PLAYER_SPEED;
    }

    if (s->key_state[SDL_SCANCODE_UP] && s->player2.y > 0) {
        s->player2.y -= PLAYER_SPEED;
    }

    if (s->key_state[SDL_SCANCODE_DOWN] && s->player2.y < WINDOW_HEIGHT - PLAYER_HEIGHT) {
        s->player2.y += PLAYER_SPEED;
    }

}

void draw_players(struct State *s) {
    SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(s->renderer, &s->player1);
    SDL_RenderFillRect(s->renderer, &s->player2);
}
