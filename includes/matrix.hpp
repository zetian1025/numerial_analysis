#ifndef MATRIX_H_
#define MATRIX_H_

#include "vector.hpp"
#include "util.hpp"
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

    Matrix();
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
    bool invertible() const;

    Matrix& transpose();
    Matrix& identity();
    Matrix identity(const int &);
    Matrix& invertion();
    double det();
    double norm(const std::string &);

    friend std::ostream& operator <<(std::ostream& os, const Matrix<T> & Mat){
        int row, col;
        row = Mat.get_size().first;
        col = Mat.get_size().second;
        os << "Matrix: \n" << "row: " << row << "\t col: " << col << std::endl;
        for (int i=0; i<row; i++){
                os << Mat[i] << '\t';
            os << std::endl;
        }
        return os;
    }

    friend Matrix<T> operator *(const double & k, Matrix<T> Mat) { return Mat*k; }

    friend Matrix<T> operator -(Matrix<T> Mat) { return -1*Mat; }

    friend Matrix<T> transpose(Matrix<T> Mat) { return Mat.transpose();}

    friend Matrix<T> identity(Matrix<T> Mat) { return Mat.identity();}

    friend Matrix<T> invertion(Matrix<T> Mat) { return Mat.invertion();}
};

#endif