#include "../includes/matrix.hpp"

template <typename T>
inline pair<int, int> Matrix<T>::get_size() const{
    pair<int, int> size(row, col);
    return size;
}

template <typename T>
inline vector<vector<T>> Matrix<T>::get_matrix() const{
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
    my_matrix = vector<vector<T>>(_row, vector<T>(_col, init));
    row = _row;
    col = _col;
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T> & Mat){
    vector<vector<T>> temp_matrix = Mat.get_matrix();
    my_matrix = temp_matrix;
    row = Mat.get_size().first;
    col = Mat.get_size().second;
}

template <typename T>
Matrix<T>::Matrix(const vector<vector<T>> & mat){
    my_matrix = mat;
    row = mat.size();
    col = mat[0].size();
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const T & number){
    vector<vector<T>> newMat = my_matrix;
    for (auto& ele : newMat)
        ele += number;
    return Matrix(newMat);
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const T & number){
    vector<vector<T>> newMat = my_matrix;
    for (auto& ele : newMat)
        ele -= number;
    return Matrix(newMat);
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T & number){
    vector<vector<T>> newMat = my_matrix;
    for (auto& ele : newMat)
        ele *= number;
    return Matrix(newMat);
}
template <typename T>
Matrix<T> Matrix<T>::operator/(const T & number){
    if (abs(number) < ZERO_LIMIT){
        printf("div 0 error\n");
        exit(-1);
    }
    vector<vector<T>> newMat = my_matrix;
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
    if (abs(number) < ZERO_LIMIT){
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
        printf("vector and matrix size mismatched!\n");
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
        printf("vector and matrix size mismatched!\n");
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
        printf("vector and matrix size mismatched!\n");
        exit(-1);
    }
    Vector<T> newVec(row);
    for (int i=0; i<row; i++)
        newVec[i] = (*this)[i].dot(Vec);
    return newVec;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Vector<T> & Vec){
    if (Vec.get_size() != col){
        printf("vector and matrix size mismatched!\n");
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
        printf("vector and matrix size mismatched!\n");
        exit(-1);
    }
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            my_matrix[i][j] -= Vec[j];
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix & Mat){
    pair<int, int> size = Mat.get_size();
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
    pair<int, int> size = Mat.get_size();
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
    pair<int, int> size = Mat.get_size();
    if (col != size.first){
        printf("col #1 be not equal to row #2\n");
        exit(-1);
    }
    vector<vector<T>> newmat(row, vector<T>(size.second, 0));
    for (int i=0; i<row; i++)
        for (int j=0; j<size.second; j++)
            for (int k=0; k<col; k++)
                newmat[i][j] += my_matrix[i][k]*Mat[k][j];
    return Matrix<T>(newmat);
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix & Mat){
    pair<int, int> size = Mat.get_size();
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
    pair<int, int> size = Mat.get_size();
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
    pair<int, int> size = Mat.get_size();
    if (col != size.first){
        printf("col #1 be not equal to row #2\n");
        exit(-1);
    }
    vector<vector<T>> newmat(row, vector<T>(size.second, 0));
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
Matrix<T>& Matrix<T>::operator=(const vector<vector<T>> & mat){
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
bool Matrix<T>::operator==(const vector<vector<T>> & mat){
    return (*this)==Matrix<T>(mat);
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
Matrix<T> Matrix<T>::identity(){
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
        std::cout << i+1 << std::endl;
        j = i+1;
        while (abs(newMat[i][i]) < ZERO_LIMIT) {
            if (j == row) {
                printf("matrix is not inversible.\n");
                exit(-1);
            }
            if (abs(newMat[j][i]) < ZERO_LIMIT) {
                j++;
                continue;
            }
            swap(newMat[j], newMat[i]);
            swap(I[j], I[i]);
        }
        j = i+1;
        while (j < row) {
            if (abs(newMat[j][i]) < ZERO_LIMIT){
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
        if (abs(newMat[i][i] - 1) < ZERO_LIMIT) {
            I[i] /= newMat[i][i];
            newMat[i] /= newMat[i][i];
        }
    }
    return I;
}