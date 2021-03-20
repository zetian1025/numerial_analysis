#ifndef MATRIX_H_
#define MATRIX_H_

#include "vector.hpp"
#include "util.hpp"
#include <utility>
#include <initializer_list>
#include <algorithm>

template <typename T>
class Matrix{
    private:
    std::vector<Vector<T>> my_matrix;
    int row;
    int col;

    public:
    std::pair<int, int> get_size() const;
    std::vector<Vector<T>> get_matrix() const;

    Vector<T>& operator[](const int &);
    const Vector<T>& operator[](const int &) const;

    Matrix(int, int, T init=0);
    Matrix(const Matrix & );
    Matrix(const std::vector<vector<T>> &);
    Matrix(int, const std::vector<T>&);
    Matrix(const std::initializer_list<vector<T>> &);
    Matrix(const std::vector<Vector<T>> &);

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
    Matrix& operator =(const std::vector<std::vector<T>> &);
    
    bool operator ==(const Matrix &);
    bool operator ==(const std::vector<std::vector<T>> &);

    Matrix transpose();
    Matrix identity();
    Matrix invertion();
    double det();
    double norm(const std::string &);

    friend std::ostream& operator <<(std::ostream& os, const Matrix<T> & Mat){
        int row, col;
        row = Mat.get_size().first;
        col = Mat.get_size().second;
        os << "Matrix: \n" << "row: " << row << "\t col: " << col << std::endl;
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++)
                os << Mat[i][j] << '\t';
            os << std::endl;
        }
        return os;
    }
};

#endif