#ifndef CIRCLE_H_
#define CIRCLE_H_
#define PI 3.14159
#include "shape.h"
class Circle : public Shape
{
private:
    /* data */
    double radius;
public:
    Circle(/* args */);
    Circle(double _radius);
    ~Circle();
    double area();
};


#endif