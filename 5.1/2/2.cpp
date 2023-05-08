#include <bits/stdc++.h>
#include "circle.h"
#include "rectangle.h"
#include "shape.h"
#include "square.h"
int main()
{
    Circle circle(3);
    Rectangle rectangle(3, 4);
    Square square(5);
    circle.area();
    rectangle.area();
    square.area();
    return 0;
}