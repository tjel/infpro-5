#include "include/CRender.hpp"
#include <SDL2/SDL_image.h>
CRender * CRender::instance = nullptr;
CRender::CRender()
{
    mWin = SDL_CreateWindow("Hello World",0,0,800,600,SDL_WINDOW_SHOWN);
    mRender =  SDL_CreateRenderer(mWin,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}
CRender * CRender::GetRender()
{
    if(instance == nullptr)instance = new CRender;//prezent dla Grzesia!``
    return instance;
}
CRender::~CRender()
{
    SDL_DestroyWindow(mWin);
    SDL_DestroyRenderer(mRender);
}
