#ifndef POINT_H_
#define POINT_H_

class Point
{
public:
    Point();
    ~Point();
    Point(int, int);
    Point(const Point&);
    int GetX() { return x; }
    int GetY() { return y; }
    void SetX(int _x) { x = _x; }
    void SetY(int _y) { y = _y; }
    void Show();
    friend Point operator++(Point &);//++c
    friend Point operator++(Point &, int);//c++
    friend Point operator--(Point &);     //++c
    friend Point operator--(Point &, int); // c++

private:
    int x, y;
};
#endif