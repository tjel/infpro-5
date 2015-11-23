#include "Shape.h"
#include <iostream>
#include <GL/gl.h>


Shape::Shape()
{

}

Shape::Shape(std::vector<Point> _points)
{
    points = _points;
}

Shape::Shape(Point _point)
{
    points.push_back(_point);
}

Shape::Shape(Point _point_a, Point _point_b)
{
    points.push_back(_point_a);
    points.push_back(_point_b);
}

Shape::Shape(Point _point_a, Point _point_b, Point _point_c)
{
    points.push_back(_point_a);
    points.push_back(_point_b);
    points.push_back(_point_c);
}

Shape::Shape(Point _point_a, Point _point_b, Point _point_c, Point _point_d)
{
    points.push_back(_point_a);
    points.push_back(_point_b);
    points.push_back(_point_c);
    points.push_back(_point_d);
}

void Shape::AddPoint(Point point)
{
    points.push_back(point);
}


void Shape::Draw()
{
    glColor3f(1.0, 1.0, 1.0);
    if(points.size()>=2)
    {
        glLineWidth(2.5);
        glBegin(GL_LINES);
        for(unsigned i=0; i<points.size(); i++)
        {
            glVertex3f(points[i].X, points[i].Y,0.0f);
            if(i<points.size()-1)
                glVertex3f(points[i+1].X, points[i+1].Y,0.0f);
            else//na sam koniec rysuje połączenie z pierwszym wierzchołkiem
                glVertex3f(points[0].X,points[0].Y,0.0f);
        }

        glEnd();
    }
    else if(points.size()==1) //w przypadku rysowania jednego punktu
    {
        glPointSize(2.5);
        glBegin(GL_POINTS);
        glVertex3f(points[0].X,points[0].Y,0.0f);
        glEnd();
    }
}
