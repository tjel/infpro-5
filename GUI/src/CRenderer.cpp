#include "include/CRenderer.h"
CRenderer * CRenderer::instance = nullptr;
CRenderer::CRenderer()
{
    mWin = SDL_CreateWindow("Hello World",100,100,640,480,SDL_WINDOW_SHOWN);
    mRender =  SDL_CreateRenderer(mWin,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}
CRenderer * CRenderer::GetRenerer()
{
    if(instance == nullptr)instance = new CRenderer;
    return instance;
}
