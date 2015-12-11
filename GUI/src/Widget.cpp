#include "include/Widget.hpp"

Widget::Widget()
{

}
void Widget::setPosition(int x, int y)//Ustawianie Pozycji na poctawie x i y;
{
   mPosition.x = x;
   mPosition.y = y;
}
void Widget::setPosition(SDL_Point Pos)//Ustawianie Pozycji na poctawie Vector2<int>
{
    mPosition = Pos;
}
void Widget::setSize(int w, int h)
{
    mSize.x = w;
    mSize.y = h;
}
void Widget::setSize(SDL_Point Size)
{
    mSize.x = Size.x;
    mSize.y = Size.y;
}
SDL_Point Widget::GetSize()
{
    return mSize;
}

SDL_Point Widget::GetPosition()
{
    return mPosition;
}

void Widget::Draw()
{

}
void Widget::handleEvent(SDL_Event * events)
{

}
SDL_Rect Widget::GetRect()
{
    SDL_Rect temp {mPosition.x,mPosition.y,mSize.x,mSize.y};
    return temp;
}
 int Widget::GetMode()
{
    return mode;
}

void Widget::setMode(int mMode)
{
    mode = mMode;
}

std::shared_ptr<Widget> Widget::GetPtr()
{
    return std::shared_ptr<Widget>(this);
}
