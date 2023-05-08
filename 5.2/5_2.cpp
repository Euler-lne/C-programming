#include "point.h"
int main()
{
    Point point1(2,2);
    point1.Show();
    point1++;
    point1.Show();
    --point1;
    point1.Show();
    return 0;
}