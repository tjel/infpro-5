#ifndef SHAPE_H
#define SHAPE_H

#include "Drawable_Object.h"
#include "Point.h"
#include <string>
#include <vector>

class Shape : public Drawable_Object
{
public:
    Shape(std::vector<Point> _points);

    void Draw();
private:
    std::vector<Point> points;
};

#endif // SHAPE_H
