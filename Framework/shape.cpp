#include "shape.h"
#include <iostream>

Shape::Shape(std::string text)
{
    this->text=text;
}



void Shape::Draw()
{
    std::cout<<"Rysowanie kształtu "<<text<<" \n****\n****\n*****"<<std::endl;
}
