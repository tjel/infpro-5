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

    Shape();

    Shape(Point _point);

    Shape(Point _point_a, Point _point_b);

    Shape(Point _point_a, Point _point_b, Point _point_c);

    Shape(Point _point_a, Point _point_b, Point _point_c, Point _point_d);

    void AddPoint(Point point);

    void Draw();
    
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();

    Point* GetPoints(unsigned i);

    void SetVisability(bool _visable);

private:
    std::vector<Point> points;
    float line_width;
    bool visable;
};

#endif // SHAPE_H
