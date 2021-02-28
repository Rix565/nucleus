#include <SDL2/SDL.h>
#include <editor/editor.h>
#include <gui.h>
#include <stdio.h>

Colorscheme dracula;


int main(int argc, char *argv[])
{

    if (argc >= 2)
    {
        Editor_open(argv[1]);
    }

    dracula.bg = (RGBA){40, 42, 54,255};
    dracula.fg = (RGBA){248, 248, 242,255};

    GUI_init(dracula);

    return 0;
}
