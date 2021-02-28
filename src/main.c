#include <gui.h>
#include <editor/editor.h>
#include <SDL2/SDL.h>
#include <stdio.h>
int main(int argc, char *argv[])
{

    if (argc >= 2)
    {
        Editor_open(argv[1]);
    }
    Colorscheme onedark;
    onedark.bg = (RGBA){40, 44, 52, 100};
    GUI_init(onedark);
    return 0;
}
