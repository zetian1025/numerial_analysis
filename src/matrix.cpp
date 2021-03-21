#include "../includes/matrix.hpp"

template <typename T>
inline std::pair<int, int> Matrix<T>::get_size() const{
    std::pair<int, int> size(row, col);
    return size;
}

template <typename T>
inline std::vector<Vector<T>> Matrix<T>::get_matrix() const{
    return my_matrix;
}

template <typename T>
Vector<T>& Matrix<T>::operator[](const int& index){
    if (index >= row){
        printf("index out of bound\n");
        exit(-1);
    }
    return my_matrix[index];
}

template <typename T>
const Vector<T>& Matrix<T>::operator[](const int& index) const{
    if (index >= row){
        printf("index out of bound\n");
        exit(-1);
    }
    return my_matrix[index];
}

template <typename T>
Matrix<T>::Matrix(int _row, int _col, T init){
    my_matrix = std::vector<Vector<T>>(_row, Vector<T>(_col, init));
    row = _row;
    col = _col;
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T> & Mat){
    std::vector<Vector<T>> temp_matrix = Mat.get_matrix();
    my_matrix = temp_matrix;
    row = Mat.get_size().first;
    col = Mat.get_size().second;
}

template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>> & mat){
    my_matrix.clear();
    for (auto& Vec : mat)
        my_matrix.push_back(Vec);
    row = mat.size();
    col = mat[0].size();
}

template <typename T>
Matrix<T>::Matrix(int _row, const std::vector<T> & vec){
    my_matrix.clear();
    for (int i=0; i<_row; i++) {
        my_matrix.push_back(vec);
    }
    row = _row;
    col = vec.size();
}

template <typename T>
Matrix<T>::Matrix(const std::initializer_list<std::vector<T>> & args){
    my_matrix.clear();
    col = 0;
    for (auto& arg : args){
        my_matrix.push_back(arg);
        col = std::max(col, (const int)(arg.size()));
    }
    row = args.size();
    for (auto& Vec : my_matrix){
        Vec.resize(col);
    }
}

