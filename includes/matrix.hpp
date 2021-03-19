#ifndef MATRIX_H_
#define MATRIX_H_

#include "vector.hpp"
#include "util.hpp"
#include <utility>

using std::vector;
using std::pair;

template <typename T>
class Matrix{
    private:
    vector<vector<T>> my_matrix;
    int row;
    int col;

    public:
    pair<int, int> get_size() const;
    vector<vector<T>> get_matrix() const;

    Vector<T>& operator[](const int &);
    const Vector<T>& operator[](const int &) const;

    Matrix(int, int, T init=0);
    Matrix(const Matrix & );
    Matrix(const vector<vector<T>> &);

    Matrix operator +(const T &);
    Matrix operator -(const T &);
    Matrix operator *(const T &);
    Matrix operator /(const T &);

    Matrix& operator +=(const T &);
    Matrix& operator -=(const T &);
    Matrix& operator *=(const T &);
    Matrix& operator /=(const T &);

    Matrix operator +(const Vector<T> &);
    Matrix operator -(const Vector<T> &);
    Vector<T> operator *(const Vector<T> &);

    Matrix& operator +=(const Vector<T> &);
    Matrix& operator -=(const Vector<T> &);

    Matrix operator +(const Matrix &);
    Matrix operator -(const Matrix &);
    Matrix operator *(const Matrix &);

    Matrix& operator +=(const Matrix &);
    Matrix& operator -=(const Matrix &);
    Matrix& operator *=(const Matrix &);

    Matrix& operator =(const Matrix &);
    Matrix& operator =(const vector<vector<T>> &);
    
    bool operator ==(const Matrix &);
    bool operator ==(const vector<vector<T>> &);

    Matrix transpose();
    Matrix identity();
    Matrix invertion();
    T det();
    T norm();

    friend int rank(const Matrix &);
};


#endif