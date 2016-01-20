#include "Drawable_Object.h"
#include "Draw_Queue.h"

Drawable_Object::Drawable_Object()
{
}

Drawable_Object* Drawable_Object::AddToQueue()
{
    Draw_Queue::Get()->AddToQueue(this);

    return this;
}

Drawable_Object* Drawable_Object::RemoveFromQueue()
{
    Draw_Queue::Get()->RemoveFromQueue(this);
    
    return this;
}

bool Drawable_Object::IsFirstPlaneFrom(Drawable_Object* one, Drawable_Object* two)
{
    return (one->plane<two->plane);
}

void Drawable_Object::SetPlane(unsigned _plane)
{
    plane = _plane;
}