#include <SDL2/SDL.h>

typedef struct RenderWindow RenderWindow;

struct RenderWindow {
    SDL_Window* window;
    SDL_Renderer* renderer;
    void (*Create) (RenderWindow *, const char*, int, int);
    void (*CleanUp) (RenderWindow *);
};

RenderWindow RenderWindowInit(void);
void RenderWindow_Create(RenderWindow* self, const char* title, int width, int height);
void RenderWindow_CleanUp(RenderWindow* self);
