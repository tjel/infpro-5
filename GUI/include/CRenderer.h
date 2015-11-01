#ifndef CRENDERER_H
#define CRENDERER_H
#include <SDL2/SDL.h>
#include <memory>
class CRenderer
{
public:
    static CRenderer * GetRenerer();
    SDL_Renderer * mRender;
    SDL_Window * mWin;
private:
    CRenderer();
    static CRenderer * instance;


};

#endif // CRENDERER_H
