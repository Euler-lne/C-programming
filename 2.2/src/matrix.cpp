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
    if (other.GetLines() != this->lines || other.GetRows() != this->rows)
    {
        cout << "Error. The two matrices are not the same size." << endl;
    }
    else
    {
        for (int i = 0; i < this->lines; i++)
        {
            for (int j = 0; j < this->rows; j++)
            {
                this->matirx[i][j] = other.matirx[i][j];
            }
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
/// @param _line 第line行
/// @param _row 第row类
/// @param _value 值
void Matrix::ChangeItem(int _line, int _row, int _value)
{
    if (_line <= this->lines && _line > 0 && _row <= this->rows && _row > 0)
    {
        this->matirx[_line - 1][_row - 1] = _value;
    }
    else
    {
        cout << "Error, The location you want to change is not within the scope of the matrix." << endl;
    }
}
Matrix &Matrix::operator=(const Matrix &A)
{
    return *this;
}
Matrix operator+(const Matrix &A, const Matrix &B)
{
    Matrix answer(A.GetLines(), A.GetRows());
    return answer;
}
Matrix operator-(const Matrix &A, const Matrix &B)
{
    Matrix answer(A.GetLines(), A.GetRows());
    return answer;
}
void Matrix::InitMatrix()
{
    this->matirx = new int *[this->lines];
    for (int i = 0; i < this->rows; i++)
    {
        this->matirx[i] = new int[this->rows];
        for (int j = 0; j < this->rows; j++)
        {
            this->matirx[i][j] = 0; // 先初始化为0
        }
    }
}
void Matrix::DeleteMatrix()
{
    for (int i = 0; i < this->lines; i++)
    {
        delete[] this->matirx[i];
    }
    delete[] this->matirx;
}
