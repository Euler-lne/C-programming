* 对于构造一个圆的类来说，初始化构造，是传入一个点的两个坐标和半径还是传入一个点和半径
```Cpp
Circular(Point A, double radius);
Circular(double x, double y, double radius);
```
* 如果采用第一种方式，那么在构造函数中，怎么为Point赋值？下图代码的 = 运用了什么原理
```CPP
Circular::Circular(double radius, Point center)
{
    this->radius = radius;
    this->center = center;  // 这里 = 有何问题？
    // 执行完成之后就会释放Point的内存，也就是调用析构函数
}
```
