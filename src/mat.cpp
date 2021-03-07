#include "../includes/mat.hpp"
#include <cstdio>
#include <cstdlib>

using std::vector;

mat::mat(int row, int col, int num=0){
    mat_d = matrix_d(row, (vector_d(col, num)));
}

mat::mat(const matrix_d & matr){
    mat_d = matr;
}

int mat::size() const{
    return mat_d.size();
}

vector_d& mat::operator [](int index){
    if (index < 0 || index >= size()) {
        printf("index out of bound!");
        exit(1);
    }
    return mat_d[index];
}

const vector_d& mat::operator [](int index) const{
    if (index < 0 || index >= size()) {
        printf("index out of bound!");
        exit(1);
    }
    return mat_d[index];
}

mat mat::operator +(const mat & matr){
    if (this->size() != matr.size() || (*this)[0].size() != matr[0].size()){
        printf("matrix size mismatch!");
        exit(1);
    }

    matrix_d newMat = mat_d;
    for (int i=0; i<this->size(); i++)
        for (int j=0; j<(*this)[0].size(); j++) 
            newMat[i][j] += matr[i][j];
    return mat(newMat);
}

mat mat::operator -(const mat & matr){
    if (this->size() != matr.size() || (*this)[0].size() != matr[0].size()){
        printf("matrix size mismatch!");
        exit(1);
    }

    matrix_d newMat = mat_d;
    for (int i=0; i<this->size(); i++)
        for (int j=0; j<(*this)[0].size(); j++) 
            newMat[i][j] -= matr[i][j];
    return mat(newMat);
}

mat mat::operator *(const mat & matr){
    if ((*this).size() != matr.size()) {
        printf("col of mat 1 mismatch row of mat 2!");
        exit(1);
    }

    int row = this->size();
    int col = matr[0].size();

    mat newMat(row, col);
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            for (int k=0; k<matr.size(); k++)
                newMat[i][j] += (*this)[i][k]*matr[k][j];

    return newMat;
}

void mat::operator +=(const mat & matr){
    if (this->size() != matr.size() || (*this)[0].size() != matr[0].size()){
        printf("matrix size mismatch!");
        exit(1);
    }

    for (int i=0; i<this->size(); i++)
        for (int j=0; j<(*this)[0].size(); j++) 
            (*this)[i][j] += matr[i][j];
}

void mat::operator -=(const mat & matr){
    if (this->size() != matr.size() || (*this)[0].size() != matr[0].size()){
        printf("matrix size mismatch!");
        exit(1);
    }

    for (int i=0; i<this->size(); i++)
        for (int j=0; j<(*this)[0].size(); j++) 
            (*this)[i][j] -= matr[i][j];
}

void mat::operator *=(const mat & matr){
    if ((*this).size() != matr.size()) {
        printf("col of mat 1 mismatch row of mat 2!");
        exit(1);
    }

    int row = this->size();
    int col = matr[0].size();

    mat newMat(row, col, 0);
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            for (int k=0; k<matr.size(); k++)
                newMat[i][j] += (*this)[i][k]*matr[k][j];

    (*this) = newMat;
}

mat mat::operator +(const double & k){
    mat newMat(*this);
    for (int i=0; i<newMat.size(); i++)
        for (int j=0; j<newMat[0].size(); j++)
            newMat[i][j] += k;
    return newMat;
}

mat mat::operator -(const double & k){
    mat newMat(*this);
    for (int i=0; i<newMat.size(); i++)
        for (int j=0; j<newMat[0].size(); j++)
            newMat[i][j] -= k;
    return newMat;
}

mat mat::operator *(const double & k){
    mat newMat(*this);
    for (int i=0; i<newMat.size(); i++)
        for (int j=0; j<newMat[0].size(); j++)
            newMat[i][j] *= k;
    return newMat;
}

mat mat::operator /(const double & k){
    if (k == 0) {
        printf("div 0 error");
        exit(1);
    }

    mat newMat(*this);
    for (int i=0; i<newMat.size(); i++)
        for (int j=0; j<newMat[0].size(); j++)
            newMat[i][j] /= k;
    return newMat;
}

void mat::operator +=(const double & k){
    for (auto& rows : this->mat_d)
        for (auto& num : rows)
            num += k;
}

void mat::operator -=(const double & k){
    for (auto& rows : this->mat_d)
        for (auto& num : rows)
            num -= k;
}

void mat::operator *=(const double & k){
    for (auto& rows : this->mat_d)
        for (auto& num : rows)
            num *= k;
}

void mat::operator /=(const double & k){
    if (k == 0){
        printf("div 0 error");
        exit(1);
    }

    for (auto& rows : this->mat_d)
        for (auto& num : rows)
            num /= k;
}

mat mat::invertion(){
    int row = size();
    int col = this->mat_d[0].size();
    if (row != col){
        printf("rectangle matrix can't be inverted");
        exit(1);
    }

    //Guass-Jordan Elimination
    //todo
}