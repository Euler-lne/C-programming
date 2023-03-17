#include <iostream>
#include "point.h"
#include "circular.h"
using namespace std;

void PromptUser();

int main()
{
    double x, y, radius;
    PromptUser();
    cin >> x >> y;
    cout << "-----------------------------------------------------------------------------" << endl
         << "Enter the radius of the circle. The radius must be greater than or equal to 0." << endl;
    cin >> radius;
    cout << "-----------------------------------------------------------------------------" << endl;
    Point pointA(x, y);
    Circular A(radius, pointA);
    PromptUser();
    cin >> x >> y;
    cout << "-----------------------------------------------------------------------------" << endl
         << "Enter the radius of the circle. The radius must be greater than or equal to 0." << endl;
    cin >> radius;
    cout << "-----------------------------------------------------------------------------" << endl;
    Point pointB(x, y);
    Circular B(radius, pointB);
    cout << "-----------------------------------------------------------------------------" << endl
         << "Show Cricular" << endl;
    A.ShowCircular();
    B.ShowCircular();
    cout << "-----------------------------------------------------------------------------" << endl
         << "End Show Cricular" << endl;
    // 这里进行了圆的拷贝函数，因为圆作为参数
    if (B.IsIntersect(A))
        cout << "-----------------------------------------------------------------------------" << endl
             << "Two circles intersect." << endl;
    else
        cout << "-----------------------------------------------------------------------------" << endl
             << "The two circles do not intersect" << endl;
    return 0;
}
void PromptUser()
{
    cout << "-----------------------------------------------------------------------------" << endl
         << "Please enter the coordinates of a center of the circle. " << endl
         << "the first value is the horizontal axis; " << endl
         << "and the second value is the vertical axis. Separated by spaces!" << endl;
}

// 不写拷贝构造函数也可以正常运行，为什么？
// 因为系统会自动调用浅拷贝构造函数