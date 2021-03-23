#ifndef LINEAREQUATIONS_H_
#define LINEAREQUATIONS_H_

#include "vector.hpp"
#include "matrix.hpp"

std::pair<Matrix<double>, Matrix<double>> LU(const Matrix<double> &);

std::pair<Matrix<double>, Matrix<double>> _LU(const Matrix<double> &);

Matrix<double> LL(const Matrix<double> &);

std::pair<Matrix<double>, Matrix<double>> LDL(const Matrix<double> &);

std::vector<Matrix<double>> LDU(const Matrix<double> &);

Vector<double> Guass(Matrix<double>, Vector<double>);

Vector<double> Guass_Jordan(Matrix<double>, Vector<double>);

Vector<double> Doolittle_LU(const Matrix<double> &, Vector<double>);

Vector<double> Crout_LU(const Matrix<double> &, Vector<double>);

Vector<double> Cholesky_LL(const Matrix<double> &, Vector<double>);

Vector<double> Cholesky_LDL(const Matrix<double> &, Vector<double>);

Vector<double> Jacobi_iteration(Matrix<double>, Vector<double>);

Vector<double> Guass_Seidel_iteration(Matrix<double>, Vector<double>);

Vector<double> SOR_iteration(Matrix<double>,  Vector<double>, double);

#endif