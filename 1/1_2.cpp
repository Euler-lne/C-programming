/***
 * 直接使用二级指针
 */
#include <iostream>
#define N 4 // 行
#define M 5 // 列
using namespace std;

// 设置一个布尔值以示区分，因为A3需要被初始化，但是不需要传入数据
void InitMatix(int **, bool);
void OutputMatix(int **);
void AddMatix(int **, int **, int **);
void SubMatix(int **, int **, int **);
void DeletMatix(int **);

int main()
{
    int **A1 = new int *[M];
    int **A2 = new int *[M];
    int **A3 = new int *[M];
    InitMatix(A1, true);
    InitMatix(A2, true);
    InitMatix(A3, false);
    AddMatix(A1, A2, A3);
    OutputMatix(A3);
    SubMatix(A1, A2, A3);
    OutputMatix(A3);
    DeletMatix(A1);
    DeletMatix(A2);
    DeletMatix(A3);
    return 0;
}
void InitMatix(int **A, bool isInput)
{
    for (int i = 0; i < N; i++)
    {
        A[i] = new int[M];
    }
    for (int i = 0; i < N && isInput; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> A[i][j];
    }
    return;
}
void OutputMatix(int **A)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    return;
}
void AddMatix(int **A, int **B, int **C)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            C[i][j] = A[i][j] + B[i][j];
    }
    return;
}
void SubMatix(int **A, int **B, int **C)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            C[i][j] = A[i][j] - B[i][j];
    }
    return;
}
void DeletMatix(int **A)
{
    for (int i = 0; i < N; i++)
        delete[] A[i];
    delete[] A;
}

/***
 * 注意：虽然A3不需要输入，但是这种方法生成的矩阵需要初始化每一列
*/