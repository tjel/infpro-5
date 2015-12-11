#ifndef CRENDER_H
#define CRENDER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <memory>
class CRender
{
public:
    static CRender * GetRender();
    SDL_Renderer * mRender;
    SDL_Window * mWin;
    SDL_GLContext gContext;
    ~CRender();
private:
    CRender();
    static CRender * instance;

};

#endif // CRENDER_H
