#include "include/LogSDL.hpp"
#include <SDL2/SDL.h>
#include "include/CRender.hpp"
LogSDL::LogSDL()
{

}
void LogSDL::logSDLError(std::ostream &os, const std::string &msg)
{
    os << msg << " error: " << SDL_GetError() << std::endl;
    mess = msg + " " + SDL_GetError();
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING,msg.c_str(),mess.c_str(),CRender::GetRender()->mWin);

}
