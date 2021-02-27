import std.stdio;
import std.string : fromStringz;
import std.conv;

import bindbc.sdl;
import bindbc.sdl.image;

void main()
{
    loadSDL();
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        writeln("SDL_Init: ", fromStringz(SDL_GetError()));
    }
    else
        SDL_Quit();

<<<<<<< HEAD
    SDL_Window *window = SDL_CreateWindow(
        "Example Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800,
        600,
        SDL_WINDOW_OPENGL);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool quit = false;
    while (!quit)
    {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }

            if (event.type == SDL_KEYDOWN)
            {
                quit = true;
            }
        }
    }
=======
write("If you see this, then the shit works  h o r r a a  a");
>>>>>>> 033e3fd18a05b91c48f963f870a0dba3724f99fe
}
