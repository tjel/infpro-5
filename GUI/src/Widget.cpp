#include "include/Widget.hpp"

Widget::Widget()
{

}
void Widget::setPosition(int x, int y)//Ustawianie Pozycji na poctawie x i y;
{
   mSDLrect.x = x;
   mSDLrect.y = y;
}
void Widget::setPosition(Vector2i Pos)//Ustawianie Pozycji na poctawie Vector2<int>
{
    mSDLrect.x = Pos.a;
    mSDLrect.y = Pos.b;
}
void Widget::setSize(int w, int h)
{
    mSDLrect.w = w;
    mSDLrect.h = h;
}
void Widget::setSize(Vector2i Size)
{
    mSDLrect.w = Size.a;
    mSDLrect.h = Size.b;
}
SDL_Point Widget::GetSize()
{
    SDL_Point temp;
    temp.x = mSDLrect.w;
    temp.y = mSDLrect.h;
    return temp;
}

SDL_Point Widget::GetPosition()
{
    SDL_Point temp;
    temp.x = this->mSDLrect.x;
    temp.y = this->mSDLrect.y;
    return temp;
}

void Widget::Draw()
{

}
void Widget::handleEvent(SDL_Event * events)
{

}

std::shared_ptr<Widget> Widget::GetPtr()
{
    return std::shared_ptr<Widget>(this);
}
