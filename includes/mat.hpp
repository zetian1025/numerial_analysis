#ifndef MAT_H_
#define MAT_H_

#include "vec.hpp"

typedef vector<vector_d> matrix_d;

class mat{
    private:
    matrix_d mat_d;

    public:
    mat(int, int, int);
    mat(const matrix_d &);

    int size() const;

    vector_d& operator [](int);
    const vector_d& operator [](int) const;

    mat operator +(const mat &);
    void operator +=(const mat &);
    mat operator -(const mat &);
    void operator -=(const mat &);
    mat operator *(const mat &);
    void operator *=(const mat &);

    mat operator +(const double &);
    void operator +=(const double &);
    mat operator -(const double &);
    void operator -=(const double &);
    mat operator *(const double &);
    void operator *=(const double &);
    mat operator /(const double &);
    void operator /=(const double &);

    mat invertion();
};

#endif