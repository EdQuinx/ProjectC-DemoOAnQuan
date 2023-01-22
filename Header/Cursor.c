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
    cursor.Draw = &Cursor_Draw;
    cursor.Update = &Cursor_Update;
    SDL_ShowCursor(false);
    return cursor;
}
void Cursor_Draw(Cursor* self) {
    SDL_RenderCopy(self->renderer, self->tex, NULL, &self->rect);
}
void Cursor_Update(Cursor* self) {
    SDL_GetMouseState(&self->rect.x, &self->rect.y);
    self->point.x = self->rect.x;
    self->point.y = self->rect.y;
}