template <typename T>
Matrix<T>::Matrix(const std::vector<Vector<T>> & Mat){
    my_matrix = Mat;
    row = Mat.size();
    col = Mat[0].get_size();
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const T & number){
    std::vector<Vector<T>> newMat = my_matrix;
    for (auto& ele : newMat)
        ele += number;
    return Matrix(newMat);
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const T & number){
    std::vector<Vector<T>> newMat = my_matrix;
    for (auto& ele : newMat)
        ele -= number;
    return Matrix(newMat);
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T & number){
    std::vector<Vector<T>> newMat = my_matrix;
    for (auto& ele : newMat)
        ele *= number;
    return Matrix(newMat);
}
template <typename T>
Matrix<T> Matrix<T>::operator/(const T & number){
    if (fabs(number) < ZERO_LIMIT){
        printf("div 0 error\n");
        exit(-1);
    }
    std::vector<Vector<T>> newMat = my_matrix;
    for (auto& ele : newMat)
        ele /= number;
    return Matrix(newMat);
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const T & number){
    for (auto& ele : my_matrix)
        ele += number;
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const T & number){
    for (auto& ele : my_matrix)
        ele -= number;
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const T & number){
    for (auto& ele : my_matrix)
        ele *= number;
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator/=(const T & number){
    if (fabs(number) < ZERO_LIMIT){
        printf("div 0 error\n");
        exit(-1);
    }
    for (auto& ele : my_matrix)
        ele /= number;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Vector<T> & Vec){
    if (Vec.get_size() != col){
        printf("std::vector and matrix size mismatched!\n");
        exit(-1);
    }
    Matrix<T> newMat(*this);
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            newMat[i][j] += Vec[j];
    return newMat;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Vector<T> & Vec){
    if (Vec.get_size() != col){
        printf("std::vector and matrix size mismatched!\n");
        exit(-1);
    }
    Matrix<T> newMat(*this);
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            newMat[i][j] -= Vec[j];
    return newMat;
}

template <typename T>
Vector<T> Matrix<T>::operator*(const Vector<T> & Vec){
    if (Vec.get_size() != col){
        printf("std::vector and matrix size mismatched!\n");
        exit(-1);
    }
    Vector<T> newVec(row, 0);
    for (int i=0; i<row; i++)
        newVec[i] = (*this)[i].dot(Vec);
    return newVec;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Vector<T> & Vec){
    if (Vec.get_size() != col){
        printf("std::vector and matrix size mismatched!\n");
        exit(-1);
    }
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            my_matrix[i][j] += Vec[j];
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Vector<T> & Vec){
    if (Vec.get_size() != col){
        printf("std::vector and matrix size mismatched!\n");
        exit(-1);
    }
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            my_matrix[i][j] -= Vec[j];
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix & Mat){
    std::pair<int, int> size = Mat.get_size();
    if (row != size.first || col != size.second) {
        printf("matrix size mismatched!\n");
        exit(-1);
    }
    Matrix<T> newMat(*this);
    for (int i=0; i<row; i++) {
        newMat[i] += Mat[i];
    }
    return newMat;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix & Mat){
    std::pair<int, int> size = Mat.get_size();
    if (row != size.first || col != size.second) {
        printf("matrix size mismatched!\n");
        exit(-1);
    }
    Matrix<T> newMat(*this);
    for (int i=0; i<row; i++) {
        newMat[i] -= Mat[i];
    }
    return newMat;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix & Mat){
    std::pair<int, int> size = Mat.get_size();
    if (col != size.first){
        printf("col #1 be not equal to row #2\n");
        exit(-1);
    }
    std::vector<Vector<T>> newmat(row, Vector<T>(size.second, 0));
    for (int i=0; i<row; i++)
        for (int j=0; j<size.second; j++)
            for (int k=0; k<col; k++)
                newmat[i][j] += my_matrix[i][k]*Mat[k][j];
    return Matrix<T>(newmat);
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix & Mat){
    std::pair<int, int> size = Mat.get_size();
    if (row != size.first || col != size.second) {
        printf("matrix size mismatched!\n");
        exit(-1);
    }
    for (int i=0; i<row; i++) {
        (*this)[i] += Mat[i];
    }
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix & Mat){
    std::pair<int, int> size = Mat.get_size();
    if (row != size.first || col != size.second) {
        printf("matrix size mismatched!\n");
        exit(-1);
    }
    for (int i=0; i<row; i++) {
        (*this)[i] -= Mat[i];
    }
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix & Mat){
    std::pair<int, int> size = Mat.get_size();
    if (col != size.first){
        printf("col #1 be not equal to row #2\n");
        exit(-1);
    }
    std::vector<Vector<T>> newmat(row, Vector<T>(size.second, 0));
    for (int i=0; i<row; i++)
        for (int j=0; j<size.second; j++)
            for (int k=0; k<col; k++)
                newmat[i][j] += my_matrix[i][k]*Mat[k][j];
    my_matrix = newmat;
    col = size.second;
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix & Mat){
    auto mat = Mat.get_matrix();
    auto size = Mat.get_size();

    my_matrix = mat;
    row = size.first;
    col = size.second;
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const std::vector<std::vector<T>> & mat){
    my_matrix = mat;
    row = mat.size();
    col = mat[0].size();
}

template <typename T>
bool Matrix<T>::operator==(const Matrix & Mat){
    auto mat = Mat.get_matrix();
    auto size = Mat.get_size();
    if (row != size.first || col != size.second) return false;
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            if (my_matrix[i][j] != Mat[i][j]) return false;
    return true;
}

template <typename T>
bool Matrix<T>::operator==(const std::vector<std::vector<T>> & mat){
    return (*this)==Matrix<T>(mat);
}

template <typename T>
bool Matrix<T>::invertible() const{
    if (row != col) return false;
    int j; double residual;
    Matrix<T> newMat(*this);
    for (int i=0; i<row; i++) {
        j = i+1;
        while (fabs(newMat[i][i]) < ZERO_LIMIT) {
            if (j == row) return false;
            if (fabs(newMat[j][i]) < ZERO_LIMIT) {
                j++;
                continue;
            }
            swap(newMat[j], newMat[i]);
        }
        j = i+1;
        while (j < row) {
            if (fabs(newMat[j][i]) < ZERO_LIMIT){
                j++;
                continue;
            }
            residual = 1.0*newMat[j][i]/newMat[i][i];
            newMat[j] -= (newMat[i] * residual);
            j++;
        }
    }
    return true;
}

template <typename T>
Matrix<T> Matrix<T>::transpose(){
    Matrix<T> newMat(col, row);
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            newMat[j][i] = my_matrix[i][j];
    return newMat;
}

template <typename T>
Matrix<T> Matrix<T>::identity() const{
    if (row != col){
        printf("row != col, matrix can't be inverted.\n");
        exit(-1);
    }

    Matrix<T> newMat(row, col);
    for (int i=0; i<row; i++) {
        newMat[i][i] = 1;
    }
    return newMat;
}

template <typename T>
Matrix<T> Matrix<T>::invertion(){
    if (row != col){
        printf("row != col, matrix can't be inverted.\n");
        exit(-1);
    }
    int j;
    double residual;
    Matrix<T> I(row, col);
    Matrix<T> newMat(*this);
    I = I.identity();
    for (int i=0; i<row; i++) {
        j = i+1;
        while (fabs(newMat[i][i]) < ZERO_LIMIT) {
            if (j == row) {
                printf("matrix is not inversible.\n");
                exit(-1);
            }
            if (fabs(newMat[j][i]) < ZERO_LIMIT) {
                j++;
                continue;
            }
            swap(newMat[j], newMat[i]);
            swap(I[j], I[i]);
        }
        j = i+1;
        while (j < row) {
            if (fabs(newMat[j][i]) < ZERO_LIMIT){
                j++;
                continue;
            }
            residual = 1.0*newMat[j][i]/newMat[i][i];
            newMat[j] -= (newMat[i] * residual);
            I[j] -= (I[i]*residual);
            j++;
        }
    }
    for (int i=0; i<row; i++) {
        if (fabs(newMat[i][i] - 1) >= ZERO_LIMIT) {
            I[i] /= newMat[i][i];
            newMat[i] /= newMat[i][i];
        }
    }
    return I;
}

template <typename T>
double Matrix<T>::det(){
    if (row != col){
        printf("not a square matrix. No det.\n");
        exit(-1);
    }
    int j;
    double residual, det = 1;
    Matrix<T> newMat(*this);
    for (int i=0; i<row; i++) {
        j = i+1;
        while (fabs(newMat[i][i]) < ZERO_LIMIT) {
            if (j == row) return 0;
            if (fabs(newMat[j][i]) < ZERO_LIMIT) {
                j++;
                continue;
            }
            swap(newMat[j], newMat[i]);
        }
        j = i+1;
        while (j < row) {
            if (fabs(newMat[j][i]) < ZERO_LIMIT){
                j++;
                continue;
            }
            residual = 1.0*newMat[j][i]/newMat[i][i];
            newMat[j] -= (newMat[i] * residual);
            j++;
        }
    }
    for (int i=0; i<row; i++) det *= newMat[i][i];
    return det;
}

template <typename T>
double Matrix<T>::norm(const std::string & norm_rank){
    double res = 0;
    if (norm_rank == "1") {
        double temp;
        for (int j=0; j<col; j++){
            temp = 0;
            for (int i=0; i<row; i++)
                temp += fabs(my_matrix[i][j]);
            res = std::max(res, temp);
        }
    }
    else if (norm_rank == "inf"){
        double temp;
        for (int i=0; i<row; i++) {
            temp = 0;
            for (int j=0; j<col; j++)
                temp += fabs(my_matrix[i][j]);
            res = std::max(res, temp);
        }
    }
    else if (norm_rank == "F"){
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++)
                res += my_matrix[i][j]*my_matrix[i][j];
        res = sqrt(res);
    }
    else {
        printf("argument mismatch.\n");
        exit(-1);
    }
    return res;
}