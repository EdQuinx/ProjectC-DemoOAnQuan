#include <stdio.h>
#include "RenderWindow.h"

RenderWindow RenderWindowInit() {
    RenderWindow renderWindow;
    renderWindow.Create = &RenderWindow_Create;
    renderWindow.CleanUp = &RenderWindow_CleanUp;
    
    return renderWindow;
}

void RenderWindow_Create(RenderWindow* self, const char* title, int width, int height) {
    self->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI);

    if (self->window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
    }

    self->renderer = SDL_CreateRenderer(self->window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow_CleanUp(RenderWindow* self) {
    SDL_DestroyWindow(self->window);
}