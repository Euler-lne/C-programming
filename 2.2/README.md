# 2.2 编写C++程序完成“矩阵”类以下功能：
* （1） 用类来实现矩阵，定义一个矩阵的类，属性包括：
    * 矩阵大小，用 lines, rows（行、列来表示）；
    * 存贮矩阵的数组指针，根据矩阵大小动态申请（new）。
* （2） 矩阵类的方法包括：
    * 构造函数，参数是矩阵大小，需要动态申请存贮矩阵的数组；
    * 析构函数，需要释放矩阵的数组指针；
    * 拷贝构造函数，需要申请和复制数组；
    * 输入，可以从 cin 中输入矩阵元素；
    * 输出，将矩阵格式化输出到 cout；
    * 矩阵相加的函数，实现两个矩阵相加的功能，结果保存在另一个矩阵类，但必须矩阵大小相同；
    * 矩阵相减的函数，实现两个矩阵相减的功能，结果保存在另一个矩阵类，但必须矩阵大小相同。
* （3） 定义三个矩阵：A1、A2、A3；
* （4） 初始化 A1、A2；
* （5） 计算并输出 A3 = A1 + A2，A3 = A1 - A2；（要求及提示：最好能实现对赋值操作符“=”的重载；注意检查“自赋值”、释放“旧元素”）
* （6） 用 new 动态创建三个矩阵类的对象：pA1、pA1、pA3；
* （7） 初始化 pA1、pA2；
* （8） 计算并输出 pA3=pA1 加 pA2，pA3=pA1 减 pA2；
* （9） 释放 pA1、pA2、pA3。
# 注意
* delete
```CPP
// delete不能用, delete pA, pB;
delete pA;
delete pB;
```
* 重载等于号，如果不一样，要删除之前的，然后重新创建
```CPP
/// @brief 重载等号，要考虑到行类不一样的情况，不一样需要强制赋值
/// @param A 引用传递
/// @return 返回等号后的指
Matrix &Matrix::operator=(const Matrix &_other)
{
    if(this == &_other)
    {
        return *this;
    }
    // 要考虑到行类不一样的情况，不一样需要强制赋值
    this->DeleteMatrix();
    this->lines = _other.GetLines();
    this->rows = _other.GetRows();
    this->InitMatrix();
    for (int i = 0; i < lines;i++)
    {
        for (int j = 0; j < rows;j++)
            matirx[i][j] = _other.matirx[i][j];
    }
    return *this;
}
```
* 重载加法
```CPP
/// @brief 重构加法会调用析构函数，因为里面调用了构造函数
/// @param A 引用传递
/// @param B 引用传递
/// @return 返回相加的值
Matrix operator+(const Matrix &A, const Matrix &B)
{
    Matrix answer(A.GetLines(), A.GetRows());
    if(A.GetLines()!=B.GetLines()||A.GetRows()!=B.GetRows())
    {
        cout << "Error, The two matrix rows and columns are not the same." << endl;
        return answer;
    }
    for (int i = 0; i < A.lines; i++)
    {
        for (int j = 0; j < A.rows; j++)
        {
            answer.matirx[i][j] = A.matirx[i][j] + B.matirx[i][j];
        }
    }
    return answer;
}
```
