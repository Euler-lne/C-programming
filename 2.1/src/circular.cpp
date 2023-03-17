#include "circular.h"
#include <cmath>
#include <iostream>
using namespace std;

Circular::Circular(double radius, Point A) : center(A)
{
    this->radius = radius;
    // this->center = A;  // 这里 = 有何问题？
    // 执行完成之后就会释放Point的内存，也就是调用析构函数
    cout << "Circular Init" << endl;
}
Circular::Circular(const Circular &A) : center(A.center)
{
    this->radius = A.radius;
    cout << "Circular copy" << endl;
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
    if (fabs(this->radius - other.radius) <= distance && distance <= this->radius + other.radius)
        key = true;
    else
        key = false;
    return key;
}
void Circular::ShowCircular()
{
    cout << "Radius: " << this->radius << " ";
    this->center.ShowPoint();
    return;
}