#include "init.h"

bool init_sdl(struct State *s) {
    if (!SDL_Init(SDL_FLAGS)) {
        fprintf(stderr, "Error initializing SDL3: %s\n", SDL_GetError());
        return false;
    }

    s->window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!s->window) {
        fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
        return false;
    }

    s->renderer = SDL_CreateRenderer(s->window, nullptr);
    if (!s->renderer) {
        fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
        return false;
    }

    if (!TTF_Init()) {
        fprintf(stderr, "Error initializing SDL3_ttf: %s\n", SDL_GetError());
        return false;
    }
    s->font = TTF_OpenFont("data/Roboto-Regular.ttf", SCORE_FONT_SIZE);
    if (!s->font) {
        fprintf(stderr, "Error opening font: %s\n", SDL_GetError());
    }

    return true;
}
