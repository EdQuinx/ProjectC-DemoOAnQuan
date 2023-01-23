#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct Cursor Cursor;

struct Cursor
{
    SDL_Renderer* renderer;
    SDL_Texture* tex;
    SDL_Rect srcRect;
    SDL_Rect rect;
    SDL_Rect point;
    int frameWidth;
    int frameHeight;
    int textureWidth;
    int textureHeight;
    void (*Draw) (Cursor *);
    void (*Update) (Cursor *);
    void (*Animate) (Cursor *, SDL_Event);
};

Cursor CursorInit(SDL_Renderer* renderer, SDL_Texture* texture);
void Cursor_Draw(Cursor* self);
void Cursor_Update(Cursor* self);
void Cursor_Animate(Cursor* self, SDL_Event e);
