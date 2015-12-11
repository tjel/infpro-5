#ifndef WIDGET_H
#define WIDGET_H
#include <Vector/Vector2.h>
#include "include/ResourceManager.hpp"
#include <SDL2/SDL_rect.h>
#include <memory>
class Widget
{
public:
    Widget();
    virtual void Draw();
    virtual void handleEvent(SDL_Event * events);

    virtual void setPosition(int x,int y);
    virtual void setPosition(SDL_Point Pos);

    virtual void setSize(int w,int h);
    virtual void setSize(SDL_Point Size);

    virtual SDL_Rect GetRect();

    virtual SDL_Point GetPosition();

    virtual SDL_Point GetSize();
    virtual int GetMode();
    virtual void setMode(int mMode);
    virtual std::shared_ptr<Widget> GetPtr();
private:
    SDL_Rect mSDLrect;
    SDL_Point mPosition;
    SDL_Point mSize;
    int mode;
};

#endif // WIDGET_H
