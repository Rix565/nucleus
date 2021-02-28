#ifndef GUI_H
#define GUI_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

typedef struct
{
    int r, g, b, a;
} RGBA;

typedef struct
{
    RGBA fg, bg, c_0, c_1, c_2, c_3, c_4, c_5, c_6, c_7;

} Colorscheme;

void GUI_init(Colorscheme colorscheme);

#endif
