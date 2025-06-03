#include <time.h>
#include "main.h"
#include "init.h"
#include "player.h"
#include "ball.h"

bool setup(struct State **state);
void cleanup(struct State **state);

int main(void) {
    bool exit_status = EXIT_FAILURE;

    struct State *state = nullptr;
    if (setup(&state)) {
        run(state);
        exit_status = EXIT_SUCCESS;
    }

    cleanup(&state);
    state = nullptr;

    return exit_status;
}

bool setup(struct State **state) {
    *state = calloc(1, sizeof(struct State));
    if (*state == NULL) {
        fprintf(stderr, "Error allocating memory: %s\n", SDL_GetError());
        return false;
    }

    struct State *s = *state;

    if (!init_sdl(s)) {
        return false;
    }

    if (!init_players(s)) {
        return false;
    }

    if (!init_ball(s)) {
        return false;
    }

    s->is_running = true;
    s->key_state = SDL_GetKeyboardState(nullptr);
    srand(time(NULL));

    return true;
}

void cleanup(struct State **state) {
    if (*state) {
        struct State *s = *state;
        if (s->renderer) {
            SDL_DestroyRenderer(s->renderer);
            s->renderer = nullptr;
        }
        if (s->window) {
            SDL_DestroyWindow(s->window);
            s->window = nullptr;
        }
        if (s->ball) {
            free(s->ball);
            s->ball = nullptr;
        }
        if (s->playerLeft) {
            free(s->playerLeft);
            s->playerLeft = nullptr;
        }
        if (s->playerRight) {
            free(s->playerRight);
            s->playerRight = nullptr;
        }
        free(s);
        s = nullptr;
    }
    SDL_Quit();
}