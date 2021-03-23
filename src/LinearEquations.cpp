#include "../includes/LinearEquations.hpp"
#define ITERATION_TIME 100000;

std::pair<Matrix<double>, Matrix<double>> LU(const Matrix<double> & Mat) {
    if (!Mat.invertible()) {
        printf("[LU]Matrix is uninvertible.\n");
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
        printf("[_LU]Matrix is uninvertible.\n");
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
                printf("[_LU]Sequential principal minor is illegal.\n");
                exit(-1);
            }
            else U[r][j] /= L[r][r];
        }
    }

    return {L, U};
}

Matrix<double> LL(const Matrix<double> & Mat){
    if (!Mat.invertible()) {
        printf("[LL]Matrix is uninvertible.\n");
        exit(-1);
    }
    auto size = Mat.get_size();
    int row, col; row = col = size.first;
    Matrix<double> L(Mat);
    for (int j=0; j<col; j++) {
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
        printf("[LDL]Matrix is uninvertible.\n");
        exit(-1);
    }
    Matrix<double> L = identity(Mat);
    Matrix<double> D = identity(Mat);
    int size = Mat.get_size().first;
    for (int i=0; i<size; i++) D[i][i] = Mat[i][i];
    for (int r=0; r<size; r++) {
        for (int k=0; k<r; k++) D[r][r] -= D[k][k]*L[r][k]*L[r][k];
        for (int i=r+1; i<size; i++) {
            L[i][r] = Mat[i][r];
            for (int k=0; k<r; k++) L[i][r] -= L[i][k]*D[k][k]*L[r][k];
            L[i][r] /= D[r][r];
        }
    }
    return {L, D};
}

std::vector<Matrix<double>> LDU(const Matrix<double> & Mat){
    auto size = Mat.get_size();
    if (size.first != size.second) {
        printf("[LDU]row != col. \n");
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

Vector<double> Guass(Matrix<double> Mat, Vector<double> Vec){
    double residual;
    auto size = Mat.get_size();
    int row, col; row = size.first, col = size.second;
    if (row != col) {
        printf("[G]row != col.\n");
        exit(-1);
    }

    for (int i=0; i<row; i++) {
        int j = i+1;
        while (fabs(Mat[i][i]) < ZERO_LIMIT || fabs(Vec[i]) < ZERO_LIMIT) {
            if (j == row) {
                printf("[G]Equation has no solution or infinite solutions.\n");
                exit(-1);
            }
            if (fabs(Mat[i][i]) > ZERO_LIMIT && fabs(Vec[i]) > ZERO_LIMIT) {
                swap(Mat[i], Mat[j]);
                swap(Vec[i], Vec[j]);
            }
        }
        for(int j=0; j<row; j++) {
            if (j == i) continue;
            residual = Mat[j][i] / Mat[i][i];
            Mat[j] -= residual*Mat[i];
            Vec[j] -= residual*Vec[i];
        }
    }
    for (int i=0; i<row; i++) Vec[i] /= Mat[i][i];
    return Vec;
}

Vector<double> Guass_Jordan(Matrix<double> Mat, Vector<double> Vec){
    double residual;
    auto size = Mat.get_size();
    int row, col; row = size.first, col = size.second;
    if (row != col) {
        printf("[GJ]row != col.\n");
        exit(-1);
    }

    for (int i=0; i<row; i++) {
        int index = i;
        for (int j=i+1; j<row; j++) if(fabs(Mat[j][i]) > fabs(Mat[index][i])) index = j;
        swap(Mat[i], Mat[index]); swap(Vec[index], Vec[i]);
        if (fabs(Mat[i][i]) < ZERO_LIMIT || fabs(Vec[i]) < ZERO_LIMIT) {
            printf("[GJ]Equation has no solution or infinite solutions.\n");
            exit(-1);
        }
        for(int j=0; j<row; j++) {
            if (j == i) continue;
            residual = Mat[j][i] / Mat[i][i];
            Mat[j] -= residual*Mat[i];
            Vec[j] -= residual*Vec[i];
        }
    }
    for (int i=0; i<row; i++) Vec[i] /= Mat[i][i];
    return Vec;
}

Vector<double> Doolittle_LU(const Matrix<double> & Mat, Vector<double> Vec){
    if (Mat.get_size().first != Vec.get_size()) {
        printf("[D_LU]Matrix and vector size mismatched.\n");
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
        printf("[C_LU]Matrix and vector size mismatched.\n");
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

Vector<double> Cholesky_LL(const Matrix<double> & Mat, Vector<double> Vec) {
    Matrix<double> L(LL(Mat));
    Matrix<double> L_trans(transpose(L));
    int size = Vec.get_size();
    Vector<double> X(size, 0);
    Vector<double> Y(size, 0);

    for (int i=0; i<size; i++) {
        for (int j=0; j<i; j++) Vec[i] -= L[i][j]*Y[j];
        Y[i] = Vec[i] / L[i][i];
    }
    for (int i=size-1; i>=0; i--) {
        for (int j=size-1; j>i; j--) Y[i] -= L_trans[i][j]*X[j];
        X[i] = Y[i] / L_trans[i][i];
    }
    return X;
}

Vector<double> Cholesky_LDL(const Matrix<double> & Mat, Vector<double> Vec){
    auto LD = LDL(Mat);
    Matrix<double> L, D; L = LD.first, D = invertion(LD.second);
    int size = Vec.get_size();
    Vector<double> X(size, 0);
    Vector<double> Y(size, 0);

    for (int i=0; i<size; i++){
        for (int j=0; j<i; j++) Vec[i] -= L[i][j]*Y[j];
        Y[i] = Vec[i];
    }
    Y = D*Y; L.transpose();
    for (int i=size-1; i>=0; i--) {
        for (int j=size-1; j>i; j--) Y[i] -= L[i][j]*X[j];
        X[i] = Y[i];
    }
    return X;
}

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