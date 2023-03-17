### 2.1编写一个程序完成“圆形”一下功能：
* 定义一个Point类，其属性包括点的坐标，提供计算两点之间距离的方法；
* 定义一个圆形对象类，其属性包括圆心和半径；
* 创建两个圆形对象，提示用户输入圆心坐标和半径，判断两个圆是否相交，并输出结果；
* 观察圆形对象以及Point类成员的构造函数与析构函数的调用。（提示及要求：1.通过在构造函数与析构函数中加入输出提示信息的方式观察相关调用；可以使用system("pause")进行程序的暂停；2.能够解释并说明每一次构造与析构函数调用是哪一个对象的调用，并观察和解释相关调用顺序及其原因）


### 笔记
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
* 更改方式，用拷贝构造函数的方法
```CPP
Circular::Circular(double radius, Point A) : center(A)
{
    this->radius = radius;
    // this->center = center;  // 这里 = 有何问题？
    // 执行完成之后就会释放Point的内存，也就是调用析构函数
    cout << "Circular Init" << endl;
}
```
* 对于计算两个圆是否相交传入了圆对象作为参数，所以需要为圆写一个拷贝函数，传入参数的时候调用拷贝函数赋值
```CPP
Circular(const Circular &);

Circular::Circular(const Circular &A) : center(A.center)
{
    this->radius = A.radius;
    cout << "Circular copy" << endl;
}
```

## 注意类作为参数传入到函数的情况，注意类内嵌类的情况

输出如下
```
-----------------------------------------------------------------------------
Please enter the coordinates of a center of the circle.
the first value is the horizontal axis;
and the second value is the vertical axis.
0 0
-----------------------------------------------------------------------------
Enter the radius of the circle. The radius must be greater than or equal to 0.
1
-----------------------------------------------------------------------------
Point Init 1
Point copy
Point copy
Circular Init
Point Delete Point: (0, 0).
-----------------------------------------------------------------------------
Please enter the coordinates of a center of the circle.
the first value is the horizontal axis;
and the second value is the vertical axis.
0 0
-----------------------------------------------------------------------------
Enter the radius of the circle. The radius must be greater than or equal to 0.
2
-----------------------------------------------------------------------------
Point Init 1
Point copy
Point copy
Circular Init
Point Delete Point: (0, 0).
Radius: 1 Point: (0, 0).
Radius: 2 Point: (0, 0).
Point copy                                  拷贝圆的时候先拷贝点
Circular copy                               拷贝圆
Point copy                                  计算坐标拷贝点
Point Delete Point: (0, 0).                 计算坐标结束
Circular Delete Radius: 1 Point: (0, 0).    结束圆相交函数
Point Delete Point: (0, 0).                 结束圆相交函数，后调用点
-----------------------------------------------------------------------------
The two circles do not intersect

```