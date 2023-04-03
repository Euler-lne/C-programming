#ifndef MATRIX_H_
#define MATRIX_H_
#define CHANGE_ERROR_ 1
#define _OK_ 2
class Matrix
{
public:
    Matrix(int, int);
    Matrix(const Matrix &);
    ~Matrix();
    int GetLines() const { return this->lines; }
    int GetRows() const { return this->rows; }
    int GetValue(int _line, int _row) const {return this->matirx[_line][_row];}
    void ShowMatrix();
    int ChangeItem(int _line, int _row, int _value);
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
