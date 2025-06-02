#include "loop.h"

void run(struct State *s) {
    while (s->is_running) {
        process_input(s);
        update(s);
        draw(s);

        SDL_Delay(2);
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

}

void draw(struct State *s) {
    SDL_RenderClear(s->renderer);
    SDL_RenderPresent(s->renderer);
}