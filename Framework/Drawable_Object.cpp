#include "Drawable_Object.h"
#include "Draw_Queue.h"

Drawable_Object::Drawable_Object()
{

}

Drawable_Object* Drawable_Object::AddToQueue()
{
    Draw_Queue::GetInstance()->AddToQueue(this);

    return this;
}

