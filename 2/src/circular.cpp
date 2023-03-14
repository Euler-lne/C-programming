#include "circular.h"
#include <cmath>
#include<iostream>
using namespace std;

Circular::Circular(double radius, Point center)
{
    this->radius = radius;
    this->center = center; // 这里可能有问题
    //执行完成之后就会释放center的内存
}
Circular::~Circular()
{
    cout << "Circular Delete ";
    this->ShowCircular();
}
bool Circular::IsIntersect(Circular other)
{
    // 相交条件 r1 - r2 <= d <= r1 + r2
    bool key;
    double distance = this->center.DistanceOfPoints(other.center);
    if (fabs(this->radius - other.radius) <= distance)
        key = true;
    else if (distance <= this->radius + other.radius)
        key = true;
    else
        key = false;
    return key;
}
void Circular::ShowCircular()
{
    cout << "Radius: " << this->radius << endl;
    this->center.ShowPoint();
    return;
}