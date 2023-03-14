/**
 /// * 采用的是行指针
* typedef int (*ARRAY)[M]
*/
#include <iostream>
#define N 4 //行/高度
#define M 5 //列/宽度
using namespace std;
typedef int (*ARRAY)[M]; // 行指针

void InitMatix(ARRAY);
void OutputMatix(ARRAY);
void AddMatix(ARRAY, ARRAY, ARRAY);
void SubMatix(ARRAY, ARRAY, ARRAY);

int main()
{
    ARRAY A1 = new int[N][M];
    ARRAY A2 = new int[N][M];
    ARRAY A3 = new int[N][M];
    InitMatix(A1);
    InitMatix(A2);
    AddMatix(A1, A2, A3);
    OutputMatix(A3);
    SubMatix(A1, A2, A3);
    OutputMatix(A3);
    delete[] A1;
    delete[] A2;
    delete[] A3;
    return 0;
}
/// @brief 初始化矩阵
/// @param A 
void InitMatix(ARRAY A)
{
    for (int i = 0; i < N;i++)
    {
        for (int j = 0; j < M;j++)
            cin >> A[i][j];
    }
    return;
}
/// @brief 输出矩阵
/// @param A 
void OutputMatix(ARRAY A)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    return;
}
/// @brief 矩阵相加
/// @param A 
/// @param B 
/// @param C 引用变量，作为输出
void AddMatix(ARRAY A, ARRAY B, ARRAY C)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            C[i][j] = A[i][j] + B[i][j];
    }
    return;
}
/// @brief 矩阵相减
/// @param A
/// @param B
/// @param C 引用变量，作为输出
void SubMatix(ARRAY A, ARRAY B, ARRAY C)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            C[i][j] = A[i][j] - B[i][j];
    }
    return;
}

// 错误：int **A1 = new int [N][M];
// 1. int(*A1)[M] = new int[N][M];//直接可用
// 元素类型为‘int[M]’的数组，可赋值给‘int[M]’类型的指针。行指针的定义形式为：类型标识符 （*指针变量名）[长度/列数];
// 2. int ** A1 = new int *[M];//需要再次为每一行的元素申请空间赋值

// 如果返回的是ARRAY类型，而不是直接引用怎么搞？要在返回之前把new出来的变量删除
// 不用引用也可以因为，这里变量的值是指针，可以更改值