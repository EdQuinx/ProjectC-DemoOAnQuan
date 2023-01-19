#include <iostream>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "Header/RenderWindow.c"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    RenderWindow renderWindow = RenderWindowInit();

    renderWindow.Create(&renderWindow, "Ô Ăn Quan", 1280, 720);
    renderWindow.CleanUp(&renderWindow);
    SDL_Quit(); 
    
    return EXIT_SUCCESS;
}