#include "loop.h"
#include "player.h"
#include "ball.h"

void run(struct State *s) {
    while (s->is_running) {
        process_input(s);
        update(s);
        draw(s);

        SDL_Delay(16);
    }
}

void process_input(struct State *s) {
    while (SDL_PollEvent(&s->event)) {
        switch (s->event.type) {
            case SDL_EVENT_QUIT:
                s->is_running = false;
                break;
            case SDL_EVENT_KEY_DOWN:
                switch (s->event.key.scancode) {
                    case SDL_SCANCODE_ESCAPE:
                        s->is_running = false;
                        break;
                    case SDL_SCANCODE_SPACE:
                        start_ball(s->ball);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}

void update(struct State *s) {
    update_players(s);
    update_ball(s);
}

void draw(struct State *s) {
    SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 255);
    SDL_RenderClear(s->renderer);

    SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, 255);
    SDL_RenderLine(s->renderer, WINDOW_WIDTH/2 + BORDER_WIDTH/2, BORDER_INDENT, WINDOW_WIDTH/2 + BORDER_WIDTH/2, WINDOW_HEIGHT - BORDER_INDENT);

    draw_players(s);
    draw_ball(s);

    SDL_RenderPresent(s->renderer);
}