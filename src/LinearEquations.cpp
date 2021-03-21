#include "../includes/LinearEquations.hpp"

std::pair<Matrix<double>, Matrix<double>> LU(const Matrix<double> & Mat) {
    if (!Mat.invertible()) {
        printf("Matrix is uninvertible.\n");
        exit(-1);
    }
    Matrix<double> L = Mat.identity();
    Matrix<double> U = Mat.identity();
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
    std::cout << L*U;
    return {L, U};
}

std::pair<Matrix<double>, Matrix<double>> _LU(const Matrix<double> & Mat) {
    if (!Mat.invertible()) {
        printf("Matrix is uninvertible.\n");
        exit(-1);
    }
    Matrix<double> L = Mat.identity();
    Matrix<double> U = Mat.identity();

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

Matrix<double> LL(const Matrix<double> & Mat);

std::pair<Matrix<double>, Matrix<double>> LDL(const Matrix<double> & Mat);

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

    int vec_size = Vec.get_size();
    Vector<double> X(vec_size, 0);
    Vector<double> Y(vec_size, 0);
    for (int i=0; i<vec_size; i++) {
        for (int k=i-1; k>=0; k--) Vec[i] -= Y[k]*L[i][k];
        Y[i] = Vec[i];
    }
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

    int vec_size = Vec.get_size();
    Vector<double> X(vec_size, 0);
    Vector<double> Y(vec_size, 0);
    for (int i=0; i<vec_size; i++) {
        for (int k=i-1; k>=0; k--) Vec[i] -= Y[k]*L[i][k];
        Y[i] = Vec[i]/=L[i][i];
    }
    for (int i=vec_size-1; i>=0; i--) {
        for (int k=i+1; k<vec_size; k++) Y[i] -= X[k]*U[i][k];
        X[i] = Y[i];
    }
    return X;
}

Vector<double> Cholesky_LL(const Matrix<double> & Mat, const Vector<double> & Vec);

Vector<double> Cholesky_LDL(const Matrix<double> & Mat, const Vector<double> & Vec);

Vector<double> Jacobi_iteration(const Matrix<double> &, const Vector<double> &);

Vector<double> Guass_Seidel_iteration(const Matrix<double> &, const Vector<double> &);

Vector<double> SOR_iteration(const Matrix<double> &, const Vector<double> &);