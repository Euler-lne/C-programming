#include "point.h"
#include <cmath>
#include<iostream>
using namespace std;

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

Point::Point()
{
    this->x = 0.0;
    this->y = 0.0;
}

Point::~Point()
{
    cout << "Point Delete ";
    this->ShowPoint();
}

Point::Point(const Point &A)
{
    this->x = A.x;
    this->y = A.y;
}

double Point::DistanceOfPoints(Point A)
{
    double distance, a, b;
    a = pow(this->x - A.x, 2);
    b = pow(this->y - A.y, 2);
    distance = sqrt(a + b);
    return distance;
}

void Point::ShowPoint()
{
    cout << "Point: (" << this->x << ", "
         << this->y << "). " << endl;
}