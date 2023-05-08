#include "square.h"
#include <bits/stdc++.h>
Square::Square()
{
    std::cout << "调用Square的无参构造函数" << std::endl;
}
Square::Square(double _length)
{
    length = _length;
    std::cout << "调用Square的有参构造函数" << std::endl;
}
Square::~Square()
{
    std::cout << "调用Square的析构函数" << std::endl;
}
double Square::area()
{
    std::cout << "调用Square的area函数" << std::endl;
    std::cout << "面积为" << length * length << std::endl;
    return length*length;
}