#include <iostream>
#include <stdbool.h>
#include "Header/RenderWindow.c"

SDL_Event event;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    RenderWindow renderWindow = RenderWindowInit();

    renderWindow.Create(&renderWindow, "Ô Ăn Quan", 1280, 720);
    while (true)
    {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                break;
        }
    }
    renderWindow.CleanUp(&renderWindow);

    SDL_Quit(); 
    return EXIT_SUCCESS;
}