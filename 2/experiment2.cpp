#include <iostream>
#include "point.h"
#include "circular.h"
using namespace std;
void InitCircular();
int main()
{
    Point pointA(2, 0), pointB;
    Circular A(2, pointA), B(1, pointB);
    A.ShowCircular();
    B.ShowCircular();
    return 0;
}
void InitCircular()
{
    cout << "";
}



// 不写拷贝构造函数也可以正常运行，为什么？
// 因为系统会自动调用浅拷贝构造函数