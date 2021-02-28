#include "gui.h"

SDL_Window *window;
SDL_Renderer *renderer;
bool is_running = false;

static float get_time_in_seconds()
{
    float t = SDL_GetTicks();
    t *= 0.001f;
    return t;
}

void GUI_handle_events()
{
    SDL_Event event;
    if (SDL_WaitEvent(&event) != 0)
    {
        switch (event.type)
        {

        case SDL_QUIT:
            is_running = false;
            break;

        default:
            break;
        }
    }
}

int GUI_get_refresh_rate()
{
    int displayIndex = SDL_GetWindowDisplayIndex(window);
    SDL_DisplayMode mode;

    SDL_GetDisplayMode(displayIndex, 0, &mode);

    return mode.refresh_rate;
}

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

    /* Limiting the main loop */
    const float timestep = 0.01f;
    float accumulator = 0.0f;

    float current_time = get_time_in_seconds();
    
    while (is_running)
    {

        int start_tick = SDL_GetTicks();
        float new_time = get_time_in_seconds();
        float frame_time = new_time - current_time;

        accumulator += frame_time;

        /* Handling events */
        while (accumulator >= timestep)

        {
            GUI_handle_events();
            accumulator -= timestep;
        }

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        int frame_ticks = SDL_GetTicks() - start_tick;

        if (frame_ticks < 1000 / GUI_get_refresh_rate())
        {

            SDL_Delay(1000 / GUI_get_refresh_rate() - frame_ticks);
        }
    }

    SDL_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
