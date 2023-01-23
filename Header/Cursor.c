#include <stdio.h>
#include <stdbool.h>
#include "Cursor.h"
#include "GFX.h"

Cursor CursorInit(SDL_Renderer* renderer, SDL_Texture* texture) {
    Cursor cursor;
    cursor.renderer = renderer;
    cursor.tex = texture;
    cursor.rect.w = 50;
    cursor.rect.h = 50;
    cursor.point.w = 1;
    cursor.point.h = 1;

    SDL_QueryTexture(texture, NULL, NULL, &cursor.textureWidth, &cursor.textureHeight);
    cursor.frameWidth = cursor.textureWidth / 3;
    cursor.frameHeight = cursor.textureHeight;
    cursor.srcRect.x = cursor.srcRect.y = 0;
    cursor.srcRect.w = cursor.frameWidth;
    cursor.srcRect.h = cursor.frameHeight;
    cursor.Draw = &Cursor_Draw;
    cursor.Update = &Cursor_Update;
    cursor.Animate = &Cursor_Animate;
    SDL_ShowCursor(false);
    return cursor;
}
void Cursor_Draw(Cursor* self) {
    SDL_RenderCopy(self->renderer, self->tex, &self->srcRect, &self->rect);
}
void Cursor_Update(Cursor* self) {
    SDL_GetMouseState(&self->rect.x, &self->rect.y);
    self->point.x = self->rect.x;
    self->point.y = self->rect.y;
}
void Cursor_Animate(Cursor* self, SDL_Event e) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        if (e.button.button == SDL_BUTTON_LEFT) {
            self->srcRect.x += self->frameWidth;
        }
    }
    else if (e.type == SDL_MOUSEBUTTONUP) {
        if (e.button.button == SDL_BUTTON_LEFT) {
            self->srcRect.x -= self->frameWidth;
        }
    }
}
