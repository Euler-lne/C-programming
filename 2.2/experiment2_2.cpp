#include "matrix.h"
#include <bits/stdc++.h>
using namespace std;
void InputMatrix(Matrix *);

int main()
{
    Matrix A(2, 4);
    InputMatrix(&A);
    Matrix B(2,4);
    B = A;
    Matrix C(2,4);
    C = A + B;
    C.ShowMatrix();
    C = C - A;
    C.ShowMatrix();
    return 0;
}
/// @brief 传入指针不需要调用拷贝函数和析构函数
/// @param _matrix 
void InputMatrix(Matrix* _matrix)
{
    for (int i = 0; i < _matrix->GetLines(); i++)
    {
        for (int j = 0; j < _matrix->GetRows(); j++)
        {
            int temp = 1;
            // cin >> temp;
            //FIXME:最后需要把输入更改
            if(_matrix->ChangeItem(i, j, temp) == CHANGE_ERROR_)
                return;
        }
    }
}