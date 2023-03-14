#ifndef CIRCULAR_H_
#define CIRCULAR_H_
#include "point.h"
class Circular
{
private:
    double radius;
    Point center;

public:
    Circular(double, Point);
    ~Circular();
    void ShowCircular();
    bool IsIntersect(Circular);
};

#endif