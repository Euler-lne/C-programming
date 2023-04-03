#include "matrix.h"
#include <bits/stdc++.h>
using namespace std;
void InputMatrix(Matrix *);

int main()
{
    int line, row;
    cout << "Input line and row of matrixes" << endl;
    cin >> line >> row;
    Matrix A(line, row);
    InputMatrix(&A);
    Matrix B(line,row);
    InputMatrix(&B);
    Matrix C(line,row);
    C = A + B;
    C.ShowMatrix();
    C = A - B;
    C.ShowMatrix();
    Matrix *pA = new Matrix(line, row);
    Matrix *pB = new Matrix(line, row);
    Matrix *pC = new Matrix(line, row);
    InputMatrix(pA);
    InputMatrix(pB);
    *pC = *pA + *pB;
    pC->ShowMatrix();
    *pC = *pA - *pB;
    pC->ShowMatrix();
    // delete不能用, delete pA, pB;
    delete pA;
    delete pB;
    delete pC;
    return 0;
}
/// @brief 传入指针不需要调用拷贝函数和析构函数
/// @param _matrix 
void InputMatrix(Matrix* _matrix)
{
    cout << "Input the all items of matrix, line " << _matrix->GetLines() << " row " << _matrix->GetRows() << endl;
    for (int i = 0; i < _matrix->GetLines(); i++)
    {
        for (int j = 0; j < _matrix->GetRows(); j++)
        {
            int temp;
            cin >> temp;
            if(_matrix->ChangeItem(i, j, temp) == CHANGE_ERROR_)
                return;
        }
    }
}
/***

3 4

1 2 3 4
1 2 3 4
1 2 3 4

4 3 2 1
1 2 3 4
4 3 2 1
*/