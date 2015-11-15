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
    virtual void setPosition(int x,int y);
    virtual void setPosition(Vector2i Pos);
    virtual void setSize(int w,int h);
    virtual void setSize(Vector2i Size);
    virtual SDL_Rect GetRect(){return mSDLrect;}
    virtual SDL_Point GetPosition();
    virtual SDL_Point GetSize();
    virtual std::shared_ptr<Widget> GetPtr();
    virtual void Draw();
    virtual void handleEvent(SDL_Event * events);
private:
    SDL_Rect mSDLrect;
};

#endif // WIDGET_H
