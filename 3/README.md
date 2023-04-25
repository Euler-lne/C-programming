# 继承与派生实验
编写C++程序完成“形状”的以下功能：
* （1） 声明一个基类 Shape（形状），其中包含一个方法来计算面积；
* （2） 从 Shape 派生两个类：矩形类和圆形类；
* （3） 从矩形类派生正方形类；
* （4） 分别实现派生类构造函数、析构函数和其他方法；
* （5） 创建派生类的对象，观察构造函数、析构函数调用次序；
（提示及要求：1，可通过在构造与析构函数中加入输出提示信息的方式观察
相关调用；可以使用 system("pause")进行程序的暂停；2，能够理解并说明每
一次构造与析构函数调用是哪个对象的调用，并观察和解释相关调用顺序及
其原因）
* （6） 对不同对象计算面积。
# 笔记
* 需要在需要继承的类中添加头文件
```CPP
#ifndef CIRCLE_H_
#define CIRCLE_H_
#define PI 3.14159
#include "shape.h"
class Circle : public Shape
{
private:
    /* data */
    double radius;
public:
    Circle(/* args */);
    Circle(double _radius);
    ~Circle();
    double area();
};


#endif
```
* 注意析构和构造的顺序
* 还需要更多的尝试