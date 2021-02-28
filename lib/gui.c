#include "gui.h"

SDL_Window *window;
SDL_Renderer *renderer;
bool is_running = false;

void GUI_init(Colorscheme colorscheme)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        is_running = true;
    }

    /* Create Window and renderer */
    window = SDL_CreateWindow("Nucleus", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, colorscheme.bg.r, colorscheme.bg.g, colorscheme.bg.b, colorscheme.bg.a);

    while (is_running)
    {
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            is_running = false;
            break;
        default:
            break;
        }
    }
    free(window);
    free(renderer);
}
