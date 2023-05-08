#include "circle.h"
#include <bits/stdc++.h>
Circle::Circle()
{
    std::cout << "调用Circle的无参构造函数" << std::endl;
}
Circle::Circle(double _radius)
{
    radius = _radius;
    std::cout << "调用Circle的有参构造函数" << std::endl;
}
Circle::~Circle()
{
    std::cout << "调用Circle的析构函数" << std::endl;
}
double Circle::area()
{
    std::cout << "调用Circle的area函数" << std::endl;
    std::cout << "面积为" << radius * radius * PI << std::endl;
    return radius * radius * PI;
}