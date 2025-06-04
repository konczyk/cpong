#ifndef SDL_MAIN_H
#define SDL_MAIN_H

#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"
#include "SDL3_ttf/SDL_ttf.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SDL_FLAGS SDL_INIT_VIDEO
#define WINDOW_TITLE "CPong"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define PLAYER_WIDTH 20
#define PLAYER_HEIGHT 150
#define PLAYER_INDENT 40

#define BALL_SPEED 8
#define PLAYER_SPEED 5

#define BALL_SIZE 20
#define MIDDLE_LINE_WIDTH 10
#define MIDDLE_LINE_INDENT 40

#define SCORE_FONT_SIZE 72

struct State {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    bool is_running;
    struct Player *playerLeft;
    struct Player *playerRight;
    struct Ball *ball;
    const bool *key_state;
    struct TTF_Font *font;
};

#endif