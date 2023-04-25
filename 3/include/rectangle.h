#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include "shape.h"
class Rectangle : public Shape
{
private:
    double length,width;
public:
    Rectangle(/* args */);
    Rectangle(double _length, double _width);
    ~Rectangle();
    double area();
};


#endif