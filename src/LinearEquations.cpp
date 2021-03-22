#include "../includes/LinearEquations.hpp"
#define ITERATION_TIME 100000;

std::pair<Matrix<double>, Matrix<double>> LU(const Matrix<double> & Mat) {
    if (!Mat.invertible()) {
        printf("Matrix is uninvertible.\n");
        exit(-1);
    }
    Matrix<double> L = identity(Mat);
    Matrix<double> U = identity(Mat);
    int n = Mat.get_size().first;
    for (int r=0; r<n; r++) {
        for (int j=r; j<n; j++){
            U[r][j] = Mat[r][j];
            for (int k=0; k<r; k++) U[r][j] -= L[r][k]*U[k][j];
        }
        for (int i=r+1; i<n; i++){
            L[i][r] = Mat[i][r];
            for (int k=0; k<r; k++) L[i][r] -= L[i][k]*U[k][r];
            L[i][r] /= U[r][r];
        }
    }
    return {L, U};
}

std::pair<Matrix<double>, Matrix<double>> _LU(const Matrix<double> & Mat) {
    if (!Mat.invertible()) {
        printf("Matrix is uninvertible.\n");
        exit(-1);
    }
    Matrix<double> L = identity(Mat);
    Matrix<double> U = identity(Mat);

    for (int r=0; r<Mat.get_size().first; r++) {
        for (int i=r; i<Mat.get_size().first; i++) {
            L[i][r] = Mat[i][r];
            for (int k=0; k<r; k++) L[i][r] -= L[i][k]*U[k][r];
        }
        for (int j=r+1; j<Mat.get_size().first; j++) {
            U[r][j] = Mat[r][j];
            for (int k=0; k<r; k++) U[r][j] -= L[r][k]*U[k][j];
            if (fabs(L[r][r]) < ZERO_LIMIT) {
                printf("Sequential principal minor is illegal.\n");
                exit(-1);
            }
            else U[r][j] /= L[r][r];
        }
    }

    return {L, U};
}

Matrix<double> LL(const Matrix<double> & Mat){
    if (!Mat.invertible()) {
        printf("Matrix is uninvertible.\n");
        exit(-1);
    }
    auto size = Mat.get_size();
    int row, col; row = col = size.first;
    Matrix<double> L(Mat);
    for (int j=0; j<col; j++) {
        std::cout << L;
        for (int i=0; i<j; i++) L[j][j] -= L[i][j]*L[j][i];
        L[j][j] = sqrt(L[j][j]);
        for (int i=j+1; i<row; i++) {
            for (int k=0; k<j; k++) L[i][j] -= L[i][k]*L[k][j];
            L[i][j] /= L[j][j];
            L[j][i] = L[i][j];
        }
    }
    for (int i=0; i<row; i++) for (int j=i+1; j<col; j++) L[i][j] = 0;
    return L;
}

std::pair<Matrix<double>, Matrix<double>> LDL(const Matrix<double> & Mat){
    if (!Mat.invertible()) {
        printf("Matrix is uninvertible.\n");
        exit(-1);
    }
    Matrix<double> L = identity(Mat);
    Matrix<double> D = identity(Mat);
    int size = Mat.get_size().first;
    for (int i=0; i<size; i++) D[i][i] = Mat[i][i];
    
}

std::vector<Matrix<double>> LDU(const Matrix<double> & Mat){
    auto size = Mat.get_size();
    if (size.first != size.second) {
        printf("row != col. \n");
        exit(-1);
    }
    Matrix<double> L(size.first, size.second);
    Matrix<double> D = identity(Mat);
    Matrix<double> U(size.first, size.second);
    for (int i=0; i<size.first; i++) {
        for (int j=0; j<i; j++) L[i][j] = Mat[i][j];
        D[i][i] = Mat[i][i];
        for (int j=i+1; j<size.second; j++) U[i][j] = Mat[i][j];
    }
    return {L, D, U};
}

