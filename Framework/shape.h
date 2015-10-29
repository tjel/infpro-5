#ifndef SHAPE_H
#define SHAPE_H

#include "drawableobject.h"
#include <string>

class Shape : public DrawableObject
{
public:
    Shape(std::string text);

    void Draw();
private:
    std::string text;
};

#endif // SHAPE_H
