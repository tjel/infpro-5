#include "drawableobject.h"
#include "drawround.h"

DrawableObject::DrawableObject()
{

}

DrawableObject* DrawableObject::AddToRound()
{
    DrawRound::GetInstance()->AddToRound(this);

    return this;
}

