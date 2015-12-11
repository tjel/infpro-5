#ifndef LOGSDL_H
#define LOGSDL_H
#include<string>
#include<strstream>
#include<SDL2/SDL_error.h>

class LogSDL
{
public:
    LogSDL();
    void logSDLError(std::ostream &os, const std::string &msg);
private:
    std::string mess;
    std::string title;
};

#endif // LOGSDL_H
