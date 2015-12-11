#include "include/CRender.hpp"
#include <SDL2/SDL_image.h>
CRender * CRender::instance = nullptr;
CRender::CRender()
{
    mWin = SDL_CreateWindow("Hello World",0,0,800,600,SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    mRender =  SDL_CreateRenderer(mWin,0,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32); //reserved memory byts for color
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
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
