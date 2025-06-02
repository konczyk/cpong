#ifndef SDL_GAME_H
#define SDL_GAME_H

#include "main.h"

void run(struct State *s);
void process_input(struct State *s);
void update(struct State *s);
void draw(struct State *s);

#endif //SDL_GAME_H
