#include <stdio.h>
#include "RenderWindow.h"

RenderWindow RenderWindowInit() {
    RenderWindow renderWindow;
    renderWindow.Create = &RenderWindow_Create;
    renderWindow.Clear = &RenderWindow_Clear;
    renderWindow.Render = &RenderWindow_Render;
    renderWindow.Display = &RenderWindow_Display;
    renderWindow.Close = &RenderWindow_Close;
    renderWindow.DestroyTexture = &RenderWindow_DestroyTexture;

    return renderWindow;
}

SDL_Texture* LoadTexture(RenderWindow* self, const char* path) {
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = NULL;

    surface = IMG_Load(path);
    if (surface == NULL) {
        printf("Cannot load surface: %s! ---- Error: %s\n", path, IMG_GetError());
    }
    else {
        texture = SDL_CreateTextureFromSurface(self->renderer, surface);
        if (texture == NULL) {
            printf("Cannot load texture: %s! ---- Error: %s\n", path, SDL_GetError());
        }
        SDL_FreeSurface(surface);
    }
    return texture;
}

void RenderWindow_Create(RenderWindow* self, const char* title, int width, int height) {
    self->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI);

    if (self->window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
    }

    self->renderer = SDL_CreateRenderer(self->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void RenderWindow_Clear(RenderWindow* self) {
    SDL_RenderClear(self->renderer);
}
void RenderWindow_Render(RenderWindow* self, SDL_Texture* tex, SDL_Rect* srcrect, SDL_Rect* rect) {
    SDL_RenderCopy(self->renderer, tex, srcrect, rect);
}
void RenderWindow_Display(RenderWindow* self) {
    SDL_RenderPresent(self->renderer);
}
void RenderWindow_Close(RenderWindow* self) {
    SDL_DestroyRenderer(self->renderer);
    SDL_DestroyWindow(self->window);
    self->renderer = NULL;
    self->window = NULL;

    IMG_Quit();
    SDL_Quit();
}
void RenderWindow_DestroyTexture(SDL_Texture* tex) {
    SDL_DestroyTexture(tex);
    tex = NULL; 
}
