#include "point.h"
#include <bits/stdc++.h>
Point::Point()
{
    x = 0;
    y = 0;
}
Point::~Point()
{

}
Point::Point(const Point & _point)
{
    x = _point.x;
    y = _point.y;
}
Point::Point(int _x,int _y)
{
    x = _x;
    y = _y;
}
Point operator++(Point& _point)
{
    ++_point.x;
    ++_point.y;
    return _point;
}
Point operator++(Point &_point, int)
{
    _point.x++;
    _point.y++;
    return _point;
}
Point operator--(Point &_point)
{
    --_point.x;
    --_point.y;
    return _point;
}
Point operator--(Point &_point, int)
{
    _point.x--;
    _point.y--;
    return _point;
}
void Point::Show()
{
    std::cout << x << " " << y << std::endl;
}