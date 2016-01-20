#include "Shape.h"
#include <iostream>
#include "Renderer.h"
#include <GL/gl.h>

Shape::Shape()
{
    visable = true;
}

Shape::Shape(std::vector<Point> _points)
{
    visable = true;
    points = _points;
}

Shape::Shape(Point _point)
{
    visable = true;
    points.push_back(_point);
}

Shape::Shape(Point _point_a, Point _point_b)
{
    visable = true;
    points.push_back(_point_a);
    points.push_back(_point_b);
}

Shape::Shape(Point _point_a, Point _point_b, Point _point_c)
{
    visable = true;
    points.push_back(_point_a);
    points.push_back(_point_b);
    points.push_back(_point_c);
}

Shape::Shape(Point _point_a, Point _point_b, Point _point_c, Point _point_d)
{
    visable = true;
    points.push_back(_point_a);
    points.push_back(_point_b);
    points.push_back(_point_c);
    points.push_back(_point_d);
}

void Shape::MoveDown()
{
    for(unsigned i = 0; i<points.size(); i++)
    {
        points[i].Y++;
    }
}

void Shape::MoveLeft()
{
    for(unsigned i = 0; i<points.size(); i++)
    {
        points[i].X--;
    }
}

void Shape::MoveRight()
{
    for(unsigned i = 0; i < points.size(); i++)
    {
        points[i].X++;
    }
}

void Shape::MoveUp()
{
    for(unsigned i = 0 ; i<points.size(); i++)
    {
        points[i].Y--;
    }
}

Point* Shape::GetPoints(unsigned i)
{
    return &points[i];
}

void Shape::AddPoint(Point point)
{
    points.push_back(point);
}

void Shape::Draw()
{
    if(visable)
    {
        SDL_SetRenderDrawColor( Renderer::Get()->display_renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        glLineWidth(	2.5 );
        if(points.size() >= 2)
        {
            for(unsigned i = 0; i < points.size(); i++)
            {
                if(i < points.size() - 1)
                    SDL_RenderDrawLine(Renderer::Get()->display_renderer,points[i].X, points[i].Y, points[i+1].X, points[i+1].Y);
                else // na sam koniec rysuje połączenie z pierwszym wierzchołkiem
                    SDL_RenderDrawLine(Renderer::Get()->display_renderer,points[i].X, points[i].Y, points[0].X, points[0].Y);
            }
        }
        else if(points.size() == 1)   // w przypadku rysowania jednego punktu
        {

        }
    }
}

void Shape::SetVisability(bool _visable)
{
    visable = _visable;
}
