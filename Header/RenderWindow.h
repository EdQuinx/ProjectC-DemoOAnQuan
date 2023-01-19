#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct RenderWindow RenderWindow;

struct RenderWindow {
    SDL_Window* window;
    SDL_Renderer* renderer;
    void (*Create) (RenderWindow *, const char*, int, int);
    void (*CleanUp) (RenderWindow *);
    void (*Clear) (RenderWindow *);
    void (*Render) (RenderWindow *, SDL_Texture *);
    void (*Display) (RenderWindow *);
};

RenderWindow RenderWindowInit(void);
SDL_Texture* LoadTexture(RenderWindow* self, const char* path);
void RenderWindow_Create(RenderWindow* self, const char* title, int width, int height);
void RenderWindow_CleanUp(RenderWindow* self);
void RenderWindow_Clear(RenderWindow* self);
void RenderWindow_Render(RenderWindow* self, SDL_Texture* tex);
void RenderWindow_Display(RenderWindow* self);
