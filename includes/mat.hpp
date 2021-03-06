#ifndef MAT_H_
#define MAT_H_

#include "vec.hpp"

typedef vector<vector_d> matrix_d;

class mat{
    private:
    matrix_d mat_d;
    int size();

    public:
    mat(int row, int col, int num=0);

    matrix_d& operator [](int);

    matrix_d& operator +(const matrix_d &);
    matrix_d& operator +=(const matrix_d &);
    matrix_d& operator -(const matrix_d &);
    matrix_d& operator -=(const matrix_d &);
    matrix_d& operator *(const matrix_d &);
    matrix_d& operator *=(const matrix_d &);
    matrix_d& operator /(const matrix_d &);
    matrix_d& operator /=(const matrix_d &);

    matrix_d& operator +(const double &);
    matrix_d& operator +=(const double &);
    matrix_d& operator -(const double &);
    matrix_d& operator -=(const double &);
    matrix_d& operator *(const double &);
    matrix_d& operator *=(const double &);
    matrix_d& operator /(const double &);
    matrix_d& operator /=(const double &);

    matrix_d& operator *(const vector_d &);
    matrix_d& operator *=(const vector_d &);

    matrix_d invertion();
};

#endif