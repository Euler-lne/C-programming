#include "rectangle.h"
#include <bits/stdc++.h>
Rectangle::Rectangle()
{
    std::cout << "调用Rectangle的无参构造函数" << std::endl;
}
Rectangle::Rectangle(double _length, double _width)
{
    length = _length;
    width = _width;
    std::cout << "调用Rectangle的有参构造函数" << std::endl;
}
Rectangle::~Rectangle()
{
    std::cout << "调用Rectangle的析构函数" << std::endl;
}
double Rectangle::area()
{
    std::cout << "调用Rectangle的area函数" << std::endl;
    std::cout << "面积为" << length * width << std::endl;
    return length * width;
}