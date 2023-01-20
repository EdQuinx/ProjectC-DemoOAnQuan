#include <stdbool.h>
#include "Header/RenderWindow.c"
#include "Header/GFX.h"

SDL_Event event;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    RenderWindow renderWindow = RenderWindowInit();

    renderWindow.Create(&renderWindow, "Ô Ăn Quan", 1280, 720);

    SDL_Texture* background = LoadTexture(&renderWindow, BACKGROUND_PIC);
    while (true)
    {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                break;
        }
        renderWindow.Clear(&renderWindow);
        renderWindow.Render(&renderWindow, background);
        renderWindow.Display(&renderWindow);
    }
    renderWindow.CleanUp(&renderWindow);

    SDL_Quit(); 
    return EXIT_SUCCESS;
}