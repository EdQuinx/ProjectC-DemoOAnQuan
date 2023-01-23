#include <stdbool.h>
#include "Header/RenderWindow.c"
#include "Header/Cursor.c"
#include "Header/GFX.h"

SDL_Event event;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    RenderWindow renderWindow = RenderWindowInit();
    renderWindow.Create(&renderWindow, "Ô Ăn Quan", 1280, 720);

    SDL_Texture* background = LoadTexture(&renderWindow, BACKGROUND_PIC);
    SDL_Texture* cursorTex = LoadTexture(&renderWindow, MOUSE_PIC);
    Cursor cursor = CursorInit(renderWindow.renderer, cursorTex);
    while (true)
    {
        cursor.Update(&cursor);
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                break;
            cursor.Animate(&cursor, event);
        }
        renderWindow.Clear(&renderWindow);
        renderWindow.Render(&renderWindow, background, NULL, NULL);
        cursor.Draw(&cursor);
        renderWindow.Display(&renderWindow);

    }

    renderWindow.Close(&renderWindow);
    return EXIT_SUCCESS;
}