#include <stdio.h>
#include "RenderWindow.h"

RenderWindow RenderWindowInit() {
    RenderWindow renderWindow;
    renderWindow.Create = &RenderWindow_Create;
    renderWindow.CleanUp = &RenderWindow_CleanUp;
    renderWindow.Clear = *RenderWindow_Clear;
    renderWindow.Render = *RenderWindow_Render;
    renderWindow.Display = *RenderWindow_Display;
    
    return renderWindow;
}

SDL_Texture* LoadTexture(RenderWindow* self, const char* path) {
    SDL_Texture* texture = NULL;

    texture = IMG_LoadTexture(self->renderer, path);
    if (texture == NULL) {
        printf("Cannot load texture: %s\n", SDL_GetError());
    }
    return texture;
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
void RenderWindow_Clear(RenderWindow* self) {
    SDL_RenderClear(self->renderer);
}
void RenderWindow_Render(RenderWindow* self, SDL_Texture* tex) {
    SDL_RenderCopy(self->renderer, tex, NULL, NULL);
}
void RenderWindow_Display(RenderWindow* self) {
    SDL_RenderPresent(self->renderer);
}