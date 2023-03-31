#ifndef MATRIX_H_
#define MATRIX_H_
class Matrix
{
public:
    Matrix(int, int);
    Matrix(const Matrix &);
    ~Matrix();
    int GetLines() const { return this->lines; }
    int GetRows() const { return this->rows; }
    void ShowMatrix();
    void ChangeItem(int, int, int);
    Matrix& operator=(const Matrix &);
    friend Matrix operator+(const Matrix &, const Matrix &);
    friend Matrix operator-(const Matrix &, const Matrix &);

private:
    int **matirx;
    int lines;
    int rows;
    void InitMatrix();
    void DeleteMatrix();
};
#endif