Vector<double> Guass(const Matrix<double> &, const Vector<double> &);

Vector<double> Guass_Jordan(const Matrix<double> &, const Vector<double> &);

Vector<double> Doolittle_LU(const Matrix<double> & Mat, Vector<double> Vec){
    if (Mat.get_size().first != Vec.get_size()) {
        printf("Matrix and vector size mismatched.\n");
        exit(-1);
    }
    auto L_U = LU(Mat);
    Matrix<double> L = L_U.first;
    Matrix<double> U = L_U.second;
    // std::cout << L << U;

    int vec_size = Vec.get_size();
    Vector<double> X(vec_size, 0);
    Vector<double> Y(vec_size, 0);
    for (int i=0; i<vec_size; i++) {
        for (int k=i-1; k>=0; k--) Vec[i] -= Y[k]*L[i][k];
        Y[i] = Vec[i];
    }
    // std::cout << Y;
    for (int i=vec_size-1; i>=0; i--) {
        for (int k=i+1; k<vec_size; k++) Y[i] -= X[k]*U[i][k];
        X[i] = Y[i]/=U[i][i];
    }
    return X;
}

Vector<double> Crout_LU(const Matrix<double> & Mat, Vector<double> Vec){
    if (Mat.get_size().first != Vec.get_size()) {
        printf("Matrix and vector size mismatched.\n");
        exit(-1);
    }
    auto L_U = _LU(Mat);
    Matrix<double> L = L_U.first;
    Matrix<double> U = L_U.second;
    // std::cout << L << U;

    int vec_size = Vec.get_size();
    Vector<double> X(vec_size, 0);
    Vector<double> Y(vec_size, 0);
    for (int i=0; i<vec_size; i++) {
        for (int k=i-1; k>=0; k--) Vec[i] -= Y[k]*L[i][k];
        Y[i] = Vec[i]/=L[i][i];
    }
    // std::cout << Y;
    for (int i=vec_size-1; i>=0; i--) {
        for (int k=i+1; k<vec_size; k++) Y[i] -= X[k]*U[i][k];
        X[i] = Y[i];
    }
    return X;
}

Vector<double> Cholesky_LL(const Matrix<double> & Mat, const Vector<double> & Vec);

Vector<double> Cholesky_LDL(const Matrix<double> & Mat, const Vector<double> & Vec);

Vector<double> Jacobi_iteration(Matrix<double> Mat, Vector<double> Vec){
    auto L_D_U = LDU(Mat);
    Matrix<double> L, D, U; L = L_D_U[0], D = L_D_U[1].invertion(), U = L_D_U[2];
    Vector<double> X(Vec.get_size(), 0);
    Vec = D*Vec, Mat = -D*(L + U);
    int n = ITERATION_TIME;
    while (n--) X = Mat*X + Vec;
    return X;
}

Vector<double> Guass_Seidel_iteration(Matrix<double> Mat, Vector<double> Vec){
    auto L_D_U = LDU(Mat);
    Matrix<double> L, D, U; L = L_D_U[0], D = L_D_U[1], U = L_D_U[2];
    Vector<double> X(Vec.get_size(), 0);
    Mat = (L+D).invertion(); Vec = Mat * Vec; Mat *= -U;
    int n = ITERATION_TIME;
    while (n-->0) X = Mat*X + Vec;
    return X;
}

Vector<double> SOR_iteration(Matrix<double> Mat, Vector<double> Vec, double w=1){
    auto L_D_U = LDU(Mat);
    Matrix<double> L, D, U; L = L_D_U[0], D = L_D_U[1], U = L_D_U[2];
    Vector<double> X(Vec.get_size(), 0);
    Mat = (w*L + D).invertion(); Vec = w*Mat*Vec; Mat *= ((1-w)*D - w*U);
    int n = ITERATION_TIME;
    while (n-->0) X = Mat*X + Vec;
    return X;
}