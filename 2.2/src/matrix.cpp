#include "matrix.h"
#include <bits/stdc++.h>
using namespace std;

/// @brief 构造函数
/// @param _line 行
/// @param _row 列
Matrix::Matrix(int _line, int _row) : rows(_row), lines(_line)
{
    this->InitMatrix();
}
/// @brief 拷贝函数
/// @param other 传入的值
Matrix::Matrix(const Matrix &other)
{
    // 为行和列赋值，初始化这个矩阵
    this->lines = other.GetLines();
    this->rows = other.GetRows();
    this->InitMatrix();
    for (int i = 0; i < this->lines; i++)
    {
        for (int j = 0; j < this->rows; j++)
        {
            this->matirx[i][j] = other.matirx[i][j];
        }
    }
}
/// @brief 析构函数，调用删除函数
Matrix::~Matrix()
{
    this->DeleteMatrix();
    cout << "Delete all." << endl;
}
void Matrix::ShowMatrix()
{
    for (int i = 0; i < this->lines; i++)
    {
        for (int j = 0; j < this->rows; j++)
        {
            cout << this->matirx[i][j] << " ";
        }
        cout << std::endl;
    }
}
/// @brief 更改相应的值
/// @param _line 第line行下标
/// @param _row 第row列下标
/// @param _value 值
/// @return 返回一些状态
int Matrix::ChangeItem(int _line, int _row, int _value)
{
    if (_line < this->lines && _line >= 0 && _row < this->rows && _row >= 0)
    {
        this->matirx[_line][_row] = _value;
        return _OK_;
    }
    else
    {
        cout << "Error, The location you want to change is not within the scope of the matrix." << endl;
        return CHANGE_ERROR_;
    }
}
/// @brief 重载等号
/// @param A 引用传递
/// @return 返回等号后的指
Matrix &Matrix::operator=(const Matrix &A)
{
    bool key = false;
    // 只有满足情况才可以进行等号赋值
    if (A.GetLines() == this->lines && A.GetRows() == this->rows)
        key = true;
    for (int i = 0; i < A.GetLines() && key; i++)
    {
        for (int j = 0; j < A.GetRows(); j++)
        {
            this->matirx[i][j] = A.GetValue(i, j);
        }
    }
    return *this;
}
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
/// @brief 重构加法会调用析构函数，因为里面调用了构造函数
/// @param A 引用传递
/// @param B 引用传递
/// @return 返回相减的值
Matrix operator-(const Matrix &A, const Matrix &B)
{
    Matrix answer(A.GetLines(), A.GetRows());
    if (A.GetLines() != B.GetLines() || A.GetRows() != B.GetRows())
    {
        cout << "Error, The two matrix rows and columns are not the same." << endl;
        return answer;
    }
    for (int i = 0; i < A.lines; i++)
    {
        for (int j = 0; j < A.rows; j++)
        {
            answer.matirx[i][j] = A.matirx[i][j] - B.matirx[i][j];
        }
    }
    return answer;
}
/// @brief 初始化矩阵
void Matrix::InitMatrix()
{
    this->matirx = new int *[this->lines];
    for (int i = 0; i < this->lines; i++)
    {
        this->matirx[i] = new int[this->rows];
        for (int j = 0; j < this->rows; j++)
        {
            this->matirx[i][j] = 0; // 先初始化为0
        }
    }
}
/// @brief 删除矩阵
void Matrix::DeleteMatrix()
{
    for (int i = 0; i < this->lines; i++)
    {
        delete[] this->matirx[i];
    }
    delete[] this->matirx;
}
