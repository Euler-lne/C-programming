#ifndef SQUARE_H_
#define SQUARE_H_
#include "rectangle.h"
class Square : public Rectangle
{
private:
    /* data */
    double length;
public:
    Square(/* args */);
    Square(double _length);
    ~Square();
    double area();
};
#endif