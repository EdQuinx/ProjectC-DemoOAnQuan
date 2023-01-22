#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct RenderWindow RenderWindow;

struct RenderWindow {
    SDL_Window* window;
    SDL_Renderer* renderer;
    void (*Create) (RenderWindow *, const char*, int, int);
    void (*Clear) (RenderWindow *);
    void (*Render) (RenderWindow *, SDL_Texture *, SDL_Rect *, SDL_Rect *);
    void (*Display) (RenderWindow *);
    void (*Close) (RenderWindow *);
    void (*DestroyTexture) (SDL_Texture *);
};
RenderWindow RenderWindowInit(void);
SDL_Texture* LoadTexture(RenderWindow* self, const char* path);
void RenderWindow_Create(RenderWindow* self, const char* title, int width, int height);
void RenderWindow_Clear(RenderWindow* self);
void RenderWindow_Render(RenderWindow* self, SDL_Texture* tex, SDL_Rect* srcrect, SDL_Rect* rect);
void RenderWindow_Display(RenderWindow* self);
void RenderWindow_Close(RenderWindow* self);
void RenderWindow_DestroyTexture(SDL_Texture* tex);
