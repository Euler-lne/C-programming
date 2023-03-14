#ifndef POINT_H_
#define POINT_H_
class Point
{
private:
    double x, y;
public:
    Point(double, double);
    Point();
    ~Point();
    Point(const Point &);
    double DistanceOfPoints(Point);
    void ShowPoint();
};
#endif