#include "score.h"
#include "player.h"

void draw_scores(struct State *s) {
    draw_score(s, s->playerLeft->score, WINDOW_WIDTH / 4);
    draw_score(s, s->playerRight->score, WINDOW_WIDTH - WINDOW_WIDTH / 4);
}

void draw_score(struct State *s, int score, float x) {
    char buf[3];
    sprintf(buf, "%02d", score);
    SDL_Surface *surf = TTF_RenderText_Blended(s->font, buf, 0, (SDL_Color){255, 255, 255, 255});
    SDL_FRect rect = {
        .x = x - surf->w/2,
        .y = 40,
        .w = surf->w,
        .h = surf->h
    };
    SDL_Texture *tex = SDL_CreateTextureFromSurface(s->renderer, surf);
    SDL_RenderTexture(s->renderer, tex, NULL, &rect);
    SDL_DestroySurface(surf);
    SDL_DestroyTexture(tex);
}